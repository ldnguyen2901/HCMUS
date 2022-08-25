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
    public partial class RegistrationForm : Form
    {
        string startupPath;
        string AvatarPath;
        LoginForm ParentForm;
        public RegistrationForm()
        {
            InitializeComponent();
            startupPath = LoginForm.OriginalForm.startupPath;
            ParentForm = LoginForm.OriginalForm;
        }

        private void RegistrationForm_Load(object sender, EventArgs e)
        {

        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            ComponentResourceManager resources = new ComponentResourceManager(typeof(RegistrationForm));
            picAvatar.Image = ((System.Drawing.Image)(resources.GetObject("picAvatar.Image")));
            picAvatar.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            openFileDlg.Title = "Find Avatar Images";
            openFileDlg.Filter = "JPG files|*.jpg";
            openFileDlg.InitialDirectory = startupPath;

            if (openFileDlg.ShowDialog() == DialogResult.OK)
                AvatarPath = openFileDlg.FileName;
            picAvatar.Image = Image.FromFile(AvatarPath);
            startupPath = Path.GetDirectoryName(AvatarPath);
            picAvatar.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            User obj = new User();
            Customer objCustomer = new Customer();
            if (txtUserID.Text.Trim().Length == 0 || txtPassword.Text.Trim().Length == 0 || txtCustomerID.Text.Trim().Length == 0)
            {
                MessageBox.Show("CustomerID, UserName, Password are not blank", "Input Error", MessageBoxButtons.OK,
                                 MessageBoxIcon.Exclamation);
                return;
            }
            if (txtPassword.Text != txtPasswordConfirm.Text)
            {
                MessageBox.Show("Password and Comfirm Password are not matched", "Input Error", MessageBoxButtons.OK,
                                 MessageBoxIcon.Exclamation);
                return;
            }
            User Specificone = ParentForm.UserList.Find(x => (x.UserName == txtUserID.Text) & (x.Password == txtPassword.Text));
            if (Specificone != null)
            {
                MessageBox.Show("UserID is existed", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
            obj.UserName = txtUserID.Text;
            obj.Password = txtPassword.Text;
            obj.CustomerID = txtCustomerID.Text;
            objCustomer.CustomerID = txtCustomerID.Text;
            objCustomer.CustomerName = txtCustomerName.Text;
            objCustomer.Avatar = picAvatar.Image;
            objCustomer.Birthday = dtBirthday.Value;
            ParentForm.UserList.Add(obj);
            ParentForm.CustomerList.Add(objCustomer);

            MessageBox.Show(" New IserID is Created", "Account Created", MessageBoxButtons.OK, MessageBoxIcon.Information);

        }

        private void btncbLogin_Click(object sender, EventArgs e)
        {
            this.Close();
            ParentForm.Show();
        }
    }
}
