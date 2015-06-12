using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGameLib
{
    public class Player
    {
        public Player()
        {
            cardsQueue = new Queue<Card>();
        }
        public void Push(Card card)
        {
            cardsQueue.Enqueue(card);
        }
        public Card Pull()
        {
            return cardsQueue.Dequeue();
        }
        public Card Peek()
        {
            return cardsQueue.Peek();
        }
        public void ShowCards()
        {
            foreach (Card card in cardsQueue)
            {
                Console.WriteLine(card.ToString());
            }
        }
        public int Count
        {
            get { return cardsQueue.Count; }
        }
        private Queue<Card> cardsQueue;
    }
}
