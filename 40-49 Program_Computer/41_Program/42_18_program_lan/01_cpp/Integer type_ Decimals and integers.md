# Integer type: Decimals and integers
###### tags: `learn cpp`

# varaibles
- A named piece of memory that you use to store specific types of data
- init variable syntax struct `typename variable_name {initializer_value};`
## variable braced initialization
```cpp=
// Variable may contain random garbage value . WARNING
int elephant_count;

int lion_count{}; // Initializes to zero

int dog_count{10}; //Initializes to 10

int cat_count{15};

// Can use expression as initializer
int domesticated_animals {dog_count + cat_count};

// Won't compile, the expression in the braces uses undeclared variables
int bad_initialization {doesnt_exist1 + doesnt_exist2};

// 2.9 is of type doulbe, with a wider range than int.ERROR OR WARNING.
int narrowing_conversion {2.9};
```
## functional variable init
```cpp=
int apple_count(5);

int orange_count(10);

int fruit_count (app_count + orange_count);

int bad_initialization (doesnt_exist3 + doesnt_exist4);

// info lost. less safe than braced initializers
int narrowing_conversion_functional(2.9);
```

## Size of a type in memory
```cpp=
std::cout << "sizeof int : " << sizeof(int) << std::endl;
std::cout << "sizeof truck_count : " << sizeof(truck_count) << std::endl;

```

# int
- Stores decimals
- Typically occupies 4 bytes or more in memory

# integer Modifiers
![](https://i.imgur.com/rBmJp1D.png)
> n is the number of bits for a type in memory

![](https://i.imgur.com/CUT6oTX.png)

![](https://i.imgur.com/t4pfdvg.png)

> These modifiers only apply to integral types: those in which you can store decimal numbers