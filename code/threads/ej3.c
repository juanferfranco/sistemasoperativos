#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x = 0;

void* function(void *parg){
    for(int i = 0; i< 100; i++)x++;
    return NULL;
}


int main(int argc, char *argv[]){
    pthread_t threadsID[4];

    for(int i = 0; i < 4; i++){
        pthread_create(&threadsID[i],NULL,&function, NULL);
    }

    for(int i = 0; i < 4; i++){
        pthread_join(threadsID[i],NULL);
    }

    printf("x value: %d\n",x);

    exit(EXIT_SUCCESS);
}