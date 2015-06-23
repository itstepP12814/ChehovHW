using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace IniParserLib
{
    public class IniParser
    {
        public IniParser(string iniPath)
        {
            using (FileStream fsStream = new FileStream(iniPath, FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.ReadWrite))
            {
                try
                {
                    sIniPath = iniPath;
                    StreamReader srReader = new StreamReader(fsStream, Encoding.UTF8);
                    string strSection, str;
                    string sPatternSection = @"\[[A-Za-z0-9_-]*\]";
                    string sPatternKey = @"[A-Za-zА-Яа-я0-9-]*=";
                    string sPatternValue = @"=[A-Za-zА-Яа-я0-9-]*";
                    string sPatternKeyValue = @"[A-Za-zА-Яа-я0-9-]*=[A-Za-zА-Яа-я0-9-]*";
                    DOM = new Dictionary<string, Dictionary<string, string>>();
                    strSection = srReader.ReadLine().Trim();//читаем первую строку файла
                    while (!srReader.EndOfStream)
                    {//считывая файл, я предпологаю что первая строка всега является секцией, в проивном случае мы игнорируем
                        //все пары ключ значение вне секции
                        if (Regex.IsMatch(strSection, sPatternSection))
                        {
                            DOM.Add(strSection, new Dictionary<string, string>());
                            str = srReader.ReadLine().Trim();//считываем вторую строку
                            while (Regex.IsMatch(str, sPatternKeyValue))
                            {//продолжаем считывать строки, пока они подходят под шаблок ключ=значение
                                Match key = Regex.Match(str, sPatternKey);
                                Match value = Regex.Match(str, sPatternValue);
                                if (key.Value != "")
                                {
                                    //эта длиная строка добавляет пару ключ значение в словарь, и во вермя доабвления
                                    //на лету удаляет знак = у ключа(в конце строки) и у значения(в начале строки со значением)
                                    DOM[strSection].Add(key.Value.Remove(key.Value.Length - 1, 1), value.Value.Remove(0, 1));
                                }
                                if (!srReader.EndOfStream)
                                {//Если не конец файла считываем новую строку, и смотрим если она секция, перезаписываем сторку секции
                                    str = srReader.ReadLine().Trim();
                                    if (Regex.IsMatch(str, sPatternSection)) strSection = str;
                                }
                                else break;
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }
        }
        public bool WriteToFile()
        {
            using (FileStream fsStream = new FileStream(sIniPath, FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.ReadWrite))
            {
                StreamWriter swWriter = new StreamWriter(fsStream, Encoding.UTF8);
                string str = this.ToString();
                swWriter.Write(str);
                swWriter.Close();
            }
            return true;
        }
        public override string ToString()
        {
            string str = "";
            foreach (var dicExternal in DOM)
            {
                str += dicExternal.Key + "\n";
                foreach (var dicInner in DOM[dicExternal.Key])
                {
                    str += String.Format("{0}={1}\n", dicInner.Key, dicInner.Value);
                }
            }
            return str;
        }
        public string GetKeyValueStr(string sSection, string sKey, string sDefault)
        {
            if (DOM.ContainsKey(sSection))
            {
                if (DOM[sSection].ContainsKey(sKey)) return (string)DOM[sSection][sKey];
                else return sDefault;
            }
            else return sDefault;
        }
        public int GetKeyValueInt(string sSection, string sKey, int iDefault)
        {
            int value;
            if (DOM.ContainsKey(sSection))
            {
                if (DOM[sSection].ContainsKey(sKey))
                {
                    if (Int32.TryParse(DOM[sSection][sKey], out value)) return value;
                    else return iDefault;
                }
                else return iDefault;
            }
            else return iDefault;
        }
        public bool GetKeyValueBool(string sSection, string sKey, bool bDefault)
        {
            if (DOM.ContainsKey(sSection))
            {
                if (DOM[sSection].ContainsKey(sKey))
                {
                    if (DOM[sSection][sKey] != "FALSE" || DOM[sSection][sKey] != "false") return true;
                    else return bDefault;
                }
                else return bDefault;
            }
            else return bDefault;
        }
        public bool SetKeyValue(string sSection, string sKey, string sValue)
        {
            if (!DOM.ContainsKey(sSection))
            {
                DOM.Add(sSection, new Dictionary<string, string>());
                DOM[sSection].Add(sKey, sValue);
                return true;
            }
            else
            {
                if (!DOM[sSection].ContainsKey(sKey))
                {
                    DOM[sSection].Add(sKey, sValue);
                    return true;
                }
                else return false;
            }
        }

        private string sIniPath;
        private Dictionary<string, Dictionary<string, string>> DOM;
    }
}
