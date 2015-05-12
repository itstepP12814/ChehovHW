using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            int first, second;
            string firstStr = "", secondStr = "";
            while (true)
            {
                Console.WriteLine("Введите первое число");
                firstStr = Console.ReadLine();
                Console.WriteLine("Введите второе число");
                secondStr = Console.ReadLine();
                if (CompareString(firstStr) && CompareString(secondStr)) break;
                else  Console.WriteLine("Повторите ввод");
            }
            first = Convert.ToInt32(firstStr);
            second = Convert.ToInt32(secondStr);
            for (int i = first; i <= second; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    Console.Write(i + " ");
                }
                Console.WriteLine();
            }
        }
        static bool CompareString(string str)
        {
            if (str == "") return false;
            for (int i = 0; i < str.Length; ++i)
            {
                int temp = Convert.ToInt32(str[i]);
                if (temp >=48 && temp <= 57) continue;
                else return false;
            }
            return true;
        }
    }
}
