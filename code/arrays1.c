#include <stdio.h>
#include <stdlib.h>

void printArr(int *, int);


int main(){

    int arr[] = {1,2,3,4};

    for(int i = 0; i < sizeof(arr)/sizeof(int);i++){
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    // - arr: el nombre del arreglo es la dirección del primer 
    // elemento del arreglo.
    // - ¿Cuál es el tipo del primer elemento del arreglo? int
    // --> arr es te tipo int *

    printArr(arr, sizeof(arr)/sizeof(int));

    return EXIT_SUCCESS;
}

void printArr(int *var, int size){

    for(int i = 0; i < size;i++){
        //printf("by printArr arr[%d]: %d\n", i, *(var + i));
        printf("by printArr arr[%d]: %d\n", i, var[i]);
    }
}