using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Reflection;


namespace Attribute
{
    public sealed class IniParamsAttribute : System.Attribute
    {
        private string iniPath;
        
        public string IniPath
        {
          get { return iniPath; }
          set { iniPath = value; }
        }
    }
    class MyClass
    {

        public MyClass() { }
        public string OpenIniFile(string path)
        {
            try
            {
                using (FileStream fs = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read))
                {
                    StreamReader sr = new StreamReader(fs);
                    return sr.ReadLine();
                }
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }

        [property: IniParams(IniPath = "../../../field1.ini")]
        public string Field1
        {
            get
            {
                Type t = this.GetType();
                PropertyInfo pi = t.GetProperty("Field1");
                IniParamsAttribute[] ipa = (IniParamsAttribute[])pi.GetCustomAttributes(typeof(IniParamsAttribute), false);
                if (ipa.Length != 0)
                {
                    return OpenIniFile(ipa[0].IniPath);
                }
                else
                {
                    return "Не удается получить список атрибутов";
                }
            }
        }
        [property: IniParams(IniPath = "../../../field2.ini")]
        public string Field2
        {
            get
            {
                Type t = this.GetType();
                PropertyInfo pi = t.GetProperty("Field2");
                IniParamsAttribute[] ipa = (IniParamsAttribute[])pi.GetCustomAttributes(typeof(IniParamsAttribute), false);
                if (ipa.Length != 0)
                {
                    return OpenIniFile(ipa[0].IniPath);
                }
                else
                {
                    return "Не удается получить список атрибутов";
                }
            }
        }
        [property: IniParams(IniPath = "../../../field3.ini")]
        public string Field3
        {
            get
            {
                Type t = this.GetType();
                PropertyInfo pi = t.GetProperty("Field3");
                IniParamsAttribute[] ipa = (IniParamsAttribute[])pi.GetCustomAttributes(typeof(IniParamsAttribute), false);
                if (ipa.Length != 0)
                {
                    return OpenIniFile(ipa[0].IniPath);
                }
                else
                {
                    return "Не удается получить список атрибутов";
                }
            }
        }
        [property: IniParams(IniPath = "../../../field4.ini")]
        public string Field4
        {
            get
            {
                Type t = this.GetType();
                PropertyInfo pi = t.GetProperty("Field4");
                IniParamsAttribute[] ipa = (IniParamsAttribute[])pi.GetCustomAttributes(typeof(IniParamsAttribute), false);
                if (ipa.Length != 0)
                {
                    return OpenIniFile(ipa[0].IniPath);
                }
                else
                {
                    return "Не удается получить список атрибутов";
                }
            }
        }


        public static string GetIniFileName(Type Temp)
        {
           
            PropertyInfo pi= Temp.GetProperty("Field1");
            IniParamsAttribute[] ipa = (IniParamsAttribute[])pi.GetCustomAttributes(typeof(IniParamsAttribute), false);
            if (ipa.Length != 0) return ipa[0].IniPath;
            else return "нет атрибутов";
        }

        private string field1;
        private string field2;
        private string field3;
        private string field4;
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyClass myClass = new MyClass();
            Console.WriteLine(myClass.Field1);
            Console.WriteLine(myClass.Field2);
            Console.WriteLine(myClass.Field3);
            Console.WriteLine(myClass.Field4);

        }
    }
}
