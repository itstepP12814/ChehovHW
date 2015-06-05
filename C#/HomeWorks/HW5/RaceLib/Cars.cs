using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RaceLib
{
    public enum CarType { SPORT, CAR, TRUCK, BUS };

    public abstract class Car
    {
        public abstract void Move();
        protected CarType carType;
        protected int speed;
        protected int milage;
        protected int routeLength;
        public abstract event EventHandler Finish;
        public bool MayMove
        {
            get { return (milage < routeLength) ? true : false; }
        }
        public CarType GetCarType
        {
            get { return carType; }
        }
        public int Milage
        {
            get { return milage; }
            set { milage = value; }
        }
        public int RouteLength
        {
            get { return routeLength; }
            set { routeLength = value; }
        }

    }
    public class Sport : Car
    {
        public Sport()
        {
            carType = CarType.SPORT;
            milage = 0;
        }
        public override void Move()
        {
            Random ran = new Random();
            speed = ran.Next(150, 300);
            milage += speed;
            if (milage >= routeLength) Finish(this, EventArgs.Empty);
        }
        public override event EventHandler Finish;
    }
    public class OrdinaryCar : Car
    {
        public OrdinaryCar()
        {
            carType = CarType.CAR;
            milage = 0;
        }
        public override void Move()
        {
            Random ran = new Random();
            speed = ran.Next(120, 220);
            milage += speed;
            if (milage >= routeLength) Finish(this, EventArgs.Empty);

        }
        public override event EventHandler Finish;

    }
    public class Truck : Car
    {
        public Truck()
        {
            carType = CarType.TRUCK;
            milage = 0;
        }
        public override void Move()
        {
            Random ran = new Random();
            speed = ran.Next(60, 140);
            milage += speed;
            if (milage >= routeLength) Finish(this, EventArgs.Empty);

        }
        public override event EventHandler Finish;

    }
    public class Bus : Car
    {
        public Bus()
        {
            carType = CarType.BUS;
            milage = 0;
        }
        public override void Move()
        {
            Random ran = new Random();
            speed = ran.Next(60, 120);
            milage += speed;
            if (milage >= routeLength) Finish(this, EventArgs.Empty);

        }
        public override event EventHandler Finish;

    }
}
