# Dynamic Memory Allocation
###### tags: `learn cpp`
## How we've used pointers so far
```cpp=
// How we've used pointers so far
int number2 {22};
int  *p_number2 = &number2;

std::cout << std::endl;
std::cout << "Declaring pointer and assigning address : " << std::endl;
std::cout << "number : " << number2 << std::endl;
std::cout << "p_number : " << p_number2 << std::endl;
std::cout << "&number : " << &number2 << std::endl;
std::cout << "*p_number : " << *p_number2 << std::endl;

int  *p_number3; // Uninit pointer, contains junk address (not recommend)
int number3{12};
p_number3 = &number3; // Make it point to a valid address
std::cout << std::endl;
std::cout << "Unini pointer : " << std::endl;
std::cout << "*p_number1 : " << *p_number3 << std::endl;
```

![](https://i.imgur.com/9jaBhta.png)

![](https://i.imgur.com/zvY79Sk.png)
## difference with stack and heap
![](https://i.imgur.com/4d0z6tn.png)

## Allocate dynamic memory through 'new'
```cpp=
// Allocate dynamic memory through 'new'
/*
    Init the pointer with dynamic memory. Dynamically allocate
    memory at run time and make a pointer point to it
*/

int *p_number4{nullptr};
p_number4 = new int; /*
                        Dynamically allocate space for single int on the heap
                        This memory belongs to our program from now on. The system
                        can't use it for anything else, until we return it.
                        After this line executes, we will have valid memory location
                        allocated. The size of the allocated memory will be such that it can
                        store the type pointed to by the pointer
                    */
*p_number4 = 77;
std::cout << "Dynamically allocating memory : " << std::endl;
std::cout << "*p_number4 : " << *p_number4 << std::endl;
```

## releasing and resetting dynamic memory
```cpp=
delete p_number4;
p_number4 = nullptr;
```

##  Init with 'new' upon pointer declartion
```cpp=
// Init with 'new' upon pointer declartion
/*
    It is also possible to init the pointer with valid
    adress up on declaration. Not with nullptr
*/
int *p_number5{new int}; // Memory contains junk value
int *p_number6{new int (22)}; // use direct inti
int *p_number7{new int { 23 }}; // use uniform init
std::cout << "Init with valid memory address at declaration : " << std::endl;
std::cout << "p_number5 : " << p_number5 << std::endl;
std::cout << "*p_number5 : " << *p_number5 << std::endl; // Junk value

std::cout << "p_number 6 : " << p_number6 << std::endl;
std::cout << "*p_number6 : " << *p_number6 << std::endl;

std::cout << "p_number7 : " << p_number7 << std::endl;
std::cout << "*p_number7 : " << *p_number7 << std::endl;

// Remember to release the memory
delete p_number5;
p_number5 = nullptr;

delete p_number6;
p_number6 = nullptr;

delete p_number7;
p_number7 = nullptr;
```

![](https://i.imgur.com/VHBxp8k.png)
