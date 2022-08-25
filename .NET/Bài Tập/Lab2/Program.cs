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
delegate int BookReadWrite(string filename);

namespace Lab2
{
    class Program
    {
        [DllImport("User32.dll")]
        public static extern int MessageBox(int hParent, string Message, string Caption, int Type);
        static void Main(string[] args)
        {
            Book book = new Book();
            book.ValAuthor = "Nguyen Van";
            book.ValTitle = "Lap Trinh NET";
            book.ValPublishedDate = "21/12/2015";
            book.ValPrice = 200;

            // Console.WriteLine("Thong tin sach la:");
            // Console.WriteLine("\t BookID = {0}, Title = {1}", book.ValBookID, book.ValTitle);
            // Console.WriteLine("\t Author = {0}, PublishedDate = {1}", book.ValAuthor, book.ValPublishedDate);
            // Console.WriteLine("\t Price = {0} VND", book.ValPrice);

            // string OutputMessage = String.Format("\n BookID = {0}, \n Title = {1}", book.ValBookID, book.ValTitle);
            // OutputMessage += String.Format("\n Author = {0}, \n PublishedDate = {1}", book.ValAuthor, book.ValPublishedDate);
            // OutputMessage += String.Format("\n Price {0} VND", book.ValPrice);
            // MessageBox(0, OutputMessage, "Thong Tin Sach", 1);

            Type type = typeof(Book);
            string OutputMessage = "Thong Tin Chinh Sua Lop:";
            foreach (Object attributes in type.GetCustomAttributes(false))
            {
                CodingInfo cinfo = (CodingInfo)attributes;
                if (cinfo != null)
                {
                    OutputMessage = String.Format("\n Developer = {0}, \n", cinfo.DeveloperName);
                    OutputMessage += String.Format("\n\t CreatedDate {0}, ModifiedDate = {1}", cinfo.CreatedDate, cinfo.ModifiedDate);
                    OutputMessage += String.Format("\n\t Comment = {0}", cinfo.Comment);
                    Console.WriteLine(OutputMessage);
                }
            }

            int numline = book.ReadBookFromFile("D:\\HCMUS\\Computer Science\\.NET\\Data\\BookData.txt");
            if (numline > 0)
            {
                Console.WriteLine("Thong tin sach la:");
                Console.WriteLine("\t BookID = {0}, Title = {1}", book.ValBookID, book.ValTitle);
                Console.WriteLine("\t Author = {0}, PublishedDate = {1}", book.ValAuthor, book.ValPublishedDate);
                Console.WriteLine("\t Price = {0} VND", book.ValPrice);
            }
            //book.ValPrice = 700;
            book.WriteBookToFile("D:\\HCMUS\\Computer Science\\.NET\\Data\\OutputData.txt");
            Console.WriteLine("Write to File Successfully");

            BookReadWrite action1 = new BookReadWrite(book.ReadBookFromFile);
            BookReadWrite action2 = new BookReadWrite(book.WriteBookToFile);
            action1.Invoke("D:\\HCMUS\\Computer Science\\.NET\\Data\\BookData.txt");
            Console.WriteLine("Read Successfully");
            //book.ValPrice = 10000;
            action2.Invoke("D:\\HCMUS\\Computer Science\\.NET\\Data\\OutputData.txt");
            Console.WriteLine("Write Successfully");

            Console.ReadKey();
        }
    }
}

namespace MainData
{
    interface IBookAction
    {
        int ReadBookFromFile(string filename);
        int WriteBookToFile(string filename);
    }
    [CodingInfo("Tran Anh", "20/10/2015", "22/10/2015", "Tao Lop Book")]
    [CodingInfo("Nguyen Van", "25/10/2015", "30/10/2015", "Cap Nhat Cach Tao BookID trong lop Book")]
    [CodingInfo("Le Dinh Nguyen", "1/11/2021", "2/11/2021", "Khong biet lam bai, kho qua => dau dau, chong mat")]

    class Book : IBookAction
    {
        private string BookID = "BOOK01011900";
        private string Author;
        private string Title;
        private DateTime PublishedDate;
        private float Price;

        public Book(string Author = "Not Assigned", string Title = "Not Assigned", string PublishedDate = "01/01/1990", float Price = 0)
        {
            this.Author = Author;
            this.Title = Title;
            this.Price = Price;
            this.PublishedDate = DateTime.ParseExact(PublishedDate, "dd/MM/yyyy", CultureInfo.InvariantCulture);
            this.BookID = String.Format("BOOK{0}", this.PublishedDate.ToString("ddMMyyyy"));
        }
        public string ValBookID
        {
            get { return BookID; }
        }
        public string ValAuthor
        {
            get { return Author; }
            set { Author = value; }
        }
        public string ValTitle
        {
            get { return Title; }
            set { Title = value; }
        }
        public string ValPublishedDate
        {
            get { return PublishedDate.ToString("dd/MM/yyyy"); }
            set
            {
                PublishedDate = DateTime.ParseExact(value, "dd/mm/yyyy", CultureInfo.InvariantCulture);
                BookID = String.Format("BOOK{0}", this.PublishedDate.ToString("ddmmyyyy"));
            }
        }
        public float ValPrice
        {
            get { return Price; }
            set { Price = value; }
        }

        public int ReadBookFromFile(string filename)
        {
            int counter = 0;
            string line;
            // Read the file and display it line by line.
            System.IO.StreamReader file = new System.IO.StreamReader(filename);
            while ((line = file.ReadLine()) != null)
            {
                string[] terms = line.Split(':');
                if (line.Contains("Author:")) ValAuthor = terms[1];
                if (line.Contains("Title:")) ValTitle = terms[1];
                if (line.Contains("PublishedDate:")) ValPublishedDate = terms[1].Trim();
                if (line.Contains("Price:")) ValPrice = float.Parse(terms[1].Trim());

                counter++;
            }
            file.Close();
            return counter;
        }

        public int WriteBookToFile(string filename)
        {
            System.IO.StreamWriter file = new System.IO.StreamWriter(filename);

            string OutputMessage = "";
            OutputMessage = string.Format("\nBookID = {0}, \nTitle = {1},", ValBookID, ValTitle);
            file.WriteLine(OutputMessage);
            OutputMessage = String.Format("\nAuthor = {0}, \nPublishedDate = {1},", ValAuthor, ValPublishedDate);
            file.WriteLine(OutputMessage);
            OutputMessage = String.Format("\nPrice = {0} VND", ValPrice);
            file.WriteLine(OutputMessage);
            file.Close();
            return 1;
        }
    }
}



namespace AttributeData
{
    [AttributeUsage(AttributeTargets.All, AllowMultiple = true)]
    public class CodingInfo : System.Attribute
    {
        public string DeveloperName { get; set; }
        public string CreatedDate { get; set; }
        public string ModifiedDate { get; set; }
        public string Comment { get; set; }
        public CodingInfo(string DeveloperName = "", string CreatedDate = "", string ModifiedDate = "", string Comment = "")
        {
            this.DeveloperName = DeveloperName;
            this.CreatedDate = CreatedDate;
            this.ModifiedDate = ModifiedDate;
            this.Comment = Comment;
        }
    }
}