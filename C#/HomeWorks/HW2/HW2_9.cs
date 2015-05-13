using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication
{
    class Programm
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите предложение");
            string str = Console.ReadLine();
            string[] strArray = str.Split();
            for (int i = 0; i < strArray.Length-1; i+=2)
            {
                string temp = strArray[i];
                strArray[i] = strArray[i + 1];
                strArray[i + 1] = temp;
            }
            foreach (string s in strArray) Console.Write(s + " ");
        }
    }
}
