#include <stdio.h>
#include <stdlib.h>

void swap(int * d1, int  *d2 );

int main(){

    int x = 1;
    int y = 2;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    swap( &x , &y );

    printf("x: %d\n", x);
    printf("y: %d\n", y);

    return EXIT_SUCCESS;
}

void swap(int *d1, int  *d2 ){
    int temp;
    temp =  *d1;
    *d1 = *d2;
    *d2 = temp;
    
}

