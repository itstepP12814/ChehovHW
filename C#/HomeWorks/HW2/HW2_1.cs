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
        static void InitializeArray(ref double[] arr)
        {

            for (int i = 0; i < arr.Length; ++i)
            {
                string str;
                str = Console.ReadLine();
                arr[i] = Convert.ToDouble(str);
            }
        }
        static void InitializeArray(ref double[,] arr)
        {
            Random ran = new Random();
            for (int i = 0; i < arr.GetLength(0); ++i)
            {
                for (int j = 0; j < arr.GetLength(1); ++j)
                {
                    arr[i, j] = ran.NextDouble();
                }
            }
        }
        static void ShowArray(ref double[] arr)
        {
            foreach (double a in arr) Console.Write(a + " ");
            Console.WriteLine();
        }
        static void ShowArray(ref double[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); ++i)
            {
                for (int j = 0; j < arr.GetLength(1); ++j)
                {
                    Console.Write(arr[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
        static double GetMaxOrMinElement(ref double[,] arr, bool flag)
        {
            double element = arr[0, 0];
            //если флаг - истина то возвращаем максимальынй жлемент, есл ложь - минимальный
            foreach (double temp in arr)
            {
                if (flag)
                {
                    if (element < temp) element = temp;
                }
                else
                {
                    if (element > temp) element = temp;
                }
            }
            return element;
        }
        static double GetSumm(ref double[,] arr)
        {
            double summ = 0;
            foreach (double temp in arr)
            {
                summ += temp;
            }
            return summ;
        }
        static double GetOp(ref double[,] arr)
        {
            double op = 1;
            foreach (double temp in arr)
            {
                op *= temp;
            }
            return op;
        }
        static double GetOp(ref double[] arr)
        {
            double op = 1;
            foreach (double temp in arr)
            {
                op *= temp;
            }
            return op;
        }
        static double GetSummEvenElements(ref double[] arr){
            double summ = 0;
            for (int i = 0; i < arr.Length; i += 2)
            {
                summ += arr[i];
            }
            return summ;
        }
        static double GetSummOddColumns(ref double[,] arr)
        {
            double summ = 0;
            for (int i = 0; i < arr.GetLength(0); ++i)
            {
                for (int j = 1; j < arr.GetLength(1); j+=2)
                {
                    summ += arr[i, j];
                }
            }
            return summ;
        }
        static void Main(string[] args)
        {
            double[] arr = new double[5];
            Console.WriteLine("Вводите числа");
            InitializeArray(ref arr);
            ShowArray(ref arr);
            double[,] arr_2D = new double[3, 4];
            InitializeArray(ref arr_2D);
            ShowArray(ref arr_2D);
            Console.WriteLine("Максимальный элемент одномерного массива\n"+arr.Max());
            Console.WriteLine("Минимальный элемент одномерного массива\n" + arr.Min());
            Console.WriteLine("Максимальный элемент двумерного массива\n"+GetMaxOrMinElement(ref arr_2D, true));
            Console.WriteLine("Минимальный элемент двумерного массива\n"+GetMaxOrMinElement(ref arr_2D, false));
            Console.WriteLine("Сумма всех элементов одномерного массива\n"+arr.Sum());
            Console.WriteLine("Сумма всех элементов двумерного массива\n" + GetSumm(ref arr_2D));
            Console.WriteLine("Произведение всех элементов одномерного массива\n" + GetOp(ref arr));
            Console.WriteLine("Произведение всех элементов двумерного массива\n" + GetOp(ref arr_2D));
            Console.WriteLine("Cумма всех четных элементов одномерного массива\n" + GetSummEvenElements(ref arr));
            Console.WriteLine("Cумма всех нечетных столбцов двумерного массива\n" + GetSummOddColumns(ref arr_2D));        }
    }
}
