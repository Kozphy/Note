# Declaring and Using References
###### tags: `learn cpp`

## Declaring and using references
```cpp=
// Declaring and using references
int int_value{45};
double double_value{33.65};

int& reference_to_int_value_1{int_value}; // Assign throught init
int& reference_to_int_value_2 = int_value; //Assign throught assignment
double& reference_to_double_value_1 {double_value};

// You have to declare and init in one statement
// int& some_reference; // Error

std::cout << "int_value: " << int_value << std::endl;
std::cout << "double_value: " << double_value << std::endl;
std::cout << "reference_to_int_value_1: " << reference_to_int_value_1 << std::endl;
std::cout << "reference_to_int_value_2: " << reference_to_int_value_2 << std::endl;
std::cout << "reference_to_double_value_1: " << reference_to_double_value_1 << std::endl;
std::cout << "&int_value: " << &int_value << std::endl;
std::cout << "&double_value: " << &double_value << std::endl;
std::cout << "&reference_to_int_value_1: " << &reference_to_int_value_1 << std::endl;
std::cout << "&reference_to_int_value_2: " << &reference_to_int_value_2 << std::endl;
std::cout << "&reference_to_double_value_1: " << &reference_to_double_value_1 << std::endl;
std::cout << "sizeof(int): " << sizeof(int) << std::endl;
std::cout << "sizeof(int&): " << sizeof(int&) << std::endl;
std::cout << "sizeof(reference_to_int_value_1): " << sizeof(reference_to_int_value_1) << std::endl;
```

## Modify data through original variable
```cpp=
// Modify data directly: changes reflect even in references
std::cout << std::endl;
std::cout << "Modifying data directly: " << std::endl;
double_value = 9.99;

// Print out after modifiecation of double_value
std::cout << "int_value: " << int_value << std::endl;
std::cout << "double_value: " << double_value << std::endl;
std::cout << "reference_to_int_value_1: " << reference_to_int_value_1 << std::endl;
std::cout << "reference_to_int_value_2: " << reference_to_int_value_2 << std::endl;
std::cout << "reference_to_double_value_1: " << reference_to_double_value_1 << std::endl;
std::cout << "&int_value: " << &int_value << std::endl;
std::cout << "&double_value: " << &double_value << std::endl;
std::cout << "&reference_to_int_value_1: " << &reference_to_int_value_1 << std::endl;
std::cout << "&reference_to_int_value_2: " << &reference_to_int_value_2 << std::endl;
std::cout << "&reference_to_double_value_1: " << &reference_to_double_value_1 << std::endl;
std::cout << "sizeof(int): " << sizeof(int) << std::endl;
std::cout << "sizeof(int&): " << sizeof(int&) << std::endl;
std::cout << "sizeof(reference_to_int_value_1): " << sizeof(reference_to_int_value_1) << std::endl;
```

