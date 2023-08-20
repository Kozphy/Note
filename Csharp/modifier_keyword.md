# modifier keyword

## static
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