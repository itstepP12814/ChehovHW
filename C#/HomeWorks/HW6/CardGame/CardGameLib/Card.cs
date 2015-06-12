using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGameLib
{
    public enum SUITS { HEARTS, DIAMONDS, CROSS, SPADES };
    public enum RANKS { SIX = 6, SEVEN, EIGHT, NINE, TEN, KNAVE, QUEEN, KING, ACE };

    public class Card : IComparable
    {
        public Card(SUITS suit, RANKS rank)
        {
            this.suit = suit;
            this.rank = rank;
        }
        public int CompareTo(Object c)
        {
            Card crd = (Card)c;
            if (this.rank > crd.rank) return 1;
            if (this.rank == crd.rank) return 0;
            else return -1;
        }
        public RANKS Rank
        {
            get { return rank; }
        }
        public override string ToString()
        {

            string s = "";
            if (rank > RANKS.TEN)
            {
                switch (rank)
                {
                    case RANKS.KNAVE: s += "ВАЛЕТ ";
                        break;
                    case RANKS.QUEEN: s += "ДАМА ";
                        break;
                    case RANKS.KING: s += "КОРОЛЬ ";
                        break;
                    case RANKS.ACE: s += "ТУЗ ";
                        break;
                }
            }
            else
            {
                int k = (int)rank;
                s += k.ToString();
            }

            switch (suit)
            {
                case SUITS.HEARTS: s += " ♥";
                    break;
                case SUITS.DIAMONDS: s += " ♦";
                    break;
                case SUITS.CROSS: s += " ♣";
                    break;
                case SUITS.SPADES: s += " ♠";
                    break;
            }
            return s;
        }
        private RANKS rank;
        private SUITS suit;
    }
}
