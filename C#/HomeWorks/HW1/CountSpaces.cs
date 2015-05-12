using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            double spaces = 0;
            char tempChar = ' ';
            Console.WriteLine("Вводите текст, для прекращения ввода нажмите \".\"");
            while (tempChar != '.')
            {
                tempChar = Convert.ToChar(Console.Read());
                if (tempChar == ' ') ++spaces;
            }
            if (spaces > 0)
                Console.WriteLine("Количество пробелов: {0}", spaces);
            else
                Console.WriteLine("Нет пробелов");
        }
    }
}
