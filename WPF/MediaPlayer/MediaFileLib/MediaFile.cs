using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace MediaFileLib {
   [Serializable]
   public class MediaFile {
      public MediaFile(FileInfo fileInfo) {
         FileInfo = fileInfo;
      }

      public FileInfo FileInfo { get; private set; }

      public string Name {
         get { return FileInfo.Name; }
      }

      public override string ToString() {
         return Name;
      }
   }
}