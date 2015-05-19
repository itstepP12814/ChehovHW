using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bankomat.Account
{
   public class Account
    {
        public Account(double money, Card.Card creditCard_, Client.Client client_, int clientNumber_)
        {
            creditCard = creditCard_;
            balance = money;
            client = client_;
            accauntNumber = String.Format(Convert.ToString(clientNumber_) + creditCard.CardNumber);
        }
        public string ClientName
        {
            get { return client.Name; }
        }
        public Card.Card CreditCard
        {
            get { return creditCard; }
        }
        public double Balance
        {
            get { return balance; }
            set { balance = (double)value; }
        }
        private Client.Client client;
        private double balance;
        private Card.Card creditCard;
        private string accauntNumber;
    }
}
