#csharp 

## virtual
If a method is declared as `virtual`, any class inheriting the method can implement its own version.
```csharp
class GraphicsClass
{
    public virtual void DrawLine() { }
    public virtual void DrawPoint() { }
}
```

## new
When you declare a method using `new`, you are `not overriding the base class method`; instead, you're creating a new method in the derived class with the same name as the base class method. This technique is called `method hiding`.

```csharp
class YourDerivedGraphicsClass : GraphicsClass
{
    public new void DrawRectangle() { }
}
```

## override
`override` is used to cover base class method.
```csharp
class YourDerivedGraphicsClass : GraphicsClass
{
    public override void DrawRectangle() { }
}
```