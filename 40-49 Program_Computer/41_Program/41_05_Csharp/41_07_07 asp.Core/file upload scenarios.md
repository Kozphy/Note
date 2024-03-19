#csharp 

## Source
[Upload files in ASP.NET Core | Microsoft Learn](https://learn.microsoft.com/en-us/aspnet/core/mvc/models/file-uploads?view=aspnetcore-6.0)

## File upload scenarios
### Buffering
The entire file is read into an [IFormFile](https://learn.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.http.iformfile). `IFormFile` is a C# representation of the file used to process or save the file.
- 



### Streaming
The file is received from a `multipart request` and directly processed or saved by the app.

### When to use Streaming
 If the size or frequency of file uploads is exhausting app resources, use streaming.

