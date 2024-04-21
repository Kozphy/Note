#csharp 

## Source
[oop - What is the difference between an interface and abstract class? - Stack Overflow](https://stackoverflow.com/questions/1913098/what-is-the-difference-between-an-interface-and-abstract-class)

|Interface|Abstract class|
|---|---|
|Interface support multiple implementations.|Abstract class does not support multiple inheritance.|
|Interface does not contain Data Member|Abstract class contains Data Member|
|Interface does not contain Constructors|Abstract class contains Constructors|
|An interface Contains only incomplete member (signature of member)|An abstract class Contains both incomplete (abstract) and complete member|
|An interface cannot have access modifiers by default everything is assumed as public|An abstract class can contain access modifiers for the subs, functions, properties|
|Member of interface can not be Static|Only Complete Member of abstract class can be Static|
## abstract and virtual
### abstract
- **Abstract classes** can contain both **abstract and non-abstract methods**.
- Derived classes **must override** these abstract methods to provide their own implementation.
- An abstract class is a blueprint for other classes.
- It `cannot be instantiated` directly; it serves as a base for derived classes.
### virtual
- A virtual method `has an initial implementation in the base class`.
- `Derived classes` have the **option to override** this method.
- Virtual methods allow late `binding (dynamic method resolution at runtime)`.
```csharp
using System;
 
public abstract class Animal
{
    public abstract string Sound { get; }
 
    public virtual void Move()
    {
        Console.WriteLine("Moving...");
    }
}
 
public class Cat : Animal
{
    public override string Sound => "Meow";
 
    public override void Move()
    {
        Console.WriteLine("Walking like a cat...");
    }
}
 
public class Dog : Animal
{
    public override string Sound => "Woof";
 
    public override void Move()
    {
        Console.WriteLine("Running like a dog...");
    }
}
 
class Program
{
    static void Main(string[] args)
    {
        Animal[] animals = new Animal[] { new Cat(), new Dog() };
 
        foreach (Animal animal in animals)
        {
            Console.WriteLine($"The {animal.GetType().Name} goes {animal.Sound}");
            animal.Move();
        }
    }
}
```

## interface
- An interface defines a contract for classes, ensuring that they adhere to a specific structure or behavior.
- It contains only method, property, event, and indexer declarations (no implementation).
- Classes that implement an interface must provide concrete implementations for all its members.
- Multiple inheritance is achieved through interfaces.
```csharp
public interface IShape
{
    double GetArea();
    double GetPerimeter();
}
```

### implement interface
```csharp
// implement interface
public class Rectangle : IShape
{
    public double Width { get; set; }
    public double Height { get; set; }

    public double GetArea()
    {
        return Width * Height;
    }

    public double GetPerimeter()
    {
        return 2 * (Width + Height);
    }
}
```