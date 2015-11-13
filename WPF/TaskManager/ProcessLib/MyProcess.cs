using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace ProcessLib {
   public class MyProcess {
      private PerformanceCounter objCounter;

      public MyProcess() {
         objCounter = new PerformanceCounter();
      }

      public int CpuUsage {
         get { return (int)objCounter.NextValue(); }
      }

      public string ProcessName { get; private set; }
      public int MemoryUsage { get; private set; }
      public int Id { get; private set; }

      public static MyProcess[] GetProcesses() {
         Process[] objProcesses = Process.GetProcesses();
         List<MyProcess> objMyProcesses = new List<MyProcess>();

         foreach(var proc in objProcesses) {
            var process = new MyProcess {
               objCounter = new PerformanceCounter("Process", "% Processor Time", proc.ProcessName),
               ProcessName = proc.ProcessName,
               Id = proc.Id,
               MemoryUsage = (int)(proc.WorkingSet64 / 10000)
            };
            process.objCounter.NextValue();
            objMyProcesses.Add(process);
         }

         return objMyProcesses.ToArray();
      }
   }
}