using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Figures
{
    abstract class Figure
    {
        public abstract void ShowFigure();
        protected ConsoleColor color;
    }
    class Square : Figure
    {
        public Square(ConsoleColor color)
        {
            this.color = color;
        }
        public override void ShowFigure()
        {
            Console.ForegroundColor = color;
            Console.WriteLine("****");
            for (int i = 0; i < 2; ++i) Console.Write("*  *\n");
            Console.WriteLine("****");
            Console.ResetColor();
        }
    }
    class Round : Figure
    {
        public Round(ConsoleColor color)
        {
            this.color = color;
        }
        public override void ShowFigure()
        {
            Console.ForegroundColor = color;
            Console.WriteLine(" ** ");
            for (int i = 0; i < 2; ++i) Console.Write("*  *\n");
            Console.WriteLine(" ** ");
            Console.ResetColor();
        }
    }
    class Rectangle : Figure
    {
        public Rectangle(ConsoleColor color)
        {
            this.color = color;
        }
        public override void ShowFigure()
        {
            Console.ForegroundColor = color;
            Console.WriteLine("******");
            Console.WriteLine("*    *");
            Console.WriteLine("******");
            Console.ResetColor();
        }
    }
    class Triangle : Figure
    {
        public Triangle(ConsoleColor color)
        {
            this.color = color;
        }
        public override void ShowFigure()
        {
            Console.ForegroundColor = color;
            Console.WriteLine("  *  ");
            Console.WriteLine(" *** ");
            Console.WriteLine("*****");
            Console.ResetColor();
        }
    }
    class GeneralizedFigure
    {
        public GeneralizedFigure()
        {
            figures = new List<Figure>();
        }
        public void ShowAllFigures()
        {
            foreach (Figure f in figures) f.ShowFigure();
        }
        public List<Figure> figures;
    }
    class Program
    {
        static void AddNewFigure(int fig, int col, GeneralizedFigure figureList)
        {
            ConsoleColor color = ConsoleColor.White;
            switch (col)
            {
                case 1: color = ConsoleColor.Red;
                    break;
                case 2: color = ConsoleColor.Green;
                    break;
                case 3: color = ConsoleColor.Blue;
                    break;
                case 4: color = ConsoleColor.Yellow;
                    break;
                default: break;
            }
            switch (fig)
            {

                case 1: figureList.figures.Add(new Square(color));
                    break;
                case 2: figureList.figures.Add(new Rectangle(color));
                    break;
                case 3: figureList.figures.Add(new Round(color));
                    break;
                case 4: figureList.figures.Add(new Triangle(color));
                    break;
                default: break;
            }
        }
        static void Main(string[] args)
        {
            GeneralizedFigure figuresList = new GeneralizedFigure();
            string answer = "y";
            while (answer == "y")
            {
                Console.WriteLine("Выберите фигуру и цвет");
                Console.WriteLine("1 квадрат\n2 прямоугольник\n3 круг\n4 треугольник");
                string str = Console.ReadLine();
                int choiceFigure = Convert.ToInt32(str);
                Console.WriteLine("Выберите цвет");
                Console.WriteLine("1 красный\n2 зеленый\n3 синий\n4 желтый");
                str = Console.ReadLine();
                int choiceColor = Convert.ToInt32(str);
                AddNewFigure(choiceFigure, choiceColor, figuresList);
                Console.WriteLine("Продолжить добавление фигур y/n");
                answer = Console.ReadLine();
            }
            figuresList.ShowAllFigures();
        }
    }
}
