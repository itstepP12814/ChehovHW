
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AirplaneLib
{
    public class Dispathcer
    {
        //Hp=7*Скорость (км/ч)  –  N,
        public Dispathcer(string name)
        {
            this.name = name;
            Random r = new Random();
            recomendedHeight = 0;
            penaltyPoints = 0;
            correctHeight = r.Next(-200, 200);
        }
        /// <summary>
        /// Получение рекомендации от диспетчера
        /// </summary>
        /// <param name="planeSpeed">текущая скорость самолета</param>
        /// <returns></returns>
        public int GetRecomendedHeight(int planeSpeed)
        {
            recomendedHeight = 7 * planeSpeed - correctHeight;
            return recomendedHeight;
        }
        /// <summary>
        /// Функиция, на которую подписан делегат самолета, для оповещения диспетчеров о состоянии
        /// своей скорости и высоты
        /// </summary>
        /// <param name="speed">скорость самолета</param>
        /// <param name="height">высота самолета</param>
        public void GetInfo(int speed, int height)
        {
            //если самолет по высоте отклонился более чем на 1000м или если скорость=0 и высота=0 при условии что
            //рекомендуемая скорость 0 не равняется, то значит самолет разбился
            if (recomendedHeight - height >= 1000 || (height == 0 && speed == 0 && recomendedHeight != 0)) throw new Exception("Самолет разбился");
            if (penaltyPoints >= 1000) throw new Exception("Пилот непригоден к полетам");
            if (recomendedHeight - height >= 300 && recomendedHeight - height <= 600) penaltyPoints += 25;
            if (recomendedHeight - height >= 600 && recomendedHeight - height <= 1000) penaltyPoints += 50;
            if (speed > 1000)
            {
                penaltyPoints += 100;
                throw new Exception("Снизьте скорость!");
            }
            if (speed > 50) GetRecomendedHeight(speed);
            else recomendedHeight = 0;
        }
        public override string ToString()
        {
            return String.Format("Имя:{0} Рекомендуемая высота:{1} Штраф:{2}", name, recomendedHeight, penaltyPoints);
        }
        /// <summary>
        /// свойство для рекомендованной высоты
        /// </summary>
        public int RecomendedHeigh
        {
            get { return recomendedHeight; }
        }
        /// <summary>
        /// свойство для получения количества штрафных очков
        /// </summary>
        public int PenaltyPoints
        {
            get { return penaltyPoints; }
        }
        /// <summary>
        /// собственно имя диспетчера
        /// </summary>
        public string Name
        {
            get { return name; }
        }
        private int penaltyPoints;
        private int recomendedHeight;
        private int correctHeight;//корректировка погодных условий
        private string name;
    }
}