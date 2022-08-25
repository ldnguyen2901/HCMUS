using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using Excel = Microsoft.Office.Interop.Excel;
using System.Globalization;
using System.Data.SqlClient;

namespace LaptopManagement
{
    public partial class LaptopManagementForm : Form
    {
        public List<Laptop> List = new List<Laptop>();

        public int loadData = 0;
        static string ProjectPath = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;
        string ExcelFilePath = ProjectPath + "\\Data\\LaptopList.xlsx";
        string connetionString = "Data Source=KARAMA\\SQLEXPRESS;Initial Catalog = LaptopDB; Integrated Security=SSPI";
        int CurrentLaptopIndex = -1;
        DataTable datatable;
        BindingSource binding = new BindingSource();

        public LaptopManagementForm()
        {
            InitializeComponent();
        }

        private void btnLoadExcel_Click(object sender, EventArgs e)
        {
            loadData = 1;
            datatable = new DataTable();
            List.Clear();

            int colCount = 9;
            int NumDataRow = ReadDataFromFile(List, ExcelFilePath, colCount);

            var sublist = List.Select(x => new
            {
                LaptopID = x.LaptopID,
                LaptopName = x.LaptopName,
                LaptopType = x.LaptopType,
                ProductDate = x.ProductDate.ToString("dd/MM/yyyy"),
                Processor = x.Processor,
                HDD = x.HDD,
                RAM = x.RAM,
                Price = x.Price.ToString() + "VND"
            }).ToList();

            datatable.Columns.Add("LaptopID");
            datatable.Columns.Add("LaptopName");
            datatable.Columns.Add("LaptopType");
            datatable.Columns.Add("ProductDate");
            datatable.Columns.Add("Processor");
            datatable.Columns.Add("HDD");
            datatable.Columns.Add("RAM");
            datatable.Columns.Add("Price");

            DataRow newrow;
            foreach (var h in sublist)
            {
                newrow = datatable.NewRow();
                newrow["LaptopID"] = h.LaptopID;
                newrow["LaptopName"] = h.LaptopName;
                newrow["LaptopType"] = h.LaptopType;
                newrow["ProductDate"] = h.ProductDate;
                newrow["Processor"] = h.Processor;
                newrow["HDD"] = h.HDD;
                newrow["RAM"] = h.RAM;
                newrow["Price"] = h.Price;
                datatable.Rows.Add(newrow);
                datatable.AcceptChanges();
            }

            binding.AllowNew = true;
            binding.DataSource = datatable;
            dgvLapList.AutoGenerateColumns = false;
            dgvLapList.DataSource = binding;
        }

        public int ReadDataFromFile(List<Laptop> DataList, string FilePath, int colCount)
        {
            Excel.Application xlApp = new Excel.Application();
            Excel.Workbook xlWorkbook = xlApp.Workbooks.Open(FilePath);
            Excel._Worksheet xlWorksheet = xlWorkbook.Sheets[1];
            Excel.Range xlRange = xlWorksheet.UsedRange;

            xlWorksheet.Columns.ClearFormats();
            xlWorksheet.Rows.ClearFormats();

            int rowCount = xlWorksheet.UsedRange.Rows.Count;

            int numLaptop = 0;
            string LaptopID = "";
            string LaptopName = "";
            string LaptopType = "";
            DateTime ProductDate = DateTime.Now;
            string Processor = "";
            string HDD = "";
            string RAM = "";
            int Price = 0;
            string Avatar = "";

            for (int i = 2; i <= rowCount; i++)
            {
                for (int j = 1; j <= colCount; j++)
                {
                    switch (j)
                    {
                        case 1:
                            LaptopID = xlRange.Cells[i, j].Value2.ToString();
                            break;
                        case 2:
                            LaptopName = xlRange.Cells[i, j].Value2.ToString();
                            break;
                        case 3:
                            LaptopType = xlRange.Cells[i, j].Value2.ToString();
                            break;
                        case 4:
                            ProductDate = DateTime.ParseExact(xlRange.Cells[i, j].Value2.ToString(),
                                                              "dd/MM/yyyy", CultureInfo.InvariantCulture);
                            break;
                        case 5:
                            Processor = xlRange.Cells[i, j].Value2.ToString();
                            break;
                        case 6:
                            HDD = xlRange.Cells[i, j].Value2.ToString();
                            break;
                        case 7:
                            RAM = xlRange.Cells[i, j].Value2.ToString();
                            break;
                        case 8:
                            Price = Convert.ToInt32(xlRange.Cells[i, j].Value2.ToString());
                            break;
                        case 9:
                            Avatar = xlRange.Cells[i, j].Value2.ToString();
                            break;
                    }
                }
                DataList.Add(new Laptop());
                DataList[numLaptop].LaptopID = LaptopID;
                DataList[numLaptop].LaptopName = LaptopName;
                DataList[numLaptop].LaptopType = LaptopType;
                DataList[numLaptop].ProductDate = ProductDate;
                DataList[numLaptop].Processor = Processor;
                DataList[numLaptop].HDD = HDD;
                DataList[numLaptop].RAM = RAM;
                DataList[numLaptop].Price = Price;
                DataList[numLaptop].Avatar = Avatar;
                numLaptop = numLaptop + 1;
            }
            
            xlApp.Quit();

            MessageBox.Show("Load Data From Excel Done! : " + (rowCount - 1).ToString() + " Records");

            return (rowCount - 1);
        }

