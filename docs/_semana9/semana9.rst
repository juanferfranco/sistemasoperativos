Semana 9
===========
Esta semana vamos a realizar los ejercicios propuestos en la guía de hilos.

Material
----------
La guía de trabajo para el tema de hilos está `aquí <https://drive.google.com/open?id=1I5G4rRNEzmAuOgpEtgDra8TPUTpIPHTXCTwzHF93wHE>`__. 
Al final de la guía hay ejercicios tipos examen llamados alimento para el pensamiento.

Dejo como referencia una posible solución a la evaluación sumativa 1:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define COMMANDMAXSIZE 50
    #define NAMEMAXSIZE 30
    char commandBuffer[COMMANDMAXSIZE + 1];

    const char makeDatabase[] = "mkdb";
    const char loadDatabase[] = "loaddb";
    const char saveDatabase[] = "savedb";
    const char readAllRegisters[] = "readall";
    const char readDbSize[] = "readsize";
    const char readDbCapacity[] = "readcapacity";
    const char makeRegister[] = "mkreg";
    const char readRegister[] = "readreg";
    const char quit[] = "exit";

    int makeDatabasefn(int);
    int loadDatabasefn(char *);
    void saveDatabasefn(char *);
    void readAllRegistersfn(void);
    int readsizefn(void);
    int makeRegisterfn(int, char *, int );
    int readRegisterfn(int);
    void quitfn(void);

    struct estudiante
    {
        int cedula;
        char nombre[30];
        int semestre;
    };

    char currentDataBaseName[50];
    int currentDataBaseSize = 0;
    struct estudiante *pcurrentDataBase;
    int currentDataBaseRegister = 0;

    int main()
    {
        while(1){
            printf(">");
            if ( fgets(commandBuffer, COMMANDMAXSIZE + 1,stdin) != NULL){
                
                int commandSize = strlen(commandBuffer);
                
                if(commandBuffer[commandSize - 1] != '\n'){
                    printf("Error: command too long \n");
                    return EXIT_FAILURE;
                }
                else{
                commandBuffer[commandSize - 1] = 0;
                }
                
                if( 0 == strncmp(makeDatabase, commandBuffer, strlen(makeDatabase) ) ){
                    char* token = strchr(commandBuffer, ' ');
                    if(token != NULL){
                        int result = sscanf(token + 1, "%s %d", currentDataBaseName, &currentDataBaseSize);
                        if(result != 2){
                        currentDataBaseName[0] = 0;
                        currentDataBaseSize = 0;
                        printf("Enter a valid arguments\n");  
                        }
                        else{
                            if ( makeDatabasefn(currentDataBaseSize) != 1){
                                printf("Database can't be created\n");
                            }
                        }
                    }
                    else{
                        printf("Enter a valid arguments\n");
                    }
                }
                else if ( 0 == strncmp(readAllRegisters, commandBuffer, strlen(readAllRegisters) ) ){
                    readAllRegistersfn();
                }
                else if ( 0 == strncmp(makeRegister, commandBuffer, strlen(makeRegister) ) ){
                    char* token = strchr(commandBuffer, ' ');
                    char name[50];
                    int cedula;
                    int semestre;
                    
                    if(token != NULL){
                        int result = sscanf(token + 1, "%d %s %d", &cedula, name,&semestre);
                        if(result != 3){
                        printf("Enter a valid register arguments\n");  
                        }
                        else{
                            if( makeRegisterfn(cedula, name, semestre) != 1){
                                printf("Data base is full, register was not created\n");
                            }
                        }
                    }
                }
                else if( 0 == strncmp(saveDatabase, commandBuffer, strlen(saveDatabase) ) ){
                    if(currentDataBaseName[0] == 0){
                        printf("Load a data base first\n");
                        continue;
                    }
                    char* token = strchr(commandBuffer, ' ');
                    if(token != NULL){
                        int result = sscanf(token + 1, "%s", currentDataBaseName);
                        if(result != 1){
                        printf("Enter a name\n");  
                        }
                        else{
                            saveDatabasefn(currentDataBaseName);
                        }
                    }
                    else{
                        printf("Enter a name\n");
                    }
                }
                else if( 0 == strncmp(quit, commandBuffer, strlen(quit) ) ){
                    if(currentDataBaseName[0] == 0){
                        printf("No active db\n");
                        continue;
                    }
                    printf("save data base with name %s? y/n: ",currentDataBaseName);
                    if (fgets(commandBuffer, COMMANDMAXSIZE + 1,stdin) != NULL){

                    int commandSize = strlen(commandBuffer);
                    commandBuffer[commandSize - 1] = 0;         
                    if( 0 == strncmp("y", commandBuffer, 1) ){
                        saveDatabasefn(currentDataBaseName);
                    }
                    }
                    return EXIT_SUCCESS;
                }
                else if( 0 == strncmp(loadDatabase, commandBuffer, strlen(loadDatabase) ) ){
                    char* token = strchr(commandBuffer, ' ');
                    char name[50];

                    if(token != NULL){
                        int result = sscanf(token + 1, "%s",name);
                        if(result != 1){
                        printf("Enter a data base name\n");  
                        }
                        else{
                            if( loadDatabasefn(name) == 0){
                                printf("Can't load de database\n");
                            }
                            else{
                                strncpy(currentDataBaseName, name, 50);
                            }
                        }
                    }
                    else{
                        printf("Enter a database name\n");
                    }
                }
                else if( 0 == strncmp(readDbSize, commandBuffer, strlen(readDbSize) ) ){
                    printf("%d\n",currentDataBaseRegister);
                }
                else if( 0 == strncmp(readDbCapacity, commandBuffer, strlen(readDbCapacity) ) ){
                    printf("%d\n",currentDataBaseSize);
                }
                else if( 0 == strncmp(readRegister, commandBuffer, strlen(readRegister) ) ){
                    char* token = strchr(commandBuffer, ' ');
                    int cedula;

                    if(token != NULL){
                        int result = sscanf(token + 1, "%d",&cedula);
                        if(result != 1){
                        printf("Enter a numeric id number\n");  
                        }
                        else{
                            if( readRegisterfn(cedula)  == 0){
                                printf("Can't find the id number in the database\n");
                            }
                        }
                    }
                    else{
                        printf("Enter a id number\n");
                    }
                }
                else{
                    printf("Not valid command\n");
                }
            }
            else{
                perror("Error: ");
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    }


    int makeDatabasefn(int size){
        int success = 0;
        pcurrentDataBase = (struct estudiante *) malloc( sizeof(struct estudiante)*size );
        if(pcurrentDataBase != NULL) success = 1;
        return success;
    }

    void readAllRegistersfn(void){
        for(int i = 0; i < currentDataBaseRegister; i++){
            printf("registro %d cedula: %d, nombre: %s, semestre: %d\n", i+1, (pcurrentDataBase + i)->cedula,(pcurrentDataBase + i)->nombre, (pcurrentDataBase + i)->semestre);
        }
    }

    int makeRegisterfn(int cedula, char * nombre, int semestre){
        int result = 0;
        if(currentDataBaseRegister < currentDataBaseSize){
            (pcurrentDataBase+ currentDataBaseRegister)->cedula = cedula;
            strncpy( (pcurrentDataBase+ currentDataBaseRegister) ->nombre, nombre, NAMEMAXSIZE);
            (pcurrentDataBase+ currentDataBaseRegister)->semestre = semestre;
            currentDataBaseRegister++;
            result = 1;
        }
        return result;
    }

    void saveDatabasefn(char * name){
        FILE *fp = fopen(name, "w+");
        fprintf(fp,"%d\n",currentDataBaseSize);
        for(int i = 0; i < currentDataBaseRegister; i++){
            fprintf(fp, "%d %s %d\n", (pcurrentDataBase + i)->cedula,(pcurrentDataBase + i)->nombre, (pcurrentDataBase + i)->semestre);
        }
        fclose(fp);    
    }


    int loadDatabasefn(char * dataBaseFileName){
        int currentDataBaseSizeTmp = 0;
        struct estudiante *pcurrentDataBaseTmp;
        int currentDataBaseRegisterTmp = 0;

        int result = 0;
        FILE *fp = fopen(dataBaseFileName, "r");
        if(fp == NULL){
            perror("Error: ");
        }
        else{
            int scanfStatus = fscanf(fp,"%d", &currentDataBaseSizeTmp);
            if(feof(fp) == 0){
                if(scanfStatus == 1){
                    pcurrentDataBaseTmp = (struct estudiante *) malloc( sizeof(struct estudiante)*currentDataBaseSizeTmp );
                    if(pcurrentDataBaseTmp != NULL){
                        while(1){
                            int scanfStatus = fscanf(fp,"%d %s %d", &((pcurrentDataBaseTmp + currentDataBaseRegisterTmp)->cedula), (pcurrentDataBaseTmp + currentDataBaseRegisterTmp)->nombre, &((pcurrentDataBaseTmp + currentDataBaseRegisterTmp)->semestre) );
                            if(feof(fp) == 0){
                                if(scanfStatus != 3){
                                    free(pcurrentDataBaseTmp);
                                    break;
                                }
                                else{
                                    currentDataBaseRegisterTmp++;
                                }
                            }
                            else{
                                result = 1;
                                pcurrentDataBase = pcurrentDataBaseTmp;
                                currentDataBaseSize = currentDataBaseSizeTmp;
                                currentDataBaseRegister = currentDataBaseRegisterTmp;
                                break;
                            }
                        }
                    }
                }
                else{
                    printf("Can't read database size\n");
                }
            }
            else{
                printf("Can't read database\n");
            }

            fclose(fp);
        }
        return result;
    }


    int readRegisterfn(int id){
        int result = 0;

        for(int i = 0; i < currentDataBaseRegister;i++){
            if( (pcurrentDataBase + i)->cedula == id ){
                result = 1;
                printf("registro %d cedula: %d, nombre: %s, semestre: %d\n", i+1, (pcurrentDataBase + i)->cedula,(pcurrentDataBase + i)->nombre, (pcurrentDataBase + i)->semestre);
                break;
            }
        }
        return result;
    }
