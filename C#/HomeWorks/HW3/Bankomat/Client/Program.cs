using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


using Bankomat;
using Bankomat.Account;
using Bankomat.Bank;
using Bankomat.Card;
using Bankomat.Client;

namespace ConsoleApplication
{
    class Program
    {
        static bool Continue()
        {
            Console.WriteLine("Вернуться в меню? y/n д/н");
            string str = Console.ReadLine();
            if (str == "y" || str == "Y" || str == "д" || str == "Д") return true;
            else return false;
        }
        static void Main(string[] args)
        {    
            Bank alfaBank = new Bank();
            Client vasya = new Client("Василий");
            vasya.getAccaunt(alfaBank, 15000);
            Console.WriteLine("Клиент: {0} номер карты: {1} пин-код {2}", vasya.Name, vasya.Card.CardNumber, vasya.Card.PinCode);
            while (true)
            {
                Console.WriteLine("Выберите необходимую опцию:\n1. вывод баланса\n2. пополнение счета\n3. cнять денег со счета\n4. выход");
                try
                {
                    int query = Convert.ToInt32(Console.ReadLine());
                    switch (query)
                    {
                        case 1: Bankomat.Bankomat.getBalance(vasya.Card);
                            if (!Continue()) return;
                            break;
                        case 2: Bankomat.Bankomat.putMoney(vasya.Card);
                            if (!Continue()) return;
                            break;
                        case 3: Bankomat.Bankomat.getMoney(vasya.Card);
                            if (!Continue()) return;
                            break;
                        case 4: Console.WriteLine("Всего хорошего");
                            return;
                        default: break;
                    }
                }
                catch (FormatException ex)
                {
                    Console.WriteLine(ex.Message);
                    //тут ловим все исключения от банкомата и при вводе
                }
            }
        }
    }
}
