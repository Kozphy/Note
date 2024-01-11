#visual_studio 

## Source
https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/xmldoc/recommended-tags

## xml comment
type `///` will generate xml comment in visual studio.
```csharp
/// <summary>
/// This method returns the sum of two integers.
/// </summary>
/// <param name="a">The first integer to add.</param>
/// <param name="b">The second integer to add.</param>
/// <returns>The sum of <paramref name="a"/> and <paramref name="b"/>.</returns>
public int Add(int a, int b)
{
    return a + b;
}
```