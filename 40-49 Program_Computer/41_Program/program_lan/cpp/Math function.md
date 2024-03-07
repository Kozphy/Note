# Math function
###### tags: `learn cpp`

![](https://i.imgur.com/UvFjxAA.png)

## abs
```cpp=
#include <iostream>
#include <cmath>

int main() {
    double savings {-5000};
    float weight = 7.7;
    std::cout << "Abs of weight is : " << std::abs(weight) << std::endl;
    std::cout << "Abs of weight is : " << std::abs(savings) << std::endl;
}
```

## exp
```cpp=
    // exp : f(x) e ^ x, where e = 2.71828
    double exponential = std::exp(10);
    std::cout << "The exponential of 10 is : " << exponential << std::endl;
```