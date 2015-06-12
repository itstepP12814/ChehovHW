using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WordsCounter
{
    class Program
    {
        class WordCounter
        {
            public WordCounter(string str)
            {
                this.str = str;
                dict = new Dictionary<string, int>();
                stringList = new List<string>();

                string[] array = this.str.Split(' ', ',', '.');
                foreach (string s in array)
                {
                    if (s != "") stringList.Add(s);
                }
            }
            public int Count
            {
                get { return stringList.Count; }
            }
            public string SetText
            {
                get { return str; }
                set { str = value; }
            }
            public void MakeStatics()
            {
                int count = 0;
                for (int i = 0; i < stringList.Count; ++i)
                {
                    count = 0;
                    if (dict.ContainsKey(stringList[i])) continue;
                    for (int j = 0; j < stringList.Count; ++j)
                    {
                        if (stringList[i] == stringList[j]) ++count;
                    }
                    dict.Add(stringList[i], count);
                }

            }
            public Dictionary<string, int> GetDict()
            {
                return dict;
            }
            private Dictionary<string, int> dict;
            private List<string> stringList;
            private string str;
        }
        static void ShowStatistics(WordCounter wc)
        {
            int uniqueWords = 0;
            int allWords = 0;
            foreach (var obj in wc.GetDict())
            {
                allWords += obj.Value;
                if (obj.Value == 1) ++uniqueWords;
                Console.WriteLine("{0} {1}", obj.Key, obj.Value);
            }
            Console.WriteLine("всего слов {0} уникальных {1}", allWords, uniqueWords);
        }
        static void Main(string[] args)
        {
            string str = "Вот дом, Который построил Джек. А это пшеница, Которая в темном чулане хранится В доме, Который построил Джек. А это веселая птица-синица, Которая часто ворует пшеницу, Которая в темном чулане хранится В доме, Который построил Джек";
            WordCounter wc = new WordCounter(str);
            wc.MakeStatics();
            ShowStatistics(wc);

        }
    }
}
