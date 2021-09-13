#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){

    if(argc > 1){

        int32_t *arr = malloc(sizeof(uint32_t)*argc);

        for(int i = 1; i < argc; i++){
            if( sscanf(argv[i], "%d", &arr[i-1]) != 1){
                printf("sscanf argument %d error \n", i);
                free(arr);
                exit(EXIT_FAILURE);
            } 
        }

        int32_t avg = 0;

        for(int i = 0; i<argc-1;i++){
            avg = avg + arr[i];
        }

        printf("avg: %.2f\n", (double)avg/(argc-1));

        free(arr);
    }
    else{
        printf("fails: arguments missing\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}