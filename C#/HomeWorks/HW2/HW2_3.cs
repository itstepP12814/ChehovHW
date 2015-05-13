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
        static bool PolindromCompare(string str)
        {

            if (str.Length <= 1)
            {
                Console.WriteLine("В строке слишком мало символов");
                return false;
            }
            str = str.ToLower();
            str = str.Replace(" ", string.Empty);
            int j = str.Length-1;
            for (int i = 0; i < str.Length; ++i)
            {
                if (str[i] != str[j]) return false;
                --j;
            }
                return true;
        }

        static void Main(string[] args)
        {
            string str;
            str = Console.ReadLine();
            if (PolindromCompare(str)) Console.WriteLine("Строка - полиндром");
            else Console.WriteLine("Строка не палиндром");
        }
    }
}
