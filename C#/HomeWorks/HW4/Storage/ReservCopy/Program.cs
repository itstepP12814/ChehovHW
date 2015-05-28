using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using StorageLib;

namespace ReservCopy
{
    class Program
    {
        static double SummarySpace(ref Storage[] storages)
        {
            double summSpace = 0;
            foreach (Storage s in storages)
            {
                summSpace += s.GetSpace();
            }
            return summSpace;
        }
        static double SummaryFreeSpace(ref Storage[] storages)
        {
            double freeSpace = 0;
            foreach (Storage storage in storages) freeSpace += storage.GetFreeSpace();
            return freeSpace;
        }
        static void SummaryInfo(ref Storage[] storages)
        {
            foreach (Storage storage in storages)
            {
                Console.WriteLine(storage.GetInfo());
            }
        }
        static double CopyTime(ref Storage[] storages, double size)
        {
            double copyTime = 0;
            if (SummarySpace(ref storages) < size) throw new Exception("Нехватает места для копирования на носителях");
            for (int i = 0; i < storages.Length; ++i)
            {
                while (storages[i].GetFreeSpace() >= 0.780 && size > 0)
                {
                    copyTime += storages[i].Copy(0.780);
                    size -= 0.78;
                }
            }
            return Math.Ceiling(copyTime);
        }
        static void NumberOfStorages(double size)
        {
            Console.WriteLine("Для копирования {0} гб информации необоходимо:", size);
            Console.WriteLine(Math.Ceiling(size / new Dvd(1).GetSpace()) + " односторонних DVD-RW");
            Console.WriteLine(Math.Ceiling(size / new Dvd(2).GetSpace()) + " двусторонних DVD-RW");
            for (int i = 2; i <= 128; i *= 2) Console.WriteLine("{0} флешек на {1} гб", Math.Ceiling(size / new Flash(2, i).GetSpace()), i);
            for (int i = 64; i <= 1024; i *= 2) Console.WriteLine("{0} HDD на {1} гб", Math.Ceiling(size / new Flash(2, i).GetSpace()), i);
        }
        
        static void Main(string[] args)
        {
            Storage[] array = new Storage[15];
            for (int i = 0; i < array.Length; ++i)//инициализация массива из 10 флешек на 8 гб и 10 односторонних двд
            {
                if (i <= 10) array[i] = new Flash(3, 64);
                else array[i] = new Dvd(1);
            }
            try
            {
                SummaryInfo(ref array);//Вывод инфы о носителях до копирования
                Console.WriteLine("\nОбщее место на выбранных носителях: {0} гб", SummarySpace(ref array));//рассчет общего места на носителях
                Console.WriteLine("\nОбщее время копирования: {0} минут", (int)(CopyTime(ref array, 565)/60));//рассчет времени копирования
                SummaryInfo(ref array);//после копирования
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                NumberOfStorages(565);
            }
        }
    }
}
