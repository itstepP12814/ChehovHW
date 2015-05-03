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
                if (!Regex.IsMatch(firstStr, "[0-9]")) return;
                Console.WriteLine("Введите второе число");
                secondStr = Console.ReadLine();
                if (!Regex.IsMatch(secondStr, "[0-9]")) return;
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
        }
    }
}
