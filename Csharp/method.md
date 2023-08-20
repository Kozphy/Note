# csharp method
```csharp
using System;

namespace C_Sharp_begin
{
    class Program
    {
        //程序入口
        static void Main(string[] args)
        {
            int cubedNumber = cube(5);
            Console.WriteLine(cubedNumber);
            SayHi("Tom",33);
            SayHi("John",56);
            SayHi("Mike",12);
            Console.WriteLine(cube(5));
            Console.ReadLine();
        }
        // create method
        static void SayHi(string name, int age)
        {
            Console.WriteLine($"Hello {name} you are {age}");
        }

        static int cube(int num) 
        {
            int result = num * num * num;
            return result;
        }
    }
}
```