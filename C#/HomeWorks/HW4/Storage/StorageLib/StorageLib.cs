using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StorageLib
{
    public abstract class Storage
    {
        public abstract double GetFreeSpace();
        public abstract double Copy(double size);
        public abstract double GetSpace();
        public abstract string GetInfo();
        public string StorageModel
        {
            get { return storageModel; }
        }
        public string StorageType
        {
            get { return storageType; }
        }
        protected string storageType;
        protected string storageModel;
    }
    public class Flash : Storage
    {
        public Flash(int usbVersion, int space)
            : base()
        {
            switch (usbVersion)
            {
                case 2:
                    writeSpeed = 0.02;
                    readSpeed = 0.03;
                    storageType = "flash USB 2.0";
                    storageModel = String.Format("FLSH-{0} gb", space.ToString()); ;
                    break;
                case 3:
                    writeSpeed = 0.055;
                    readSpeed = 0.085;
                    storageType = "flash USB 3.0";
                    storageModel = String.Format("FLSH-{0} gb", space.ToString()); ;
                    break;
                default: break;
            }
            this.space = space;
            busySpace = 0;
        }
        public override double Copy(double size)
        {
            if (size > space || size > GetFreeSpace()) throw new Exception("Не хватает места но носителе " + storageType);
            double time = size / writeSpeed;
            busySpace += size;
            return time;
        }
        public override string GetInfo()
        {
            return String.Format("\nтип: {0} модель: {1}\nобщее простарнство/незанятое пространство: {4}/{3}гб\nскорость чтения/записи: {4}/{5}мб/с",
                storageType, storageModel, space.ToString(), Math.Round(GetFreeSpace(),2), (readSpeed * 1000).ToString(), (writeSpeed * 1000).ToString());
        }
        public override double GetSpace()
        {
            return space;
        }
        public override double GetFreeSpace()
        {
            return space - busySpace;
        }
        private double writeSpeed;
        private double readSpeed;
        private double space;
        private double busySpace;
    }
    public class Dvd : Storage
    {
        public Dvd(int sides)
            : base()//sides - определяет количество сторон на диск, и соответсвенно объем накопителя
        {
            switch (sides)
            {
                case 1: storageType = "DVD-RW одностор";
                    this.space = 4.7;
                    break;
                case 2: storageType = "DVD-RW двустор";
                    this.space = 9.4;
                    break;
            }
            this.speed = 0.021;
            storageModel = "Sony DVD-RW";
            busySpace = 0;
        }
        public override double Copy(double size)
        {
            if (size > space || size > GetFreeSpace()) throw new Exception("Не хватает места но носителе " + storageType);
            double time = size / speed;
            busySpace += size;
            return time;
        }
        public override string GetInfo()
        {
            return String.Format("\nтип: {0} модель: {1}\nобщее простарнство/незанятое пространство: {2}/{3}гб\nскорость(чтения/записи): {4}мб/с",
                storageType, storageModel, space, Math.Round(GetFreeSpace(), 2), (speed * 1000));
        }
        public override double GetSpace()
        {
            return space;
        }
        public override double GetFreeSpace()
        {
            return space - busySpace;
        }
        private double speed;
        private double space;
        private double busySpace;
    }
    public class Hdd : Storage
    {
        public Hdd(int usbVersion, int space)
            : base()
        {
            switch (usbVersion)
            {
                case 2:
                    writeSpeed = 0.02;
                    readSpeed = 0.03;
                    storageType = "HDD USB 2.0";
                    break;
                case 3:
                    writeSpeed = 0.055;
                    readSpeed = 0.085;
                    storageType = "HDD USB 3.0";
                    break;
                default: break;
            }

            storageModel = String.Format("HDD-{0} gb", space.ToString());
            this.space = space;
            busySpace = 0;
        }
        public override double Copy(double size)
        {
            if (size > space || size > GetFreeSpace()) throw new Exception("Не хватает места но носителе " + storageType);
            double time = size / writeSpeed;
            busySpace += size;
            return time;
        }
        public override string GetInfo()
        {
            return String.Format("\nтип: {0} модель: {1}\nобщее простарнство/незанятое пространство: {2}/{3}гб\nскорость чтения/записи: {4}/{5}мб/с",
                storageType, storageModel, space.ToString(), Math.Round(GetFreeSpace(), 2), (readSpeed * 1000).ToString(), (writeSpeed * 1000));
        }
        public override double GetSpace()
        {
            return space;
        }
        public override double GetFreeSpace()
        {
            return space - busySpace;
        }
        private double writeSpeed;
        private double readSpeed;
        private double space;
        private double busySpace;
    }
}
