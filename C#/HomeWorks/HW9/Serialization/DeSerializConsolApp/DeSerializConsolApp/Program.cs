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
            string path = "../../../../PCfolder";
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            int count = dirInfo.GetFiles().Length;
            List<PC> lPc = new List<PC>(count);

            foreach (FileInfo f in dirInfo.GetFiles())
            {
                using (FileStream fs = new FileStream(path+"/"+f.Name, FileMode.Open, FileAccess.Read, FileShare.Read))
                {
                    try
                    {
                        BinaryFormatter bf = new BinaryFormatter();
                        PC pc = (PC)bf.Deserialize(fs);
                        lPc.Add(pc);
                        Console.WriteLine(pc);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
            }

        }
    }
}
