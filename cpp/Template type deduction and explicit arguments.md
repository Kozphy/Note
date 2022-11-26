# Template type deduction and explicit arguments
###### tags: `learn cpp`
![](https://i.imgur.com/diWILiU.png)


```cpp=
template <typename T> T maximum(T a, T b);

int main() {
    int a {10};
    int b {23};
    double c{34.7};
    double d{23.4};
    std::string e{"hello"};
    std::string f{"world"};

    maximum(a, b); // int type deduced
    maximum(c,d); // double type deduced
    maximum(e,f); // string type deduced

    maximum<double>(c,d); // explicitly say that we want the double 
                        // version called
    maximum<double>(a, c); // works, these is implicit conversion from int to double

    // maximum<double>(a,e); // Error: can't convert std::string to double




    return 0;
}
template <typename T> 
T maximum(T a, T b){
    if (a>b)
        return a;
    return b;
}
```
