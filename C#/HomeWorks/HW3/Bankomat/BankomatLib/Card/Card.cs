using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bankomat.Card
{
   public class Card
    {
        public Card(Bank.Bank bank_, Client.Client client)
        {
            Random ran = new Random();
            pinCode = Convert.ToString(ran.Next(1000, 9999));
            cardNumber = Convert.ToString(ran.Next(1000000, 9999999));
            bank = bank_;
            clientName = client.Name;
        }
        public string CardNumber
        {
            get { return cardNumber; }
        }
        public string ClientName
        {
            get { return clientName; }
        }
        public string PinCode
        {
            get { return pinCode; }
        }
        public Bank.Bank Bank
        {
            get { return bank; }
        }
        private Bank.Bank bank;
        private string clientName;
        private string cardNumber;
        private string pinCode;
    }
}
