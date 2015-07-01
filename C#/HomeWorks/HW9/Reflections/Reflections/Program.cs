using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
/*класс 1 это класс,класс2 енум, класс3 это класс, класс 4 делегат*/
namespace Reflections
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Assembly complexLib = Assembly.LoadFrom(@"D:\Dropbox\_PROJECTS\Reflections\ComplexLib.dll");
                Assembly initializerLib = Assembly.LoadFrom(@"D:\Dropbox\_PROJECTS\Reflections\InitializerLib.dll");

                Type[] types = complexLib.GetTypes();
                // Type[] types = initializerLib.GetTypes();
                foreach (Type t in types)
                {
                    Console.WriteLine("Class Name:{0} BaseType{1}", t.Name, t.BaseType);

                    ConstructorInfo[] ci = t.GetConstructors(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                    foreach (ConstructorInfo c in ci)
                    {
                        Console.WriteLine("Constructor: Name:{0} Public:{1}", c.Name, c.IsPublic);
                    }

                    MethodInfo[] mi = t.GetMethods(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                    foreach (MethodInfo m in mi)
                    {
                        Console.WriteLine("Method:{0} Public:{1} Return:{2}", m.Name, m.IsPublic, m.ReturnType);

                    }

                    MemberInfo[] members = t.GetMembers();
                    foreach (MemberInfo member in members)
                    {
                        Console.WriteLine("Member: Name:{0} Type:{1}", member.Name, member.MemberType);
                    }

                }
                ///////////////////////////InitializerLib//////////////////////////////////////////////////////////////////////////////////////
                Type _initializer = initializerLib.GetTypes()[0];
                ConstructorInfo _initializerCi = _initializer.GetConstructors(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic)[0];
                ConstructorInfo _initializerCi2 = _initializer.GetConstructors(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic)[1];
                object _initializerObject = _initializerCi.Invoke(BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic,
                    null, new object[] { 670, 1, "lol" }, null);


                ///////////////////////////SuperSecretClass3////////////////////////////////////////////////////////////////////////////////
                Type _superSecretClass3 = complexLib.GetTypes()[0];
                ConstructorInfo _ctor = _superSecretClass3.GetConstructor(new Type[] { });
                object _superSecretClass3Object = _ctor.Invoke(new object[] { });
                MethodInfo _superSecretClass3MainMetod = _superSecretClass3.GetMethod("MainMetod",
                    BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                MethodInfo _superSecretClass3Initialize = _superSecretClass3.GetMethod("Initialize",
                    BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                Console.WriteLine(_superSecretClass3Initialize.Invoke(_superSecretClass3Object, new object[] { _initializerObject }));
                Console.WriteLine(_superSecretClass3MainMetod.Invoke(_superSecretClass3Object, new object[] { new Random(50) }));

                ///////////////////////SuperSecretClass1//////////////////////////////////////////////////////////////////////////////////
                Type _superSecretClass1 = complexLib.GetTypes()[1];
                ConstructorInfo _ctorSuperSecretClass1 = _superSecretClass1.GetConstructor(new Type[] { });
                object _superSecretClass1Object = _ctorSuperSecretClass1.Invoke(new Type[] { });

                MethodInfo _superSecretClass1MainMetod = _superSecretClass1.GetMethod("MainMetod",
                    BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                MethodInfo _superSecretClass1Initialize = _superSecretClass1.GetMethod("Initialize",
                    BindingFlags.DeclaredOnly | BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                Console.WriteLine(_superSecretClass1Initialize.Invoke(_superSecretClass1Object, new object[] { _initializerObject }));
                Console.WriteLine(_superSecretClass1MainMetod.Invoke(_superSecretClass1Object, new object[] { }));

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }
    }
}
