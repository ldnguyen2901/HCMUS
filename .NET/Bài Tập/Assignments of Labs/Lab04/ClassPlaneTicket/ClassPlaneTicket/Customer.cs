using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.IO;
using System.ComponentModel;


namespace ClassPlaneTicket
{
    public enum sex { Male, Female };
    public class Customer
    {
        //CustomerID, CustomerName, Birthday, PassPortNbr, Nationality, Avatar
        public string CustomerID { get; set; }
        public string CustomerName { get; set; }
        public sex Gender { get; set; }
        public DateTime Birthday { get; set; }
        public string email { get; set; }
        public Image Avatar { get; set; }
        public Customer()
        {
            CustomerID = "Not Assigned";
        }
        public Customer(string CustomerID, string CustomerName, sex Gender, DateTime Birthday, string email, Image Avatar)
        {
            this.CustomerID = CustomerID;
            this.CustomerName = CustomerName;
            this.Gender = Gender;
            this.Birthday = Birthday;
            this.email = email;
            this.Avatar = Avatar;
        }
    }
    public class User
    {
        public string UserName { get; set; }
        public string Password { get; set; }
        public string CustomerID { get; set; }
        public User()
        {
            UserName = "Not Assigned";
        }
        public User(string UserName, string Password, string CustomerID)
        {
            this.UserName = UserName;
            this.Password = Password;
            this.CustomerID = CustomerID;
        }
    }
    public class Flight
    {
        public string FlightID { get; set; }
        public string TimeDepart { get; set; }
        public string TimeArrival { get; set; }
        public string FlightType { get; set; }
        public Flight()
        {
            FlightID = "Not Assigned";
        }
        public Flight(string FlightID, string TimeDepart, string TimeArrival, string FlightType)
        {
            this.FlightID = FlightID;
            this.TimeDepart = TimeDepart;
            this.TimeArrival = TimeArrival;
            this.FlightType = FlightType;
        }
    }
    public class FlightRegistration
    {
        public string CustomerID { get; set; }
        public List<Flight> FlightEnrollList;
        public FlightRegistration()
        {
            CustomerID = "Not Assigned";
            FlightEnrollList = new List<Flight>();
        }
        public FlightRegistration(string CustomerID)
        {
            this.CustomerID = CustomerID;
            FlightEnrollList = new List<Flight>();
        }
    }
}
