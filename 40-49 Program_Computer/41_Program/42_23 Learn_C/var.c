#include <stdio.h>

int main(){
    // declare
    // 123 ~ -123, 2 or 4 bytes
    int studentID;
    // 19.99 ~ -19.99, 4 bytes
    float studentFee;
    // 'a' or 'B', 1 byte
    char studentGrade;
    // 8 bytes = long float
    double studentNum;

    // assign
    studentID = 15;
    studentFee = 75.25;
    studentGrade = 'B';
    studentNum = 20.00;

    // printf
    // %i is used to represent integer of various bases such as decimal, hexadecimal, or octal 
    printf("Student id, Fee, Grade: %i\n %f\n %i\n", studentID, studentFee, studentGrade);
    // %d for signed decimal integer.
    printf("Student id: %d\n", studentID);
    // %f for float
    printf("Student Fee: %f\n", studentFee);
    // %c for char
    printf("Student grade: %c", studentGrade);
    return 0;
}
