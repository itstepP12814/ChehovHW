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
        static int WordCount(string str)
        {   //количество слов=количество пробелов между словами+1
            str = str.Trim();
            int spaces = 0;
            for (int i = 0; i < str.Length; ++i)
            {
                if (str[i] == ' ') ++spaces;
            }
            return spaces + 1;
        }

        static void Main(string[] args)
        {
            string str;
            str = Console.ReadLine();
            if (str.Length >= 1) Console.WriteLine("В строке {0} слова", WordCount(str));
        }
    }
}
