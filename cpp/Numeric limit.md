# Numeric limit
###### tags: `learn cpp`

![](https://i.imgur.com/ekSAFlG.png)

![](https://i.imgur.com/WVR6FdT.png)

![](https://i.imgur.com/nulpy7a.png)

![](https://i.imgur.com/klUL2JV.png)

```cpp=
#include <iostream>
#include <limits>

int main() {
    std::cout << "The range for short is from " << std::numeric_limits<short>::min() << " to "
    << std::numeric_limits<short>::max() << std::endl;
    
    std::cout << "The range for unsigned short is from " << std::numeric_limits<unsigned short>::min() << " to "
    << std::numeric_limits<unsigned short>::max() << std::endl;

    std::cout << "The range for int is from " << std::numeric_limits<int>::min() << " to "
    << std::numeric_limits<int>::max() << std::endl;


    std::cout << "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to "
    << std::numeric_limits<unsigned int>::max() << std::endl;
}
```