# C++ Functions
###### tags: `learn cpp`

![](https://i.imgur.com/VytXsP2.png)

## void function
![](https://i.imgur.com/Lp474Hi.png)

## implicit conversion in function
```cpp=
// implicit conversions in functions
char d{55};
char e{51};

double f{12.33};
double g{51.25};

std::cout << "Calling min function with char arguments: " << std::endl;

int minimun_number{std::min(d,e)}; // d, e  implicitly converted to int
std::cout << "min(" << static_cast<int>(d) << "," << static_cast<int>(e) << ") : "
<< minimun_number << std::endl;

// doubles will undergo an implicit narrowing conversion
// from double to int. Info after decimal point will be lost
std::cout << std::endl;
std::cout << "Calling min function with double arguments: " << std::endl;
minimun_number = std::min(f,g);
std::cout << "min(" << f << "," << g << ") : "
<< minimun_number << std::endl;
```


## argument scope
```cpp=
// Argument scope
double increment_multiply(double a, double b) {
    // Parameters passed this way are scoped localy in the function
    // Changes to them are not visible outside the function. What we 
    // have inside the function are actually COPIES of the arguments
    // passed to the function
    std::cout << "Inside function, before increment: " << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    double result = ((++a) * (++b));

    std::cout << "Inside function, after increment: " << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Returning the result
    return result;
}

int main() {
    // argument scope: Copies
    std::cout << "argument scope: COPIES " << std::endl;
    double h{3.00};
    double i{4.00};

    std::cout << "Outside function, before incement: " << std::endl;
    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;

    double incr_mult_result = increment_multiply(h,i);
    std::cout << "Outside function, before increment: " <<std::endl;
    std::cout << "h: " <<h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "incr_mult_result: " << incr_mult_result << std::endl;
    return 0;
}
```