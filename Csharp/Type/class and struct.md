#csharp 

## Source
https://stackoverflow.com/questions/13049/whats-the-difference-between-struct-and-class-in-net

## **Classes Only:**

- Can support inheritance
- Are reference (pointer) types
- The reference can be null
- Have memory overhead per new instance

## **Structs Only:**

- Cannot support inheritance
- Are value types
- Are passed by value (like integers)
- Cannot have a null reference (unless Nullable is used)
- Do not have a memory overhead per new instance - unless 'boxed'
- sealed type.

## **Both Classes and Structs:**

- Are compound data types typically used to contain a few variables that have some logical relationship
- Can contain methods and events
- Can support interfaces