using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGameLib
{
    public class Game
    {
        public Game()
        {
            players = new List<Player>(2);
            for (int i = 0; i < 2; ++i)
            {
                players.Add(new Player());
            }
            WIN = new EventHandler(ShowWinner);
            MakeDeck();
            Shuffle();
        }
        public void GetCards()
        {
            for (int i = 0; i < players.Count; ++i)
            {
                if (players[i].Count == 0)
                {
                    //каждому игроку раздается по 4 карты, если игрок слил все карты, он снова берет 4 из общей колоды, иначе
                    //перебирает карты из своей колоды, пока не сольет
                    int limit;
                    if (deckOfCards.Count >= 4) limit = 4;
                    else limit = deckOfCards.Count;

                    for (int j = 0; j < limit; ++j)
                    {
                        players[i].Push(deckOfCards.Dequeue());
                    }
                }

            }
        }
        private void ShowWinner(Object obj, EventArgs e)
        {
            GameEventArgs args = (GameEventArgs)e;
            Console.WriteLine("Победитель " + args.Message);
        }
        public void OpenCards()
        {
            for (int i = 0; i < players.Count - 1; ++i)
            {
                Card playerCard1 = players[i].Pull();
                Card playerCard2 = players[i + 1].Pull();
                //шестерка не забирает туза? как это понимать, ведь туз больше шести, следовательно это он заюирает 6, а не наоборот
                //if ((playerCard1.Rank == RANKS.ACE && playerCard2.Rank == RANKS.SIX) || (playerCard1.Rank == RANKS.SIX && playerCard2.Rank == RANKS.ACE))
                //{
                //    players[i].Push(playerCard1);
                //    players[i + 1].Push(playerCard2);
                //    return;
                //}
                if (playerCard1.CompareTo(playerCard2) == 1)
                {
                    players[i].Push(playerCard1);
                    players[i].Push(playerCard2);

                }
                if (playerCard1.CompareTo(playerCard2) == 0)
                {
                    players[i].Push(playerCard1);
                    players[i].Push(playerCard2);
                }
                if (playerCard1.CompareTo(playerCard2) == -1)
                {
                    players[i + 1].Push(playerCard1);
                    players[i + 1].Push(playerCard2);
                }

            }
        }
        public bool CheckToWin()
        {
            for (int i = 0; i < players.Count; ++i)
            {
                string str = String.Format("игрок {0}", i);
                if (players[i].Count == 36)
                {
                    WIN(this, new GameEventArgs(str));
                    return true;
                }
            }
            return false;
        }
        public void Shuffle()
        {
            Random rnd = new Random();
            Queue<Card> tempDeck = new Queue<Card>(deckOfCards.Count);
            List<Card> arrayList = new List<Card>(deckOfCards.Count);
            arrayList.AddRange(deckOfCards.ToArray());
            for (int i = 0; i < deckOfCards.Count; ++i)
            {
                int index = rnd.Next(0, arrayList.Count - 1);
                tempDeck.Enqueue(arrayList[index]);
                arrayList.RemoveAt(index);
            }
            deckOfCards = tempDeck;
        }
        private void MakeDeck()
        {
            deckOfCards = new Queue<Card>(36);
            for (SUITS suit = SUITS.HEARTS; suit <= SUITS.SPADES; ++suit)
            {
                for (RANKS rank = RANKS.SIX; rank <= RANKS.ACE; ++rank)
                {
                    deckOfCards.Enqueue(new Card(suit, rank));
                }
            }
        }

        public class GameEventArgs : EventArgs
        {
            public GameEventArgs(string mess)
            {
                message = mess;
            }
            public string Message
            {
                get { return message; }
                set { message = value; }
            }
            private string message;
        }
        public Queue<Card> deckOfCards;
        public List<Player> players;
        private event EventHandler WIN;
    }
}
