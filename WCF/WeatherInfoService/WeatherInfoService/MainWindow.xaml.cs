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
using WeatherInfoService.ServiceReference1;

namespace WeatherInfoService {
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window {
      public MainWindow() {
         InitializeComponent();
      }

      private void ButtonBase_OnClick(object sender, RoutedEventArgs e) {
         string strZip = TextBox.Text;
         var objProxy = new WeatherSoapClient("WeatherSoap");
         var city = objProxy.GetCityWeatherByZIP(strZip);//44103;
         string str = $"City:{city.City}\nTemperature:{city.Temperature}\nPressure:{city.Pressure}";
         TextBlock.Text = String.Empty;
         TextBlock.Text = str;
      }
   }
}
