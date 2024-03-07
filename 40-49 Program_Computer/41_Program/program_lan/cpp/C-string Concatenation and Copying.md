# C-string Concatenation and Copying
###### tags: `learn cpp`

## std::strcat : Joining strings
```cpp=
// std::strcat : Joining strings
std::cout << "std::strcat : " << std::endl;

char dest[50] = "Hello ";
char src[50] = "World!";
std::strcat(dest, src);
std::strcat(dest, "Goodbye World!");
std::cout << "dest: " << dest << std::endl;
```

### More concatenation
```cpp=
std::cout <<std::endl;
std::cout << "More std::strcat: " << std::endl;

char *dest1 = new char[30]{'F','i','r', 'e', '\0'};
char *source1 = new char[30]{',','T','h','e','\0'};
std::cout << "std::strlen(dest1): " << std::strlen(dest1) << std::endl;
std::cout << "std::strlen(source1): " << std::strlen(source1) << std::endl;

std::cout << "Concatenating..." << std::endl;
std::strcat(dest1, source1);
std::cout << "std::strlen(dest1): "  << std::strlen(dest1) << std::endl;
std::cout << "dest1: " << dest1 << std::endl;
```

## std::strncat : Joining strings
```cpp=
// std::strncat : Joining strings
// std::strncat : concatenates n characters from src to dest and
// returns a pointer to the result string
// signature: char *strncat( char *dest, const char *src, std::size_t count ) ;
std::cout <<std::endl;
std::cout << "std::strncat: " << std::endl;
char dest2[50]{"Hello"};
char source2[30] = {"There is a bird on my window"};

// You can even use the returned pointer immediately for print out
// This is a pattern you'll see a lot in C++ code out there.
std::cout << std::strncat(dest2,source2,6) << std::endl;

// Or you can do std::strncat separately and print dest2
std::strncat(dest2,source2,6);
std::cout << "The concatenated string is: " << dest2 << std::endl;
```

## std::strncpy : Copying strings
```cpp=
std::cout << std::endl;
std::cout << "std::strncpy: " << std::endl;
const char *source4 = "Hello";
char dest4[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'}; // Have to put the terminating
                                                    // null char if we want to print
std::cout << "dest4: " << dest4 << std::endl;
std::cout << "Copying..." << std::endl;
std::strncpy(dest4,source4, 5);
std::cout << "dest4: " << dest4 << std::endl;
```

