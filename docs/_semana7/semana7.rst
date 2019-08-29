Semana 7
===========
Esta semana vamos a introducir el concepto de proceso.

Lecturas
---------
Para complementar el material discutido en la sesión se recomienda leer el capítulo 3 del 
libro del dinosaurio (texto guía).

Material de clase
------------------
El material que vamos a trabajar esta semana en clase lo pueden encontrar en este
`enlace <https://drive.google.com/open?id=1xojM0NJibnQdIT_UzzrnlS1Fj5NSNtkVNfCnJNBIBYs>`__.

En este `otro enlace <https://drive.google.com/open?id=1oaxFASOGJr13tqfaIocN8eEcApvAnsuotAcTJI8i7Sk>`__
encontrará una guía. La guía hace referencia a un tutorial muy completo que servirá de material 
de consulta. Adicionalmente, la guía propone unos ejercicios

Ejercicios
-----------
Los siguientes ejercicios buscan plantear retos de trabajo para esta semana y la próxima sesión.
Se recomiendo dar una lectura a primera vista del tutorial y de los ejercicios propuestos en 
la sección material de clase. 

Ejercicio 1
------------
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
------------
Construya un programa así:

* ./programa arg1 arg2 arg3 ... argn 
* La cantidad de argumentos es arbitraria, es decir, se puede pasar 1 o muchos.
* Los argumentos serán números enteros.

El programa debe almacenar en un arreglo de enteros los argumentos y calcular:

* El promedio.
* El mínimo entero.
* El máximo entero.

Ejercicio 3
------------
Compare el siguiente programa con el del ejercicio 1.

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char **argv) {
        
        printf("argc =  %d\n",argc);
        for(int i = 0; i< argc; i++){
            printf("argv[%d] = %s\n", i, argv[i]);
        }
        exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
    }

Note que en este caso argv es una variable que almancena direcciones de otras variables que
almacenan direcciones de caracteres.

* Ejecute el código anterior.
* Haga las mismas pruebas que realizó con el ejercicio 1.
* Modifique el código de tal manera que funcione igual, pero sin utilizar notación de arreglos.

Ejercicio 4
------------
Haga un programa que cree tres procesos. Cada uno de los procesos hijos calculará el factorial 
de los enteros entre 1 y 10 comenzando por 1. Los resultados se irán imprimiendo en pantalla. 
El mensaje impreso por cada proceso debe ser lo suficientemente claro para entender cuál es el 
proceso hijo que está ejecutando la operación factorial.

Una salida tentativa se muestra a continuación (esto no quiere decir que el orden en que se 
despliegue sea el mismo):

HIJO1: fact(1) = 1

HIJO2: fact(2) = 1

HIJO2: fact(2) = 2

HIJO1: fact(2) = 2

El proceso padre tiene que esperar a que los hijos terminen utilizando la función waitpid.

* Antes de comenzar ejecute en la línea de comandos: man waitpid
* ¿Qué es un proceso Zombie?
* ¿Qué pasa con la ejecución de un proceso cuando llama a wait?
* ¿Cuando wait retorna cómo sabe el proceso padre cuál de los hijos terminó?
* ¿Cuántos wait tendría que llamar el padre para este programa?

Ejercicio 5
------------
Ejecute en la línea de comandos: man exec 

* ¿Qué hace la familia de funciones exec?
* ¿Qué biblioteca se debe incluir para poder utilizar una función de la familia exec?
* ¿Qué es una función variádica?
* Una función de la familia exec cuándo retorna?
* ¿Cómo podemos imprimir el error ocurrido si la función de la familia exec falla?

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
------------
* Divida el programa del ejercicio 2 en tres programas. Uno que calcule el promedio, otro 
  que calcule el máximo y otro que calcule el mínimo.
* Compile cada programa y genere un ejecutable, tal como lo hizo en el ejercicio 5.
* Cree un cuarto programa. Este programa recibirá los argumentos y realizará 3 fork. Luego cada 
  uno de los hijos cambiará su imagen (ejecutable) por los ejecutables de los programas 
  promedio, mínimo y máximo.
* El programa padre debe esperar que cada hijo termine.






