#csharp 

## Source
https://www.c-sharpcorner.com/article/http-methods-in-net-core/#:~:text=GET%3A%20Used%20to%20retrieve%20information,without%20changing%20the%20server's%20state.

## Http methods
1. **GET:** Used to retrieve information or data from the server. It is a safe and idempotent method, meaning it should not have any side effects on the server and can be repeated multiple times without changing the server's state.
	- An `idempotent` element of a set does not change in value when multiplied by itself.
1. **POST:** Data is sent to the server for processing. It is frequently used to create new server resources. POST, unlike GET, is not idempotent, as multiple requests may result in the generation of many resources.
2. **PUT:** Used to update or replace a resource on the server. It is idempotent in the sense that several identical PUT requests should produce the same results as a single request..
3. **PATCH:** Similar to PUT, PATCH is used to update a resource. However, while PUT typically replaces the entire resource, PATCH applies partial modifications. It is also idempotent.
4. **DELETE:** Used to request that a resource be removed from the server. Like GET, DELETE is also idempotent.

## Handling Http methods in .net core
```csharp
using Microsoft.AspNetCore.Mvc;

[Route("api/[controller]")]
[ApiController]
public class MyController : ControllerBase
{
    [HttpGet]
    public IActionResult Get()
    {
        // Logic to retrieve and return data
    }

    [HttpPost]
    public IActionResult Post([FromBody] MyModel model)
    {
        // Logic to create a new resource using the provided data
    }

    [HttpPut("{id}")]
    public IActionResult Put(int id, [FromBody] MyModel model)
    {
        // Logic to update the resource with the specified ID
    }

    [HttpDelete("{id}")]
    public IActionResult Delete(int id)
    {
        // Logic to delete the resource with the specified ID
    }
}
```

