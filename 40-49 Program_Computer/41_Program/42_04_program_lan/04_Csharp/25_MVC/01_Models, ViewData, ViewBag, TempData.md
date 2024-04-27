#csharp 

## Source
https://www.linkedin.com/pulse/aspnet-mvc-models-viewdata-viewbag-tempdata-explained-ervis-trupja-ytn7f/

## Model
### Single object
A `strongly typed` method and the recommended way for passing data. It allows for intelligent and compile-time checking.
```csharp
public class Url
    {
        public int Id { get; set; }
        public string OriginalLink { get; set; }
        public string ShortLink { get; set; }
        public int NrOfClicks { get; set; }
    }

```

```csharp
public class UrlController : Controller
    {
        public IActionResult Index()
        {
            var newUrl = new Url()
            {
                Id = 1,
                OriginalLink = "https://dotnethow.net",
                ShortLink = "dnh",
                NrOfClicks = 1
            };

            return View(newUrl);
        }
    }

```

```csharp
@model Url

<h4>@Model.OriginalLink</h4>
```

### list of object
```csharp
 public class UrlController : Controller
    {
        public IActionResult Index()
        {
            var newUrls = new List<Url>{....}
            return View(newUrls);
        }
    }
```
I
```csharp
@model List<Url>

@foreach(var link in @Model)
{
    <p>@link.OriginalLink</p>
}
```

## ViewData
A `dictionary object` for passing data as `key-value pairs`. It is loosely typed, requiring casting in the view and lacks compile-time checking.
```csharp
public class UrlController : Controller
    {
        public IActionResult Index()
        {
            ViewData["BlogPostUrl"] = "https://dotnethow.net"
            return View();
        }
    }
```

```csharp
<h4>@ViewData["BlogPostUrl"]</h4>
```

## ViewBag
Similar to `ViewData`, it provides `dynamic access to properties`. It is also loosely typed and lacks compile-time checking.
```csharp
public class UrlController : Controller
    {
        public IActionResult Index()
        {
            ViewBag.BlogPostUrl = "https://dotnethow.net"
            return View();
        }
    }
```

```csharp
<h4>@ViewData.BlogPostUrl</h4>
```

## TempData 
Used to pass data from the current controller to the next request. `TempData is backed by session state` and is useful in redirect scenarios.
```csharp
public class UrlController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Create()
        {
            ViewData["ViewDataMessage"] = "Success from ViewData!";
            ViewBag.ViewBagMessage = "Success from ViewBag!";
            TempData["TempDataMessage"] = "Success from TempData!";

            return RedirectToAction("Index");
        }
    }
```

```csharp
<h4>@ViewData["ViewDataMessage"]</h4>
<h4>@ViewBag.ViewBagMessage</h4>
<h4>TempData["TempDataMessage"]</h4>
```