using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CarLib;
/*пояснение для самого себя:
 *1 мы создаем в классе Car событие  public event EventHandler Overheat, к которому можно привязать тип делегата EventHandler
 *2 в Main() мы каждое такое событие подписываем на обработчик car_Stop, обработчик события в свою очередь должен иметь такую же
 *сигнатуру что и делегат EventHandler, при генерации события, вызовется соответсвующий обработчик, в данном случае он один для трех разных
 событий(машина останавливается), отличаются только передаваемые обработчику аргументы*/
namespace MovingCar
{
    class Program
    {
        static void car_Stop(Object obj, EventArgs args)
        {
            Car.CarEventArgs m = (Car.CarEventArgs)args;
            Console.WriteLine(m.Message + ", стоим");
        }
        static void Main(string[] args)
        {
            Car subary = new Car(50, 4.0);
            subary.Overheat += new EventHandler(car_Stop);
            subary.FuelEnded += new EventHandler(car_Stop);
            subary.OilEnded += new EventHandler(car_Stop);
            while (subary.MayMove)
            {
                Console.WriteLine(subary.ToString());
                subary.Move();
            }
        }
    }
}
