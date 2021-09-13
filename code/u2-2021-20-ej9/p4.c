#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
    char *programs[] = {"./min","./max","./avg"};

    /*
    for(int i= 0;i<=argc;i++){
        printf("argv[%d]: %p \n",i,argv[i]);
    }
    */

    if(argc > 1){

        for(int i = 0; i < 3; i++){
            pid_t pid = fork();
            if(pid == 0){
                argv[0] = programs[i];
                execv(programs[i], argv);
                perror("execvs fails: ");
                exit(EXIT_FAILURE);
            }
            else if(pid == -1){
                printf("fork fails \n");
                exit(EXIT_FAILURE);
            }
        }
        int status;
        wait(&status);
        wait(&status);
        wait(&status);
    }
    else{
        printf("fails: arguments missing\n");
        exit(EXIT_FAILURE);
    }
}
