# Template Concept
###### tags: `learn cpp`

![](https://i.imgur.com/TWXHJcl.png)

![](https://i.imgur.com/1gQjb2d.png)

![](https://i.imgur.com/DqO75PT.png)

## An alternative to static asserts and type traits
```cpp=
template <typename T>
void print_number(T n){
    static_assert(std::is_integral<T>::value, "Must pass in an integral aurgument");
    std::cout << "n : " << n << std::endl;
}
```

## Syntax1
```cpp=
// Syntax1
template <typename T>
requires std::integral<T>
T add(T a, T b){
    return a + b;
}
```
### calling
```cpp=
int main() {
    char a_0{10} ;
    char a_1{20};

    auto result_a = add(a_0, a_1);
    std::cout << "result_a: " << static_cast<int>(result_a) << std::endl;

    int b_0{11};
    int b_1{5};
    auto result_b = add(b_0,b_1);
    std::cout << "result_b: " << result_b << std::endl;

    double c_0 {11.1};
    double c_1 {1.9};
    // auto result_c = add(c_0, c_1); // Error std::integral concept not satisfied.
    return 0;
}
```

## Syntax1 with type traits
```cpp=
// Syntax1 using type traits
template <typename T>
requires std::is_integral_v<T> // Using a type trait
T add2(T a, T b) {
    return a + b;
}
```

## Syntax2
```cpp=
template <std::integral T>
T add (T a, T b){
    return a + b;
}
```

## Syntax3
```cpp=
auto add (std::integral auto a, std::integral auto b){
    return a + b;
}
```

## Syntax 4
```cpp=
template <typename T>
T add5(T a, T b) requires std::integral<T>{
    return a + b;
}
```