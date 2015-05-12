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
            double summ = 1000;
            double P = 0.05;
            int months=0;
            while (summ < 1100D)
            {
                summ += summ *= P;
                ++months;
            }
            Console.WriteLine("Итоговая сумма: {0} была достигнута через {1} месяц(a)", summ, months);
        }
    }
}
