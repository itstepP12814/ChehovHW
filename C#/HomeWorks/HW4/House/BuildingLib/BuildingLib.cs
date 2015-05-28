using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BuildingLib
{
    public interface IPart
    {
        bool IsBuilding { get; set; }
    }
    public interface IWorker
    {
        bool IsWorking { get; }
        string Name { get; }
        string Work(House h);
    }

    public class Basement : IPart
    {
        public Basement()
        {
            building = false;
        }
        public bool IsBuilding
        {
            get { return building; }
            set { building = (bool)value; }
        }
        private bool building;
    }
    public class Wall : IPart
    {
        public Wall()
        {
            building = false;
        }
        public bool IsBuilding
        {
            get { return building; }
            set { building = (bool)value; }
        }
        private bool building;
    }
    public class Window : IPart
    {
        public Window()
        {
            building = false;
        }
        public bool IsBuilding
        {
            get { return building; }
            set { building = (bool)value; }
        }
        private bool building;
    }
    public class Roof : IPart
    {
        public Roof()
        {
            building = false;
        }
        public bool IsBuilding
        {
            get { return building; }
            set { building = (bool)value; }
        }
        private bool building;
    }
    public class Door : IPart
    {
        public Door()
        {
            building = false;
        }
        public bool IsBuilding
        {
            get { return building; }
            set { building = (bool)value; }
        }
        private bool building;
    }
    public class House
    {
        public House()
        {
            basement = new Basement();
            roof = new Roof();
            door = new Door();
            walls = new Wall[4];
            windows = new Window[4];
            for (int i = 0; i < 4; ++i)
            {
                walls[i] = new Wall();
                windows[i] = new Window();
            }
        }

        public Basement basement;
        public Wall[] walls;
        public Window[] windows;
        public Roof roof;
        public Door door;
    }
    public class Worker : IWorker
    {
        public Worker()
        {
            working = false;
        }
        public Worker(string name)
        {
            this.name = name;
            working = false;
        }
        public virtual string Work(House house)
        {//build home
            if (!house.basement.IsBuilding)
            {
                house.basement.IsBuilding = true;
                return String.Format("Рабочий {0} построил фундамент\n", this.name);
            }
            for (int i = 0; i < house.walls.Length; ++i)
            {
                if (!house.walls[i].IsBuilding)
                {
                    house.walls[i].IsBuilding = true;
                    return String.Format("Рабочий {0} построил {1} стену\n", this.name, i);
                }
            }
            for (int i = 0; i < house.windows.Length; ++i)
            {
                if (!house.windows[i].IsBuilding)
                {
                    house.windows[i].IsBuilding = true;
                    return String.Format("Рабочий {0} построил {1} окно\n", this.name, i);
                }
            }
            if (!house.door.IsBuilding)
            {
                house.door.IsBuilding = true;
                return String.Format("Рабочий {0} построил дверь\n", this.name);
            }
            if (!house.roof.IsBuilding)
            {
                house.roof.IsBuilding = true;
                return String.Format("Рабочий {0} построил крышу\n", this.name);
            }
            return String.Format("Рабочий бездельничает\n");
        }
        public string Name
        {
            get { return name; }
        }
        public bool IsWorking
        {
            get { return working; }
        }
        protected bool working;
        protected string name;
    }
    public class TeamLeader : Worker, IWorker
    {
        public TeamLeader()
            : base()
        {
        }
        public TeamLeader(string name)
            : base(name)
        {
        }
        public override string Work(House house)
        {//make report
            StringBuilder str=new StringBuilder();
            if (house.basement.IsBuilding) str = str.Append("Построен фундамент\n");
            for (int i = 0; i < house.walls.Length; ++i)
            {
                if (house.walls[i].IsBuilding) str = str.Append("Построена " + i + " стена\n");
            }
            for (int i = 0; i < house.windows.Length; ++i)
            {
                if (house.windows[i].IsBuilding) str.Append("Построено " + i + " окно\n");

            }
            if (house.door.IsBuilding) str.Append("Построена дверь\n");
            if (house.roof.IsBuilding) str.Append("Построена крыша\n");

            if (str.Length!=0) return str.ToString();
            else return "Ничего не сделано";
        }
    }
    public class Team
    {
        public Team(int size)
        {
            workers = new Worker[size];
            for (int i = 0; i < size; ++i) workers[i] = new Worker();
        }
        public Worker this[int index]
        {
            get { return workers[index]; }
        }
        public int Length
        {
            get { return workers.Length;}
        }
        private Worker[] workers;
    }
}