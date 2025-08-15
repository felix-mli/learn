#include <stdio.h>

int main(){

    int a[10];

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 6;
    a[6] = 7;
    a[7] = 8;
    a[8] = 9;
    a[9] = 10;
    
    for(int i = 0; i < 10; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}