using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace WcfService {
   [ServiceContract]
   public interface IClientCallback {
      [OperationContract(IsOneWay = true)]
      void ReciveInfo(DirectoryInfo objInfo);
   }
}
