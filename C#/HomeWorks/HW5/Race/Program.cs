using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RaceLib;

namespace Race
{

    class Game
    {
        public delegate void StartLength(int a);//делегат для установки значения старта
        public delegate void FinishLength(int a);//делегат для задачи всем финиша

        public Game(List<Car> cars)
        {
            this.cars = cars;
            start = new StartLength(cars[0].SetMilage);
            finish = new FinishLength(cars[0].SetRouteLenght);
            allCarsFinished = new EventHandler(race_AllCarsFinished);
            //криво, конечно
            for (int i = 1; i < cars.Count; ++i)
            {
                start += cars[i].SetMilage;
                finish += cars[i].SetRouteLenght;
            }
        }
        public bool CheckFinish()
        {   //проверяем все ли машины проехали на финиш;
            bool check = false;
            for (int i = 0; i < cars.Count; ++i)
            {
                if (cars[i].MayMove) check = true;
            }
            if (!check) allCarsFinished(this, EventArgs.Empty);
            return check;
        }
        public void race_AllCarsFinished(Object obj, EventArgs e)
        {
            Console.WriteLine("Все машины приехали на финиш");
        }
        public void race_Finish(Object obj, EventArgs e)
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
        public void Start()
        {
            foreach (Car c in cars)
            {
                c.Finish += new EventHandler(race_Finish);
            }
            //на самом деле логичнее было бы стартовую длину установить в 0 при создании машины, в конструкторе, но хотят делегатами
            start(0);
            finish(500);
            Move();
        }
        public void Move()
        {
            while (CheckFinish())
            {
                foreach (Car c in cars)
                {
                    if (c.MayMove)
                    {
                        ShowCarInfo(c.ToString());
                        c.Move();
                    }
                }
            }
        }
        public void ShowCarInfo(string str)
        {
            Console.WriteLine(str);
        }
        private StartLength start;
        private FinishLength finish;
        private event EventHandler allCarsFinished;
        private List<Car> cars;
    }
    class Programm
    {
        static void Main(string[] args)
        {
            List<Car> cars = new List<Car>();
            cars.Add(new Sport());
            cars.Add(new Truck());
            cars.Add(new Bus());
            cars.Add(new OrdinaryCar());

            Game game = new Game(cars);
            game.Start();
            game.Move();
        }
    }
}
