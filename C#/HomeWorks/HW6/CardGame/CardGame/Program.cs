using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CardGameLib;

namespace CardGame
{
    class Program
    {
        static void Main(string[] args)
        {
            Game game = new Game();
            int i = 0;
            while (!game.CheckToWin())
            {
                game.GetCards();
                game.OpenCards();
            }
        }
    }
}
