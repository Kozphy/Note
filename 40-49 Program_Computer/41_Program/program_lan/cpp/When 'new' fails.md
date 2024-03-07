# When 'new' fails
###### tags: `learn cpp`

![](https://i.imgur.com/CzFZEpF.png)

## Simulating memory allocation failure
```cpp=
// Try to allocate a insanely huge array in one go
// Unhandled new failure: Crash
int* lots_of_ints1 {new int[100000000000000000]}; // May give an error about
                                                // exceeding array size
// Use a huge loop to try and exhaust the memory capabilities
// of your system. When new fails, your program is going to
// forecefuly terminate.

for (size_t i{}; i < 100000000000; ++i) {
    int *lots_of_ints2 {new int [10000000]};
}
```


![](https://i.imgur.com/GB1l0Ck.png)

## The Exception mechanism
```cpp=
// Handling the exception

// Handle the problem in a way that makes sense for your application.
// For example if you were trying to allocate memory to store color information
// for your application, and allocation fails, you could opt for showing some
// feedback message to the user, and rendering your app in black/white.

for (size_t i{}; i< 100000000000; ++i){
    try{
        int *lots_of_ints3 {new int[10000000]};
    }catch(std::exception& ex) {
        std::cout << "Cought exception ourselves : " << ex.what() << std::endl;
    }
}
```

## std::nothrow
```cpp=
//std:: nothrow: ideal if you don't want exceptions thrown when
// new fails

for (size_t i{}; i<100000000000; ++i) {
    int* lots_of_ints4 {new(std::nothrow) int[10000000]};

    if(lots_of_ints4 == nullptr){
        // Don't try to dereference and use lots_of_ints4 in here.
        // You'll get UB. No memory has really been allocated here
        // It failed and returned nullptr because of the std::nothrow setting
        std::cout << "Memory allocation failed" << std::endl;
    }else {
        std::cout << "Memory allocation succeeded" << std::endl;
    }
}
```