using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bankomat.Client
{
   public  class Client
    {
        public Client(string name_)
        {
            name = name_;
        }
        public void getAccaunt(Bank.Bank bank, double money)
        {//мы открываем счет, но реально банк должен вернуть человеку только крудитку
            creditCard = bank.getCreditCard(this, money);
        }
        public string Name
        {
            get { return name; }
        }
        public Card.Card Card
        {
            get { return creditCard; }
        }
        private Card.Card creditCard;
        private string name;
    }
}
