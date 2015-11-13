using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace TaskManager
{
   class CpuUsageConverter:IValueConverter
   {
      public object Convert(object value, Type targetType, object parameter, CultureInfo culture) {
         var objCounter=new PerformanceCounter();
         objCounter = new PerformanceCounter("Process", "% Processor Time", (string)value);
         return objCounter.NextValue();
      }

      public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture) {
         return value;
      }
   }
}
