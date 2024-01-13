#csharp 
## static
1. Use the `static` modifier to declare a static member, which belongs to the type itself rather than to a specific object. 
2. The `static` modifier can be used to declare `static` classes. In classes, interfaces, and structs, you may add the `static` modifier to fields, methods, properties, operators, events, and constructors. 
3. The `static` modifier can't be used with `indexers or finalizers`.
```csharp
public class MyBaseC
{
    public struct MyStruct
    {
        public static int x = 100;
    }
}
// To refer to the static member x, use the fully qualified name, MyBaseC.MyStruct.x,
// unless the member is accessible from the same scope:
Console.WriteLine(MyBaseC.MyStruct.x);
```

## async
```csharp
public async Task<int> ExampleMethodAsync()
{
    string contents = await httpClient.GetStringAsync(requestUrl);
    //...
}
```