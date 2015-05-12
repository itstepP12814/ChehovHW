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
            int A, B, C, numOfQuadrats;
            double freeSquare;
            Console.WriteLine("Введите длину");
            A = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите ширину");
            B = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите сторону квадрата");
            C = Convert.ToInt32(Console.ReadLine());
            if (C <= A && C <= B)
            {//проверка влезут ли вообще квадраты в наш прямоугольник
                numOfQuadrats = (A / C) * (B / C);
                freeSquare=((A * B) - (numOfQuadrats*C*C));
                Console.WriteLine("Количество квадратов: {0}\nСвободная площадь: {1}", numOfQuadrats, freeSquare);
            } else
                 Console.WriteLine("Невозможно расставить квадраты");
        }
    }
}
