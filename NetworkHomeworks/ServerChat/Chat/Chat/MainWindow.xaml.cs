using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using StreetAdressServer;

namespace Chat {
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window {
      private IPEndPoint ServerEndPoint;
      private IPEndPoint LocalEndPoint;
      private static bool IsReceiveNow = false;
      private ClientInfo LocalClientInfo;
      private ClientInfo RemoteClientInfo;
      private Socket _Socket;
      private Socket _Listener;

      public MainWindow() {
         InitializeComponent();
      }

      private bool TryConnect() {
         _Socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         _Socket.Connect(ServerEndPoint);
         if(_Socket.Connected) {
            return true;
         }
         else {
            return false;
         }
      }

      private void BeginListen() {
         _Listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
         _Listener.Bind(LocalEndPoint);
         _Listener.Listen(5);
      }

      public async void ReceiveMessages() {
         await Task.Run(() => ReceiveMessagesAsync());
      }

      public async void SendMessage(string strMessage) {
         await Task.Run(() => SendMessageAsync(strMessage));
      }

      public byte[] SerializeMessage(string Message) {
         BinaryFormatter objFormatter = new BinaryFormatter();
         LocalClientInfo.Message = Message;
         Dispatcher.Invoke(() => LocalClientInfo.RecieverName = textBox7.Text);
         byte[] mess;
         using(MemoryStream objStream = new MemoryStream()) {
            objFormatter.Serialize(objStream, LocalClientInfo);
            mess = objStream.ToArray();
         }
         return mess;
      }

      public void SendMessageAsync(string strMessage) {
         try {
            TryConnect();
            byte[] btarrMessage = SerializeMessage(strMessage);
            _Socket.Send(btarrMessage);
         }
         catch(Exception ex) {
            MessageBox.Show("SendMessageAsync " + ex.Message);
         }
      }

      public async void ReceiveMessagesAsync() {
         try {
            while(true) {
               var objLocalSocket = _Listener.Accept();
               byte[] btarrMessage = new byte[1024];
               objLocalSocket.Receive(btarrMessage);

               ClientInfo objInfo = DeserializeClientInfo(btarrMessage);

               await richTextBox1.Dispatcher.InvokeAsync(() => { richTextBox1.AppendText($"{objInfo.Name} {objInfo.Message}\n"); });
            }
         }
         catch(Exception ex) {
            MessageBox.Show("ReceiveMessageAsync " + ex.Message);
         }
      }

      private ClientInfo DeserializeClientInfo(byte[] info) {
         BinaryFormatter objFormatter = new BinaryFormatter();
         ClientInfo objInfo;
         using(var objStream = new MemoryStream(info)) {
            objInfo = (ClientInfo)objFormatter.Deserialize(objStream);
         }
         return objInfo;
      }

      private void button1_Click(object sender, RoutedEventArgs e) {
         SendMessage(textBox1.Text);
         textBox1.Text = String.Empty;
      }

      private void button2_Click(object sender, RoutedEventArgs e) {
         LocalEndPoint = new IPEndPoint(IPAddress.Parse(textBox2.Text), Convert.ToInt32(textBox3.Text));
         LocalClientInfo = new ClientInfo(LocalEndPoint, textBox4.Text);

         RemoteClientInfo = new ClientInfo() {
            Name = textBox7.Text
         };

         ServerEndPoint = new IPEndPoint(IPAddress.Parse(textBox5.Text), Convert.ToInt32(textBox6.Text));
         if(!IsReceiveNow && LocalEndPoint != null) {
            IsReceiveNow = true;
            BeginListen();
            ReceiveMessages();
         }
      }
   }
}