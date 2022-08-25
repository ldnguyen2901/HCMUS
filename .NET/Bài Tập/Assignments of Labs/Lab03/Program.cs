using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MainData;

namespace Lab03
{
    class Program
    {
        static void UpdateNumberofCustomer(Company company)
        {
            company.ValNumberofCustomer = company.Customers.Count;
        }
        static void Main(string[] args)
        {
            Company company = new Company();
            company.ValNameC = "Garena";
            company.CompanyAddorRemoveEvent += new Company.CompanyHandler(UpdateNumberofCustomer);

            company.AddCustomer(new Customer("C001", "Hoang Luan", "SG", 02134522829, CustomerType.TiemNang));
            company.AddCustomer(new Customer("C002", "Ba Nhat", "HN", 0907081191, CustomerType.CanQuanTam));
            company.AddCustomer(new Customer("C003", "Be But", "LA", 030209992, CustomerType.TrungThanh));
            company.AddCustomer(new Customer("C004", "Thien Red", "TD", 0629274613, CustomerType.KhachHangKhac));

            Customer customer = company.SearchCustomer("C002");
            company.RemoveCustomer(customer);

            Customer customer1 = company.SearchCustomer("C005");
            company.AddCustomer(customer1);
            company.CompanyInfo();
        }
    }
}

namespace MainData
{
    public enum CustomerType { TrungThanh, TiemNang, CanQuanTam, KhachHangKhac };
    public class Customer
    {
        string CustomerID = "CS000";
        string CustomerName;
        string CustomerAddress;
        int CustomerPhone;
        CustomerType customertype = CustomerType.KhachHangKhac;
        public Customer() { }
        public Customer(string CustomerID, string CustomerName,
        string CustomerAddress,
        int CustomerPhone,
        CustomerType customertype)
        {
            this.CustomerID = CustomerID;
            this.CustomerName = CustomerName;
            this.CustomerAddress = CustomerAddress;
            this.CustomerPhone = CustomerPhone;
            this.customertype = customertype;
        }
        public string ValCustomerID
        {
            get { return CustomerID; }
            set { CustomerID = value; }
        }
        public string ValCustomerName
        {
            get { return CustomerName; }
            set { CustomerName = value; }
        }
        public string ValCustomerAddress
        {
            get { return CustomerAddress; }
            set { CustomerAddress = value; }
        }
        public int ValCustomerPhone
        {
            get { return CustomerPhone; }
            set { CustomerPhone = value; }
        }
        public CustomerType Valcustomertype
        {
            get { return customertype; }
            set { customertype = value; }
        }

        public void CustomerInfo()
        {
            string customertypeName = Enum.GetName(typeof(CustomerType), customertype);
            if (CustomerID != "CS000")
                Console.WriteLine("Khach hang: {0} - {1} - {2} - {3} - {4}",
                                            CustomerID, CustomerName, CustomerAddress, CustomerPhone, customertype);
        }
    }

    public class Company
    {
        public List<Customer> Customers { get; set; }
        Dictionary<CustomerType, string> customerinfos = new Dictionary<CustomerType, string>();
        string NameC;
        public delegate void CompanyHandler(Company company);
        public event CompanyHandler CompanyAddorRemoveEvent;
        public Company()
        {
            Customers = new List<Customer>();
            NameC = "Not Assigned";
            customerinfos.Add(CustomerType.CanQuanTam, "Khach hang can quan tam");
            customerinfos.Add(CustomerType.KhachHangKhac, "Khach hang can nhung dich vu khac");
            customerinfos.Add(CustomerType.TiemNang, "Khac hang VIP");
            customerinfos.Add(CustomerType.TrungThanh, "Khach hang than quen");
        }
        public string ValNameC
        {
            get { return NameC; }
            set { NameC = value; }
        }
        public void CompanyInfo()
        {
            Console.WriteLine("Cong ty {0} co {1} khach hang nhu sau:", NameC, NumberofCustomer);
            foreach (Customer cs in Customers)
            {
                KeyValuePair<CustomerType, string> info = customerinfos.FirstOrDefault(o => o.Key == cs.Valcustomertype);

                cs.CustomerInfo();
                Console.WriteLine("-Thong tin Khach hang {0}\n", info.Value);
            }
        }
        public Customer SearchCustomer<SCC>(SCC search)
        {
            Customer c = new Customer();
            if (typeof(SCC) == typeof(string))
            {
                c = Customers.FirstOrDefault(o => o.ValCustomerID == search.ToString());
                if (c != null)
                    return c;
            }
            else if (typeof(SCC) == typeof(int))
            {
                if (Convert.ToInt32(search) < Customers.Count)
                    return Customers[Convert.ToInt32(search)];
            }
            else Console.WriteLine("Customer is not found");
            return new Customer();
        }
        int NumberofCustomer = 0;
        public int ValNumberofCustomer
        {
            get { return NumberofCustomer; }
            set { NumberofCustomer = value; }
        }
        public void AddCustomer(Customer customer)
        {
            Customers.Add(customer);
            OnCompanyChanger(this);
        }
        public void RemoveCustomer(Customer customer)
        {
            Customers.Remove(customer);
            OnCompanyChanger(this);
        }
        public void OnCompanyChanger(Company company)
        {
            if (CompanyAddorRemoveEvent != null)
                CompanyAddorRemoveEvent(this);
        }
    }
    public static class MyExtensions
    {
        public static string ConvertToString(this Customer customer)
        {
            string customertypeName = Enum.GetName(typeof(CustomerType), customer.Valcustomertype);
            if (customer.ValCustomerID != "C001")
                return String.Format("Khach hang: {0} - {1} - {2} - {3} - {4}",
                customer.ValCustomerID, customertypeName, customer.ValCustomerAddress, customer.ValCustomerPhone, customertypeName);
            else return "";
        }
    }
}
