#include <stdio.h>

void writeFile();
void readFile();
void readEveryLineOfFile();

int main(){
    // readFile();
    readEveryLineOfFile();
}

void writeFile(){
    FILE *fptr;
    // "w" for override
    // "a" for append
    fptr = fopen("filename.txt", "w");
    fprintf(fptr, "Some text");
    fclose(fptr);
}

void readFile(){
    FILE *fptr;
    // "r" for read
    fptr = fopen("filename.txt", "r");

    char myString[100];

    // fgets for reading file
    fgets(myString, 100, fptr);

    printf("\n %s \n", myString);

    fclose(fptr);
}

void readEveryLineOfFile(){
    FILE *fptr;

    fptr = fopen("filename.txt", "r");

    char myString[100];

    while(fgets(myString, 100, fptr)){
        printf("%s", myString);
    }

    fclose(fptr);
}