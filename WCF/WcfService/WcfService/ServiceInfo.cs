using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WcfService {
   // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
   public class ServiceInfo : IServiceInfo {
      public void GetDirectoryInfo(string strPath) {
         var objInfo = new DirectoryInfo(strPath);
         var objCallback = OperationContext.Current.GetCallbackChannel<IClientCallback>();
         objCallback.ReciveInfo(objInfo);
      }
   }
}