        private void dgvLapList_CellContentClick(object sender, EventArgs e)
        {
            if (List.Count == 0 || datatable.Rows.Count == 0)
            {
                return;
            }

            CurrentLaptopIndex = dgvLapList.CurrentRow.Index;
            if (CurrentLaptopIndex >= 0 && CurrentLaptopIndex < List.Count)
            {
                picLapImage.Image = Image.FromFile(ProjectPath + "\\Data\\" + List[CurrentLaptopIndex].Avatar);
            }
        }

        private void btnLoadSQL_Click(object sender, EventArgs e)
        {
            loadData = 2;
            datatable = new DataTable();
            List.Clear();

            int NumDataRow = ReadDataFromSQLServer(List, connetionString);

            var sublist = List.Select(x => new
            {
                LaptopID = x.LaptopID,
                LaptopName = x.LaptopName,
                LaptopType = x.LaptopType,
                ProductDate = x.ProductDate.ToString("dd/MM/yyyy"),
                Processor = x.Processor,
                HDD = x.HDD,
                RAM = x.RAM,
                Price = x.Price.ToString() + "VND"
            }).ToList();

            datatable.Columns.Add("LaptopID");
            datatable.Columns.Add("LaptopName");
            datatable.Columns.Add("LaptopType");
            datatable.Columns.Add("ProductDate");
            datatable.Columns.Add("Processor");
            datatable.Columns.Add("HDD");
            datatable.Columns.Add("RAM");
            datatable.Columns.Add("Price");

            DataRow newrow;
            foreach (var h in sublist)
            {
                newrow = datatable.NewRow();
                newrow["LaptopID"] = h.LaptopID;
                newrow["LaptopName"] = h.LaptopName;
                newrow["LaptopType"] = h.LaptopType;
                newrow["ProductDate"] = h.ProductDate;
                newrow["Processor"] = h.Processor;
                newrow["HDD"] = h.HDD;
                newrow["RAM"] = h.RAM;
                newrow["Price"] = h.Price;
                datatable.Rows.Add(newrow);
                datatable.AcceptChanges();
            }

            binding.AllowNew = true;
            binding.DataSource = datatable;
            dgvLapList.AutoGenerateColumns = false;
            dgvLapList.DataSource = binding;
        }

