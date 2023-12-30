#csharp 
## Source
https://www.c-sharpcorner.com/article/boxing-and-unboxing-in-C-Sharp/#:~:text=Boxing%20and%20unboxing%20in%20C%23%20allows%20developers%20to,a%20value%20type%20is%20called%20unboxing%20in%20C%23.

## Boxing
convert value type -> reference type

## Unboxing
convert reference type -> value type


```csharp
1. class Test  
2. {  
3.     static void Main()  
4.     {  
5.         int i = 1;  
6.         object o = i; // boxing  
7.         int j = (int)o; // unboxing  
8.     }  
9. }
```

