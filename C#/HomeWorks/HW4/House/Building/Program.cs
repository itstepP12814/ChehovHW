using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BuildingLib;

namespace Building
{

    class Program
    {
        static void Main(string[] args)
        {
            Team team = new Team(300);
            TeamLeader teamLeader = new TeamLeader("Паша");
            House house = new House();
            Console.WriteLine(teamLeader.Work(house));

            for (int i = 0; i < team.Length; ++i)
            {
                team[i].Work(house);
            }
            Console.WriteLine(teamLeader.Work(house));
        }
    }
}
