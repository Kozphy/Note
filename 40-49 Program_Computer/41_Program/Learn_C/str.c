#include <stdio.h>
#include <string.h>

int for_str();
int concat_str();

int main(){
    // for_str();
    concat_str();
}

int for_str(){
    char str[] = "Hello, world!";
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        printf("%c\n", str[i]);
    }
    concat_str();
}

int concat_str(){
    char str1[20] = "Hello ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("%s", str1);
}