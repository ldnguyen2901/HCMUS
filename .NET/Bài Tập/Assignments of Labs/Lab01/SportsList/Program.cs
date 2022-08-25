using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MainData;

namespace SportsList
{
    class Program
    {
        static void Main(string[] args)
        {
            // Tennis tns = new Tennis();
            // Football bongda = new Football();
            // Volleyball bongchuyen = new Volleyball();

            //int nTennis = 0, nFootball = 0, nVolleyball = 0;
            Tennis tns;
            Football bongda;
            Volleyball bongchuyen;

            Console.Write("Enter the number of clubs Tennis: ");
            int nTennis = Convert.ToInt16(Console.ReadLine());
            
            Console.Write("Enter the number of clubs Football: ");
            int nFootball = Convert.ToInt16(Console.ReadLine());
            Console.Write("Enter the number of clubs Volleyball: ");
            int nVolleyball= Convert.ToInt16(Console.ReadLine());            
            int sum = nTennis + nFootball + nVolleyball;

            object[] obj = new object[sum];
            for(int i = 0; i < nTennis; i++)
            {
                tns = new Tennis();
                obj[i] = (Tennis)tns;
            }
            for(int i = 0; i < nFootball; i++)
            {
                bongda = new Football();
                obj[nTennis +  i] = (Football)bongda;
            }
            for(int i = 0; i < nVolleyball; i++)
            {
                bongchuyen = new Volleyball();
                obj[nTennis + nFootball + i] = (Volleyball)bongchuyen;
            }
            Console.WriteLine("\n---------------------------");
            for (int i = 0; i < sum; i++)
            {
                if (obj[i].GetType() == typeof(Tennis))
                {
                    Console.WriteLine("\nInformation of Tennis: ");
                    tns = (Tennis)obj[i];
                    tns.Displayinfo();
                }
                else if (obj[i].GetType() == typeof(Football))
                {
                    Console.WriteLine("\nInformation of Football: ");
                    bongda = (Football)obj[i];
                    bongda.Displayinfo();
                }
                else
                {
                    Console.WriteLine("\nInformation of Volleyball: ");
                    bongchuyen = (Volleyball)obj[i];
                    bongchuyen.Displayinfo();
                }
            }
            Console.ReadLine();
        }
    }
}

namespace MainData
{
    public class Sport //lop cha
    {
        protected string namegr = "Not Assigned";
        protected int amongmember = 0;
        protected float time = 0;
        protected string typeball = "Not Assigned";

        public Sport(string namegr = "", int amongmember = 0, float time = 0, string typeball = "")
        {
            this.namegr = namegr;
            this.amongmember = amongmember;
            this.time = time;
            this.typeball = typeball;
        }
        public void Displayinfo()
        {
            Console.WriteLine("Name Guild: {0}\nNumber of Members: {1}\nTime play: {2}\nTypeball: {3}", namegr, amongmember, time, typeball);
        }
        public virtual void InputInfo()
        {
        //Console.Write(Environment.NewLine); //xuong dong moi
        Console.Write("Input Name Guild: ");
        namegr = Console.ReadLine();
        InputAmongMembers();
        InputTimePlay();
        }
        public virtual void InputAmongMembers()
        {
            bool isCompleted = false;
            Console.Write("Input Number of Members: ");
            string strAmongMember = Console.ReadLine();
        try
        {
            amongmember = int.Parse(strAmongMember);
            if(amongmember <= 0)
            {
                throw new NegativeNumException();
            }
            isCompleted = true;
        }
        catch (FormatException)
            {
                Console.Write("Not input a Number. Please reinput a Number\n");
            }
            catch (NegativeNumException)
            {
                Console.Write("Negative is not accepted. Please reinput a Number\n");
            }
            finally
            {
                if(!isCompleted)
                    InputAmongMembers();
            }
        }
        public virtual void InputTimePlay()
        {
            bool isCompleted = false;
            Console.Write("Input Time Play: ");
            string strTimePay = Console.ReadLine();
        try
        {
            time = float.Parse(strTimePay);
            if(time <= 0)
            {
                throw new NegativeNumException();
            }
            isCompleted = true;
        }
        catch (FormatException)
            {
                Console.Write("Not input a Number. Please reinput a Number\n");
            }
            catch (NegativeNumException)
            {
                Console.Write("Negative is not accepted. Please reinput a Number\n");
            }
            finally
            {
                if(!isCompleted)
                    InputTimePlay();
            }
        }
    }
    public class Tennis : Sport//cac lop con
    {
        public Tennis(string namegr = "", int amongmember = 0, float time = 0) : base(namegr, amongmember, time)
        {
            Console.Write(Environment.NewLine);
            typeball = "Tennis";
            Console.WriteLine("Typeball: {0}", typeball);
            InputInfo();
            // Displayinfo();
        }
        public override void InputAmongMembers()
        {
            bool isCompleted = false;
            Console.Write("Input Number of Members: ");
            string strAmongMember = Console.ReadLine();
        try
        {
            amongmember = int.Parse(strAmongMember);
            if(amongmember <= 0 || amongmember > 2)
            {
                throw new NegativeNumException();
            }
            isCompleted = true;
        }
        catch (FormatException)
            {
                Console.Write("Not input a Number. Please reinput a Number\n");
            }
            catch (NegativeNumException)
            {
                Console.Write("Negative is not accepted. Please reinput a Number\n");
            }
            finally
            {
                if(!isCompleted)
                    InputAmongMembers();
            }
        }
    }

    public class Football : Sport
    {
        public Football(string namegr = "", int amongmember = 0, float time = 0) : base(namegr, amongmember, time)
        {
            Console.Write(Environment.NewLine);
            typeball = "Football";
            Console.WriteLine("Typeball: {0}", typeball);
            InputInfo();
            // Displayinfo();
        }
        public override void InputAmongMembers()
        {
            bool isCompleted = false;
            Console.Write("Input Number of Members: ");
            string strAmongMember = Console.ReadLine();
        try
        {
            amongmember = int.Parse(strAmongMember);
            if(amongmember < 11 || amongmember > 22)
            {
                throw new NegativeNumException();
            }
            isCompleted = true;
        }
        catch (FormatException)
            {
                Console.Write("Not input a Number. Please reinput a Number\n");
            }
            catch (NegativeNumException)
            {
                Console.Write("Negative is not accepted. Please reinput a Number\n");
            }
            finally
            {
                if(!isCompleted)
                    InputAmongMembers();
            }
        }
    }

    public class Volleyball : Sport
    {
        public Volleyball(string namegr = "", int amongmember = 0, float time = 0) : base(namegr, amongmember, time)
        {
            Console.Write(Environment.NewLine);
            typeball = "Volleyball";
            Console.WriteLine("Typeball: {0}", typeball);
            InputInfo();
            // Displayinfo();
        }
        public override void InputAmongMembers()
        {
            bool isCompleted = false;
            Console.Write("Input Number of Members: ");
            string strAmongMember = Console.ReadLine();
        try
        {
            amongmember = int.Parse(strAmongMember);
            if(amongmember < 6 || amongmember > 12)
            {
                throw new NegativeNumException();
            }
            isCompleted = true;
        }
        catch (FormatException)
            {
                Console.Write("Not input a Number. Please reinput a Number\n");
            }
            catch (NegativeNumException)
            {
                Console.Write("Negative is not accepted. Please reinput a Number\n");
            }
            finally
            {
                if(!isCompleted)
                    InputAmongMembers();
            }
        }
    }
    public class NegativeNumException : Exception
    {
        public NegativeNumException() {}
        public NegativeNumException(string message): base(message) {}
    }
}
