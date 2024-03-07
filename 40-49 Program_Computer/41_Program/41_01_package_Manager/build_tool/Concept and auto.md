# Concept and auto
###### tags: `learn cpp`


```cpp=
// Concepts and auto
// This syntax contrains the auto parameters you pass in
// to comply with the std::integral concept
std::integral auto add(std::integral auto a, std::integral auto b) {
    return a + b;
}
```

```cpp=
int main() {
    // Constraint declared auto var
    std::integral auto x = add(10, 20);
    // std::floating_point auto x = add(10, 20); // Compiler error
    std::cout << "x: " << x << std::endl;

    // std::integral auto y = 7.7;
    std::floating_point auto y = 7.7;
    std::cout << "y: " << y << std::endl;
    
    return 0;
}
```