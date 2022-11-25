# lambda Function
###### tags: `learn cpp`

![](https://i.imgur.com/zef5GxP.png)

![](https://i.imgur.com/9ohEjEn.png)

![](https://i.imgur.com/Nl9MtsH.png)


## lambda takes parameters
```cpp=
// lambda takes parameters
[](double a, double b){
    std::cout << "a + b: "<< (a + b)<< std::endl;
}(12.1, 5.7);
```

## lambda function that return something
```cpp=
// lambda function that return something
auto result = [](double a, double b){
    return (a + b);
}(12.1, 5.7);
std::cout << "result: " << result << std::endl;
```
## Specify return type explicitly 
```cpp=
// Specify return type explicitly 
auto result1 = [](double a, double b) -> double {
    return (a + b);
}(12.1, 5.7);
std::cout << "result: " << result << std::endl;
```

## Capture list
```cpp=
// Capture lists
double a{10};
double b{20};
auto funcs = [a,b](){
    std::cout << "a + b: " << a + b << std::endl;
};
funcs();
```

## capture by value
```cpp=
// Capture by value: what we have in lambda function is a copy
int c{42};

auto func2 = [c](){
    std::cout << "Inner value: " << c << std::endl;
};
for(size_t i{}; i < 5; ++i){
    std::cout << "Outer value: "<< c<< std::endl;
    func2();
    ++c;
}
```
## capturing by reference
```cpp=
    // Capturing by reference: Working on the original outside value
    std::cout << std::endl;
    int c1{42};

    auto func3 = [&c1](){
        std::cout << "Inner value: " << c1 << std::endl;
    };

    for(size_t i{}; i< 5; ++i){
        std::cout << "Outer value: " << c1<< std::endl;
        func3();
        ++c1;
    }
```

## Capture all in context
### Captureing everything by value
```cpp=
// Captureing everything by value
std::cout << std::endl;
int c2{42};
auto func4 = [=](){
    std::cout << "Inner value: " << c2 << std::endl;
};
for(size_t i{}; i<5; ++i){
    std::cout << "Outer value: " << c2 << std::endl;
    func4();
    ++c2;
}
```

### Captureing everything by reference
```cpp=
// Captureing everything by reference
std::cout << std::endl;
int c3{42};
auto func5 = [&](){
    std::cout << "Inner value: " << c3 << std::endl;
};
for(size_t i{}; i< 5; ++i){
    std::cout << "Outer value: " << c3 << std::endl;
    func5();
    ++c3;
}
```