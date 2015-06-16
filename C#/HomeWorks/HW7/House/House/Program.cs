using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using BuildingLib;
using Loger;

namespace Building
{
	class Program
	{
		static void Main (string[] args)
		{
			Team team = new Team (12);
			TeamLeader teamLeader = new TeamLeader ("Паша");
			House house = new House ();

			for (int i = 0; i < team.Length; ++i) {
				team [i].Work (house);
				teamLeader.Work (house);
			}
			Console.WriteLine (teamLeader.Work (house));
		}
	}
}
