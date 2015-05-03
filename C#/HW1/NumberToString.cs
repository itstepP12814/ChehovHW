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
            int digit = 784;
            string str = ConvertToReadbleString(digit);

            Console.WriteLine(str);

        }
        static string ConvertToReadbleString(int digit)
        {
            string tempDigit = Convert.ToString(digit);
            string readbleString = "";
            if (tempDigit.Length != 3) return "Fail";
            switch (tempDigit[0])
            {
                case '1': readbleString = "cто";
                    break;
                case '2': readbleString = "двести";
                    break;
                case '3': readbleString = "триста";
                    break;
                case '4': readbleString = "четыреста";
                    break;
                case '5': readbleString = "пятьсот";
                    break;
                case '6': readbleString = "шестьсот";
                    break;
                case '7': readbleString = "семьсот";
                    break;
                case '8': readbleString = "восемьсот";
                    break;
                case '9': readbleString = "девятьсот";
                    break;
            }
            readbleString += " ";
            switch (tempDigit[1])
            {
                case '1': readbleString += "десять";
                    break;
                case '2': readbleString += "двадцать";
                    break;
                case '3': readbleString += "тридцать";
                    break;
                case '4': readbleString += "сорок";
                    break;
                case '5': readbleString += "пятьдесят";
                    break;
                case '6': readbleString += "шестьдесят";
                    break;
                case '7': readbleString += "семдесят";
                    break;
                case '8': readbleString += "восемьдесят";
                    break;
                case '9': readbleString += "девяносто";
                    break;
            }
            readbleString += " ";
            switch (tempDigit[2])
            {
                case '1': readbleString += "один";
                    break;
                case '2': readbleString += "два";
                    break;
                case '3': readbleString += "три";
                    break;
                case '4': readbleString += "четыре";
                    break;
                case '5': readbleString += "пять";
                    break;
                case '6': readbleString += "шесть";
                    break;
                case '7': readbleString += "семь";
                    break;
                case '8': readbleString += "восемь";
                    break;
                case '9': readbleString += "девять";
                    break;
            }
            return readbleString;
        }
    }
}
