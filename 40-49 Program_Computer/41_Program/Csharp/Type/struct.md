#csharp 

## Source
https://stackoverflow.com/questions/13049/whats-the-difference-between-struct-and-class-in-net

## What is struct
The struct is blueprints. It is `value type`.

```csharp
    public struct Coords
    {
        public double X { get; }
        public double Y { get; }
        public Coords(double x, double y) {
            this.X = x;
            this.Y = y;
        }
        public override string ToString() { return $"({X}, {Y})"}
    }
```
