# Functions across Multiple Files: Compilation model revisited
###### tags: `learn cpp`

## what happen in compiler
![](https://i.imgur.com/QFHmsM0.png)

object is binary representation of content you have in translation unit.

![](https://i.imgur.com/fQVqtn8.png)
once we have object files they are going to be processed by what we call the linker and the linker is going to stitch them together and have one single binary file out of all these object files.

![](https://i.imgur.com/6INAEyP.png)

## implement multiple file
![](https://i.imgur.com/qwggW9r.png)

![](https://i.imgur.com/qYGx9B5.png)

![](https://i.imgur.com/pYLkQ5x.png)

### main.cpp
```cpp=
int main() {
    int maximum = max(134, 56);
    std::cout  << "max : " << maximum << std::endl;

    int minimum = min(134, 56);
    std::cout  << "min : " << minimum << std::endl;
    return 0;
}
```
### compare.h
```cpp=
int max(int a, int b); // Declaration
int min(int a, int b);
```
### compare.cpp
```cpp=
// Definition
int max(int a, int b) {
    if(a > b)
        return a;
    else 
        return b;
}
```
### some_other.cpp
```cpp=
// Definition
int max(int a, int b) {
    if(a > b)
        return a;
    else 
        return b;
}
```

