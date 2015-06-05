using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RaceLib;

namespace Race
{
    class Program
    {
        static void race_Finish(Object obj, EventArgs e)
        {
            Car car = (Car)obj;
            switch (car.GetCarType)
            {
                case CarType.BUS: Console.WriteLine("На финиш приехал автобус");
                    break;
                case CarType.SPORT: Console.WriteLine("На финиш приехала спортивная машина");
                    break;
                case CarType.CAR: Console.WriteLine("На финиш приехала легковая машина");
                    break;
                case CarType.TRUCK: Console.WriteLine("На финиш приехал грузовик");
                    break;
                default: break;
            }
        }
        static void Main(string[] args)
        {
            List<Car> cars = new List<Car>();
            cars.Add(new Sport());
            cars.Add(new Truck());
            cars.Add(new Bus());
            cars.Add(new OrdinaryCar());
            foreach (Car c in cars)
            {
                c.Finish += new EventHandler(race_Finish);
                c.RouteLength = 500;
            }

            while (true)
            {
                foreach (Car c in cars)
                {
                    if (c.MayMove) c.Move();
                    else return;
                }
            }
        }
    }
}
