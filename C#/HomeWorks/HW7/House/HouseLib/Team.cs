using System;

namespace BuildingLib
{
	public class Team
	{
		public Team (int size)
		{
			workers = new Worker[size];
			for (int i = 0; i < size; ++i)
				workers [i] = new Worker ();
		}

		public Worker this [int index] {
			get { return workers [index]; }
		}

		public int Length {
			get { return workers.Length;}
		}

		private Worker[] workers;
	}
}
