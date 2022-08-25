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

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            ParentForm.Show();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void txtSstudentID_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtPasswordConfirm_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtPassword_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtUserID_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtEmail_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtStudentName_TextChanged(object sender, EventArgs e)
        {

        }

        private void dtBirthday_ValueChanged(object sender, EventArgs e)
        {

        }

        private void rdMale_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void rdFemale_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void openFileDlg_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e) //btnRemove
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

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtStudentID.Text =
            txtStudentName.Text = "";
            dtBirthday.Value = DateTime.Now;
            rdMale.Checked = true;
            rdFemale.Checked = false;
            txtUserID.Text = "";
            txtEmail.Text = "";
            txtPassword.Text = "";
            txtPasswordConfirm.Text = "";
            ComponentResourceManager resourse = new ComponentResourceManager(typeof(RegistrationForm));
            picAvatar.Image = ((System.Drawing.Image)(resourse.GetObject("picAvatar.Image")));
            picAvatar.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            User obj = new User();
            Student objstudent = new Student();
            if (txtUserID.Text.Trim().Length == 0 || txtPassword.Text.Trim().Length == 0 || txtStudentID.Text.Trim().Length == 0)
            {
                MessageBox.Show("StudentID, UserName, Password are not blank", "Input Error", MessageBoxButtons.OK,
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
            obj.StudentID = txtStudentID.Text;
            objstudent.StudentID = txtStudentID.Text;
            objstudent.StudentName = txtStudentName.Text;
            objstudent.email = txtEmail.Text;
            objstudent.Avatar = picAvatar.Image;
            objstudent.Birthday = dtBirthday.Value;
            objstudent.Gender = (rdMale.Checked == true) ? Sex.Male : Sex.Female;
            ParentForm.UserList.Add(obj);
            ParentForm.Studentlist.Add(objstudent);

            MessageBox.Show("New IserID is Created", "Account Created", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
