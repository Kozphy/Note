# Pointer to Char
###### tags: `learn cpp`

## Declaring pointers to char
```cpp=
char  *p_char_var {nullptr};
char	char_var {'A'};

p_char_var = &char_var;

std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

char char_var1 {'C'};
p_char_var = &char_var1;
std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;
```

##  Init char pointer with string literal (don't do this)
```cpp=
// Init pointer with string literal
std::cout << std::endl;
/*
    Pointer to char can also do something spcial
    You can init with a string literal : C-String
    The compiler will convert "Hello World!" string to a array of const char which will be pointed first character by p_message
    which point to that array is not const char pointer.
*/
char	*p_message {"Hello World!"};

std::cout << "The message is : " << p_message << std::endl;
std::cout << "The value stored at p_message is : " << *p_message << std::endl;

// The string literal is made up of const char. Trying to modify any of them will result in a disaster!
*p_message = 'B';
std::cout << "The message is (after modifcation of first char to B) : " << p_message << std::endl;
```
The compiler will convert "Hello World!" String to a array of const char which will be pointed first character by p_message which point to that array is not const char pointer.

## Init char pointer of array with string literal 
```cpp=
char message2[] {"Hello there"};
message2[0] = 'T';
std::cout << "message2 : " << message2 << std::endl;
```