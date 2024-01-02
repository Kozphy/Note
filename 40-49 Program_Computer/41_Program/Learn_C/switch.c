#include <stdio.h>

int main(){
    int day = 4;
    switch(day){
        case 1:
            printf("\n Monday \n");
            break;
        case 2:
            printf("\n Tuesday \n");
            break;
        case 3:
            printf("\n Wednesday \n");
            break;
        default:
            // code block
            printf("\n Default \n");
    }
}