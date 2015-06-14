using System;

namespace SampleLip
{
	public class MyClass
	{
		public MyClass ()
		{
			str="null string";
		}
		public MyClass(string s){
			str = s;
		}
		public string Word{
			get {return str;}
		}
		private string str;
	}
}

