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

namespace TaskManager {
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window {
      public MyClass MyClassProperty { get; set; }

      public MainWindow() {
         InitializeComponent();
         
      }

      private void Button_Click(object sender, RoutedEventArgs e) {
         MyClassProperty = new MyClass
         {
            Name = "lold"
         };
         DetailWindow win = new DetailWindow();
         win.grid.Resources["MainWindowResource"] = this;
         win.ShowDialog();
      }
   }

   public class MyClass {
      public string Name { get; set; }
   }
}