#csharp 
## Source
[Value Type and Reference Type (tutorialsteacher.com)](https://www.tutorialsteacher.com/csharp/csharp-value-type-and-reference-type)

## Value Type
- bool
- byte
- char
- decimal
- double
- enum
- float
- int
- long
- sbyte
- short
- struct
- uint
- ulong
- ushort
```csharp
namespace CshAlgo.practice.value_ref_pointer_p
{
    internal class PassByValue
    {
        public static void Start() {
            int originValue = 10;

            Console.WriteLine($"originValue: {originValue}");
            PassByValue pbv = new PassByValue();
            pbv.PassValue(originValue);

            Console.WriteLine($"after pass by value originValue is: {originValue}");
        }

        private void PassValue(int v) {
            v = 30;
            Console.WriteLine($"Value inside method: {v}");
        }
    }
}
```

## Reference Type

```csharp
namespace CshAlgo.practice.value_ref_pointer_p
{
    internal class PassByReference
    {
        public static void Start()
        {
            int originValue = 10;

            Console.WriteLine($"originValue: {originValue}");

            PassReference(ref originValue);

            Console.WriteLine($"after pass by reference originValue is: {originValue}");
        }

        private static void PassReference(ref int v)
        {
            v = 30;
            Console.WriteLine($"Value inside method: {v}");
        }
    }
}
```

## Pointer Type
[Pointers In C# (c-sharpcorner.com)](https://www.c-sharpcorner.com/article/pointers-in-C-Sharp/)
```csharp
namespace CshAlgo.practice.value_ref_pointer_p
{
    internal class PassByPointer
    {
        public unsafe static void Start()
        {
            int originValue = 10;
            int* originPointer = &originValue;

            Console.WriteLine($"originValue: {originValue}");

            PassPointer(originPointer);

            Console.WriteLine($"after pass by pointer originValue is: {originValue}");
        }

        private unsafe static void PassPointer(int* v)
        {
            *v = 30; // dereference and assign
            Console.WriteLine($"Value inside method: {*v}");
        }
    }
}
```