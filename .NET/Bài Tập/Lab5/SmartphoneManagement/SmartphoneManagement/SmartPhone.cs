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
using System.Globalization;
using System.Data.SqlClient;
using Excel = Microsoft.Office.Interop.Excel;

namespace SmartphoneManagement
{
    public partial class Form1 : Form
    {
        public class SmartPhone
        {
            public string SmartPhoneID { get; set; }
            public string SmartPhoneName { get; set; }
            public string SmartPhoneType { get; set; }
            public DateTime AnnoucedDate { get; set; }
            public string Platform { get; set; }
            public string Camera { get; set; }
            public string RAM { get; set; }
            public string Battery { get; set; }
            public int Price { get; set; }
            public string Avatar { get; set; }
            public SmartPhone()
            {
                SmartPhoneID = "Not Assigned";
                SmartPhoneName = "Not Assigned";
            }
        }
    }
}
