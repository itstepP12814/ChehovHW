using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WeatherLib;

namespace Weather
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                string iniPath = "../../../config.ini";
                CityWeather weather = new CityWeather(iniPath);
                Console.WriteLine(weather.ToString());
                Console.WriteLine("h - показать город с самой высокой температурой");
                int number;
                string answer = "y";
                while (answer == "y" || answer=="Y")
                {
                    Console.WriteLine("Выберите город(номер или h)");
                    string str = Console.ReadLine();
                    bool res = Int32.TryParse(str, out number);
                    if (res)
                    {
                        Console.WriteLine(weather.ShowWeatherByIndex(Convert.ToInt32(str)));
                    }
                    else
                    {
                        switch (str)
                        {
                            case "h":
                                Console.WriteLine("Сейчас мы покажем в каком городе самая высокая температура");
                                Console.WriteLine(weather.SelectHottestCity());
                                break;
                            default: Console.WriteLine("Неверная опция");
                                break;
                        }
                    }
                    Console.WriteLine("Хотите посмотреть погоду в другом городе? Y(да)/N(нет)");
                    answer = Console.ReadLine();
                }
                Console.WriteLine("До свидания");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

    }
}
