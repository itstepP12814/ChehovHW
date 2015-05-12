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
        {   //а можно было str = str.ToUpper(); =(
            string str="", result="";
            str = Console.ReadLine();
            for (int i = 0; i < str.Length; ++i)
            {
                int temp = Convert.ToInt32(str[i]);
                result += Convert.ToChar(temp - 32);
            }
                Console.WriteLine(result);
        }
    }
}
