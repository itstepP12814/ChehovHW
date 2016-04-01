using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
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

namespace Chat {
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window {
      private IPEndPoint LocalEndPoint;
      private IPEndPoint RemoteEndPoint;
      private static bool IsReceiveNow = false;

      public MainWindow() {
         InitializeComponent();
      }

      public async void ReceiveMessages() {
         await ReceiveMessagesAsync();
      }

      public async void SendMessage(string strMessage) {
         await SendMessageAsync(strMessage);
      }

      public async Task SendMessageAsync(string strMessage) {
         UdpClient objClient = null;
         try {
            objClient = new UdpClient();
            byte[] btarrMessage = Encoding.UTF8.GetBytes(strMessage);

            await objClient.SendAsync(btarrMessage, btarrMessage.Length, RemoteEndPoint);
         }
         catch(Exception ex) {
            MessageBox.Show("SendMessageAsync " + ex.Message);
         }
         finally {
            if(objClient != null) {
               objClient.Close();
            }
         }
      }

      public async Task ReceiveMessagesAsync() {
         UdpClient objClient = null;
         try {
            while(true) {
               objClient = new UdpClient(LocalEndPoint);

               IPEndPoint objRemoteEndPoint;
               UdpReceiveResult objResult = await objClient.ReceiveAsync();
               objRemoteEndPoint = objResult.RemoteEndPoint;

               string strText = Encoding.UTF8.GetString(objResult.Buffer);

               await richTextBox1.Dispatcher.InvokeAsync(() => { richTextBox1.AppendText($"{objRemoteEndPoint.Address}:{objRemoteEndPoint.Port} {strText}\n"); });
               objClient.Close();
            }
         }
         catch(Exception ex) {
            MessageBox.Show("ReceiveMessageAsync " + ex.Message);
         }
      }


      private void button1_Click(object sender, RoutedEventArgs e) {
         SendMessage(textBox1.Text);
         textBox1.Text = String.Empty;
      }

      private void button2_Click(object sender, RoutedEventArgs e) {
         string strLocalIp = textBox2.Text;
         int iRemotePort = Convert.ToInt32(textBox3.Text);
         int iLocalPort = Convert.ToInt32(textBox4.Text);

         LocalEndPoint = new IPEndPoint(IPAddress.Parse(strLocalIp), iLocalPort);
         RemoteEndPoint = new IPEndPoint(IPAddress.Parse(strLocalIp), iRemotePort);

         if(!IsReceiveNow && LocalEndPoint != null) {
            IsReceiveNow = true;
            ReceiveMessages();
         }
      }
   }
}