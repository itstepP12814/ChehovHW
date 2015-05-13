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
        static void Main(string[] args)
        {
            string[] stringArray = new string[5];
            Console.WriteLine("Введите текст, для завершения ввода введите end");
            int count = 0; string str = "";
            while (true)
            {
                str = Console.ReadLine();
                if (str == "end") break;

                stringArray[count] = str;
                ++count;
                if (count == stringArray.Length) Array.Resize(ref stringArray, stringArray.Length * 2);
            }
            Console.WriteLine("Введите строку для поиска");
            string find = Console.ReadLine();
            Console.WriteLine("Введите строку для замены");
            string replace = Console.ReadLine();
            for (int i = 0; i < stringArray.Length; ++i)
            {
                if(stringArray[i]!=null)
                        stringArray[i] = stringArray[i].Replace(find, replace);
            }
            foreach (string temp in stringArray) Console.WriteLine(temp);
        }
    }
}
