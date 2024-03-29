#csharp 

## Source
https://microsoftlearning.github.io/APL-2002-develop-aspnet-core-consumes-api/Instructions/Labs/01-interact-with-an-api.html


```cmd
dotnet add package Swashbuckle.AspNetCore --version 6.5.0
```

## Add and configure swagger middleware
```csharp
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
```

```csharp
app.UseSwagger();
app.UseSwaggerUI();
```

## Swagger UI Endpoint
`http:<hostname>:<port>/swagger`.

