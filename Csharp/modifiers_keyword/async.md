#csharp 
## async
```csharp
public async Task<int> ExampleMethodAsync()
{
    string contents = await httpClient.GetStringAsync(requestUrl);
    //...
}
```