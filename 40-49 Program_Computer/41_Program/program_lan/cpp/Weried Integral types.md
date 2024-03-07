# Weried Integral types
###### tags: `learn cpp`

![](https://i.imgur.com/UPYa8hF.png)

![](https://i.imgur.com/9ppLTZs.png)

```cpp=
int main() {
    // Integral types less than 4 bytes in size
    // don't support arthmetic operations
    short int var1 {10};
    short int var2 {20};

    char var3 {40};
    char var4 {50};

    std::cout << "size of var1 : " << sizeof(var1) << std::endl;
    std::cout << "size of var2 : " << sizeof(var2) << std::endl;
    std::cout << "size of var3 : " << sizeof(var3) << std::endl;
    std::cout << "size of var4 : " << sizeof(var4) << std::endl;

    // conversion to int
    // The  same behavior if persent to other ooperators
    // like bitwise shift operators (>> and <<)
    auto result1 = var1 + var2;
    auto result2 = var3 + var4;

    std::cout << "size of result1 : " << sizeof(result1) << std::endl;
    std::cout << "size of result2 : "  << sizeof (result2) << std::endl;

    return 0;
}
```