#include <stdio.h>

int threeD_Array();
int twoD_Array();

int main(){
    int myNumber[] = {25, 50, 75, 100};
    // printf("%d", myNumber[0]);
    printf("%d", threeD_Array());
    return 0;
}

int threeD_Array(){
    int threeD_array[2][3][4] = {
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
        },
        {
            {13,14,15,16},
            {17,18,19,20},
            {21,22,23,24}
        }
    };
    return threeD_array[0][1][1];
};

void twoD_array(){
    int row = 2;
    int col = 3;

    int matrix[2][3] = {
        {1,4,2},
        {3,6,8},
    };

    for(int i = 0; i < row; i++){
        for(int j=0; j< col; j++){
            printf("%d\n", matrix[i][j]);
        }
    }
}
