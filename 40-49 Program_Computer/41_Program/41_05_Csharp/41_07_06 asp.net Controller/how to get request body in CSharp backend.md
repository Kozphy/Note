#csharp 
```csharp
public class FetchController
{
    [HttpPost]
    public async Task Post()
    {
        using (var reader = new StreamReader(Request.Body))
        {
            var body = await reader.ReadToEndAsync();
            // Process the 'body' data as needed.
            // ...
        }
    }
}
```