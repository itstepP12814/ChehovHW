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
            Console.WriteLine("Введите число");
            string str = Console.ReadLine();
            string result = "";
            if (!Regex.IsMatch(str, "[0-9]")) return;
            for (int i = str.Length-1; i >= 0; --i)
            {
                result += str[i];
            }
            Console.WriteLine(result);
        }
    }
}
