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
    public partial class ClassSelectionForm : Form
    {
        LoginForm ParentForm;
        string strRegistration;
        public Student currentStudent;
        public User currentUser;
        public int idxRegistration;
        public ClassSelectionForm()
        {
            InitializeComponent();
            ParentForm = LoginForm.OriginalForm;
            foreach (Course obj in ParentForm.CourseList)
                lsbCourseList.Items.Add(obj.CourseName);
            rtxRegistrationInfo.Text = "";
        }


        public void SetCurrentuser(User user)
        {
            currentUser = user;
            currentStudent = ParentForm.Studentlist.Find(x => (x.StudentID == currentUser.StudentID));
            idxRegistration = ParentForm.CourseRegList.FindIndex(x => (x.StudentID == currentStudent.StudentID));
            if (idxRegistration >= 0)
            {
                foreach (Course obj in ParentForm.CourseRegList[idxRegistration].CourseEnrollList)
                {
                    int idx = lsbCourseList.FindString(obj.CourseName.Trim());
                    lsbCourseList.SetSelected(idx, true);
                }
            }
            ShowRegistrationInfo();
        }
        public string ShowRegistrationInfo()
        {
            strRegistration = "\t\t\t Course Registration of Student \n";
            strRegistration += "---------------------------------------------------------------------------------------------\n";
            strRegistration += String.Format("\tStudentID: {0}\n \tStudent Name: {1} \n", currentStudent.StudentID
                                                                                        , currentStudent.StudentName);
            int sumcredit;
            if (idxRegistration >= 0)
                sumcredit = ParentForm.CourseRegList[idxRegistration].CalculateSumCredit();
            else
                sumcredit = 0;
            strRegistration += String.Format("\tSum of Registered Credit: {0} \n", sumcredit);
            strRegistration += "---------------------------------------------------------------------------------------------";
            strRegistration += "\n" + "CourseID" + "\t\t" + "Number of Credit" + "\t\t" + "Course Name";
            Course obj;
            foreach (Object selectedItem in lsbCourseList.SelectedItems)
            {
                obj = ParentForm.CourseList.Find(x => (x.CourseName == selectedItem.ToString()));
                if (obj != null)
                    strRegistration += "\n" + obj.CourseID + "\t\t" + obj.NumCredit + "\t\t" + obj.CourseName;
            }
            rtxRegistrationInfo.Text = strRegistration;
            return strRegistration;
        }
        private void btnLogOut_Click_1(object sender, EventArgs e)
        {
            this.Close();
            ParentForm.Resetlogin = true;
            ParentForm.Show();
        }
        private void btnAdd_Click_1(object sender, EventArgs e)
        {
            if (idxRegistration < 0)
            {
                ParentForm.CourseRegList.Add(new CourseRegistration(currentStudent.StudentID));
                idxRegistration = ParentForm.CourseRegList.FindIndex(x => (x.StudentID == currentStudent.StudentID));
                Course obj;
                foreach (Object selectedItem in lsbCourseList.SelectedItems)
                {
                    obj = ParentForm.CourseList.Find(x => (x.CourseName == selectedItem.ToString()));
                    ParentForm.CourseRegList[idxRegistration].CourseEnrollList.Add(obj);


                }
            }
            ShowRegistrationInfo();
        }
        private void btnConfirm_Click_1(object sender, EventArgs e)
        {
            MessageBox.Show(ShowRegistrationInfo(), "Thank You", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
    }
}
