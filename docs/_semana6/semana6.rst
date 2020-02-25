Semana 6
===========

Esta semana vamos a comenzar con la primera abstracción que ofrece el sistema
operativo relacionada con los procesos y la concurrencia.


Soluciones a las evaluaciones de la semana pasada
--------------------------------------------------

.. note:: Una posible solución a las evaluaciones de la semana pasada es esta:

Evaluación grupo 2 a 4
^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main(int argc, char * argv[]){

    FILE *fin = fopen(argv[1],"r");
    FILE *fout = fopen(argv[2],"w");
    char *pclave = argv[3];

    // Prueba 2
    fprintf(fout,"%s\n",argv[0]);

    // Prueba 3
    char * buffer = malloc(sizeof(char)*1000);
    fgets(buffer, 1000,fin);
    fprintf(fout,"%s",buffer);


    // Prueba 4
    fgets(buffer, 1000,fin);
    char *pbufferEnd = buffer + strlen(buffer)  - 2 ;
    for(; pbufferEnd > buffer;pbufferEnd--){
        fputc(*pbufferEnd,fout);
    }
    fputc(*pbufferEnd,fout);

    // Prueba 5

    while(1){
        fgets(buffer, 1000,fin);
        char *pdata = strstr(buffer, pclave);
        if(pdata != NULL){
            pdata = pdata + strlen(pclave) + 1;

            char *pop = NULL;
            pop = pdata;
            do{
                pop = strpbrk(pop,"+-%*/");
                pop++;

            }while( (*pop >= 0x030) &&  (*pop  <= 0x039));

            char op = * (pop-1);
            *(pop - 2) = 0;

            int num = 0;
            char *endp = NULL;
            int res = (int) strtol(pdata,&endp,10);
            pdata = endp + 1;
            while(1){
                num = (int) strtol(pdata,&endp,10);
                pdata = endp + 1;
                switch(op){
                case '+':
                    res = res + num;
                    break;
                case '-':
                    res = res - num;
                    break;
                case '%':
                    res = res % num;
                    break;
                case '*':
                    res = res*num;
                    break;
                case '/':
                    res = res/num;
                    break;
                }
                if(*endp == 0) break;
            }

            fprintf(fout,"\n%d\n",res);
            break;
        }
    }

    fclose(fout);
    fclose(fin);
    free(buffer);
    return EXIT_SUCCESS;
    }

El vector de prueba usado es este:

.. code-block:: html
    :linenos:

    Esta es la primera linea
    Esta es la segunda linea del archivo
    Esta es la tercera linea del archivo de entrada
    Esta es la cuarta hola 1 2 3 -4 5 6 -7 8 9 + fin de la linea
    Esta es la quinta linea
    Esta es la sexta linea

Evaluación grupo 4 a 6
^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    int main(int argc, char * argv[]){

    FILE *fin = fopen(argv[1],"r");
    FILE *fout = fopen(argv[2],"w");
    char *pclave = argv[3];

    // Prueba 2
    fprintf(fout,"%s\n",argv[2]);

    // Prueba 3
    char *buffer = malloc(sizeof(char) * 1000);
    fgets(buffer, 1000,fin);
    for(char *pbuf = buffer ; *pbuf != '\n'; pbuf++){
        fputc( toupper(*pbuf), fout);
    }
    fputc('\n',fout);


        // Prueba 4
        fgets(buffer, 1000,fin);
        char *pletter = buffer;
        int counter = 0;

        while(1){
            if(*pletter == ' '){
                fprintf(fout, "%d ", counter);
                counter = -1;
            }
            else if( *pletter == '\n' ){
                fprintf(fout, "%d ", counter);
                break;
            }

            counter++;
            pletter++;
        }
        fputc('\n',fout);

    // Prueba 5
    while(1){
        fgets(buffer,1000,fin );
        char *pdata = strstr(buffer, pclave);

            if(pdata != NULL){
                char *pLastWord = buffer + strlen(buffer) - 1;
                *pLastWord = 0;
                for(; *pLastWord != ' ' ; pLastWord--);
                char wordNum = strlen(pLastWord  + 1);
                pdata = pdata + strlen(pclave) + 1;

                char *token = strtok(pdata, " ");
                while(token != NULL){
                    if(strlen(token) == wordNum) fprintf(fout, "%s ", token);
                    token = strtok(NULL, " ");
                    if(token == (pLastWord  + 1)) break;
                }
                break;
        }
        }

    fclose(fout);
    fclose(fin);
    free(buffer);
    return EXIT_SUCCESS;
    }

