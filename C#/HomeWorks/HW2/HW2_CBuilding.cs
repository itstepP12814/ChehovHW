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
        class CBuilding
        {
            public CBuilding(int _entrances, int _floors, int _flats)
            {
                entrances = _entrances;
                floors = _floors;
                flats = _flats;
            }

            public int GetFlatsOnTheFloor()
            {
                return flats / floors;
            }
            public int GetFlatsInEntrance()
            {
                return flats / entrances;
            }
            public int Entrances
            {
                get { return entrances; }
            }
            public int Floors
            {
                get { return floors; }
            }
            public int Flats
            {
                get { return flats; }
            }

            private int entrances;
            private int floors;
            private int flats;
        }
        static void Main(string[] args)
        {
            CBuilding house = new CBuilding(3, 5, 40);
            Console.WriteLine("В доме {0} подъездов, {1} этажей и {2} квартир", house.Entrances, house.Floors, house.Flats);
            Console.WriteLine("В доме {0} кварир на каждый из {1} подъездов", house.GetFlatsInEntrance(), house.Entrances);
            Console.WriteLine("В доме {0} кварир на каждый из {1} этажей", house.GetFlatsInEntrance(), house.Floors);
            
        }
    }
}
