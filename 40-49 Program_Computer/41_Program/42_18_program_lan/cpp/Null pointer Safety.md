# Null pointer Safety
###### tags: `learn cpp`

![](https://i.imgur.com/LpKSOxA.png)

## Solution 1
```cpp=
int *p_number{};

if(!(p_number==nullptr)){
    std::cout << "p_number points to a VALID address: " << p_number << std::endl;
}else{
    std::cout << "p_number points to an INVALID address." << std::endl;
}
```
## Solution 2
```cpp=
if(p_number){
    std::cout << "p_number points to a VALID address: " << p_number << std::endl;
}else{
    std::cout << "p_number points to an INVALID address." << std::endl;
}
```

## Calling delete on a pointer containing nullptr
```cpp=
// Calling delete on a pointer containing nullptr
int *p_number1{};

delete p_number1; /*
                    This won't cause any problem 
                    if p_number1 contains nullptr
                */

// So no need to overdo something like
if (p_number1){
    delete p_number1;
    p_number1 = nullptr;
}
```

