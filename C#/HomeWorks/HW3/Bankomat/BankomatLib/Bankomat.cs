using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bankomat
{
    public class Bankomat
    {
        public static void getBalance(Card.Card creditCard)
        {
            authorize(creditCard);
            Console.WriteLine("Баланс составляет "+Convert.ToString(creditCard.Bank.getCardBalance(creditCard)));
        }
        public static bool putMoney(Card.Card creditCard)
        {
            authorize(creditCard);
            Console.WriteLine("Введите сумму на котрую пополняете счет");
            double money = Convert.ToDouble(Console.ReadLine());
            if (creditCard.Bank.putMoney(creditCard, money))
            {
                Console.WriteLine("Счет успешно пополнен");
                return true;
            }
            else
            {
                Console.WriteLine("Счет непополнен");
                return false;
            }
        }
        public static bool getMoney(Card.Card creditCard)
        {
            authorize(creditCard);
            Console.WriteLine("Введите сумму, которую хотите снять со счета");
            double money = Convert.ToDouble(Console.ReadLine());
            if (creditCard.Bank.getMoney(creditCard, money))
            {
                Console.WriteLine("Деньги сняты");
                return true;
            }
            else
            {
                Console.WriteLine("Невозможно снять средства");
                return false;
            }
        }
        public static bool authorize(Card.Card creditCard)
        {
            string pin;
            Bank.Bank bank = creditCard.Bank;
            Console.WriteLine("Введите пин-код");
            for (int i = 0; i < 3; ++i)
            {
                pin = Console.ReadLine();
                if (pin == creditCard.PinCode && bank.FindAccount(creditCard) != -1) return true;
                else Console.WriteLine("Неверный ввод у вас осталось {0} попытки", 2 - i);
            }
            Console.WriteLine("Ошибка авторизации");
            Environment.Exit(0);
            return false;
        }
    }
}
