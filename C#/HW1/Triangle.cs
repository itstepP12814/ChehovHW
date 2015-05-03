using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//d=sqrt
namespace ConsoleApplication
{
    class Program
    {
        public struct Point{
            public Point(int a, int b)
            {
                x = a;
                y = b;
            }
            public int x;
            public int y;
        }
        public class Triangle
        {
            public Triangle(Point _a, Point _b, Point _c)
            {
                a = _a; b = _b; c = _c;
            }
            public double GetPerimeter()
            {
                ab = Math.Sqrt(Math.Pow((b.x - a.x), 2) + Math.Pow((b.y - a.y), 2));
                bc = Math.Sqrt(Math.Pow((c.x - b.x), 2) + Math.Pow((c.y - b.y), 2));
                ca = Math.Sqrt(Math.Pow((a.x - c.x), 2) + Math.Pow((a.y - c.y), 2));
                perimeter=ab+bc+ca;
                return perimeter;
            }
            public double GetSquare()
            {
                if(perimeter==0) GetPerimeter();
                double p=perimeter/2;
                square=Math.Sqrt(p*(p-ab)*(p-bc)*(p-ca));
                return square;
            }
            Point a, b, c;//вершины треугольника
            double ab, bc, ca;//стороны
            double perimeter, square;
        }

        static void Main(string[] args)
        {
           Triangle triangle=new Triangle(new Point (4,7), new Point (8,14), new Point (12, 7));
           Console.WriteLine("Периметр треугольника: {0}\nПлощадь: {1}", triangle.GetPerimeter(), triangle.GetSquare());
        }
    }
}
