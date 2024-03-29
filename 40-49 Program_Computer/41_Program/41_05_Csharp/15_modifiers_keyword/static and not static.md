#csharp 

## Source
https://stackoverflow.com/questions/1276333/c-sharp-what-is-the-different-between-static-class-and-non-static-i-am-talking

## static class 
- You cannot create instances from it. 
- `static class` cannot contain `non-static members`.
- It cannot be inherited.
- sealed (can't inheritance)
```csharp
using ConsoleApp2.practice.static_p;

internal class Program
{
    static void Main(string[] args)
    {
        Statics.Start();
    }
}
```

```csharp
namespace ConsoleApp2.practice.static_p
{
    internal class Statics
    {
        public static int bookCount = 0;

        public static void Start() { 
            StaticModifier();
        }

        private static void StaticModifier()
        {
            Statics s = new Statics();
            Console.WriteLine(bookCount);
            Console.WriteLine(s.getBookCount());
        }

        public int getBookCount()
        {
            return bookCount;
        }
    }
}
```

