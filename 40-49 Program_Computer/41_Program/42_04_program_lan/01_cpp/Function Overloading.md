# Function Overloading
###### tags: `learn cpp`
## what is function overload
The function overload is a mechanism. We can set up multiple functions with the same name to make our code easier to work with.
## max() overload
```cpp=
int max(int a, int b){
    return (a>b)? a : b;
}

double max(double a, double b){
    return (a>b)? a : b;
}

std::string_view max(std::string_view a, std::string_view b){
    return (a>b)? a : b;
}


double max(double a, int b){
    return a;
}

/*
// Can't overload on the return type
double max(int a, int b){
    return (a>b)?a:b;
}
*/
```
### Calling
```cpp=
int main() {
    int int_value1{41};
    int int_value2{29};

    double double_v1{47.2};
    double double_v2{55.01};

    std::string_view first{"Hello"};
    std::string_view second{"World"};

    std::cout << "max (" << int_value1 << "," << int_value2 << ") : "
    << max(int_value1, int_value2) << std::endl;

    std::cout << "max (" << 5 << "," << 7 << ") : "
    << max(5,7) << std::endl;

    std::cout << "max (" << double_v1 << "," << double_v2 << ") : "
    << max(double_v1, double_v2) << std::endl;

    std::cout << "max (" << first << "," << second << ") : "
    << max(first,second)<< std::endl;

    std::cout << "max (dog,cat): " << max("dog", "cat")<< std::endl;

    std::cout << "max( " << double_v1 << "," << int_value1 << " ) : "
    << max(double_v1, int_value1) << std::endl;
    return 0;
}
```