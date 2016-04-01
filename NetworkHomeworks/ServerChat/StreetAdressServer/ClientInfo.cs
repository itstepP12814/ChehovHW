using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StreetAdressServer {
   [Serializable]
   public class ClientInfo {
      public ClientInfo() {
      }

      public ClientInfo(IPEndPoint objEndPoint, string strName) {
         EndPoint = objEndPoint;
         Name = strName;
      }
      public string Message { get; set; }
      public string Name { get; set; }
      public string RecieverName { get; set; }
      public IPEndPoint EndPoint { get; set; }
   }
}