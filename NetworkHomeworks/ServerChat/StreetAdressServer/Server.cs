using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StreetAdressServer {
   public class Server {
      private Socket _Socket;
      private Socket SendSocket;
      private IPEndPoint _EndPoint;
      private List<ClientInfo> Clients = new List<ClientInfo>();


      public Server(IPEndPoint objEndPoint) {
         _EndPoint = objEndPoint;
      }

      public async void Start() {
         _Socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         _Socket.Bind(_EndPoint);
         _Socket.Listen(5);

         await Task.Run(() => ServerBeginAcceptAsync(_Socket));
      }

      public void ServerBeginAcceptAsync(Socket objSocket) {
         while(true) {
            Socket objLocalSocket = objSocket.Accept();
            byte[] btarrMessage = new byte[1024];
            objLocalSocket.Receive(btarrMessage);
            ClientInfo objSender = DeserializeClientInfo(btarrMessage);

            var objSndr = Clients.SingleOrDefault(info => info.Name == objSender.Name);
            if(objSndr == null) {
               Clients.Add(objSender);
            }

            ClientInfo objRecever = Clients.SingleOrDefault(info => info.Name == objSender.RecieverName);
            if(objRecever != null) {
               SendMessage(objSender, objRecever);
            }
            objLocalSocket.Close();

            //btarrMessage = btarrMessage.Where(b => b != '\0' && b != '\n' && b != '\r').ToArray();
            //string strCommand = Encoding.ASCII.GetString(btarrMessage);
         }
      }

      private void SendMessage(ClientInfo objSender, ClientInfo objReceiver) {
         SendSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         SendSocket.Connect(objReceiver.EndPoint);

         byte[] btarrMessage = SerializeClientInfo(objSender);
         SendSocket.Send(btarrMessage);
         SendSocket.Close();
      }

      private byte[] SerializeClientInfo(ClientInfo objInfo) {
         BinaryFormatter objFormatter = new BinaryFormatter();
         byte[] info;
         using(MemoryStream objStream = new MemoryStream()) {
            objFormatter.Serialize(objStream, objInfo);
            info = objStream.ToArray();
         }
         return info;
      }

      private ClientInfo DeserializeClientInfo(byte[] info) {
         BinaryFormatter objFormatter = new BinaryFormatter();
         ClientInfo objInfo;
         using(var objStream = new MemoryStream(info)) {
            objInfo = (ClientInfo)objFormatter.Deserialize(objStream);
         }
         return objInfo;
      }

      public void ServerEndAcceptAsync(Socket objLocalUsedSocket) {
         objLocalUsedSocket.Shutdown(SocketShutdown.Both);
         objLocalUsedSocket.Close();
      }

      public async Task ExecuteCommand(string strCommand, Socket objLocalSocket) {
         Regex objExpression = new Regex("[0-9]");
         if(objExpression.IsMatch(strCommand)) {
         }
         else {
            switch(strCommand) {
            case "make-screenshot":
               await Task.Factory.StartNew(() => { MakeScreenshot(strCommand, objLocalSocket); });
               break;
            default:
               break;
            }
         }
      }

      public void MakeScreenshot(string strCommand, Socket objLocalSocket) {
         using(Bitmap objBitMap = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height)) {
            using(Graphics objGraphics = Graphics.FromImage(objBitMap)) {
               objGraphics.CopyFromScreen(Screen.PrimaryScreen.Bounds.X,
                  Screen.PrimaryScreen.Bounds.Y,
                  0, 0,
                  objBitMap.Size,
                  CopyPixelOperation.SourceCopy);

               BinaryFormatter objFormatter = new BinaryFormatter();
               using(MemoryStream objStream = new MemoryStream()) {
                  objFormatter.Serialize(objStream, objBitMap);
                  objLocalSocket.Send(objStream.ToArray());
               }

               ServerEndAcceptAsync(objLocalSocket);
            }
         }
      }
   }
}