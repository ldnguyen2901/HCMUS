using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MainData;

namespace AnimalList
{
    class Program
    {
        // static void Main(string[] args)
        // {
        //     Dog cho = new Dog ("Pin",5,30,12);
        //     cho.Displayinfo();
        //     Console.WriteLine(cho.ToString());

        //     Cat meow = new Cat ("monleo",3,20,7);
        //     meow.Displayinfo();
        //     Console.WriteLine(meow.ToString());

        //     Console.ReadLine();
        // }

        static void Main(string[] args)
        {
            int nDog = 3;
            int nCat = 2;

            Dog cho;
            Cat meo;
            object[] obj = new object[nDog + nCat];

            for(int i = 0; i < nDog; i++)
            {
                cho = new Dog();
                cho.InputInfo();
                obj[i] = (Dog)cho;
            }

            for(int i = 0; i < nCat; i++)
            {
                meo = new Cat();
                meo.InputInfo();
                obj[nDog + i] = (Cat)meo;
            }

            for (int i = 0; i < nDog + nCat; i++)
            {
                if (obj[i].GetType() == typeof(Dog))
                {
                    Console.WriteLine("Information of Dog: ");
                    cho = (Dog)obj[i];
                    cho.Displayinfo();
                }
                else
                {
                    Console.WriteLine("Information of Cat: ");
                    meo = (Cat)obj[i];
                    meo.Displayinfo();
                }
            }
            Console.ReadLine();
        }
    }
}

namespace MainData
{
    public class Dog
    {
        private string Name = "Not Assigned";
        private int Age = 0;
        private float Height = 0;
        private float Weight = 0;


        public Dog(string Name = "", int Age = 0, float Height = 0, float Weight = 0)
        {
            this.Name = Name;
            this.Age = Age;
            this.Height = Height;
            this.Weight = Weight;
        }

        public void Displayinfo()
        {
            Console.WriteLine("Name = {0}, Age = {1}, Height = {2}, Weight = {3}\n", Name, Age, Height, Weight);
        }

        public void InputInfo()
        {
        Console.Write("Input Dog Name: ");
        Name = Console.ReadLine();
        InputAge();
        InputHeight();
        InputWeight();
        }
        public void InputAge()
        {
            bool isCompleted = false;

            Console.Write("Input Dog Age: ");
            string strAge = Console.ReadLine();
            try
            {
                Age = int.Parse(strAge);
                if(Age <= 0 || Age > 20)
                {
                    throw new  NegativeNumException();
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
                    InputAge();
            }
        }

        public void InputHeight()
        {
            bool isCompleted = false;
            Console.Write("Input Dog Height(cm): ");
            string strHeight = Console.ReadLine();
        try
        {
            Height = int.Parse(strHeight);
            if(Height <= 0)
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
                    InputHeight();
            }
        }
        
        public void InputWeight()
        {
            bool isCompleted = false;
            Console.Write("Input Dog Weight(kg): ");
            string strWeight = Console.ReadLine();
        try
        {
            Weight = int.Parse(strWeight);
            if(Weight <= 0)
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
                    InputWeight();
            }
        }
    }

    public class Cat
    {
        private string Name = "Not Assigned";
        private int Age = 0;
        private float Height = 0;
        private float Weight = 0;


        public Cat(string Name = "", int Age = 0, float Height = 0, float Weight = 0)
        {
            this.Name = Name;
            this.Age = Age;
            this.Height = Height;
            this.Weight = Weight;
        }

        public void Displayinfo()
        {
            Console.WriteLine("Name = {0}, Age = {1}, Height = {2}, Weight = {3}\n", Name, Age, Height, Weight);
        }
        public void InputInfo()
        {
        Console.Write("Input Cat Name: ");
        Name = Console.ReadLine();
        InputAge();
        InputHeight();
        InputWeight();
        }
        public void InputAge()
        {
            bool isCompleted = false;

            Console.Write("Input Cat Age: ");
            string strAge = Console.ReadLine();
            try
            {
                Age = int.Parse(strAge);
                if(Age <= 0 || Age > 20)
                {
                    throw new  NegativeNumException();
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
                    InputAge();
            }
        }

        public void InputHeight()
        {
            bool isCompleted = false;
            Console.Write("Input Cat Height: ");
            string strHeight = Console.ReadLine();
        try
        {
            Height = int.Parse(strHeight);
            if(Height <= 0)
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
                    InputHeight();
            }
        }
        
        public void InputWeight()
        {
            bool isCompleted = false;
            Console.Write("Input Cat Weight: ");
            string strWeight = Console.ReadLine();
        try
        {
            Weight = int.Parse(strWeight);
            if(Weight <= 0)
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
                    InputWeight();
            }
        }
    }
    public class NegativeNumException : Exception
    {
        public NegativeNumException() {}
        public NegativeNumException(string message): base(message) {}
    }
}