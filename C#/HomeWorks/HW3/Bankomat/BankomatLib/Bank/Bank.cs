using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bankomat.Bank
{
    public class Bank
    {
        public Bank()
        {
            //изначально банк расчитан на 10 клиентов
            accaunts = new Account.Account[10];
            numOfClients = 0;
        }
        public double getCardBalance(Card.Card creditCard)
        {
            for (int i = 0; i < accaunts.Length; ++i)
            {
                Card.Card card = accaunts[i].CreditCard;
                if (card.Bank == creditCard.Bank && card.CardNumber == creditCard.CardNumber
                    && card.ClientName == card.ClientName)
                {
                    return accaunts[i].Balance;
                }
            }
            return -1.0;
        }
        public int FindAccount(Card.Card creditCard)
        {   //метод ищет в массиве аккаунтов акк кредиктой, которую мы передали
            //как притерий поиска
            for (int i = 0; i < accaunts.Length; ++i)
            {
                Card.Card card = accaunts[i].CreditCard;
                //можно было бы сравнить адреса кредиток в памяти машины, но это противоречит свойствам предметной области
                //поэтому сравнение идет по трем критериям.
                if (card.Bank == creditCard.Bank && card.CardNumber == creditCard.CardNumber
                    && card.ClientName == creditCard.ClientName)
                {
                    return i;
                }
            }
            return -1;
        }
        public bool putMoney(Card.Card creditCard, double money)
        {   //метод для зачисления средств
            try
            {
                int accountIndex = FindAccount(creditCard);
                if (accountIndex == -1) throw new IndexOutOfRangeException("Ваш счет аннулирован");
                if (money < 0) throw new Exception("Введена отрициательная сумма");
                accaunts[accountIndex].Balance += money;
                return true;
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            return false;
        }
        public bool getMoney(Card.Card creditCard, double money)
        {
            try
            {
                int accountIndex = FindAccount(creditCard);
                if (accountIndex == -1) throw new IndexOutOfRangeException("Ваш счет аннулирован");
                if (accaunts[accountIndex].Balance < money) throw new Exception("Нехватает средств");
                if (money < 0) throw new Exception("Введена отрициательная сумма");
                accaunts[accountIndex].Balance -= money;
                return true;
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            return false;

        }
        public Card.Card getCreditCard(Client.Client client, double money)
        {
            Card.Card creditCard = new Card.Card(this, client);//банк сделал карточку
            //проверили есть ли еще место в массиве аккаунтов(счетов)
            if (numOfClients == accaunts.Length) Array.Resize(ref accaunts, numOfClients * 2);
            accaunts[numOfClients] = new Account.Account(money, creditCard, client, numOfClients);//создали аккаунт
            ++numOfClients;//сделали инкремент к числу клиентов
            return creditCard;//вернули карточку человеку
        }
        private int numOfClients;//счетчик количества клиентов банка
        private Account.Account[] accaunts;//массив аккаунтов(счетов)
    }
}
