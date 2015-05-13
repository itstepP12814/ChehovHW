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
        static void ShowArray(int[] arr)
        {
            foreach (int temp in arr) Console.Write(temp + " ");
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            Random ran = new Random();
            int[] arrM = new int[6];
            int[] arrN = new int[10];
            int[] arrCommon = new int[1];
            for (int i = 0; i < arrM.Length; ++i) arrM[i] = ran.Next(0, 10);
            for (int i = 0; i < arrN.Length; ++i) arrN[i] = ran.Next(0, 10);
            Array.Sort(arrM);
            Array.Sort(arrN);

            int j = 0;
            foreach (int temp in arrM)
            {
                int index = -1;
                index = Array.BinarySearch(arrN, temp);

                if (index >= 0)
                {
                    //проверяем нет ли уже искомого числа(повторения) в результирующем массиве
                    int index_repeat = Array.BinarySearch(arrCommon, temp);
                    if (index_repeat >= 0 && arrCommon[index_repeat]!=0) continue;

                    //если не хватет длины массива изменяем размер
                    if (j == arrCommon.Length) Array.Resize(ref arrCommon, arrCommon.Length+1);
                    
                    arrCommon[j] = arrN[index];
                    Array.Sort(arrCommon);
                    ++j;
                }
            }
            ShowArray(arrM);
            ShowArray(arrN);
            Console.WriteLine("Результирующий массив");
            ShowArray(arrCommon);

        }
    }
}
