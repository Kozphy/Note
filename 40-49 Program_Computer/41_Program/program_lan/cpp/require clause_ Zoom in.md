# require clause: Zoom in
###### tags: `learn cpp`

![](https://i.imgur.com/uEtVsUf.png)
## Simple requirement: Expressions only checked for valid syntax
```cpp
template <typename T>
concept TinyType = requires(T t){
    sizeof(T) <= 4; // Simple requirement: Only checks syntax
};
TinyType auto add(TinyType auto a, TinyType auto b) {
    return a + b;
}
```

## Nested requirement
```cpp
template <typename T>
concept TinyType1 = requires(T t){
    sizeof(T) <=4; // Simple requirement: Only checks syntax
    requires sizeof(T) <= 4; // Nested requirement: checks the if the expression is true
};

TinyType1 auto add1(TinyType1 auto a, TinyType1 auto b){
    return a + b;
}
```

## Compound requirement
```cpp
template <typename T>
concept Addable = requires(T a, T b){
    { a + b } -> std::convertible_to<int>;
};

Addable auto add2( Addable auto a, Addable auto b){
    return a + b;
}
```

## use 
```cpp
int main() {
    double x{67};
    double y{56};

    auto result = add(x, y);
    std::cout << "result: " << result << std::endl;
    std::cout << "sizeof(result): " << sizeof(result) << std::endl;
    // add1(x, y); // Fail
    std::string a{"hello"};
    std::string b{"world"};
    auto result2 = add2(a, b);
    std::cout << "result2: " << result2 << std::endl;
    std::cout << "sizeof(result2): " << sizeof(result2) << std::endl;
    
    
    return 0;
}
```