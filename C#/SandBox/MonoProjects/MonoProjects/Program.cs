using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using SampleLip;

namespace MonoProjects
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			List<string> s = new List<string> (10);
			s.Add ("lol");
			s.Add ("trol");
			foreach(string str in s){
				Console.WriteLine (str);
			}
			MyClass obj = new MyClass ("Привет я объект из либы!");
			Console.WriteLine (obj.Word);
		}
	}
}
