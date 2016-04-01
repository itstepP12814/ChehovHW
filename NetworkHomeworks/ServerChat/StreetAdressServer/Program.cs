using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace StreetAdressServer {
   class Program {
      static void Main(string[] args) {
         IPEndPoint objEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 88);
         Server objServer = new Server(objEndPoint);
         objServer.Start();
         Console.Read();
      }
   }
}