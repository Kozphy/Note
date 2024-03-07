# Output formating
###### tags: `learn cpp`

![](https://i.imgur.com/ufwMQ7Q.png)

![](https://i.imgur.com/nOJA6Ah.png)

![](https://i.imgur.com/IZ6aKLW.png)

## std:endl
![](https://i.imgur.com/kFBH74N.png)

## std:flush
![](https://i.imgur.com/KtEjqg0.png)
```cpp=
// std:: flush : flushes the output buffer to its final destination.
std::cout << "This is a nice message..." << std::endl << std::flush;
// After this std::flush, we're sure that at this line, the message has been sent 
// to the stream. This may be important in some applications.
```

## std:setw
![](https://i.imgur.com/FJGUywA.png)
```cpp=
int col_width{14};
    
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Carr"<< std::setw(col_width) << "20" << std::endl;
```
### combine with std::right
![](https://i.imgur.com/g1IQwms.png)

### combine with std::internal
![](https://i.imgur.com/C0CACkR.png)
### combine with std::setfill
![](https://i.imgur.com/O36PtkU.png)


## std::boolalpha
![](https://i.imgur.com/qapIa2j.png)

## std::showpos
![](https://i.imgur.com/s8d3o7E.png)

## std:dec std::oct and std::hex
![](https://i.imgur.com/SvDFmmB.png)

## std::showbase
![](https://i.imgur.com/g28XXNN.png)


## std::uppercase
![](https://i.imgur.com/K2EjzDV.png)

## std::scientific - std::fixed
![](https://i.imgur.com/2SwwbCV.png)

![](https://i.imgur.com/3IIYSiB.png)

## std::setprecision
![](https://i.imgur.com/tN8pXeX.png)

## std::showpoint
![](https://i.imgur.com/D0zNU6x.png)

