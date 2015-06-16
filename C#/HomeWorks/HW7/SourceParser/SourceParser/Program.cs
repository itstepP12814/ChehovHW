using System;
using System.IO;

namespace SourceParser
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			try {
				string filePath = "../../../StorageLib.cs";
				string newFilePath = "../../../change.cs";
				FileStream fsRead = new FileStream (filePath, FileMode.Open, FileAccess.Read, FileShare.Read);
				FileStream fsWrite = new FileStream (newFilePath, FileMode.Create, FileAccess.ReadWrite, FileShare.ReadWrite);
				StreamReader reader = new StreamReader (fsRead);
				StreamWriter writer = new StreamWriter (fsWrite);

				string str = null;
				string tempStr = null;

				while (!reader.EndOfStream) {
					str = (reader.ReadLine ()).Trim ();
					tempStr = "";
					if (str == "{" || str == "}") {
						tempStr = str;
					} else {
						//Если есть public Меняем на private
						str = str.Replace ("public", "private");
						//вырезаем пробелы, табуляции и переводим все в нижний регистр
						string[] array = str.Split (' ');
						for (int i=0; i<array.Length; ++i) {
							if (array [i].Length > 2) {
								array [i] = array [i].ToLower ();
								tempStr += array [i] + " ";
							} else {
								tempStr += array [i] + " ";
							}
						}
					}
					char[] charArray = tempStr.ToCharArray ();
					Array.Reverse (charArray);
					writer.WriteLine (charArray);
				}
				//пишем на дск файл и закрываем потоки
				writer.Flush ();
				reader.Close ();
				Console.WriteLine("All done successfull");
			} catch (Exception ex) {
				Console.WriteLine (ex.Message);
			}
		}
	}
}