#include <stdio.h>

int sum(int k);

int main(){
    int result = sum(10);
    printf("%d", result);
    return 0;
}

int sum(int k){
    if(k > 0){
        // 10 + sum(9) ... + sum(1)
        return k + sum(k - 1);
    }else{
        return 0;
    }
}