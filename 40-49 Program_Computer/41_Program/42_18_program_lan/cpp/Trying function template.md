# Trying function template
###### tags: `learn cpp`
![](https://i.imgur.com/JccNLzn.png)

Function template is avoiding code repetition.
## create function template
```cpp=
template <typename T> 
T maximum(T a, T b);

template <typename T>
T multiply(T a, T b);

int main() {
    int a {10};
    int b {23};

    int *p_a {&a};
    int *p_b {&b};

    double c{34.7};
    double d{23.4};

    std::string e{"hello"};
    std::string f{"world"};

    std::cout << "max(int) : " << maximum(a, b) << std::endl; // int version created
    std::cout << "max(double): " << maximum(a, b) << std::endl; // double version created
    std::cout << "max(string): " << maximum(e, f) << std::endl; // string version created
    
    std::string s1{"hey"};
    std::string s2{"bro"};

    std::cout << "max(string): " << maximum(s1, s2) << std::endl;
    // std::cout << "multiply(string)" << multiply(s1, s2) << std::endl; // error

    auto result = maximum(p_a, p_b);
    std::cout << "result: " << *result << std::endl; //error. we are compare the address store in vars.
    return 0;
}

template <typename T> 
T maximum(T a, T b){
    return (a > b) ? a : b ; // a and b must support the > operator. Otherwise, hard Error.
}

template <typename T>
T multiply(T a, T b){
    return a * b;
}
```

![](https://i.imgur.com/B51DI3D.png)
