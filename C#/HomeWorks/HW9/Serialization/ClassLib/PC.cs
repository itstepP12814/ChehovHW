using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLib
{   
    [Serializable]
    public class PC{
        public PC(string _model, string _cpu, int _ram, int _hdd)
        {
            model = _model;
            cpu = _cpu;
            ram = _ram;
            hdd = _hdd;
            on = false;
        }
        public string Load()
        {
            on = true;
            return "Машина включена";
        }
        public string Shutdown()
        {
            on = false;
            return "Машина выключена";
        }
        public string Reload()
        {
            return String.Format("{0}...{1}...{2}", "Перезагрузка", Shutdown(), Load());
        }
        public string Mark
        {
            get { return model; }
        }
        public string HDD
        {
            get { return hdd.ToString() + "GB"; }
        }
        public string RAM
        {
            get { return ram.ToString() + "GB"; }
        }
        public string CPU
        {
            get { return cpu; }
        }
        public string Status
        {
            get { return (on)?"Машина включена":"Машина выключена";}
        }
        public override string ToString()
        {
            return String.Format("Модель: {0} CPU: {1} RAM: {2}GB HDD: {3}GB", model, cpu, ram, hdd);
        }
        private string model;
        private string cpu;
        private int hdd;
        private int ram;
        private bool on;
    }
}
