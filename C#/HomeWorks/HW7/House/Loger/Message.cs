using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Loger
{
	public class Message
	{
		public Message (string message): this(message, "", "")
		{
		}

		public Message (string message, string user):this(message, user, "")
		{
		}

		public Message (StringBuilder message, StringBuilder user):this(message.ToString(), user.ToString(),"")
		{
		}

		public Message (StringBuilder message, string user):this(message.ToString(), user, "")
		{
		}

		public Message (string message, string user, string ex)
		{
			try {
				iniPath = "../../../setup.ini";
				StreamReader sr = new StreamReader (iniPath, Encoding.UTF8);
				string str = sr.ReadLine ().Trim ();
				string[] array = str.Split (' ');

				param = new Dictionary<string, string> ();
				foreach (string s in array) {
					param.Add (s, null);
				}

				time = DateTime.Now;
				messageText = message;
				userName = user;
				exception = ex;

				if (param.ContainsKey ("date"))
					param ["date"] = this.Date;
				if (param.ContainsKey ("message"))
					param ["message"] = messageText;
				if (param.ContainsKey ("user"))
					param ["user"] = userName;
				if (param.ContainsKey ("exception"))
					param ["exception"] = ex;

			} catch (Exception e) {
				Console.WriteLine (e.Message);
			}
		}

		public string Exception {
			get{ return exception;}
		}

		public string UserName {
			get { return userName;}
		}

		public string MessageText {
			get{ return messageText;}
		}

		public string Date {
			get{ return time.ToString (@"d/MM/yyyy HH:mm:ss");}
		}

		public string SetupPath {
			get{ return iniPath;}
		}

		public override string ToString ()
		{
			StringBuilder str = new StringBuilder ();
			foreach (var s in param) {
				str.Append (String.Format ("{0} ", s.Value.ToString ()));
			}
			return str.ToString ();
		}

		private string exception;
		private string userName;
		private string messageText;
		private DateTime time;
		private Dictionary<string, string> param;
		private string iniPath;
	}
}