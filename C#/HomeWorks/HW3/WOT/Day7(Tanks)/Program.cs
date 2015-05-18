using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyClassLib.WorldOfTanks;

namespace Day7_Tanks_
{
    class Program
    {
        static int FindByModel(string model_, Tank[] array)
        {
            int count = 0;
            for (int i = 0; i < array.Length; ++i)
            {
                if (array[i].Model == model_) ++count;
            }
            return count;
        }
        static void Main(string[] args)
        {
            Random ran = new Random();
            Tank[] T34array = new Tank[5];
            Tank[] panterArray = new Tank[5];
            Tank[] winnersArray = new Tank[5];

            for (int i = 0; i < 5; ++i) T34array[i] = new Tank(ran.Next(0, 100), ran.Next(0, 100), ran.Next(0, 100), "T34");
            for (int i = 0; i < 5; ++i) panterArray[i] = new Tank(ran.Next(0, 100), ran.Next(0, 100), ran.Next(0, 100), "Panter");
            for (int i = 0; i < 5; ++i)
            {
                Console.WriteLine(T34array[i].ToString() + "\n" + panterArray[i].ToString());
                Console.WriteLine();
                winnersArray[i] = T34array[i] ^ panterArray[i];
                Console.WriteLine("Победил " + winnersArray[i].ToString());
                Console.WriteLine();
            }
            if (FindByModel("Panter", winnersArray) >= 3) Console.WriteLine("Победила команда Пантер");
            else Console.WriteLine("Победила команда Т34");
        }
    }
}
