# flow of control
###### tags: `c++ learn`

## while statement
```c++=
#include <iostream>
int main() {
    int sum = 0, val = 1;
    while (val <= 10) {
        sum += val; // assigns sum + val to sum
        ++val; // add 1 to val
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
```

## for statement
```c++=
# include<iostream>

int main(){
    int sum = 0;
    for (int val = 1; val <=10; ++val) 
        sum += val;
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
    
}
```

## uknown_input
```c++=
#include <iostream>

int main() {
    int sum = 0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
```
When we use an **istream** as a condition, the effect is to test the state of the stream. If the stream is valid—that is, if the stream hasn’t encountered an error—then the test succeeds. An istream becomes invalid when we hit **end-of-file or encounter an invalid input**, such as reading a value that is not an integer. An istream that is in an invalid state will cause the condition to yield false
> Entering an End-of-File from the Keyboard
> When we enter input to a program from the keyboard, different operating systems use different conventions to allow us to indicate end-of-file. On **Windows systems** we enter an end-of-file by typing a **control-d—hold down the Ctrl key and press d—followed by hitting either the Enter or Return key**. On **UNIX systems**, including on **Mac OS X** machines, end-of-file is usually **control-d**.

## if statement
We can use an if to write a program to count how many consecutive times each distinct value appears in the input
```c++=
#include <iostream>

int main() {
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}
```