        public int ReadDataFromSQLServer(List<Laptop> DataList, string connectionString)
        {
            SqlConnection cnn;
            cnn = new SqlConnection(connectionString);
            int iRow = 0;
            int NumRecords = 0;

            try
            {
                cnn.Open();
                Console.WriteLine("Connection Open !");

                string SqlString = @"SELECT
                                    LaptopID,
                                    LaptopName,
                                    LaptopType,
                                    ProductDate = Convert(varchar(10),CONVERT(date,ProductDate,106),103),
                                    Processor,
                                    HDD,
                                    RAM,
                                    Price,
                                    ImageName
                                    FROM Laptop";

                using (var command = new SqlCommand(SqlString, cnn))
                {
                    using (var reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            List.Add(new Laptop());
                            List[iRow].LaptopID = reader.GetString(0);
                            List[iRow].LaptopName = reader.GetString(1);
                            List[iRow].LaptopType = reader.GetString(2);
                            List[iRow].ProductDate = DateTime.ParseExact(reader.GetString(3), "dd/MM/yyyy",CultureInfo.InvariantCulture);
                            List[iRow].Processor = reader.GetString(4);
                            List[iRow].HDD = reader.GetString(5);
                            List[iRow].RAM = reader.GetString(6);
                            List[iRow].Price = reader.GetInt32(7);
                            List[iRow].Avatar = reader.GetString(8);

                            iRow = iRow + 1;
                        }
                    }
                }

                SqlCommand cmd = new SqlCommand("select count(*) from Laptop", cnn);
                object result = cmd.ExecuteScalar();
                NumRecords = int.Parse(result.ToString());

                MessageBox.Show("Finish Load Data Frome SQL: " + NumRecords.ToString() + "Records");
                cnn.Close();
            }

            catch (SqlException ex)
            {
                MessageBox.Show("Can not open connection ! : " + ex.Message);
            }
            return NumRecords;
        }

        private void dgvLapList_EditingControlShowing(object sender, DataGridViewEditingControlShowingEventArgs e)
        {
            e.Control.KeyPress -= new KeyPressEventHandler(ColumnPrice_KeyPress);
            if (dgvLapList.CurrentCell.ColumnIndex == 7)
            {
                TextBox tb = e.Control as TextBox;
                if (tb != null)
                {
                    tb.KeyPress += new KeyPressEventHandler(ColumnPrice_KeyPress);
                }
            }
        }

