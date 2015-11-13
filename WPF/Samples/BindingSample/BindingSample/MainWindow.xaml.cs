using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
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

namespace BindingSample
{
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window
   {
      public MainWindow()
      {
         InitializeComponent();
         MyClassObject = new MyClass() {
            ClassName = "MyClasslol"
         };
      }
      public MyClass MyClassObject { get; set; }

      private void Button_Click(object sender, RoutedEventArgs e) {
         var wind = new SecondWindow();
         wind.ShowDialog();
      }
   }
   public class MyClass
   {
      public string ClassName { get; set; }
   }
}
