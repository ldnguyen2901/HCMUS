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
    public partial class AirTicketBooking : Form
    {
        LoginForm ParentForm;
        string strRegistration;
        public Customer currentCustomer;
        public User currentUser;
        public int idxRegistration;

        public AirTicketBooking()
        {
            InitializeComponent();
            ParentForm = LoginForm.OriginalForm;
            foreach (Flight obj in ParentForm.FlightList)
                lsbFlightList.Items.Add(obj.FlightID);
            rtxRegistrationInfo.Text = "";
        }

        public void SetCurrentuser(User user)
        {
            currentUser = user;
            currentCustomer = ParentForm.CustomerList.Find(x => (x.CustomerID == currentUser.CustomerID));
            idxRegistration = ParentForm.FlightRegList.FindIndex(x => (x.CustomerID == currentCustomer.CustomerID));
            if (idxRegistration >= 0)
            {
                foreach (Flight obj in ParentForm.FlightRegList[idxRegistration].FlightEnrollList)
                {
                    int idx = lsbFlightList.FindString(obj.FlightID.Trim());
                    lsbFlightList.SetSelected(idx, true);
                }
            }
            ShowRegistrationInfo();
        }
        public string ShowRegistrationInfo()
        {
            strRegistration = "\t\t\t Flight Registration of Customer \n";
            strRegistration += "---------------------------------------------------------------------------------------------\n";
            strRegistration += String.Format("\tCustomerID: {0}\n \tCustomer Name: {1} \n", currentCustomer.CustomerID
                                                                                        , currentCustomer.CustomerName);

            strRegistration += "---------------------------------------------------------------------------------------------";
            strRegistration += "\n" + "FlightID" + "\t\t" + "TimeDepart" + "\t" + "TimeArrival"+ "\t" + "Flight Type";
            Flight obj;
            foreach (Object selectedItem in lsbFlightList.SelectedItems)
            {
                obj = ParentForm.FlightList.Find(x => (x.FlightID == selectedItem.ToString()));
                if (obj != null)
                    strRegistration += "\n" + obj.FlightID + "\t\t" + obj.TimeDepart + "\t\t" + obj.TimeArrival+ "\t\t" + obj.FlightType;
            }
            rtxRegistrationInfo.Text = strRegistration;
            return strRegistration;
        }
        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (idxRegistration < 0)
            {
                ParentForm.FlightRegList.Add(new FlightRegistration(currentCustomer.CustomerID));
                idxRegistration = ParentForm.FlightRegList.FindIndex(x => (x.CustomerID == currentCustomer.CustomerID));
                Flight obj;
                foreach (Object selectedItem in lsbFlightList.SelectedItems)
                {
                    obj = ParentForm.FlightList.Find(x => (x.FlightID == selectedItem.ToString()));
                    ParentForm.FlightRegList[idxRegistration].FlightEnrollList.Add(obj);


                }
            }
            ShowRegistrationInfo();
        }

        private void btnLogOut_Click(object sender, EventArgs e)
        {
            this.Close();
            ParentForm.Resetlogin = true;
            ParentForm.Show();
        }

        private void btnConfirm_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ShowRegistrationInfo(), "Thank You", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void lsbFlightList_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void rtxRegistrationInfo_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
