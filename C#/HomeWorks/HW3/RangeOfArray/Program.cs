using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication
{
    class Programm
    {
        struct AssociativeElement
        {
            private int val;
            private int key;
            public int Key
            {
                get { return key; }
                set { key = (int)value; }
            }
            public int Value
            {
                get { return this.val; }
                set { this.val = (int)value; }
            }
        }
        class RangeOfArray
        {
            public RangeOfArray(int down_, int up_)
            {
                try
                {
                    //проверка возможно ли вообще создать класс с таким количеством элементов
                    if ((up_ - down_) <= 0) throw new IndexOutOfRangeException("Неверное количесто элементов массива");
                    down = down_;
                    up = up_;
                    associativeArray = new AssociativeElement[up - down];
                }
                catch (IndexOutOfRangeException ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }
            public static void keyInitializer(RangeOfArray rof)
            {
                int key = rof.Down;
                for (int i = 0; i < rof.associativeArray.Length; ++i)
                {
                    rof.associativeArray[i].Key = key++;
                }
            }
            public static void valueInitalizer(RangeOfArray roa)
            {
                for (int i = 0; i < roa.associativeArray.Length; ++i)
                {
                    try
                    {
                        string val = Console.ReadLine();
                        roa.associativeArray[i].Value = Convert.ToInt32(val);
                    }
                    catch (FormatException ex)
                    {
                        Console.WriteLine("Введено неверное значение для инициализации");
                    }
                }
            }
            public int this[int index]
            {
                get
                {
                    if (index > up || index < down) throw new IndexOutOfRangeException("Неверный индекс");
                    for (int i = 0; i < associativeArray.Length; ++i)
                    {
                        if (associativeArray[i].Key == index) return associativeArray[i].Value;
                    }
                    return -1;
                }
                set
                {
                    if (index > up || index < down) throw new IndexOutOfRangeException("Неверный индекс");
                    for (int i = 0; i < associativeArray.Length; ++i)
                    {
                        if (associativeArray[i].Key == index) associativeArray[i].Value = (int)value;
                    }

                }
            }
            public int Down
            {
                get { return down; }
            }
            public int Up
            {
                get { return up; }
            }
            private AssociativeElement[] associativeArray;
            private int down;
            private int up;
        }
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Введите нижний индекс");
                string strDown = Console.ReadLine();
                Console.WriteLine("Введите верхний индекс");
                string strUp = Console.ReadLine();
                RangeOfArray rof = new RangeOfArray(Convert.ToInt32(strDown), Convert.ToInt32(strUp));
                RangeOfArray.keyInitializer(rof);
                Console.WriteLine("Проинициализируйте массив");
                RangeOfArray.valueInitalizer(rof);
                Console.WriteLine("Результирующий массив");
                for (int i = rof.Down; i <= rof.Up; ++i)
                {
                    Console.WriteLine("Key: {0,2} Value {1,2}", i, rof[i]);
                }

            }
            catch (FormatException ex)
            {
                Console.WriteLine("Неверно введена верхняя/нижняя граница массива");
            }
        }
    }
}