        private void ColumnPrice_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar)){
                e.Handled = true;
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            Laptop l = new Laptop();
            l.LaptopID = "Not Assigned";
            l.LaptopName = "Not Assigned";
            l.LaptopType = "Not Assigned";
            l.ProductDate = DateTime.ParseExact("01/01/1900", "dd/MM/yyyy", CultureInfo.InvariantCulture);
            l.Processor = "Not Assigned";
            l.HDD = "Not Assigned";
            l.RAM = "Not Assigned";
            l.Price = 0;
            l.Avatar = "laptop.jpg";
            List.Add(l);

            DataRow newrow;
            newrow = datatable.NewRow();
            newrow["LaptopID"] = l.LaptopID;
            newrow["LaptopName"] = l.LaptopName;
            newrow["LaptopType"] = l.LaptopType;
            newrow["ProductDate"] = l.ProductDate;
            newrow["Processor"] = l.Processor;
            newrow["HDD"] = l.HDD;
            newrow["RAM"] = l.RAM;
            newrow["Price"] = l.Price.ToString() + "VND";
            datatable.Rows.Add(newrow);
            datatable.AcceptChanges();

            MessageBox.Show("Finish Adding");

        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            Laptop l;
            if (CurrentLaptopIndex >= 0)
                l = List[CurrentLaptopIndex];
            else
                return;

            string question = "Do You Want to delete Laptop:" + l.LaptopID;
            DialogResult result = MessageBox.Show(question, "Delete", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
            {
                List.RemoveAt(CurrentLaptopIndex);
                binding.RemoveAt(CurrentLaptopIndex);
            }
            MessageBox.Show("Finish Delete");
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            DataRow row;
            for (int i = 0; i < datatable.Rows.Count; i++)
            {
                row = datatable.Rows[i];

                List[i].LaptopID = row["LaptopID"].ToString();
                List[i].LaptopName = row["LaptopName"].ToString();
                List[i].LaptopType = row["LaptopType"].ToString();
                List[i].ProductDate = DateTime.ParseExact(row["ProductDate"].ToString(),"dd/MM/yyyy",CultureInfo.InvariantCulture);
                List[i].Processor = row["Processor"].ToString();
                List[i].HDD = row["HDD"].ToString();
                List[i].RAM = row["RAM"].ToString();
                string sPrice = row["Price"].ToString();
                List[i].Price = Convert.ToInt32(sPrice.Substring(0, sPrice.IndexOf("VND")));
            }
            MessageBox.Show("Finish Update");
        }

        private void btnUpdateSource_Click(object sender, EventArgs e)
        {
            if (loadData == 1)
                WriteDataToExcelFile(List, ExcelFilePath);
            else
                WriteDataToSQLServer(List, connetionString);
        }

        public void WriteDataToExcelFile(List<Laptop> List, string ExcelFilePath)
        {
            Excel.Application xlApp = new Excel.Application();
            Excel.Workbook xlWorkbook = xlApp.Workbooks.Open(ExcelFilePath);
            Excel._Worksheet xlWorksheet = xlWorkbook.Sheets[1];

            Excel.Range xlRange;
            string[,] Data = new string[1, 10];

            int idxRow = 2;
            foreach (Laptop l in List)
            {
                Data[0, 0] = l.LaptopID;
                Data[0, 1] = l.LaptopName;
                Data[0, 2] = l.LaptopType;
                Data[0, 3] = l.ProductDate.ToString("dd/MM/yyyy", CultureInfo.InvariantCulture);
                Data[0, 4] = l.Processor;
                Data[0, 5] = l.HDD;
                Data[0, 6] = l.RAM;
                Data[0, 7] = l.Price.ToString();
                Data[0, 8] = l.Avatar;

                xlRange = xlWorksheet.get_Range("A" + idxRow.ToString(), "J" + idxRow.ToString());
                xlRange.Value2 = Data;

                idxRow = idxRow + 1;
            }

            xlWorkbook.Save();
            xlWorkbook.Close();
            xlApp.Quit();

            MessageBox.Show("Finish Update to DataSource Excel");
        }

        public void WriteDataToSQLServer(List<Laptop> List, string connetionString)
        {
            SqlConnection cnn;
            SqlCommand myCommand = new SqlCommand();
            string query;

            cnn = new SqlConnection(connetionString);
            try 
            {
                cnn.Open();
                Console.WriteLine("Connection Open !");

                query = "TRUNCATE TABLE Laptop";
                myCommand.CommandText = query;
                myCommand.Connection = cnn;
                myCommand.ExecuteNonQuery();

                query = @"INSERT INTO Laptop(LaptopID,LaptopName,LaptopType,
                                            ProductDate,Processor,HDD,RAM,Price,ImageName)";
                query += @"VALUES (@LaptopID,@LaptopName,@LaptopType,
                                            @ProductDate,@Processor,@HDD,@RAM,@Price,@ImageName)";
                myCommand.CommandText = query;
                myCommand.Connection = cnn;

                myCommand.Parameters.Add(new SqlParameter("@LaptopID", SqlDbType.NVarChar));
                myCommand.Parameters.Add(new SqlParameter("@LaptopName", SqlDbType.NVarChar));
                myCommand.Parameters.Add(new SqlParameter("@LaptopType", SqlDbType.NVarChar));
                myCommand.Parameters.Add(new SqlParameter("@ProductDate", SqlDbType.DateTime));
                myCommand.Parameters.Add(new SqlParameter("@Processor", SqlDbType.NVarChar));
                myCommand.Parameters.Add(new SqlParameter("@HDD", SqlDbType.NVarChar));
                myCommand.Parameters.Add(new SqlParameter("@RAM", SqlDbType.NVarChar));
                myCommand.Parameters.Add(new SqlParameter("@Price", SqlDbType.Int));
                myCommand.Parameters.Add(new SqlParameter("@ImageName", SqlDbType.NVarChar));

                foreach (Laptop l in List)
                {
                   myCommand.Parameters[0].Value = l.LaptopID;
                   myCommand.Parameters[1].Value = l.LaptopName;
                   myCommand.Parameters[2].Value = l.LaptopType;
                   myCommand.Parameters[3].Value = l.ProductDate.ToString("yyyy-MM-dd", CultureInfo.InvariantCulture);
                   myCommand.Parameters[4].Value = l.Processor;
                   myCommand.Parameters[5].Value = l.HDD;
                   myCommand.Parameters[6].Value = l.RAM;
                   myCommand.Parameters[7].Value = l.Price.ToString();
                   myCommand.Parameters[8].Value = l.Avatar;

                   myCommand.ExecuteNonQuery();
                }
                cnn.Close();
            }
            catch (SqlException ex)
            {
                MessageBox.Show("Can not open connection ! " + ex.Message);
            }
            MessageBox.Show("Finish Update to DataSource SQL Server");
        }

        
    }
}
