using System;
using Loger;

namespace BuildingLib
{
	public class Worker : IWorker
	{
		public Worker ()
		{
			working = false;
		}

		public Worker (string name)
		{
			this.name = name;
			working = false;
		}

		public virtual string Work (House house)
		{//build home 1 рабочий не может строить больше двух частей дома за раз
			for (int i=0; i<house.CountParts; ++i) {
				if (!house [i].IsBuilding) {
					house [i].IsBuilding = true;
					string str = String.Format ("рабочий построил {0}", house [i].ToString ());
					return str;
				}
			}
			return "Рабочий бездельничает\n";
		}

		public bool IsWorking {
			get { return working; }
		}

		public override string ToString ()
		{
			if (name != null)
				return name;
			else
				return "Worker";
		}

		protected bool working;
		protected string name;
	}
}

