# Template type by reference
###### tags: `learn cpp`
```cpp=
template <typename T>
const T &maximum(const T &a, const T &b);

int main() {
    double a {23.5};
    double b {51.2};

    std::cout << "Out - &a: " << &a << std::endl;
    double max1 = maximum(a,b);
    std::cout << "max: " << max1 << std::endl;
    return 0;
}

template <typename T>
const T &maximum(const T &a, const T &b){
    std::cout << "In - &a: " << &a << std::endl;
    return (a>b) ? a:b;
}
```

![](https://i.imgur.com/cuMITqb.png)
