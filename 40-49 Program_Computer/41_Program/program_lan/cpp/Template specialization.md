# Template specialization
###### tags: `learn cpp`

```cpp=
#include <iostream>
#include <string>
#include <cstring>

// Function template
template <typename T> T maximum(T a, T b);
// Template specialization
template <>
const char *maximum<const char*> (const char *a, const char *b);

int main() {
    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    std::string e{"hello"};
    std::string f("world!");

    int max_int = maximum(a, b); // int type deduced
    int max_double = maximum(c,d);
    std::string max_str = maximum(e,f); 

    const char *g{"wild"};
    const char *h{"animal"};

    // The following will use template specialization function
    std::cout << "max(const char*): " << maximum(g,h) << std::endl;
    return 0;
}

template <typename T> T maximum(T a, T b){
    return (a>b)? a : b;
}

template <>
const char *maximum<const char*>(const char *a, const char *b) {
    return (std::strcmp(a,b) > 0) ? a:b;
}
```