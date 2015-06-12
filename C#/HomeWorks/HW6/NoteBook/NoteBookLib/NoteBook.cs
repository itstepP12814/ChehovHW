using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NoteBookLib
{
    public class NoteBook
    {
        public NoteBook()
        {
            notes = new List<Note>();
            comparison = new Comparison<Note>(CompareByFirstName);
            SearchInNoteBook = new NotesSearchDelegate(Search);
        }
        public NoteBook(int size)
        {
            notes = new List<Note>(size);
            comparison = new Comparison<Note>(CompareByFirstName);
            SearchInNoteBook = new NotesSearchDelegate(Search);
        }
        public NoteBook(List<Note> notes)
        {
            this.notes = notes;
            comparison = new Comparison<Note>(CompareByFirstName);
            SearchInNoteBook = new NotesSearchDelegate(Search);
        }
        public string AddNote(Note n)
        {
            try
            {
                if (n == null) throw new NullReferenceException("Попытка добавить пустой объект");
                notes.Add(n);
                return String.Format("запись успешно добавлена");
            }
            catch (NullReferenceException e)
            {
                return e.Message;
            }
        }
        public string RemoveNote(int index)
        {
            try
            {
                if (index > notes.Count || index < 0) throw new IndexOutOfRangeException("Неверный номер для удаления");
                notes.RemoveAt(index);
                return "Запись успешно удалена";
            }
            catch (IndexOutOfRangeException e)
            {
                return e.Message;
            }
        }
        public int Count
        {
            get { return notes.Count; }
        }
        public void Sort()
        {
            notes.Sort(comparison);
        }
        private static int CompareByFirstName(Note x, Note y)
        {

            if (x == null)
            {
                if (y == null)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (y == null)
                {
                    return 1;
                }
                else
                {
                    int res = x.LastName.CompareTo(y.LastName);
                    if (res != 0)
                    {
                        return res;
                    }
                    else return 0;
                }
            }

        }
        public Note this[int index]
        {

            get
            {
                try
                {
                    if (index > this.notes.Count || this.notes.Count < 0) throw new ArgumentOutOfRangeException("Неверный индекс индексатора");
                    return notes[index];
                }
                catch (ArgumentOutOfRangeException e)
                {
                    Console.WriteLine(e.Message);
                    return null;
                }

            }
            set
            {
                try
                {
                    if (index > this.notes.Count || this.notes.Count < 0) throw new ArgumentOutOfRangeException("Неверный индекс индексатора");
                    notes[index] = value;
                }
                catch (IndexOutOfRangeException e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }
        public List<Note> FindAll(params string[] args)
        {   //возвращает лист записей из найденных результатов
            List<Note> list = new List<Note>();
            foreach (Note n in notes)
            {
                if (SearchInNoteBook(n, args)) list.Add(n);
            }
            return list;
        }
        public List<int> FindAllIndexes(params string[] args)
        {   //возвращает лист из индексов найденных элемнтов
            List<int> list = new List<int>();
            for (int i = 0; i < notes.Count; ++i)
            {
                if (SearchInNoteBook(notes[i], args)) list.Add(i);
            }
            return list;
        }
        private bool Search(Note n, params string[] args)
        {
            foreach (string s in args)
            {
                if (n.FirstName == s) return true;
                if (n.LastName == s) return true;
                if (n.TelNumber == s) return true;
                if (n.Email == s) return true;
                if (n.BirthDay == s) return true;
            }
            return false;
        }
        private delegate bool NotesSearchDelegate(Note n, params string[] s);
        private NotesSearchDelegate SearchInNoteBook;
        private Comparison<Note> comparison;
        private List<Note> notes;
    }
}
