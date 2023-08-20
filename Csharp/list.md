# list

## list create
```csharp
var names = new List<string> { "<name>", "Ana", "Felipe" };
foreach (var name in names)
{
  Console.WriteLine($"Hello {name.ToUpper()}!");
}
```

## add & remove
```csharp
var names = new List<string> { "<name>", "Ana", "Felipe" };
names.Add("Maria");
names.Add("Bill");
names.Remove("Ana");
foreach (var name in names)
{
  Console.WriteLine($"Hello {name.ToUpper()}!");
}
```

## Count == length
```csharp
var names = new List<string> { "<name>", "Ana", "Felipe" };
names.Add("Maria");
names.Add("Bill");
names.Remove("Ana");
foreach (var name in names)
{
  Console.WriteLine($"Hello {name.ToUpper()}!");
}

Console.WriteLine($"My name is {names[0]}.");
Console.WriteLine($"I've added {names[2]} and {names[3]} to the list.");

Console.WriteLine($"The list has {names.Count} people in it");
```

## indexOf()
```csharp
var names = new List<string> { "<name>", "Ana", "Felipe" };
var index = names.IndexOf("Felipe");
if (index != -1)
  Console.WriteLine($"The name {names[index]} is at index {index}");

var notFound = names.IndexOf("Not Found");
Console.WriteLine($"When an item is not found, IndexOf returns {notFound}");
```

## Sort()
```csharp
var names = new List<string> { "<name>", "Ana", "Felipe" };
names.Sort();
    foreach (var name in names)
    {
    Console.WriteLine($"Hello {name.ToUpper()}!");
    }
```


## fibonacciNumbers
```csharp
var fibonacciNumbers = new List<int> {1, 1};

var previous = fibonacciNumbers[fibonacciNumbers.Count - 1];
var previous2 = fibonacciNumbers[fibonacciNumbers.Count - 2];

fibonacciNumbers.Add(previous + previous2);

foreach(var item in fibonacciNumbers)
    Console.WriteLine(item);
```