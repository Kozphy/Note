#include <stdio.h>

// declare
struct MyStructure {
    int myNum;
    char myLetter;
};

int main(){
    struct  MyStructure s1;

    // assign
    s1.myNum = 13;
    s1.myLetter = 'B';

    // %d for int
    printf("My number: %d\n", s1.myNum);
    // %c for char
    printf("My letter: %c\n", s1.myLetter);

    return 0;
}