using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using ClientWithProxyClass.ServiceReference;

namespace ClientWithProxyClass {
   class Program {
      static void Main(string[] args) {
         //IDiskInfo objInfo = new DiskInfoClient(new WSHttpBinding(), new EndpointAddress("http://localhost/DiskInfoService"));
         using(DiskInfoClient objInfo = new DiskInfoClient("DefaultEndPoint")) {
            Console.WriteLine("Enter the Disk Letter");
            string strDiskName = Console.ReadLine();
            long lTotalSpace = objInfo.GetTotalSpace(strDiskName);
            long lFreeSpace = objInfo.GetFreeSpace(strDiskName);

            if(lTotalSpace > -1 && lFreeSpace > -1) {
               Console.WriteLine($"Total space on {strDiskName} is {lTotalSpace}");
               Console.WriteLine($"Free space on {strDiskName} is {lFreeSpace}");
            }
            else {
               Console.WriteLine("Error");
            }
         }
      }
   }
}