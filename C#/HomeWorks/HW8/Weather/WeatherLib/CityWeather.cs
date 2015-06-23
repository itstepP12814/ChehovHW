using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Text.RegularExpressions;

namespace WeatherLib
{
    public class CityWeather
    {
        public CityWeather(string iniPath)
        {
            FileStream fs = new FileStream(iniPath, FileMode.Open, FileAccess.Read, FileShare.Read);
            StreamReader sr = new StreamReader(fs, Encoding.UTF8);
            string sPatternKey = @"[A-Za-zА-Яа-я0-9-]*=";
            string sPatternValue = @"=[A-Za-zА-Яа-я0-9-]*";
            string sPatternKeyValue = @"[A-Za-zА-Яа-я0-9-]*=[A-Za-zА-Яа-я0-9-]*";
            cities = new List<City>(4);
            try
            {
                while (!sr.EndOfStream)
                {
                    string str = sr.ReadLine().Trim();
                    if (Regex.IsMatch(str, sPatternKeyValue))
                    {
                        Match mKey = Regex.Match(str, sPatternKey);
                        Match mValue = Regex.Match(str, sPatternValue);
                        //эта страшная длиная строка добавляет город
                        //при этом налету создается новый город, куда в качестве названия пишутся результаты вычисления
                        //регулярных выражений, метод Remove(mKey.Value.Length - 1, 1) удаляет знак =
                        cities.Add(new City(mKey.Value.Remove(mKey.Value.Length - 1, 1), mValue.Value.Remove(0, 1)));
                    }
                }
                SaveAllData();//сразу сохраняем все города в файл
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                sr.Close();
            }
        }
        public string ShowWeatherByCode(string code)
        {
            try
            {
                string str = "";
                foreach (City city in cities)
                {
                    if (city.Code == code)
                    {
                        XmlDocument xml = new XmlDocument();
                        xml.Load(String.Format("http://informer.gismeteo.by/rss/{0}.xml", city.Code));
                        XmlNodeList nodeList = xml.GetElementsByTagName("item");
                        foreach (XmlNode node in nodeList)
                        {
                            str += String.Format("{0}\n{1}\n", node["title"].InnerText, node["description"].InnerText);
                        }
                        return str;
                    }
                }
                return "Неверный код города";
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        public string ShowWeatherByIndex(int i)
        {
            try
            {
                if (i > cities.Count || i < 0) throw new IndexOutOfRangeException("Неверный индекс");
                return ShowWeatherByCode(cities[i].Code);
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }
        private void SaveAllData()
        {
            try
            {
                //делаем строку с текущей датой
                DateTime time = DateTime.Now;
                string tm = time.ToString("d/MM/yyyy");

                foreach (City city in cities)
                {
                    XmlDocument xml = new XmlDocument();
                    xml.Load(String.Format("http://informer.gismeteo.by/rss/{0}.xml", city.Code));
                    //формируем имя хмл из кода города и даты
                    xml.Save(String.Format("../../../{0}_{1}.xml", city.Code, tm));
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        public string SelectHottestCity()
        {
            try
            {
                string pattern = @"\d\d..\d\d";
                int maxTemp = 0;
                City hottestCity = null;

                foreach (City city in cities)
                {
                    XmlDocument xml = new XmlDocument();
                    xml.Load(String.Format("http://informer.gismeteo.by/rss/{0}.xml", city.Code));
                    XmlNodeList nodeList = xml.GetElementsByTagName("item");

                    foreach (XmlNode node in nodeList)
                    {
                        Match match = Regex.Match(node["description"].InnerText, pattern);
                        string t = match.Value;
                        string[] array = t.Split('.');
                        if (maxTemp < Convert.ToInt32(array[2]))
                        {
                            maxTemp = Convert.ToInt32(array[2]);
                            hottestCity = city;
                        }
                    }
                }
                return String.Format(ShowWeatherByCode(hottestCity.Code));
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return ex.Message;
            }
        }
        public override string ToString()
        {
            string str = "";
            for (int i = 0; i < cities.Count; ++i)
            {
                str += String.Format("{0,-2} {1}\n", i, cities[i].ToString());
            }
            return str;
        }

        public City this[int a]
        {
            get { return cities[a]; }
        }
        private List<City> cities;
    }
}
