using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
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
using MediaFileLib;
using Microsoft.Win32;

namespace MediaPlayer {
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window {
      private bool _bIsPlaying = false;
      private bool _bIgnoreChange = false;
      private bool _bFullScreen = false;
      private DispatcherTimer _Timer;
      private PlayList _PlayList;

      public MainWindow() {
         InitializeComponent();
      }

      private void Window_Loaded(object sender, RoutedEventArgs e) {
         _Timer = new DispatcherTimer { Interval = new TimeSpan(0, 0, 1) };
         _Timer.Tick += new EventHandler(dispatcherTimer_Tick);
         _PlayList = new PlayList();
         sliderVolume.Value = mediaElement.Volume;
      }

      private void MenuOpenFile_OnClick(object sender, RoutedEventArgs e) {
         try {
            var objDialog = new OpenFileDialog() {
               Filter = "Media files| *.mp4; *.avi; *.mp3; *.wav; *.pl"
            };
            bool? result = objDialog.ShowDialog();
            if(result == true) {
               var objFileInfo = new FileInfo(objDialog.FileName);
               //rewrite current play list
               _PlayList = new PlayList();

               //if we opened playlist
               if(objFileInfo.Extension == ".pl") {
                  _PlayList.Open(objDialog.FileName);
                  UpdatePlayListView();
               }
               else {
                  //if we opened standart media file
                  var objMediaFile = new MediaFile(objFileInfo);
                  _PlayList.MediaFiles.Add(objMediaFile);
                  ListBoxPlayList.Items.Add(objMediaFile);
               }
               ListBoxPlayList.SelectedIndex = 0;
               ListBoxPlayList_OnMouseDoubleClick(sender, null);
            }
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }

      private void MenuSavePlaylist_OnClick(object sender, RoutedEventArgs e) {
         try {
            var objDialog = new SaveFileDialog();
            bool? result = objDialog.ShowDialog();
            if(result == true) {
               if(objDialog.FileName.EndsWith(".pl")) {
                  _PlayList.Save(objDialog.FileName);
               }
               else {
                  _PlayList.Save(objDialog.FileName + ".pl");
               }
            }
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }

      private void MenuFullScreen_OnClick(object sender, RoutedEventArgs e) {
         if(!_bFullScreen) {
            //mediaElement.Width = SystemParameters.FullPrimaryScreenWidth;
            //mediaElement.Height = SystemParameters.FullPrimaryScreenHeight;

            WindowStyle = WindowStyle.None;
            WindowState = WindowState.Maximized;
         }
         else {
            WindowStyle = WindowStyle.SingleBorderWindow;
            WindowState = WindowState.Normal;
         }
         _bFullScreen = !_bFullScreen;
      }

      private void ButtonBack_Click(object sender, RoutedEventArgs e) {
         if(ListBoxPlayList.SelectedIndex != 0) {
            ListBoxPlayList.SelectedIndex -= 1;
         }
         ListBoxPlayList_OnMouseDoubleClick(sender, null);
      }

      private void ButtonPlay_Click(object sender, RoutedEventArgs e) {
         try {
            if(_bIsPlaying) {
               mediaElement.Pause();
               _Timer.Stop();
               ButtonPlay.Content = "Play";
            }
            else {
               mediaElement.Play();
               _Timer.Start();
               ButtonPlay.Content = "Pause";
            }
            _bIsPlaying = !_bIsPlaying;
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }

      private void ButtonNext_Click(object sender, RoutedEventArgs e) {
         if(ListBoxPlayList.SelectedIndex < _PlayList.MediaFiles.Count) {
            ListBoxPlayList.SelectedIndex += 1;
         }
         ListBoxPlayList_OnMouseDoubleClick(sender, null);
      }

      private void ListBoxPlayList_OnMouseDoubleClick(object sender, MouseButtonEventArgs e) {
         try {
            mediaElement.Stop();
            _Timer.Stop();
            if(!((MediaFile)ListBoxPlayList.SelectedItem).FileInfo.Exists) {
               throw new ArgumentNullException("No such file!");
            }

            mediaElement.Source = new Uri((ListBoxPlayList.SelectedItem as MediaFile).FileInfo.FullName);
            _bIsPlaying = false;
            ButtonPlay_Click(sender, e);
         }
         catch(ArgumentNullException ex) {
            MessageBox.Show(ex.Message);
            _PlayList.MediaFiles.Remove((ListBoxPlayList.SelectedItem as MediaFile));
            UpdatePlayListView();
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }

      private void ListBox_PlayList_OnSelectionChanged(object sender, SelectionChangedEventArgs e) {
      }

      private void dispatcherTimer_Tick(object sender, EventArgs e) {
         _bIgnoreChange = true;
         sliderPosition.Value = mediaElement.Position.TotalSeconds;
         DurationNowLabel.Content = mediaElement.Position.ToString(@"hh\:mm\:ss");
         _bIgnoreChange = false;
      }

      private void sliderPosition_LostMouseCapture(object sender, MouseEventArgs e) {
         mediaElement.Position = TimeSpan.FromSeconds(sliderPosition.Value);
      }

      private void SliderPosition_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e) {
         //каждый раз когда срабатывает таймер мы сдвигаем слайдер соотвественно видео, а каждый раз когда отрабатывает сдвиг слайдера видео 
         //проматывается соотвественно сдвигу слайдера. Получается замкнутый круг где одно двигает другое чтобы двигать первое, таким костылем я избегаю подобного 
         //эффекта
         //if(_bIgnoreChange) {
         //   return;
         //}
         //if(!sliderPosition.IsMouseCaptureWithin) {
         //   mediaElement.Position = TimeSpan.FromSeconds(sliderPosition.Value);
         //}
      }

      private void SliderVolume_OnValueChangedliderVolume_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e) {
         mediaElement.Volume = sliderVolume.Value;
         VolumeLabel.Content = String.Format("{0} %", (int)(mediaElement.Volume * 100));
      }

      private void mediaElement_MediaOpened(object sender, RoutedEventArgs e) {
         sliderPosition.Maximum = mediaElement.NaturalDuration.TimeSpan.TotalSeconds;
         sliderPosition.Minimum = 0;
         sliderPosition.Value = 0;
         if(mediaElement.NaturalDuration.HasTimeSpan) {
            DurationTotalLabel.Content = mediaElement.NaturalDuration.TimeSpan.ToString(@"hh\:mm\:ss");
         }
      }

      private void ButtonStop_OnClick(object sender, RoutedEventArgs e) {
         mediaElement.Stop();
         _bIsPlaying = false;
      }

      private void ContextMenuAdd_OnClick(object sender, RoutedEventArgs e) {
         try {
            var objDialog = new OpenFileDialog() {
               Filter = "Media files| *.mp4; *.avi; *.mp3; *.wav"
            };
            bool? result = objDialog.ShowDialog();
            if(result == true) {
               var objFileInfo = new FileInfo(objDialog.FileName);
               var objMediaFile = new MediaFile(objFileInfo);
               _PlayList.MediaFiles.Add(objMediaFile);
               ListBoxPlayList.Items.Add(objMediaFile);
            }
         }
         catch(Exception ex) {
            MessageBox.Show(ex.Message);
         }
      }

      private void ContextMenuRemove_OnClick(object sender, RoutedEventArgs e) {
         _PlayList.MediaFiles.Remove((ListBoxPlayList.SelectedItem as MediaFile));
         UpdatePlayListView();
      }

      private void mediaElement_KeyDown(object sender, KeyEventArgs e) {
         if(e.Key == Key.Escape) {
            MenuFullScreen_OnClick(sender, e);
         }
      }

      private void mediaElement_MediaEnded(object sender, RoutedEventArgs e) {
         mediaElement.Stop();
      }

      private void UpdatePlayListView() {
         ListBoxPlayList.Items.Clear();
         foreach(var file in _PlayList.MediaFiles) {
            ListBoxPlayList.Items.Add(file);
         }
      }
   }
}