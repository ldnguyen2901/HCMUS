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

namespace ClassPlaneTicket
{
    public partial class LoginForm : Form
    {
        public static LoginForm OriginalForm;
        public List<Customer> CustomerList;
        public List<User> UserList;
        public List<Flight> FlightList;
        public List<FlightRegistration> FlightRegList;
        public string startupPath;
        public bool Resetlogin;
        public LoginForm()
        {
            InitializeComponent();
            OriginalForm = this;
            startupPath = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;
            CustomerList = new List<Customer>();
            CustomerList.Add(new Customer("F001", "Admin", sex.Male, DateTime.Now, "123@gmail.com",
                                Image.FromFile(startupPath + "\\Img\\Nobita.jpg")));

            UserList = new List<User>();
            UserList.Add(new User("Admin", "123456", "F001"));//ten dang nhap, mat khau, ID

            FlightList = new List<Flight>();
            FlightList.Add(new Flight("HN_HCM", "9h15", "12h00", "Vietnam Airline"));
            FlightList.Add(new Flight("VN_HQ", "8h15", "14h30", "Vietnam Airline"));
            FlightList.Add(new Flight("VN_NB", "7h30", "14h00", "Vietnam Airline"));
            FlightList.Add(new Flight("ĐN_HCM", "20h15", "21h45", "VietJack"));
            FlightList.Add(new Flight("VN_TL", "13h00", "15h00", "Vietnam Airline"));
            FlightList.Add(new Flight("HCM_PQ", "15h00", "16h30", "VietJack"));
            FlightList.Add(new Flight("PQ_HN", "8h00", "11h30", "Bamboo"));
            FlightList.Add(new Flight("HN_ĐN", "21h00", "22h30", "Vietnam Airline"));

            FlightRegList = new List<FlightRegistration>();
            Resetlogin = true;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void LoginForm_Load(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {
            if (Resetlogin == true)
            {
                txtUserName.Text = "";
                txtPassword.Text = "";
            }

        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (txtUserName.Text.Length == 0)
            {
                MessageBox.Show("Please enter user name", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                txtUserName.Focus();
                return;
            }
            if (txtPassword.Text.Length == 0)
            {
                MessageBox.Show("Please enter password", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                txtPassword.Focus();
                return;
            }
            User Specificone = UserList.Find(x => (x.UserName == txtUserName.Text) && (x.Password == txtPassword.Text));
            if (Specificone == null)
            {
                MessageBox.Show("Username and Password are not matched. \n Please reinput or register a new one",
                                    "User Not Found", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                txtUserName.Text = "";
                txtPassword.Text = "";
                txtUserName.Focus();
                return;
            }

            AirTicketBooking obj = new AirTicketBooking();
            User currentuser = UserList.Find(x => (x.UserName == txtUserName.Text) && (x.Password == txtPassword.Text));
            obj.SetCurrentuser(currentuser);
            this.Hide();
            obj.Show();
        }

        private void txtPassword_TextChanged(object sender, EventArgs e)
        {

        }

        private void linkCrAcc_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            RegistrationForm form = new RegistrationForm(); 
            this.Hide();
            form.Show();
        }
    }
}
