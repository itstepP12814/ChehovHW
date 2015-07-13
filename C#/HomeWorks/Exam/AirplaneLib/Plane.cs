using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AirplaneLib
{
    public class Plane
    {
        public delegate void Notification(int speed, int height);

        public Plane(string number, List<Dispathcer> dispatchers)
        {
            this.number = number;
            speed = 0;
            height = 0;
            penaltyPoints = 0;
            this.dispatchers = dispatchers;
            notification = this.dispatchers[0].GetInfo;
            for (int i = 1; i < dispatchers.Count; ++i)
            {
                notification += this.dispatchers[i].GetInfo;
            }
        }
        //Набор функций для переключения скоростей и набора высоты,
        //каждую описывать не вижу смысла, ибо из названий очевидно
        public void UpSpeed()
        {
            speed += 50;
            notification(speed, height);
        }
        public void UpSpeedStrong()
        {
            speed += 150;
            notification(speed, height);

        }
        public void DownSpeed()
        {
            speed -= 50;
            notification(speed, height);

        }
        public void DownSpeedStrong()
        {
            speed -= 150;
            notification(speed, height);

        }
        public void UpHeight()
        {
            height += 250;
            notification(speed, height);

        }
        public void UpHeightStrong()
        {
            height += 500;
            notification(speed, height);

        }
        public void DownHeight()
        {
            height -= 250;
            notification(speed, height);

        }
        public void DownHeightStrong()
        {
            height -= 500;
            notification(speed, height);
        }

        /// <summary>
        /// учет пилотом штрафных очков удаленных диспетчеров
        /// </summary>
        public int GetPenaltyPointsFromDeletedDispatcher(Dispathcer d)
        {
            return penaltyPoints += d.PenaltyPoints;
        }
        /// <summary>
        /// получение обзего количетсва штрафных очков пилота, с учетом удаленных диспетчеров
        /// </summary>
        /// <returns></returns>
        public int GetAllPenaltyPoints()
        {
            int k = 0;
            foreach (Dispathcer d in dispatchers)
            {
                k += d.PenaltyPoints;
            }
            k += penaltyPoints;
            return k;
        }
        public override string ToString()
        {
            return String.Format("Скорость:{0} Высота:{1} Всего штрафа:{2}", speed, height, GetAllPenaltyPoints());
        }
        /// <summary>
        /// номер воздушного судна
        /// </summary>
        public string Number
        {
            get { return number; }
        }
        /// <summary>
        /// возврат списка диспетчеров
        /// </summary>
        public List<Dispathcer> Dispathcers
        {
            get { return dispatchers; }
        }
        /// <summary>
        /// проверка, имеет ли самолет достаточное для полета количество 
        /// диспетчеров
        /// </summary>
        public bool MayFly
        {
            get
            {
                if (dispatchers.Count >= 2) return true;
                else return false;
            }
        }
        /// <summary>
        /// Добавление одного списка диспетчеров к существующему списку
        /// </summary>
        /// <param name="d">список диспетчеров</param>
        public void AddDispatcher(List<Dispathcer> d)
        {
            for (int i = 0; i < d.Count; ++i)
            {
                dispatchers.Add(d[i]);
            }
            for (int i = 0; i < dispatchers.Count; ++i)
            {
                notification += dispatchers[i].GetInfo;
            }
        }

        private string number;
        private int speed;
        private int height;
        private int penaltyPoints;
        private List<Dispathcer> dispatchers;
        private Notification notification;
    }
}
