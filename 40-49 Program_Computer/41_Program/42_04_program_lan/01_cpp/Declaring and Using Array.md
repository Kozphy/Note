# Declaring and Using Array
###### tags: `learn cpp`

![](https://i.imgur.com/PUjH1pD.png)

![](https://i.imgur.com/vwlJjUl.png)

# Declare and init
```cpp=
#include <iostream>

int main() {
    // Declare
    int scores[10]; // An array store 10 Integers
    
    for(size_t i{0} ; i < 10 ; ++i){
        scores[i] = i*3;
    }

    for(size_t i{0}; i < 10; ++i){
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    // Out of bounds is garbage data
    std::cout << scores[11] << std::endl;

    // Declar and initialize
    std::cout << std::endl;
    double salaries[5]{12.7, 7.5, 13.2, 8.1, 9.3};

    for (size_t i{0}; i < 5; ++i){
        std::cout << "salary[" << i << "] : " << salaries[i] << std::endl;
    }

    // Array init : Omitting elements
    // if you don't init all elements, those you leave out
    //are init to 0
    std::cout << std::endl;

    std::cout << std::endl;
    int families[5]{12, 7, 5};

    for (size_t i{0}; i < 5; ++i){
        std::cout << "families[" << i << "] : " << families[i] << std::endl;
    }

    // Array declare: Omit size
    std::cout << std::endl;
    // compiler will auto detect
    int class_sizes[]{10,12,15,11,18,17};
    // ragne base for loop
    for (auto value : class_sizes) {
        std::cout << "value : " << value << std::endl;
    }

    // Constant array
    std::cout << std::endl;
    const int multipliers []{20, 30, 15};
    // multipliers[1] = 20; // Can't change elements of a const array: Error
    
    // Operation an data stored in arrays
    std::cout << std::endl;
    int sum{0};

    for(int element : scores) {
        sum += element;
    }

    std::cout << "Score sum : " << sum << std::endl;
    return 0;
}
```