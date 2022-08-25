using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MainData;

namespace StudentListManagement
{
    class Program
    {
        // static void Main(string[] args)
        // {
        //     Student sv = new Student ("Le Dinh Nguyen","19110398",20);
        //     sv.InputInfo();
        //     sv.Displayinfo();
        //     Console.WriteLine(sv.ToString());
            

        //     Lecturer gv = new Lecturer("Tran Anh","Khoa Toan-tin",33);
        //     gv.InputInfo();
        //     gv.Displayinfo();
        //     Console.WriteLine(gv.ToString());


        //     Console.ReadLine();
        // }



        static void Main(string[] args)
        {
            int nSV = 2;
            int nGV = 1;

            Student sv;
            Lecturer gv;

            object[] obj = new object [nSV + nGV];

            for(int i = 0; i < nSV; i++)
            {
                sv = new Student();
                sv.InputInfo();
                obj[i] = (Student)sv;
            }
            
            for(int i = 0; i < nGV; i++)
            {
                gv = new Lecturer();
                gv.InputInfo();
                obj[nSV + i] = (Lecturer)gv;
            }

            for (int i = 0; i < nSV+nGV; i++)
            {
                if (obj[i].GetType() == typeof(Student))
                {
                    Console.WriteLine("Information of Student: ");
                    sv = (Student)obj[i];
                    sv.Displayinfo();
                }
                else
                {
                    Console.WriteLine("Information of Lecturer: ");
                    gv = (Lecturer)obj[i];
                    gv.Displayinfo();
                }
            }
            Console.ReadLine();
        }
    }
}

namespace MainData
{
    public class Student
    {
        private string name = "Not Assigned";
        private string code = "Not Assigned";
        private int age = 0;

        public Student(string name = "", string code = "", int age = 0)
        {
            this.name = name;
            this.code = code;
            this.age = age;
        }

        public void Displayinfo()
        {
            Console.WriteLine("Code = {0}, Name = {1}, Age = {2}\n",code, name, age);
        }

        // public override string ToString()
        // {
        //     return "Code = " + code + ", Name = " + name + ", Age = " + age + "\n";
        // }

        public void InputInfo()
        {
        Console.Write("Input Student Name: ");
        name = Console.ReadLine();
        Console.Write("Intput Student Code: ");
        code = Console.ReadLine();
        Console.Write("Input Student Age: ");
        string str = Console.ReadLine();
        try
        {
            age = int.Parse(str);
            if(age <= 0)
            {
                throw new NegativeNumException();
            }

        }
        catch (FormatException)
        {
            Console.Write("Not input a Number. Please reinput a Number: ");
            str = Console.ReadLine();
            age = int.Parse(str);
        }
        catch (NegativeNumException)
        {
            Console.Write("Negative is not accepted. Please reinput a Number: ");
            str = Console.ReadLine();
            age = int.Parse(str);
        }
        }
    }

    public class Lecturer
    {
        private string name = "Not Assigned";
        private string department = "Not Assigned";
        private int age = 0;

        public Lecturer(string name = "", string department = "", int age = 0)
        {
            this.name = name;
            this.department = department;
            this.age = age;
        }

        public void Displayinfo()
        {
            Console.WriteLine("Department = {0}, Name = {1}, Age = {2}\n",department, name, age);
        }

        // public override string ToString()
        // {
        //     return "Department = " + department + ", Name = " + name + ", Age = " + age + "\n";
        // }

        public void InputInfo()
        {
        Console.Write("Input Lecturer Name: ");
        name = Console.ReadLine();
        Console.Write("Intput Lecturer Department: ");
        department = Console.ReadLine();
        Console.Write("Input Lecturer Age: ");
        string str = Console.ReadLine();
        try
        {
            age = int.Parse(str);
            if(age <= 0)
            {
                throw new NegativeNumException();
            }

        }
        catch (FormatException)
        {
            Console.Write("Not input a Number. Please reinput a Number: ");
            str = Console.ReadLine();
            age = int.Parse(str);
        }
        catch (NegativeNumException)
        {
            Console.Write("Negative is not accepted. Please reinput a Number: ");
            str = Console.ReadLine();
            age = int.Parse(str);
        }
        }
        public void InputAge()
        {
            bool isCompleted = false;

            Console.Write("Input Student Age: ");
            string str = Console.ReadLine();
            try
            {
                age = int.Parse(str);
                if(age < 0)
                {
                    throw new  NegativeNumException();
                }
                isCompleted = true;
            }
            catch (FormatException)
            {
                Console.Write("Not input a Number. Please reinput a Number: ");
            }
            catch (NegativeNumException)
            {
                Console.Write("Negative is not accepted. Please reinput a Number: ");
            }
            finally
            {
                if(!isCompleted)
                    InputAge();
            }
        }
    }

    public class NegativeNumException : Exception
    {
        public NegativeNumException() {}
        public NegativeNumException(string message): base(message) {}
    }
}