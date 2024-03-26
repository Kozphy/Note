# Size of object
###### tags: `learn cpp`

![](https://i.imgur.com/zYcbMo4.png)

## Boundary alignment
It is most compilers do when they have member variables of different types and member variables that have the size of four bytes in memory are going to be stored at memory locations that are multiples of four and because of this phenomenon we might have gaps between our memory if we have variables.

For example that are two bytes in memory and four bytes in memory and we will have gaps inside and the size of the object is will be slightly off the sum we might do for the sizes of our object.
![](https://i.imgur.com/7KXx2zn.png)

```cpp=
#include <iostream>
#include <string>

using namespace std;

/*
Boundary alignment:
    It is most compilers do when they have member variables of different types and member variables that have the size of four bytes in memory
    are going to be stored at memory locations that are multiples of four and because of this phenomenon we might have gaps between our memory if we have variables.
*/

class Dog{
    public:
        Dog() = default;
        void print_info(){};
        void print_something(){};
    private:
        size_t leg_count; // 8
        size_t arm_count; // 8
        int *p_age; // 8
};


int main() {
    
    Dog dog1;
    cout << "sizeof(size_t): " << sizeof(size_t) << endl;
    cout << "sizeof(int*): " << sizeof(int*) << endl;
    cout << "sizeof(Dog): " << sizeof(Dog) << endl;
    cout << "sizeof(dog1): " << sizeof(dog1) << endl;
    
    // string is storing our text here as const char *
    // and what we have is a pointer inside which probably have inside is a member variable which is a pointer.
    // So the sizeof(name) is counting for size of pointer but it's not sizeof what is pointed to.
    string name{"fdsiwerhfkldsaghklcvxworefsdhkkj!"};
    cout << "sizeof(name): " << sizeof(name) << endl;

    return 0;
}
```