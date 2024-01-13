#csharp 

## Source
https://code-maze.com/csharp-records/

https://www.c-sharpcorner.com/article/record-types-in-c-sharp-103/#:~:text=The%20record%20types%20have%20built-in%20support%20for%20ToString,<property%20name>%20%3D%20<value>%2C%20<property%20name>%20%3D%20<value>%2C...%7D


## immutable properties
When we use `init` operator, the property can only be set `during initialization`.
Below is the syntax for defining Immutable properties.
```csharp
Public string FirstName { get; init;}
```

## What are Records?
1. **records use _value-based_ equality**
2. records is `immutable properties`.

- [reference equality vs value equality](reference%20equality%20vs%20value%20equality.md)

Two records are equal if:
- `Definitions` are equal (e.g same number/name of properties)
- `Values` in each of those definitions are equal

## Record Class
### Positional parameters syntax
```csharp
public record Employee(string EmployeeId, string FirstName, string LastName);
```

```csharp
public record Employee(string EmployeeId, string FirstName, string LastName)
{
    public string Designation {get; set;}
}
```

### initializing object
```csharp
Employee employee = new("E001", "John", "Deo");
```

```csharp
Employee employee = new("E001", "John", "Deo") { Designation = "Software Engineer" };
```

### Standard property syntax
```csharp
public record Employee
{
	public string EmployeeId {get; init;}
	public string FristName {get; init;}
	public string LantName {get; init;}
}
```

```csharp
public record Employee
{
    public string EmployeeId {get; init;}
    public string FirstName {get; init;}
    public string LastName {get; init;}
    public string Designation {get; set;}
}
```

### Initializing object
```csharp
Employee employee = new Employee()
{
	EmployeeId="E001",
	FirstName="John",
	LastName = "Deo"
};
```

```csharp
Employee employee = new Employee()
{
    EmployeeId = "E001",
    FirstName = "John",
    LastName = "Deo",
    Designation = "Software Engineer"
};
```

## Equality
Two records are equal if the `definitions` and the `values` are equal.
```csharp
public record Person
{
    public Person(string firstName, string lastName)
    {
        FirstName = firstName;
        LastName = lastName;
    }

    public string LastName { get; set; }
    public string FirstName { get; set; }
}
```

```csharp
public class Program
{
    public static void Main(string[] args)
    {
        var person1 = new Person("Joe", "Bloggs");
        var person2 = new Person("Joe", "Bloggs");
        var person3 = new Person("Jane", "Bloggs");

        Console.WriteLine($"Person1 == Person2? {person1 == person2}");
        Console.WriteLine($"Person1 == Person3? {person1 == person3}");

        Console.ReadKey();
    }
}
```

### Output
```csharp
Person1 == Person2? True
Person1 == Person3? False
```

## Positional Records (After initialize, we can't change property value)
```csharp
public record class Person(string FirstName, string LastName)
```
### initialize
```csharp
var person1 = new Person("Joe", "Bloggs");
var person2 = new Person("Joe", "Bloggs");
var person1 = new Person("Jane", "Bloggs");
```

## Cloning Records
- `Shallow cloning` (the copied object refer to the original object)
	- We use `MemberwiseClone()` to implement Shallow cloning.
- `Deep cloning` (`completely seperate`)
	-  We use `ICloneable` to implement Deep cloning.

### `with` operator for `Non-destructive mutation`
```csharp
ver person4 = person3 with {LastName = "Doe"};
Console.WriteLine(person4);
```

## Record Structures
### **Positional parameters syntax**
```csharp
public readonly record struct Employee(string EmployeeId, string FirstName, string LastName);
```

### **Initializing object**
```csharp
Employee employee = new("E001", "John", "Deo");
```

### **Standard property syntax**
```csharp
public readonly record struct Employee
{
    public string EmployeeId {get; init;}
    public string FirstName {get; init;}
    public string LastName {get; init;}
}
```

### **Initializing object**
```csharp
Employee employess = new Employee()
{
    EmployeeId = "E001",
    FirstName = "John",
    LastName = "Deo"
};
```

