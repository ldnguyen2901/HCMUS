using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Runtime.InteropServices;
using MainData;
using AttributeData;
using System.IO;
delegate int MilkReadWrite(string filename);

namespace Assignment2
{
    class Program
    {
        static void Main(string[] args)
        {
            Milk milk = new Milk();
            milk.ValMilkName = "Cô gái hà lan";
            milk.ValProductionDate = "20/10/2021";
            milk.ValExpiredDate = "20/10/2022";
            milk.ValQuantity = 10;

            Console.WriteLine("Thong tin Milk la:");
            Console.WriteLine("\t MilkID = {0},\n\t MilkName = {1}", milk.ValMilkID, milk.ValMilkName);
            Console.WriteLine("\t ProductionDate = {0},\n\t ExpiredDate = {1}", milk.ValProductionDate, milk.ValExpiredDate);
            Console.WriteLine("\t Quantity = {0} ", milk.ValQuantity);

            Type type = typeof(Milk);
            string OutputMessage = "Thong Tin chinh sua Milk:";
            foreach (Object attributes in type.GetCustomAttributes(false))
            {
                MilkMoreInfo cinfo = (MilkMoreInfo)attributes;
                if (cinfo != null)
                {
                    OutputMessage = String.Format("\n\t Manufacturer = {0}, \n", cinfo.Manufacturer);
                    OutputMessage += String.Format("\n\t CompanyName = {0}", cinfo.CompanyName);
                    Console.WriteLine(OutputMessage);
                }
            }

            int numline = milk.ReadMilkFromFile("D:\\Lập Trình.NET\\MilkData.TXT");
            if (numline > 0)
            {
                Console.WriteLine("Thong tin Milk la:");
                Console.WriteLine("\t MilkID = {0}, MilkName = {1}", milk.ValMilkID, milk.ValMilkName);
                Console.WriteLine("\t ProductionDate = {0}, ExpiredDate = {1}", milk.ValProductionDate, milk.ValExpiredDate);
                Console.WriteLine("\t Quantity = {0} ", milk.ValQuantity);
            }
            milk.WriteMilkToFile("D:\\Lập Trình.NET\\OutputMilk.TXT");
            Console.WriteLine("Write to File Successfully");

            MilkReadWrite action1 = new MilkReadWrite(milk.ReadMilkFromFile);
            MilkReadWrite action2 = new MilkReadWrite(milk.WriteMilkToFile);

            action1.Invoke("D:\\Lập Trình.NET\\MilkData.TXT");
            Console.WriteLine("Read Successfully");

            action2.Invoke("D:\\Lập Trình.NET\\OutputMilk.TXT");
            Console.WriteLine("Write Successfully");

            Console.ReadKey();
        }

    }

}

namespace MainData
{
    interface IMilkAction
    {
        int ReadMilkFromFile(string filename);
        int WriteMilkToFile(string filename);
    }
    [MilkMoreInfo("DutchLady", "FrieslandCampina")]
    class Milk:IMilkAction      
    {
        private string MilkID = "MILK01032016";
        private string MilkName;
        private DateTime ProductionDate; // ngày sản xuất
        private DateTime ExpiredDate; //ngày hết hạn
        private int Quantity; //số lượng

        public Milk(string MilkName = "Not Assigned", string ProductionDate = "01/01/2021", string ExpiredDate = "01/01/2022", int Quantity = 0)
        {
            this.MilkName = MilkName;
            this.ProductionDate = DateTime.ParseExact(ProductionDate, "dd/MM/yyyy", CultureInfo.InvariantCulture);
            this.ExpiredDate = DateTime.ParseExact(ExpiredDate, "dd/MM/yyyy", CultureInfo.InvariantCulture);
            this.Quantity = Quantity;
            this.MilkID = String.Format("Milk{0}", this.ProductionDate.ToString("ddMMyyyy"));
        }
        public string ValMilkID
        {
            get { return MilkID; }
        }
        public string ValMilkName
        {
            get { return MilkName; }
            set { MilkName = value; }
        }
        public string ValProductionDate
        {
            get { return ProductionDate.ToString("dd/MM/yyyy"); }
            set
            {
                ProductionDate = DateTime.ParseExact(value, "dd/mm/yyyy", CultureInfo.InvariantCulture);
                MilkID = String.Format("Milk{0}", this.ProductionDate.ToString("ddmmyyyy"));
            }
        }
        public string ValExpiredDate
        {
            get { return ExpiredDate.ToString("dd/MM/yyyy"); }
            set
            {
                ExpiredDate = DateTime.ParseExact(value, "dd/mm/yyyy", CultureInfo.InvariantCulture);

            }
        }
        public int ValQuantity
        {
            get { return Quantity; }
            set { Quantity = value; }
        }

        public int ReadMilkFromFile(string filename)
        {
            int counter = 0;
            string line;
            // Read the file and display it line by line.
            System.IO.StreamReader file = new System.IO.StreamReader(filename);
            while ((line = file.ReadLine()) != null)
            {
                string[] terms = line.Split(':');
                if (line.Contains("MilkName:")) ValMilkName = terms[1];
                if (line.Contains("ProductionDate:")) ValProductionDate = terms[1].Trim();
                if (line.Contains("ExpiredDate:")) ValExpiredDate = terms[1].Trim();
                if (line.Contains("Quantity:")) ValQuantity = int.Parse(terms[1].Trim());

                counter++;
            }
            file.Close();
            return counter;
        }
        public int WriteBookToFile(string filename)
        {
            System.IO.StreamWriter file = new System.IO.StreamWriter(filename);
            string OutputMessage = "";
            OutputMessage = string.Format("\n MilkID = {0}, \n MilkName = {1},", ValMilkID, ValMilkName);
            file.WriteLine(OutputMessage);
            OutputMessage = String.Format("\n ProductionDate = {0}, \n ExpiredDate = {1},", ValProductionDate, ValExpiredDate);
            file.WriteLine(OutputMessage);
            OutputMessage = String.Format("\n Quantity = {0}", ValQuantity);
            file.WriteLine(OutputMessage);
            file.Close();
            return 1;
        }
    }
}

namespace AttributeData
{
    [AttributeUsage(AttributeTargets.All, AllowMultiple = true)]
    public class MilkMoreInfo : System.Attribute
    {
        public string Manufacturer { get; set; } // nhà sản xuất
        public string CompanyName { get; set; } // cty phân phối sữa
        public MilkMoreInfo(string Manufacturer = "", string CompanyName = "")
        {
            this.Manufacturer = Manufacturer;
            this.CompanyName = CompanyName;
        }
    }
}
