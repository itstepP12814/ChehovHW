using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyClassLib.WorldOfTanks
{
    public class Tank
    {//требуется объявить класс со спецификатором доступа public, чтобы он был доступен в сборке

        public Tank(int ammo_, int armor_, int mobility_, string model_)
        {
            try
            {
                if (ammo_ > 100 || ammo_ < 0) throw new Exception("Неадекватное число процентов боекомплекта");
                if (armor_ > 100 || armor_ < 0) throw new Exception("Неадекватное число процентов брони");
                if (mobility_ > 100 || mobility_ < 0) throw new Exception("Неадекватное число процентов маневренности");
                ammo = ammo_;
                armor = armor_;
                mobility = mobility_;
                model = model_;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }
        public override string ToString()
        {
            return String.Format("{0,6} Боекомплект: {1,2} Броня: {2,2} Маневренность: {3,2} ", model, ammo, armor, mobility);
        }
        public static Tank operator ^(Tank t1, Tank t2)
        {
            try
            {
                if (t1 == null || t2 == null) throw new ArgumentNullException("Передан пустой аргумент для сравнения");
                if (t1.ammo > t2.ammo)
                {
                    if (t1.armor > t2.armor) return t1;
                    else
                    {
                        if (t1.mobility > t2.mobility) return t1;
                        else return t2;
                    }
                }
                else
                {
                    if (t1.armor > t2.armor)
                    {
                        if (t1.mobility > t2.mobility) return t1;
                        else return t2;
                    }
                    else return t2;
                }
            }
            catch (ArgumentNullException ex)
            {
                Console.WriteLine(ex.Message);
                return null;
            }
        }
        public string Model
        {
            get { return model; }
        }
        private int ammo;
        private int armor;
        private int mobility;
        private string model;

    }

}
