using System;
//  ПРИМЕР РАЗНИЦЫ МЕЖДУ СОКРЫТИЕМ ИМЕН И ПЕРЕОПРЕДЕЛЕНИЕМ ВИРТУАЛЬНОГО МЕТОДА
/* Пара правил. 1)для виртуального метода вызывается метод, соответствующий типу объекта, на который имеется ссылка
 * 2) для невиртуального метода, вызывается метод, соотвутствующий типу самой ссылки.
 * при сокрытии имени метода в дочернем классе, метод дочернего класса, будет вызываться только в случае,
 * когда вызов идет от объекта именно дочернего класса. Т.е когда объект дочернегно класса, записан с типом ссылки
 * базового класса, сокрытый метод вызовется для базового, а вот переопредлеленный уже для дочернего.
 * Выгода сокрытия в том, что таким образом можно изменить функционал метода, не помеченного в родительском классе как virtual.
 */
namespace ConsoleApplication46
{
    class Program
    {
        static void Main()
        {
            Animal animal = new Dog();
            animal.GetName();
            animal.MakeSound();
            Dog dog = new Dog();
            dog.GetName();
        }
    }

    class Animal
    {
        public void GetName()
        {
            Console.WriteLine("I'm an animal");
        }

        public virtual void MakeSound()
        {
            Console.WriteLine("boooo");
        }
    }

    class Dog : Animal
    {
        public new void GetName()//сокрытие метода базового класса
        {
            Console.WriteLine("I'm a dog");
        }

        public override void MakeSound()//переопределение виртуального метода
        {
            Console.WriteLine("Hrrrragh");
        }
    }
}
