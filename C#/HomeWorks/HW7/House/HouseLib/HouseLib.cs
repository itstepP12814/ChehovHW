using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace BuildingLib
{
	public enum PARTS
	{	BASEMENT,
		WALL,
		WINDOW,
		ROOF,
		DOOR,
		HOUSE
	}
	//interfaces
	public interface IPart
	{
		bool IsBuilding { get; set; }

		PARTS GetPathType{ get; }
	}

	public interface IWorker
	{
		bool IsWorking { get; }

		string Work (House h);

	}
	//classes
	public abstract class Part: IPart
	{
		public bool IsBuilding { 
			get{ return building;}
			set { building = value;}
		}

		public PARTS GetPathType {
			get{ return type;}
		}

		protected PARTS type;
		protected bool building;
	}

	public class Basement : Part
	{
		public Basement ()
		{
			building = false;
			type = PARTS.BASEMENT;
		}

		public override string ToString ()
		{
			return string.Format ("Фундамент");
		}
	}

	public class Wall : Part
	{
		public Wall ()
		{
			building = false;
			type = PARTS.WALL;
		}

		public override string ToString ()
		{
			return string.Format ("Стена");
		}
	}

	public class Window : Part
	{
		public Window ()
		{
			building = false;
			type = PARTS.WINDOW;
		}

		public override string ToString ()
		{
			return string.Format ("Окно");
		}
	}

	public class Roof : Part
	{
		public Roof ()
		{
			building = false;
			type = PARTS.ROOF;
		}

		public override string ToString ()
		{
			return string.Format ("Крыша");
		}
	}

	public class Door : Part
	{
		public Door ()
		{
			building = false;
			type = PARTS.DOOR;
		}

		public override string ToString ()
		{
			return string.Format ("Дверь");
		}
	}

	public class House: Part
	{
		public House ()
		{
			parts = new List<Part> (11);
			parts.Add (new Basement ());
			for (int i=0; i<4; ++i) {
				parts.Add (new Wall ());
				parts.Add (new Window ());
			}
			parts.Add (new Door ());
			parts.Add (new Roof ());
		}

		public Part this [int i] {
			get{ return parts [i];}
		}

		public int CountParts {
			get{ return parts.Count;}
		}

		List<Part> parts;
	}
}