El vector de prueba usado es este:

.. code-block:: html
    :linenos:

    Esta es la primera linea
    Esta es la segunda linea del archivo
    Esta es la tercera linea del archivo de entrada
    Esta es la cuarta hola linea casas del archivo de entrada mundo
    Esta es la quinta linea
    Esta es la sexta linea

Procesos
----------

Lecturas
^^^^^^^^^^
Para complementar el material discutido en la sesión se recomienda leer
el capítulo 3 del libro del dinosaurio (texto guía).

Material de clase
^^^^^^^^^^^^^^^^^^^
El material que vamos a trabajar esta semana en clase lo pueden encontrar
en este
`enlace <https://drive.google.com/open?id=1xojM0NJibnQdIT_UzzrnlS1Fj5NSNtkVNfCnJNBIBYs>`__.

En este `otro enlace <https://drive.google.com/file/d/1t_MhYGFmN7ti6U4TYNcpgigJESFgb7_H/view>`_
pueden leer una explicación detallada de los pasos que ocurren al
hacer un llamado al sistema.

Ejercicios
^^^^^^^^^^^
Los siguientes ejercicios buscan plantear retos de trabajo para esta semana.

Ejercicio 0: 
###############

* Escriba en la terminal el comando man syscall y lea la descripción.
* El siguiente código muestra dos formas de llamar servicios del sistema,
  directamente con la función syscall o por medio de una biblioteca, en este
  caso libc. Considere que el uso de la biblioteca es la forma como usualmente
  llamaremos servicios del sistema operativo.

.. code-block:: c
   :linenos:


    #include <syscall.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>

    int main(void) {
        long ID1, ID2;
        /*-----------------------------*/
        /* direct system call */
        /* SYS_getpid (func no. is 20) */
        /*-----------------------------*/
        ID1 = syscall(SYS_getpid);
        printf ("syscall(SYS_getpid)=%ld\n", ID1);

        /*-----------------------------*/
        /* "libc" wrapped system call */
        /* SYS_getpid (Func No. is 20) */
        /*-----------------------------*/
        ID2 = getpid();
        printf ("getpid()=%ld\n", ID2);
        return(0);
    }

* En `este <https://drive.google.com/file/d/1Z5mewc5DJ6hQqpYUL7nkp4k8WNA9i1JQ/view>`__
  pdf se pueden observar algunos llamados al sistema operativo. Vamos a
  analizar entre todos el siguiente ejemplo:

.. code-block:: c
   :linenos:

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        pid_t pid_hijo;

        printf("Ejemplo fork. Este proceso va a crear otro proceso\n\n");
        printf("El pid del programa principal es: %d\n",(int)getpid());
        pid_hijo = fork();
        switch(pid_hijo) {
            case -1: /* Codigo ejecutado en caso de error*/
                printf("Error al crear el proceso");
                return -1;
            case 0: /* Codigo ejecutado por el hijo */
                printf("PROCESO HIJO:\n");
                printf("PID del hijo: %d\n",(int)pid_hijo);
            break;
            default: /* Codigo ejecutado por el padre */
                printf("PROCESO PADRE: Proceso hijo con PID %d creado\n",(int)pid_hijo);
        }
        /*Esta linea sera ejecutada por ambos procesos (padre e hijo)*/
        printf("Fin del proceso cuyo hijo tiene un PID de %d\n",(int)pid_hijo);
        exit(EXIT_SUCCESS);
    }

