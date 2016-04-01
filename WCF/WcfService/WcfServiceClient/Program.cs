using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using WcfServiceClient.ServiceInfoReference;

namespace WcfServiceClient {
   class Program {
      static void Main(string[] args) {
         InstanceContext objSite = new InstanceContext(new CallbackHandler());
         ServiceInfoClient objProxy = new ServiceInfoClient(objSite);
         Console.WriteLine("Type the path");
         string strPath = Console.ReadLine();
         objProxy.GetDirectoryInfo(strPath);
         Console.ReadKey();
      }
   }
}