Semana 8: Unidad 3
====================

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Actividad 2 
^^^^^^^^^^^^^
* Fecha: agosto 24 de 2020 - 4:00 p.m
* Descripción: realiza en la sesión sincrónica los ejercicios propuestos
* Recursos: ejercicios
* Duración de la actividad: 1 hora 40 minutos
* Forma de trabajo: individual con solución de dudas en tiempo real

Ejercicio 1
**************

* Escribe en la terminal el comando man syscall y lee la descripción.
* El siguiente código muestra dos formas de llamar servicios del sistema,
  directamente con la función syscall o por medio de una biblioteca, en este
  caso libc. Considera que el uso de la biblioteca es la forma como usualmente
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
  pdf se pueden observar algunos llamados al sistema operativo. Analiza de nuevo
  el siguiente ejemplo, PERO usando eclipse y depurando el programa de tal manera
  que puedas controlar la ejecución de ambos procesos.


.. code-block:: c
   :linenos:

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        pid_t pid_hijo;

        printf("Este proceso va a crear otro proceso\n\n");
        printf("El pid del programa padre es: %d\n",(int)getpid());
        pid_hijo = fork();
        switch(pid_hijo) {
            case -1: /* Error */
                printf("Error al crear el proceso");
                return -1;
            case 0: /* Código ejecutado por el hijo */
                printf("PROCESO HIJO:\n");
                printf("Soy el hijo, mi PID es %d\n",(int)getpid());
            break;
            default: /* Código ejecutado por el padre */
                printf("PROCESO PADRE: Proceso hijo con PID %d creado\n",(int)pid_hijo);
        }
        /* Esta línea será ejecutada por ambos procesos, pero en
           en diferente contexto (el de cada proceso) */
        printf("Soy el proceso %d terminando \n",(int)getpid());
        exit(EXIT_SUCCESS);
    }

Ejercicio 2: repaso
*********************
Lectura de argumentos de la línea de comandos. Analiza el siguiente programa:

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

* Compila y ejecuta el programa
* Ejecuta el programa así: ./nombre_que_le _puso_usted hola mundo cruel
* ¿Para qué sirve argc?
* ¿Qué es argv?

Ejercicio 3
*******************
Construye un programa así:

* ./programa arg1 arg2 arg3 ... argn
* La cantidad de argumentos es arbitraria, es decir, se puede pasar 1 o muchos.
* Los argumentos serán números enteros.

El programa debe almacenar en un arreglo DE ENTEROS los argumentos y calcular:

* El promedio.
* El mínimo entero.
* El máximo entero.

Ejercicio 4
*************

Realiza programa que cree tres procesos. Cada uno de los procesos hijos
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

* Antes de comenzar ejecuta en la línea de comandos: man waitpid
* ¿Qué es un proceso Zombie?
* ¿Qué pasa con la ejecución de un proceso cuando llama a wait?
* ¿Cuando wait retorna cómo sabe el proceso padre cuál de los hijos terminó?
* ¿Cuántos wait tendría que llamar el padre para este programa?

Ejercicio 5
*************

Ejecuta en la línea de comandos: man exec

* ¿Qué hace la familia de funciones exec?
* ¿Qué biblioteca se debe incluir para poder utilizar una función de la
  familia exec?
* ¿Qué es una función variádica?
* De las funciones que hemos visto en el curso identifica algunas?
* Una función de la familia exec cuándo retorna?

Escribe el siguiente ejemplo tomado del sitio geekforgeeks.

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

* Compila con: gcc -Wall EXEC.c -o EXEC

* Escribe el siguiente programa:

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

* Ejecuta el programa.
* Analiza detenidamente el código.
* Analiza detenidamente qué está pasando. Entonces cuál es la diferencia entre
  un proceso y un programa?

Ejercicio 6
*************

* Divide el programa del ejercicio 3 en tres programas. Uno que calcule
  el promedio, otro que calcule el máximo y otro que calcule el mínimo.
* Compila cada programa y genere un ejecutable, tal como el
  ejercicio 4.
* Crea un cuarto programa. Este programa recibirá los argumentos y
  realizará 3 fork. Luego cada uno de los hijos cambiará su imagen
  (ejecutable) por los ejecutables de los programas promedio, mínimo y máximo.
* El programa padre debe LANZAR los procesos en paralelo y esperar que cada
  hijo termine.