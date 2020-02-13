#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    char input[50];
    char inFile[20];
    char outFile[20];
    char function[10];

    printf("Enter in_file out_file function\n");
    fgets(input, sizeof(input),stdin);
    sscanf(input, "%s %s %s", inFile, outFile,function);

    FILE *fin = fopen(inFile,"r");
    if(fin == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    }


    FILE *fout = fopen(outFile,"w");
    if(fout == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    } 

    while(1){
        
        fgets(input, sizeof(input) ,fin);
        if(feof(fin)) break;

        int n = strlen(input);

        if(strncmp("xor",function,3) == 0){
            for(int i= 0; i < n; i++){
                input[i] = input[i]  ^ 0xFF;
            }
            fputs(input,fout);
        }
    }
    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
}
