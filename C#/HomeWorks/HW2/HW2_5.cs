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
        static int GetMax(int[,] array)
        {
            int max = array[0, 0];
            foreach (int a in array) if (max < a) max = a;
            return max;
        }
        static int GetMin(int[,] array)
        {
            int min = array[0, 0];
            foreach (int a in array) if (min > a) min = a;
            return min;
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
        static int GetSumm(int[,] array, int min, int max)
        {
            int summ = 0;
            for (int i = 0; i < array.GetLength(0); ++i)
            {
                for (int j = 0; j < array.GetLength(1); ++j)
                {
                    if (array[i, j] == min || array[i, j] == max)
                    {
                        /*флажок отработает только один раз, тогда когда мы наткнемься на максимальный или минимальный элемент,
                         *Это необходимо чтобы на первой интерации цикла n=temp, мы пошли считать сумму от максимального/минимального элемента
                         *не затрагивая все вышележащие элементы в строке, но при последующих итерациях нам необходимо начинать отсчет во вложенном цикле
                         *уже от нуля, поэтому на второй итерации, флажок установится в положение ложь и мы будем 
                         *отсчитывать элементы от нуля(с начала новой строки), до тех пор пока не дойдем до второго максимального/минимального значения. 
                         *Так же, когда мы нактнемься на второй 
                         *элемент максимальный или минимальный, мы сначала его приплюсуем, а потом вычтем из общей суммы, указать n-1  нельзя т.к 
                         *тем самым мы сразу же прервем цикл на первой итерации. А вообще это все, похоже, просто эпичные костыли, и наверняка есть 
                         *нормальное решение этой задачки*/
                        bool flag = true;
                        int temp;
                        for (int m = i; m < array.GetLength(0); ++m)
                        {
                            if (flag) temp = j + 1;
                            else temp = 0;

                            for (int n = temp; n < array.GetLength(1); ++n)
                            {
                                summ += array[m, n];
                                flag = false;
                                if (array[m, n] == min) return summ - min;
                                if (array[m, n] == max) return summ - max;
                            }
                        }
                    }
                }
            }
            return summ;
        }
        static void Main(string[] args)
        {
            int[,] array = new int[5,5];
            RandomInit(array);

            ShowArray(array);
            int min = GetMin(array);
            int max = GetMax(array);
            int summ = GetSumm(array, min, max);
            Console.WriteLine("Минимальный элемент: " + min);
            Console.WriteLine("Максимальный элемент: " + max);
            Console.WriteLine("Сумма между минимальным и максимальным элементами: " + summ);

        }
    }
}
