using System;

namespace DiskInfoClientAppNs {
   class Program {
      static void Main(string[] args) {
         //IMPORTANT: must using VS developer command promt and svcutil.exe for generating WSDL and decompiling proxy class
         //using decompiled class from wsdl file and Channels

         //ChannelFactory<IDiskInfo> objFactory = new ChannelFactory<IDiskInfo>("DefaultEndPoint");
         //IDiskInfo objInfo = objFactory.CreateChannel();

         //now using proxy class with manual generated file from svcutil.exe
         //IDiskInfo objInfo = new DiskInfoClient(new WSHttpBinding(), new EndpointAddress("http://localhost/DiskInfoService"));
         IDiskInfo objInfo = new DiskInfoClient("DefaultEndPoint");

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