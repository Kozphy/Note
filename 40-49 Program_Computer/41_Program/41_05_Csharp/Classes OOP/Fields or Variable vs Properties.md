#csharp 

## Fields/Variables vs property
- **Fields/Variables** are variables of any type declared directly in a class. They `can be accessed directly` by the class or through an instance of the class. Fields can be public, private, protected, or internal.
- **Properties** are class members that provide an abstraction to `set (write) and get (read)` the value of a private field. Properties are declared using the `get` and `set` keywords. They can be used to validate data before setting it or to perform some action when getting or setting the value of a field. Properties can be public, private, protected, or internal.
```csharp
class Person
{
  private string name; // field

  public string Name   // property
  {
    get { return name; }   // get method
    set { name = value; }  // set method
  }

	// Auto-implemented properties.
	public string Name { get; set; }
}
```

