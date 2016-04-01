using System;
using System.IO;
using WcfServiceClient.ServiceInfoReference;

namespace WcfServiceClient {
   public class CallbackHandler : IServiceInfoCallback {
      public void ReciveInfo(DirectoryInfo objInfo) {
         foreach(DirectoryInfo objDirInfo in objInfo.GetDirectories()) {
            Console.WriteLine($"{objDirInfo.FullName}\n");
         }
         foreach(FileInfo objFile in objInfo.GetFiles()) {
            Console.WriteLine($"{objFile.FullName}\n");
         }
      }
   }
}