using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace DiskInfoWcfLib {
   [ServiceContract]
   public interface IDiskInfo {
      [OperationContract]
      long GetTotalSpace(string strDiskName);

      [OperationContract]
      long GetFreeSpace(string strDiskName);
   }
}