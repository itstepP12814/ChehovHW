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
            double tempFahrenheit = 98.5;
            double temCelsius = (tempFahrenheit - 32D) * 5 / 9;
            Console.WriteLine("По фаренгуйту: {0}, по цельсю: {1}", tempFahrenheit, temCelsius);
        }
    }
}
