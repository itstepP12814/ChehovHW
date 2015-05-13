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
        static void ShowArray(int[,] array)
        {
            for (int i = 0; i < array.GetLength(0); ++i)
            {
                for (int j = 0; j < array.GetLength(0); ++j)
                {
                    Console.Write("{0,4}", array[i, j]);
                }
                Console.WriteLine();
            }
        }
        static int[] GetMax(int[,] array)
        {
            int[] max = new int[array.GetLength(1)];
            for (int k = 0; k < array.GetLength(1); ++k)
            {
                for (int i = 0; i < array.GetLength(0); ++i)
                {
                    if (array[i, k] > max[k]) max[k] = array[i, k];

                }
                
            }
            return max;
        }
        static void RandomInit(int[,] array)
        {
            Random ran = new Random();
            for (int i = 0; i < array.GetLength(0); ++i)
            {
                for (int j = 0; j < array.GetLength(0); ++j)
                {
                    array[i, j] = ran.Next(-100, 100);

                }
            }
        }
        static void Main(string[] args)
        {
            int[,] array = new int[5,5];
            RandomInit(array);
            ShowArray(array);
            int[] max = GetMax(array);
            Console.WriteLine("Максимальные элементы в столбцах:");
            foreach (int a in max)
            {
                Console.Write(a + " ");
            }
            Console.WriteLine();
        }
    }
}
