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

namespace ClassRegistrationApp
{
    public partial class LoginForm : Form
    {
        public static LoginForm OriginalForm;
        public List<Student> Studentlist;
        public List<User> UserList;
        public List<Course> CourseList;
        public List<CourseRegistration> CourseRegList;
        public string startupPath;
        public bool Resetlogin;
        public LoginForm()
        {
            InitializeComponent();
            OriginalForm = this;
            startupPath = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;
            Studentlist = new List<Student>();
            Studentlist.Add(new Student("STO01", "Admin", Image.FromFile(startupPath + "\\Images\\Doraemon.jpg"),
                             Sex.Male, DateTime.Now, "admin@gmail.com"));

            UserList = new List<User>();
            UserList.Add(new User("Admin", "1234", "ST001"));

            CourseList = new List<Course>();
            CourseList.Add(new Course("Co001", "C# Programming", 4));
            CourseList.Add(new Course("Coe02", "Java Programming", 4));
            CourseList.Add(new Course("COe03", "Data Structure", 4));
            CourseList.Add(new Course("Coe04", "Database Management", 4));
            CourseList.Add(new Course("Co005", "Web Design", 4));
            CourseList.Add(new Course("CO006", "Pattern Recognition", 4));
            CourseList.Add(new Course("Co007", "Network Programming", 4));

            CourseRegList = new List<CourseRegistration>();
            Resetlogin = true;
        }

        private void btnLogin_Click_1(object sender, EventArgs e)
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
            }

            ClassSelectionForm obj = new ClassSelectionForm();
            User currentuser = UserList.Find(x => (x.UserName == txtUserName.Text) && (x.Password == txtPassword.Text));
            obj.SetCurrentuser(currentuser);
            this.Hide();
            obj.Show();
        }

        private void btnCancel_Click_1(object sender, EventArgs e)
        {
            System.Environment.Exit(0);
        }

        private void linkLblRegister_LinkClicked_1(object sender, LinkLabelLinkClickedEventArgs e)
        {
            RegistrationForm obj = new RegistrationForm();
            this.Hide();
            obj.Show();
        }

        private void txtUserName_TextChanged(object sender, EventArgs e)
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

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void txtPassword_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void LoginForm_Load(object sender, EventArgs e)
        {

        }
    }
}
