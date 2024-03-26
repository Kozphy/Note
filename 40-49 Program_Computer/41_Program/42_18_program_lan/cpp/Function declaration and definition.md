# Function declaration and definition
###### tags: `learn cpp`

![](https://i.imgur.com/ltb16o5.png)

![](https://i.imgur.com/s6oHQ0d.png)

![](https://i.imgur.com/spxqXKE.png)
```cpp=
// Function Declaration
int max(int a, int b);
int min(int a, int b);


int main() {
    int a{3};
    int b{4};

    std::cout << "max(" << a << "," << b << ") : " << max(a, b) << std::endl;
    return 0;
}

// Function definition or implementation
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
```