using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IniParserLib;

namespace IniParserProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            IniParser iniParser = new IniParser("../../../config.ini");
            iniParser.SetKeyValue("[SMALL_CITIES]", "Какой-то город", "123456789");
            Console.WriteLine(iniParser);
            Console.WriteLine(iniParser.GetKeyValueInt("[CITIES]", "Москва", 0));
            if (iniParser.WriteToFile()) Console.WriteLine("all writes");
        }
    }
}
