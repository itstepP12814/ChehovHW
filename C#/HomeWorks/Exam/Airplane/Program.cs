using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AirplaneLib;

namespace Airplane
{
    class Program
    {
        /// <summary>
        /// Установка диспетчеров. 
        /// Формируется список диспетчеров, пользователь задает количество диспетчеров и имена
        /// </summary>
        /// <returns>Функция возвращает список диспетчеров List</returns>
        static List<Dispathcer> SetDispatchers()
        {
            int count;
            Console.WriteLine("Введите количество диспетчеров");
            while (true)
            {
                if ((Int32.TryParse(Console.ReadLine(), out count))) break;
                else Console.WriteLine("Неверный формат строки");
            }
            List<Dispathcer> disps = new List<Dispathcer>(count);
            Console.WriteLine("Введите имена диспетчеров");
            string dispName = null;
            try
            {
                for (int i = 0; i < count; ++i)
                {
                    dispName = Console.ReadLine();
                    disps.Add(new Dispathcer(dispName));
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            return disps;
        }
        /// <summary>
        ///Вывод информации от диспетчеров.
        ///Вывод информации о воздушном корридоре
        /// </summary>
        /// <param name="disps">Функция принимает список диспетчеров</param>
        static void ShowDispathcerInfo(List<Dispathcer> disps)
        {
            int lowHeigh = disps[0].RecomendedHeigh;
            int highHeigh = disps[0].RecomendedHeigh;
            int penaltyPoints = 0;
            foreach (Dispathcer d in disps)
            {
                if (lowHeigh > d.RecomendedHeigh) lowHeigh = d.RecomendedHeigh;
                if (highHeigh < d.RecomendedHeigh) highHeigh = d.RecomendedHeigh;
                penaltyPoints += d.PenaltyPoints;
                Console.WriteLine(d);
            }
            Console.WriteLine("Коридор:min{0}|max{1}", highHeigh - 300, lowHeigh + 300);
        }
        /// <summary>
        /// Функция менеджмента диспетчеров
        /// </summary>
        /// <param name="plane">принимает ссылку на список диспетчеров</param>
        static void ManageDispatchers(ref Plane plane)
        {
            Console.WriteLine("1 удаление диспетчера\n2 добавление диспетчера\n3 выход");
            ConsoleKeyInfo keyInfo = Console.ReadKey();
            switch (keyInfo.Key)
            {
                case ConsoleKey.D1:
                    {
                        int i = 0;
                        int number;
                        string s = null;
                        Console.WriteLine("Выбирете id диспетчера");
                        foreach (Dispathcer d in plane.Dispathcers)
                        {
                            Console.WriteLine("{0} {1}", i++, d.Name);
                        }
                        s = Console.ReadLine();
                        if (Int32.TryParse(s, out number))
                        {
                            try
                            {
                                plane.GetPenaltyPointsFromDeletedDispatcher(plane.Dispathcers[number]);
                                plane.Dispathcers.RemoveAt(number);
                            }
                            catch (IndexOutOfRangeException ex)
                            {
                                Console.WriteLine(ex.Message);
                            }
                        }

                    }
                    break;
                case ConsoleKey.D2:
                    {
                        List<Dispathcer> list = SetDispatchers();
                        plane.AddDispatcher(list);
                    }
                    break;
                case ConsoleKey.D3: return;
                default: break;
            }
        }
        static void Main(string[] args)
        {
            List<Dispathcer> disps = SetDispatchers();
            Plane plane = new Plane("3218", disps);

            Console.WriteLine("Управление стрелками курсора. D - открывает меню диспетчеров");
            Console.WriteLine("Ок. Взлетайте");
            Console.WriteLine(plane);
            while (true)
            {
                if (!plane.MayFly)
                {
                    Console.WriteLine("Недостаточно диспетчеров");
                    plane.AddDispatcher(SetDispatchers());
                }
                ConsoleKeyInfo keyInfo = Console.ReadKey();
                if (keyInfo != null)
                {
                    try
                    {
                        switch (keyInfo.Key)
                        {
                            case ConsoleKey.RightArrow:
                                {
                                    if (keyInfo.Modifiers.ToString() == "Shift") plane.UpSpeedStrong();
                                    else plane.UpSpeed();
                                    Console.WriteLine("скорость+");
                                    Console.WriteLine(plane);
                                    ShowDispathcerInfo(plane.Dispathcers);
                                }
                                break;
                            case ConsoleKey.LeftArrow:
                                {
                                    if (keyInfo.Modifiers.ToString() == "Shift") plane.DownSpeedStrong();
                                    else plane.DownSpeed();
                                    Console.WriteLine("скорость-");
                                    Console.WriteLine(plane);
                                    ShowDispathcerInfo(plane.Dispathcers);
                                }
                                break;
                            case ConsoleKey.UpArrow:
                                {
                                    if (keyInfo.Modifiers.ToString() == "Shift") plane.UpHeightStrong();
                                    else plane.UpHeight();
                                    Console.WriteLine("высота+");
                                    Console.WriteLine(plane);
                                    ShowDispathcerInfo(plane.Dispathcers);
                                }
                                break;
                            case ConsoleKey.DownArrow:
                                {
                                    if (keyInfo.Modifiers.ToString() == "Shift") plane.DownHeightStrong();
                                    else plane.DownHeight();
                                    Console.WriteLine("высота-");
                                    Console.WriteLine(plane);
                                    ShowDispathcerInfo(plane.Dispathcers);
                                }
                                break;
                            case ConsoleKey.D: ManageDispatchers(ref plane);
                                break;
                            default: break;
                        }
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
                else
                {
                    Console.WriteLine(" Вы ввели: {0}", keyInfo.Key.ToString());
                }

            }

        }
    }
}
