Semana 4
===========

Esta semana vamos a realizar las siguientes actividades:

1. Discutir en grupo el último ejercicio de la semana pasada.
2. Evaluación formativa.
3. Análisis de la evaluación formativa.

Ejercicio: problema
^^^^^^^^^^^^^^^^^^^^

La semana pasada planteamos este problema para resolver:

Realice un programa que permita crear un base de datos de estudiantes.
Cada registro de la base de datos estará dado por:
número de cédula, nombre y semestre. Cada registro corresponde a un estudiante.

Implemente los siguientes comandos:

**mkdb nombre tamaño** : crea una base de datos especificando el nombre
y la cantidad de registros.

**loaddb nombre** : carga la base de datos en memoria desde el archivo
especificado. El comando debe indicar si la base de datos se cargó
correctamente o no existe. La base de datos debe cargarse en memoria
dinámica antes de poder aplicar los siguientes comandos.

**savedb nombre** : este comando salva la base de datos en el archivo
especificado.

**readall** : lee todos los registros de la base de datos.

**readsize** : lee la cantidad de registros de la base datos.

**mkreg cedula nombre semestre** : crea un nuevo registro en la base
de datos.

**readreg cédula** : busca en la base de datos por número de cédula.
En caso de encontrar la cédula imprime el registro completo.

**exit** : salir del programa. Antes de terminar debe preguntar si se desea
salvar la base de datos en el archivo especificado con el comando loaddb.

Cada comando deberá implementarse como una función.

Cada registro es así:

.. code-block:: c
   :linenos:

    struct estudiante
    {
        int cedula;
        char nombre[30];
        int semestre;
    };


Ingresar comandos
------------------

La primera característica que vamos a construir en nuestro programa es la
capacidad de leer los comandos y los argumentos que el usuario pasará por
la línea de comandos.

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>

    int main (void){
        while(1){

        }
        return EXIT_SUCCESS;
    }

El programa será un ciclo infinito que procesará continuamente comandos y
en condiciones normales, solo terminará si se ingresa el
comando **exit**.

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>

    #define COMMANDBUFFERMAXSIZE 50

    int main (void){
        char commandBuffer[COMMANDBUFFERMAXSIZE];

        while(1){
            printf(">");
            fgets(commandBuffer, COMMANDBUFFERMAXSIZE, stdin);

        }
        return EXIT_SUCCESS;
    }   

El programa en cada ciclo le mostrará al usuario un prompt (**>**) que
servirá para indicarle que ya está listo para recibir un nuevo comando.
Luego utilizamos la función **fgets** para leer una cadena de caracteres
del flujo de entrada. Se espera que la cadena de caracteres termine en
con un enter (``\n``) seguido de un carácter **NULL** (0) que indica
el fin de la cadena.

**fgets** espera que le pasemos la dirección en memoria donde guardaremos
los caracteres. En este caso, será un arreglo de caracteres alojados en
el stack y con una capacidad máxima de COMMANDBUFFERMAXSIZE caracteres.

**fgets** retorna NULL si ocurre algún problema con la lectura.

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>

    #define COMMANDBUFFERMAXSIZE 50

    int main (void){
        char commandBuffer[COMMANDBUFFERMAXSIZE];

        while(1){
            printf(">");
            if ( fgets(commandBuffer, COMMANDBUFFERMAXSIZE, stdin) != NULL){

            }
            else{
                perror("Error: ");
                return EXIT_FAILURE;
            }

        }
        return EXIT_SUCCESS;
    }

Podemos leer el valor retornado por **fgets** para decidir si procesamos
o no la cadena de entrada. Note que en caso de error, estamos usando la
función **perror** para imprimir un mensaje que describa el error
producido por **fgets**.

.. note::
    Cuando ocurre un error fgets coloca información en la variable entera
    y global errno a la cual podemos acceder con perror, solo que perror además
    interpreta el valor almacenado en la variable e imprime un texto
    descriptivo.

    Esta es la documentación de fgets:

    NAME

    fgets - get a string from a stream
    
    SYNOPSIS


    #include <stdio.h>

    char *fgets(char *s, int n, FILE *stream);

    DESCRIPTION
    
    The fgets() function reads bytes from stream into the array pointed to by s, until n-1 bytes are read, or a newline character is read and transferred to s, or an end-of-file condition is encountered. The string is then terminated with a null byte.
    The fgets() function may mark the st_atime field of the file associated with stream for update. The st_atime field will be marked for update by the first successful execution of fgetc(), fgets(), fgetwc(), fgetws(), fread(), fscanf(), getc(), getchar(), gets() or scanf() using stream that returns data not supplied by a prior call to ungetc() or ungetwc().

    RETURN VALUE
    
    Upon successful completion, fgets() returns s. If the stream is at end-of-file, the end-of-file indicator for the stream is set and fgets() returns a null pointer. If a read error occurs, the error indicator for the stream is set, fgets() returns a null pointer and sets errno to indicate the error.


Una vez tenemos la cadena en commandBuffer podemos proceder a procesarla.
Lo primero que haremos será eliminar el ENTER:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <string.h>

    #define COMMANDBUFFERMAXSIZE 50

    int main(void) {
        char commandBuffer[COMMANDBUFFERMAXSIZE];

        while (1) {
            printf(">");
            if (fgets(commandBuffer, COMMANDBUFFERMAXSIZE, stdin) != NULL) {

                int commandSize = strlen(commandBuffer);

                if (commandBuffer[commandSize - 1] != '\n') {
                    printf("Error: command too long \n");
                    return EXIT_FAILURE;
                } else {
                    commandBuffer[commandSize - 1] = 0;
                }


            } else {
                perror("Error: ");
                return EXIT_FAILURE;
            }

        }
        return EXIT_SUCCESS;
    }

