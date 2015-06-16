using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Loger
{
	public class Log
	{
		public Log ()
		{
			logPath = "../../../house.log";
		}

		public Log (string logPath)
		{
			this.logPath = logPath;
		}

		public void WriteToLog (Message mess)
		{
			try {
				FileStream fs = new FileStream (logPath, FileMode.Append, FileAccess.Write, FileShare.Read);
				StreamWriter writer = new StreamWriter (fs);

				writer.WriteLine (mess.ToString ());
				writer.Flush ();
				fs.Close ();
			} catch (Exception ex) {
				Console.WriteLine (ex.Message);
			}
		}

		public static void WriteLog (Message mess, string logPath)
		{
			
			try {
				FileStream fs = new FileStream (logPath, FileMode.Append, FileAccess.Write, FileShare.Read);
				StreamWriter writer = new StreamWriter (fs);

				writer.WriteLine (mess.ToString ());
				writer.Flush ();
				fs.Close ();
			} catch (Exception ex) {
				Console.WriteLine (ex.Message);
			}
		}

		public static void WriteLog (Message mess)
		{

			try {
				string logPath = "../../../house.log";
				FileStream fs = new FileStream (logPath, FileMode.Append, FileAccess.Write, FileShare.Read);
				StreamWriter writer = new StreamWriter (fs);

				writer.WriteLine (mess.ToString ());
				writer.Flush ();
				fs.Close ();
			} catch (Exception ex) {
				Console.WriteLine (ex.Message);
			}
		}

		public string LogPath {
			get { return logPath;}
		}

		private string logPath;
	}
}

