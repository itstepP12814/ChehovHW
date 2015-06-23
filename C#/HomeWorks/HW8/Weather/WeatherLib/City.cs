using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WeatherLib
{
    public class City
    {
        public City(string name, string code)
        {
            this.name = name.Trim();
            this.code = code.Trim();
        }
        public override string ToString()
        {
            return String.Format("{0,-8} {1,5}", name, code);
        }
        public string Name
        {
            get { return this.name; }
        }
        public string Code
        {
            get { return this.code; }
        }
        private string name;
        private string code;
    }
}
