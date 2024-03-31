# Return from function
###### tags: `learn cpp`

![](https://i.imgur.com/GAG0Rzf.png)

## Returning from function (default is by value)
```cpp=
int sum(int a, int b){
    int result = a + b;
    std::cout << "In: &result(int): " << &result << std::endl;
    return result
}

int main(int argc, char **argv)
{
    int a {34};
    int b {16};
    
    int result = sum(a, b);
    std::cout << "Out: &result(int): " << &result << std::endl;
    std::cout << "sum: " << result << std::endl;
    return 0;
}
```

## Compiler optimizations to return by reference(GOOD for you)
Compiler will auto return by reference to avoid unnecessary copies if the size of parameter is too big.
```cpp=
// Compiler optimizations to return by reference
std::string add_strings(std::string str1, std::string str2){
    std::string result = str1 + str2;
    std::cout << "In : &result(std::string) : " << &result << std::endl;
    return result;
}

int main() {
    std::string str_result = add_strings(std::string("Hello"), std::string(" World!"));
    std::cout << "Out: &result(std::string): " << &str_result << std::endl;
    std::cout << "str_result: " << str_result << std::endl;
    return 0;
}
```

