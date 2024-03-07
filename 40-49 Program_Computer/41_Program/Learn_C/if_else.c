#include <stdio.h>


int main(){
    int x = 20;
    int y = 18;

    y = 20;
    x = 18;

    if(x > y){
        printf("\n %d is greater than %d \n", x, y);
    }else if(x < y){
        printf("\n %d is less than %d \n", x, y);
    }else{
        printf("\n Good evening \n");
    }

    return 0;
}