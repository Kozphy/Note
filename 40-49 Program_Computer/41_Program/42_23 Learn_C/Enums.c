#include <stdio.h>

// default start from 0
enum Level{
    LOW,
    MEDIUM,
    HIGH
};

int main(){
    enum Level myVar;
    // myVar.Low = 2000;
    myVar = MEDIUM;
    printf("\n %d \n", myVar);

    return 0;
}
