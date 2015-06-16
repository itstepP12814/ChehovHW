using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using BuildingLib;
using Loger;

/// <summary>
/// Program.
/// Log имеет статические методы для записи в лог, так же есть и методы объекта,
/// класс рабоатет с объектами типа Message, берет из них инфу и записывает в конкретный файл
/// Message - класс сообщений с которыми работает лог, именно меседж инициализируется ini файлом, 
/// фомратирование текста выполняется внутри месседжа, а класс Log
/// только принимает Меседж и записывает инфу из него в конкретный файл.
/// </summary>
namespace Building
{
	class Program
	{
		static void Main (string[] args)
		{
			try {
				Team team = new Team (12);
				TeamLeader teamLeader = new TeamLeader ("Паша");
				House house = new House ();

				for (int i = 0; i < team.Length; ++i) {
					Log.WriteLog (new Message (team [i].Work (house), team [i].ToString ()));
					Log.WriteLog (new Message (teamLeader.Work (house), teamLeader.ToString ()));
				}
				Console.WriteLine (teamLeader.Work (house));
			} catch (Exception ex) {
				Log.WriteLog (new Message (ex.Message));
			}
		}
	}
}
