using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using ClassLib;
using System.Runtime.Serialization.Formatters.Binary;

namespace DeSerializConsolApp
{
    class Program
    {
        static void Main(string[] args)
        {
            List<PC> lPc = new List<PC>(4);
            lPc.Add(new PC("Toshiba", "Intel Celeron", 4, 250));
            lPc.Add(new PC("Asus", "Intel Core i3", 4, 500));
            lPc.Add(new PC("Samsung", "Intel Pentium IV", 1, 100));
            lPc.Add(new PC("DELL", "Intel Atom", 2, 200));
            string path = "../../../../PCfolder";
            string fileName = "PC";
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            List<FileInfo> lFiles = new List<FileInfo>(dirInfo.GetFiles());

            try
            {
                int n = 0;
                foreach (PC pc in lPc)
                {
                    ++n;
                    FileInfo res = lFiles.Find(delegate(FileInfo fi)
                     {
                         return (fi.Name == String.Format("{0}{1}.txt", fileName, n)) ? true : false;
                     });
                    if (res != null) Console.WriteLine("Файл {0}{1}.txt был перезаписан", fileName, n);
                    using (FileStream fs = new FileStream(String.Format("{0}/{1}{2}.txt", path, fileName, n), FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.ReadWrite))
                    {
                        BinaryFormatter bf = new BinaryFormatter();
                        bf.Serialize(fs, pc);
                    }
                }
                Console.WriteLine("Все сериализованo!");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
