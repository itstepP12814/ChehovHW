using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WcfService {
   // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.

   [ServiceContract(CallbackContract = typeof(IClientCallback))]
   public interface IServiceInfo {
      [OperationContract(IsOneWay = true)]
      void GetDirectoryInfo(string strPath);
   }
}
