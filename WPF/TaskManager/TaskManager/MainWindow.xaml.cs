using System;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Threading;

namespace TaskManager {
   /// <summary>
   ///    Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window {
      private DispatcherTimer _Timer;
      private CommandBinding _RadioButtonCommandBinding;
      public Process SelectedProcess { get; private set; }

      public MainWindow() {
         InitializeComponent();
      }


      private void gridProcess_MouseDoubleClick(object sender, System.Windows.Input.MouseButtonEventArgs e) {
         try {
            SelectedProcess = Process.GetProcessById((gridProcess.SelectedItem as Process).Id);
            var objWindow = new DetailsWindow();
            objWindow.Resources["MainResources"] = this;
            objWindow.ShowDialog();
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }

      private void Window_Loaded(object sender, RoutedEventArgs e) {
         _RadioButtonCommandBinding = new CommandBinding(ApplicationCommands.New);
         _RadioButtonCommandBinding.Executed += NewCommand_Executed;
         this.CommandBindings.Add(_RadioButtonCommandBinding);

         _Timer = new DispatcherTimer();
         _Timer = new DispatcherTimer { Interval = new TimeSpan(0, 0, 1) };
         _Timer.Tick += new EventHandler(dispatcherTimer_Tick);
         _Timer.Start();
      }

      private void NewCommand_Executed(object sender, ExecutedRoutedEventArgs e) {
         int iInterval;
         Int32.TryParse(e.Parameter.ToString(), out iInterval);
         if(iInterval == 0) {
            ChangeSkin(e.Parameter.ToString());
         }
         else {
            _Timer.Interval = new TimeSpan(0, 0, Convert.ToInt32(e.Parameter));
         }
      }

      private void ChangeSkin(string strSkinName) {
         var objResourceDictionary = new ResourceDictionary();
         objResourceDictionary.Source = new Uri(strSkinName, UriKind.Relative);
         App.Current.Resources.MergedDictionaries[0] = objResourceDictionary;
      }

      private void dispatcherTimer_Tick(object sender, EventArgs e) {
         //и все равно UI тормозит
         try {
            Dispatcher.BeginInvoke(
               new ThreadStart(() => {
                  gridProcess.ItemsSource = null;
                  gridDetails.ItemsSource = null;

                  gridProcess.ItemsSource = Process.GetProcesses().OrderBy(s => s.ProcessName);
                  gridDetails.ItemsSource = Process.GetProcesses().OrderBy(s => s.ProcessName);
               }));
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }
   }
}