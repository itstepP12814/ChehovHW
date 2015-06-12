using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NoteBookLib;

namespace NoteBookProgramm
{
    class Program
    {
        static void ShowNotes(NoteBook n)
        {
            try
            {
                for (int i = 0; i < n.Count; ++i)
                {
                    Console.WriteLine(n[i].ToString());
                }
                Console.WriteLine();

            }
            catch (NullReferenceException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (OutOfMemoryException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        static void Main(string[] args)
        {
            NoteBook notebook = new NoteBook(5);
            notebook.AddNote(new Note("Паша", "Чехов", "11.03.1991", "good-1991@mail.ru", "375296367752"));
            notebook.AddNote(new Note("Даша", "Плоткина", "11.03.1991", "good-1991@mail.ru", "375296367752"));
            notebook.AddNote(new Note("Паша", "Астахов", "11.03.1991", "good-1991@mail.ru", "375296367752"));
            notebook.AddNote(new Note("Алексй", "Мирончук", "11.03.1991", "good-1991@mail.ru", "375296367752"));
            notebook.AddNote(new Note("Костя", "Шмелев", "11.03.1991", "sdf", "375296367752"));
            notebook.AddNote(new Note("Настя", "Подворная", "11.03.1991", "good-1991@mail.ru", "375296367752"));
            Console.WriteLine("До сортировки");
            ShowNotes(notebook);
            Console.WriteLine("После сортировки");
            notebook.Sort();
            ShowNotes(notebook);
            Console.WriteLine("Поиск Костя, Паша");
            NoteBook notebook2 = new NoteBook(notebook.FindAll("Костя", "Паша"));
            ShowNotes(notebook2);
            Console.WriteLine("Удаление 4 элемента");
            notebook.RemoveNote(4);
            ShowNotes(notebook);
        }
    }
}