La función **strlen** (está prototipada en string.h) nos permite encontrar
el tamaño de la cadena. Recuerde que la cadena incluye el ENTER y en caso
de estar en la cadena se ubicará en la posición commandSize - 1. Note
que si en esta posición no está el ENTER, quiere decir que la cadena
ingresada por el usuario supera la capacidad de commandBuffer y por
tanto, **fgets** truncará la cadena. Por ejemplo, si cambiamos la capacidad
de commandBuffer de 50 a 10:

.. image:: ../_static/fgetsTrunk.gif

Para eliminar el ENTER de la cadena basta con reemplazarlo con un 0,
indicando así que la cadena termina en este punto.

Implementación del comando mkdb nombre tamaño
-----------------------------------------------

Las siguientes líneas obtienen los argumentos de **mkdb** y llaman
la función que realizará la acción.

.. code-block:: c
    :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <string.h>


    int makeDatabasefn(int);

    #define COMMANDBUFFERMAXSIZE 50

    const char makeDatabase[] = "mkdb";
    char currentDataBaseName[COMMANDBUFFERMAXSIZE];
    int currentDataBaseSize = 0;

    struct estudiante
    {
        int cedula;
        char nombre[30];
        int semestre;
    };
    struct estudiante *pcurrentDataBase;


    int main(void) {
        char commandBuffer[COMMANDBUFFERMAXSIZE];

        while (1) {
            printf(">");
            if (fgets(commandBuffer, COMMANDBUFFERMAXSIZE, stdin) != NULL) {

                int commandSize = strlen(commandBuffer);

                if (commandBuffer[commandSize - 1] != '\n') {
                    printf("Error: command too long \n");
                    return EXIT_FAILURE;
                } else {
                    commandBuffer[commandSize - 1] = 0;
                }

                if (0 == strncmp(makeDatabase, commandBuffer, strlen(makeDatabase)) ) {
                    int result = sscanf(commandBuffer, "%*s %s %d", currentDataBaseName, &currentDataBaseSize);
                    if (result != 2) {
                        currentDataBaseName[0] = 0;
                        currentDataBaseSize = 0;
                        printf("Enter valid arguments\n");
                    }
                    else {
                        if (makeDatabasefn(currentDataBaseSize) != 1) {
                            printf("Database can't be created\n");
                        }
                    }
                }

            } else {
                perror("Error: ");
                return EXIT_FAILURE;
            }

        }
        return EXIT_SUCCESS;
    }

    int makeDatabasefn(int size){
        int success = 0;
        pcurrentDataBase = malloc( sizeof(struct estudiante)*size );
        if(pcurrentDataBase != NULL) success = 1;
        return success;
    }


La función **strncmp** compara los strlen(makeDatabase) primeros bytes del
arreglo de caracteres makeDatabase con commandBuffer. Si son iguales
devuelve 0. **sscanf** lee la cadena de entrada y la procesa como **scanf**.
Finalmente, **makeDatabase** crea la base datos en memoria dinámica.

La línea ``pcurrentDataBase = malloc( sizeof(struct estudiante)*size );`` crea
tantos registros como lo indique ``size``.

Implementación del comando loaddb nombre
-----------------------------------------

Este comando lee la base de datos desde un archivo y la carga en memoria
dinámica. Cada archivo contiene en su primera línea el tamaño de la
base de datos y luego, en las demás líneas, un registro, por línea,
compuesto por la cédula, nombre y semestre. Cada uno de los campos
anteriores está separado por un espacio.

Primero añadimos el código que permite leer el comando y los argumentos:

.. code-block:: c
    :linenos:

    .
    .
    .

    // definición del nuevo comando
    const char loadDatabase[] = "loaddb";
    .
    .
    .
    // if para leer mkdb
    .
    .
    .
    else if( 0 == strncmp(loadDatabase, commandBuffer, strlen(loadDatabase) ) ){
        char name[COMMANDBUFFERMAXSIZE];
        int result = sscanf(commandBuffer, "%*s %s",name);
        if(result != 1){
            printf("Enter a data base name\n");
        }
        else{
            if( loadDatabasefn(name) == 0){
                printf("Can't load the database\n");
            }
            else{
                strncpy(currentDataBaseName, name, COMMANDBUFFERMAXSIZE);
            }
        }
	}


Y la función que leerá el archivo y cargará en memoria dinámica la base
de datos:

.. code-block:: c
    :linenos:

    //1. el prototipo
    int loadDatabasefn(char *);
    .
    .
    .
    //2. Crear un contador de registros
    int currentDataBaseRegister = 0;
    .
    .
    .
    //3. El código

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
                            int scanfStatus = fscanf(fp,"%d %s %d", &((pcurrentDataBaseTmp + currentDataBaseRegisterTmp)->cedula),
                                                    (pcurrentDataBaseTmp + currentDataBaseRegisterTmp)->nombre,
                                                    &((pcurrentDataBaseTmp + currentDataBaseRegisterTmp)->semestre) );
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

Note que la lectura de las líneas del archivo se hace en un
ciclo infinito del cual se sale cuando una lectura al archivo
retorne EOF. Tenga en cuenta que es necesario leer el archivo
para poder obtener un EOF. Es por ello que primero se
hace un **fscanf** y luego se llama feof.
