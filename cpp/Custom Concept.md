# Custom Concept
###### tags: `learn cpp`
## Building custom concept
```cpp
// Different ways to build concepts
template <typename T>
concept MyIntegral =  std::is_integral_v<T>;

template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b; // Just makes sure the syntax is valid
};

template <typename T>
concept Incrementable = requires (T a) {
    a+=1;
    ++a;
    a++;
};


```
## using custom concept
```cpp
// using custom concepts
// Syntax1
template <typename T>
requires MyIntegral<T>
T add_1(T a, T b){
    return a + b;
}

// Syntax2
template <MyIntegral T>
T add_2(T a, T b){
    return a + b;
}

auto add_3(MyIntegral auto a, MyIntegral auto b){
    return a + b;
}
```