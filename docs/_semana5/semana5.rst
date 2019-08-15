Semana 5
===========

En la primera sesión vamos a terminar los siguientes ejercicios propuestos desde la semana pasada:

Ejercicio 2
-------------
Para este ejercicio debemos hacer uso de punteros, arreglos y estructuras de datos.

El ejercicio consiste en realizar un programa que permita almacenar en una base de datos
registros compuestos por: número de órden, email y password. ¿Qué es una base de datos en 
este caso? es simplemente un arreglo de registros.

* El programa deberá soportar los siguientes comandos sobre la base de datos: leer todos los 
  registros, leer la cantidad de registros, ingresar un nuevo registro, leer un número de 
  registro específico, editar un registro. 
* La interfaz de usuario del programa deberá preguntarle al usuario si desea salir o ingresar
  un nuevo comando.
* Cada comando deberá implementarse como una función.
* En C las cadenas de carectares no son objetos, son arreglos terminados en 0. En el 
  siguiente  `enlace <https://www.geeksforgeeks.org/commonly-used-string-functions-in-c-c-with-examples/>`__ 
  se pueden ver algunas funciones típicas para manejar cadenas.
* Cada registro es así: 

.. code-block:: c
   :linenos:

    struct inputRegister 
    {
        int orderno;
        char emailaddress[30];
        char password[30];
    };

Ejercicio 3
-------------
En este ejercicio vamos a utilizar memoria dinámica para crear en tiempo de ejecución bases
de datos. En el ejercicio anterior podíamos definir una base de datos con un tamaño máximo 
definido en tiempo de compilación. En este ejercicio permitiremos que el usuario defina el 
tamaño de la base de datos en tiempo de ejecución. Por tanto será necesario utilizar memoria
dinámica. 

* Modifique el programa anterior adicionando el comando crear base de datos. El comando 
  solicitará el nombre de la base de datos y el tamaño (la cantidad de registros).
* El programa debe indicar al usuario si la base de datos no tiene más capacidad de 
  almacenamiento de registros.

Ejercicio 4
-------------
Modificar el programa anterior adicionado:

* Un archivo que almacene el nombre de todas las bases de datos.
* Cada base de datos se almacenará en un archivo.
* Adicionar el comando: listar base de datos que permite ver el nombre de todas las bases
  de datos.
* Adicionar el comando cargar base de datos.
* Adicionar el comando salvar base de datos.

Ejercicio 5
-------------

* Como ejercicio final se propone implementar una versión propia de la función 
  `strtok <https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm>`__.
* Luego construya un programa que solicite la cadena y el delimitador, aplique su versión de 
  strtok y la versión definida en string.h. Finalmente imprima el resultado de ambas funciones.

Evaluación del semestre pasado
--------------------------------
Esta evaluación no incluyó el tema de archivos.

`Aquí <https://drive.google.com/open?id=1CxuO4w7jKYNDKz8atdR2R4w75Ufo4yp7St4kawx4Mf0>`__ está la 
evaluación.

Una posible solución:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <string.h>

    char command[10];

    char dataBaseName[11];
    int dataBaseSize;
    int dataBaseRegisterCounter = 0;

    // Register struct
    struct registerT{
        char key[20];
        float value;
    };
    struct registerT *pregisterT;

    void processMDATA(void);
    void processMREG(void);
    void processVMDATA(void);
    void processDREG(void);

    int main(void) {
        int ret;

        while(1){
            // get the command
            scanf("%s", command);
            ret = strcmp(command, "mdata");
            if(ret == 0) processMDATA();
            ret = strcmp(command, "mreg");
            if(ret == 0) processMREG();
            ret = strcmp(command, "vmdata");
            if(ret == 0) processVMDATA();
            ret = strcmp(command, "dreg");
            if(ret == 0) processDREG();

        }
        free(pregisterT);
        return EXIT_SUCCESS;
    }

    void processMDATA(void){
        scanf("%s", dataBaseName);
        scanf("%d",&dataBaseSize);
        getc(stdin); //remove \n

        pregisterT = (struct registerT *) malloc(sizeof(struct registerT)*dataBaseSize);
        dataBaseRegisterCounter = 0;
        if(pregisterT == NULL) exit(0);
    }

    void processMREG(void){
        if(pregisterT != NULL){
            if(dataBaseRegisterCounter < dataBaseSize){
                scanf("%s", (pregisterT + dataBaseRegisterCounter)->key);
                scanf("%f", &((pregisterT + dataBaseRegisterCounter)->value));
                getc(stdin); //remove \n
                dataBaseRegisterCounter++;
                if(dataBaseRegisterCounter == dataBaseSize){
                    printf("Data Base full\n");
                }
            }
            else printf("Data Base full, register not stored\n");
        }

    }


    void processVMDATA(void){
        int ret;
        char dataBaseNameTargte[11];
        scanf("%s", dataBaseNameTargte);
        getc(stdin); //remove \n

        ret = strcmp(dataBaseNameTargte, dataBaseName);
        if(0 == ret){
            if(pregisterT != NULL){
                for(int i= 0; i < dataBaseRegisterCounter;i++){
                    ret = strcmp((pregisterT + i)->key, "");
                    if(0 != ret) printf("Key: %s Value:%f \n",(pregisterT + i)->key,(pregisterT + i)->value);
                }
            }
        }
    }


    void processDREG(void){
        int ret;
        char registerName[11];
        scanf("%s", registerName);
        getc(stdin); //remove \n

        if(pregisterT != NULL){
            for(int i= 0; i < dataBaseRegisterCounter;i++){
                ret = strcmp(registerName, (pregisterT + i)->key);
                if(0 == ret){
                    *((pregisterT + i)->key) = 0;
                    return;
                }
            }
            printf("Register not Found\n");
        }
    }



