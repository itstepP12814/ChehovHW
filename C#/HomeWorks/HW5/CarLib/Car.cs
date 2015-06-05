using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarLib
{
    public class Car
    {
        public Car(int f, double o)
        {
            temperature = 20;
            milage = 0;
            fuel = f;
            oil = o;
            mayMove = true;//Машина может ехать
        }
        public void Move()
        {
            if (temperature < 120 && fuel > 0 && oil > 0)
            {
                milage += 100;
                oil -= 0.1;
                fuel -= 3;
                temperature += 10;
                mayMove = true;
            }
            else
            {
                CarEventArgs args = new CarEventArgs();
                mayMove = false;

                if (temperature >= 120)
                {
                    args.Message = "Двигатель перегрелся";
                    Overheat(this, args);
                }
                if (fuel <= 0)
                {
                    args.Message = "Кончился бензин";
                    FuelEnded(this, args);
                }
                if (oil <= 0)
                {
                    args.Message = "Кончилось масло";
                    OilEnded(this, args);
                }
            }
        }
        public override string ToString()
        {
            return String.Format("Едем: {0}км бензин: {1}л масло: {2}л температура: {3}С", milage, fuel, oil, temperature);
        }
        public bool MayMove
        {
            get { return mayMove; }
        }
        public class CarEventArgs : EventArgs
        {
            public CarEventArgs() { }
            public string Message
            {
                get { return message; }
                set { message = value; }
            }
            private string message;
        }
        public event EventHandler Overheat;
        public event EventHandler FuelEnded;
        public event EventHandler OilEnded;
        private bool mayMove;
        private int temperature;
        private int fuel;
        private double oil;
        private int milage;//пробег км
        /*расход бенза 3 литра на 100 км, бак расчитан на 50 литров
         *масла 1 литр на 1000 км, т.е 0,1л/100км, движок рассчитан на 4л масла
         *температура подымается каждые 100 км на 10 градусов, 
         *предел 120С, после - перегрев*/
    }
}
