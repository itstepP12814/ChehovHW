using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace TaskManager
{
   public class MemoryConverter:IValueConverter
   {
      public object Convert(object value, Type targetType, object parameter, CultureInfo culture) {
         return (long)value / (1024*1024);
      }

      public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture) {
         return value;
      }
   }
}
