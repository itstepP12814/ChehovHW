using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using DiskInfoWcfLib;

namespace DiskInfoServer {
   class Program {
      static void Main(string[] args) {
         var objHost = new ServiceHost(typeof(DiskInfo));
         objHost.Open();
         Console.WriteLine("Press <Enter>");
         Console.ReadKey();
         objHost.Close();
      }
   }
}