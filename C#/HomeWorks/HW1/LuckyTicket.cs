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
            int summ1 = 0, summ2 = 0;
            string ticketString;
            Console.WriteLine("Ввeдите номер билета, 6 значное число");

            while (true)
            {
                ticketString = Console.ReadLine();
                bool compare = Regex.IsMatch(ticketString, @"\d{6}");
                if (!compare)
                {
                    Console.WriteLine("Неверный ввод билета, повторите ввод");
                } else break;
            }

            for (int i = 0; i < 3; ++i)
            {
                summ1 += Convert.ToInt32(Convert.ToString(ticketString[i]));
                summ2 += Convert.ToInt32(Convert.ToString(ticketString[i + 3]));
            }
            if (summ1 == summ2) Console.WriteLine("Билет счастливый");
            else Console.WriteLine("Вам еще повезет");
        }
    }
}
