#csharp 

## init
```csharp
List<int> numbers = null;
int? a = null;
```
## `??` null-coalescing operator
The null-coalescing operator `??` returns the value of its left-hand operand if it isn't `null`; otherwise, it evaluates the right-hand operand and returns its result.

```csharp
Console.WriteLine((a is null)); // expected: true
Console.WriteLine((a ?? 3)); // expected: 3 since a is still null 
```

## `??=` null-coalescing assignment operator
The null-coalescing assignment operator `??=` assigns the value of its right-hand operand to its left-hand operand only if the left-hand operand evaluates to `null`.
```csharp
(numbers ??= new List<int>()).Add(5);
numbers.Add(10);
string resStr = string.Join(" ", numbers); // output: 5, 10
Console.WriteLine(resStr);

Console.WriteLine((numbers is null)); // expected: false       
```