using System.ServiceModel;
using System.ServiceProcess;
using DiskInfoWcfLib;

namespace DiskInfoService {
   //IMPORTANT: Dont forget INSTALL service via InsallUtil and START service via services.msc
   public partial class DiskInfoService : ServiceBase {
      ServiceHost objHost = new ServiceHost(typeof(DiskInfo));

      public DiskInfoService() {
         InitializeComponent();
      }

      protected override void OnStart(string[] args) {
         objHost.Open();
      }

      protected override void OnStop() {
         objHost.Close();
      }
   }
}