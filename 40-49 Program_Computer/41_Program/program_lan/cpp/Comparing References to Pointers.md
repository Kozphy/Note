# Comparing References to Pointers
###### tags: `learn cpp`

## References vs pointers
![](https://i.imgur.com/v2uHugs.png)


## Declaration pointer and reference
```cpp=
// Declaration pointer and reference
std::cout << std::endl;
double double_value1 {12.34};

double &ref_double_value1{double_value1};

double  *p_double_value1{&double_value1};

std::cout << "double_value1: " << double_value1 << std::endl;
std::cout << "ref_double_value1: " << ref_double_value1 << std::endl;
std::cout << "p_double_value1: " << p_double_value1 << std::endl;
std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;
```

## Writing pointers and reference
```cpp=
// Writing pointers and reference 
std::cout << std::endl;
std::cout << "writing through pointer: " << std::endl;

*p_double_value1 = 15.44;

std::cout << "double_value1: " << double_value1 << std::endl;
std::cout << "ref_double_value1: " << ref_double_value1 <<std::endl;
std::cout << "p_double_value1: " << p_double_value1 << std::endl;
std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;

std::cout << std::endl;
std::cout << "writing through reference: " << std::endl;

ref_double_value1  = 18.44;

std::cout << "double_value1: " << double_value1 << std::endl;
std::cout << "ref_double_value1: " << ref_double_value1 <<std::endl;
std::cout << "p_double_value1: " << p_double_value1 << std::endl;
std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;
```

## Can't make a reference refer to something else
```cpp=
// Can't make a reference refer to something else
std:: cout << std::endl;
double double_value2{12.34};
double &ref_double_value2 {double_value2};
double other_double_value{100.23};

// it doesn't make ref_double_value2 reference to other_double_value
// It merely changes the value referenced by ref_double_value2 to 100.23
ref_double_value2 = other_double_value;
std::cout << "double_value2: " << double_value2 << std::endl;
std::cout << "&ref_double_value2: " << ref_double_value2 <<std::endl;
std::cout << "other_double_value: " << other_double_value << std::endl;

// If you change ref_double_value2 now, other_double_value stays the same
// proving that ref_double_value2 is not referencing other_double_value
ref_double_value2 = 333.33;
std::cout << "double_value2: " << double_value2 << std::endl;
std::cout << "&ref_double_value2: " << ref_double_value2 <<std::endl;
std::cout << "other_double_value: " << other_double_value << std::endl;
```

## A pointer can point somewhere else
```cpp=
// A pointer can point somewhere else
std::cout << std::endl;
std::cout << "A pointer can point somewhere else: " << std::endl;

p_double_value1 = &other_double_value;
std::cout << "double_value1: " << double_value1 << std::endl;
std::cout << "ref_double_value1: " << ref_double_value1 << std::endl;
std::cout << "p_double_value1: " << p_double_value1 << std::endl;
std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;
std::cout << "other_double_value: " << other_double_value << std::endl;

std::cout << std::endl;
std::cout << "Changing the now pointed to value: " << std::endl;

*p_double_value1 = 555.66;

std::cout << "double_value1: " << double_value1 << std::endl;
std::cout << "ref_double_value1: " << ref_double_value1 << std::endl;
std::cout << "p_double_value1: " << p_double_value1 << std::endl;
std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;
std::cout << "other_double_value: " << other_double_value << std::endl;
```


##  References are somewhat like const pointers
```cpp=
// References behave like constant pointers, but they have
// a much friendlier syntax as they don't require dereferencing
// to read and write through referenced data.
double *const const_p_double_value {&double_value};
// const_p_double_value = &other_double_value; //Error
*const_p_double_value = other_double_value;