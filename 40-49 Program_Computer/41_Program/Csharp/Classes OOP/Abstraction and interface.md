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
## abstraction
- **Abstract classes** can contain both **abstract and non-abstract methods**.
```csharp


```

## interface
**Interfaces** can only contain **abstract methods**.
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