Ejercicio 1: repaso
######################
Lectura de argumentos de la línea de comandos. Analice el siguiente programa:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        printf("argc =  %d\n",argc);
        for(int i = 0; i< argc; i++){
            printf("argv[%d] = %s\n", i,argv[i]);
        }
        exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
    }

* Compile y ejecute el programa
* Ejecute el programa así: ./nombre_que_le _puso_usted hola mundo cruel
* ¿Para qué sirve argc?
* ¿Qué es argv?

Ejercicio 2
#############
Construya un programa así:

* ./programa arg1 arg2 arg3 ... argn
* La cantidad de argumentos es arbitraria, es decir, se puede pasar 1 o muchos.
* Los argumentos serán números enteros.

El programa debe almacenar en un arreglo de enteros los argumentos y calcular:

* El promedio.
* El mínimo entero.
* El máximo entero.

Ejercicio 3
#############

Haga un programa que cree tres procesos. Cada uno de los procesos hijos
calculará el factorial de los enteros entre 1 y 10 comenzando por 1.
Los resultados se irán imprimiendo en pantalla. El mensaje impreso por
cada proceso debe ser lo suficientemente claro para entender cuál es el
proceso hijo que está ejecutando la operación factorial.

Una salida tentativa se muestra a continuación (esto no quiere decir
que el orden en que se despliegue sea el mismo):

HIJO1: fact(1) = 1

HIJO2: fact(2) = 1

HIJO2: fact(2) = 2

HIJO1: fact(2) = 2

El proceso padre tiene que esperar a que los hijos terminen utilizando
la función wait.

* Antes de comenzar ejecute en la línea de comandos: man waitpid
* ¿Qué es un proceso Zombie?
* ¿Qué pasa con la ejecución de un proceso cuando llama a wait?
* ¿Cuando wait retorna cómo sabe el proceso padre cuál de los hijos terminó?
* ¿Cuántos wait tendría que llamar el padre para este programa?

Ejercicio 4
#############

Ejecute en la línea de comandos: man exec

* ¿Qué hace la familia de funciones exec?
* ¿Qué biblioteca se debe incluir para poder utilizar una función de la
  familia exec?
* ¿Qué es una función variádica?
* De las funciones que hemos visto en el curso identifica algunas?
* Una función de la familia exec cuándo retorna?

Realice el siguiente ejemplo tomado del sitio geekforgeeks.

* Cree el siguiente programa:

.. code-block:: c
   :linenos:

    //EXEC.c 

    #include<stdio.h> 
    #include<unistd.h> 

    int main() 
    { 
        int i; 
        
        printf("I am EXEC.c called by execv() "); 
        printf("\n"); 
        return 0; 
    } 

* Compile gcc EXEC.c -o EXEC

* Cree el siguiente programa:

.. code-block:: c
   :linenos:

    //execDemo.c 

    #include<stdio.h> 
    #include<stdlib.h> 
    #include<unistd.h> 
    int main() 
    { 
            //A null terminated array of character 
            //pointers 
            char *args[]={"./EXEC",NULL}; 
            execv(args[0],args); 
        
            /*All statements are ignored after execvp() call as this whole 
            process(execDemo.c) is replaced by another process (EXEC.c) 
            */
            printf("Ending-----"); 
        
        return 0; 
    } 

* Ejecute el programa.
* Analice detenidamente el código.

Ejercicio 6
#############

* Divida el programa del ejercicio 2 en tres programas. Uno que calcule
  el promedio, otro que calcule el máximo y otro que calcule el mínimo.
* Compile cada programa y genere un ejecutable, tal como lo hizo en el
  ejercicio 5.
* Cree un cuarto programa. Este programa recibirá los argumentos y
  realizará 3 fork. Luego cada uno de los hijos cambiará su imagen
  (ejecutable) por los ejecutables de los programas promedio, mínimo y máximo.
* El programa padre debe esperar que cada hijo termine.
