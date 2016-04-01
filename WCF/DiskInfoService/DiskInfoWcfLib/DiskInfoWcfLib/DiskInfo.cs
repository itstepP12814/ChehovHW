using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DiskInfoWcfLib {
   public class DiskInfo : IDiskInfo {
      public long GetTotalSpace(string strDiskName) {
         try {
            var objInfo = new DriveInfo(strDiskName);
            return objInfo.TotalSize;
         }
         catch {
            return -1;
         }
      }

      public long GetFreeSpace(string strDiskName) {
         try {
            var objInfo = new DriveInfo(strDiskName);
            return objInfo.TotalFreeSpace;
         }
         catch {
            return -1;
         }
      }
   }
}