Unidad 2: Procesos e hilos
=============================

Introducción
--------------

En esta unidad vamos a estudiar en detalle algunas
abstracciones que ofrece el sistema operativo para hacer
uso de los recursos de procesamiento: los procesos y los hilos.

Propósito de aprendizaje
******************************

Comprender el concepto de proceso, programa, hilo y su diferencia.


Lecturas y ejercicios
------------------------

Sesión 1
***********

Ejercicio 1: concepto de proceso
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vamos al tablero para analizar juntos el concepto de proceso.
Usaremos `esta <https://drive.google.com/open?id=1xojM0NJibnQdIT_UzzrnlS1Fj5NSNtkVNfCnJNBIBYs>`__ 
presentación como material de referencia.

Ejercicio 2: preguntas sobre los conceptos básicos de los procesos 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Te voy a proponer que recuerdes los conceptos anteriores respondiendo 
las siguientes preguntas en tu bitácora de trabajo:

* ¿Cuál es la diferencia entre un programa y un proceso?
* ¿Puedo tener múltiples procesos corriendo el mismo programa?
* ¿Para qué sirve el stack de un proceso?
* ¿Para qué sirve el heap de un proceso?
* ¿Qué es la zona de texto de un proceso?
* ¿Dónde se almacenan las variables globales inicializadas?
* ¿Dónde se almacenan las variables globales no inicializadas?
* ¿Cuáles son los posibles estados de un proceso en general? Ten en cuenta
  que esto varía entre sistemas operativos.

¿Compartimos el resultado entre todos?

Ejercicio 3: creación de procesos 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vamos a analizar juntos el siguiente programa que te muestra cómo 
puedes crear procesos:

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

Trabajo autónomo 1
*******************

Realiza los siguientes ejercicios para la próxima sesión:


Ejercicio 4: lectura sobre procesos 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ejecuta en la línea de comandos: man waitpid. Lee la información que está allí 
y responde estas preguntas: 

* ¿Qué es un proceso Zombie?
* ¿Qué pasa con la ejecución de un proceso cuando llama a wait?
* ¿Cuando wait retorna cómo sabe el proceso padre cuál de los hijos terminó?

(Tiempo estimado 1 hora 25 minutos)

Ejercicio 5: reto procesos y llamado al sistema WAIT
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Realiza programa que cree tres procesos. Cada uno de los procesos hijos
calculará el factorial de los enteros entre 1 y 10 comenzando por 1.
Los resultados se irán imprimiendo en pantalla. El mensaje impreso por
cada proceso debe ser lo suficientemente claro para entender cuál es el
proceso hijo que está ejecutando la operación factorial.

Una salida tentativa se muestra a continuación (esto no quiere decir
que el orden en que se despliegue sea el mismo):

.. code-block:: bash

    HIJO1: fact(1) = 1
    HIJO2: fact(2) = 1
    HIJO2: fact(2) = 2
    HIJO1: fact(2) = 2
    HIJO1: fact(3) = 6


El proceso padre tiene que esperar a que los hijos TERMINEN utilizando
el llamado al sistema `WAIT <https://man7.org/linux/man-pages/man2/wait.2.html>`__.

¿Cuántos wait tendría que llamar el padre para este programa?

(Tiempo estimado 1 hora 25 minutos)

Sesión 2
**********

Ejercicio 6: imagen de un proceso
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Analicemos juntos el concepto de imagen de un proceso. Vamos para 
el tablero.


Ejercicio 7: cambiar la imagen de un proceso
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Ejercicio 8: analiza el ejercicio anterior
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Escribe tu mismo y repite el ejercicio anterior.
* Analiza detenidamente el código.
* Analiza detenidamente qué está pasando. Entonces cuál es la diferencia entre
  un proceso y un programa? En el ejercicio ¿Cuál es el programa? ¿Cuál es el proceso?
  ¿Cuáles son las imágenes que el proceso ejecutó?

Trabajo autónomo 2
**********************

Ejercicio 9: reto procesos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Construye TRES programa que se ejecutarán, cada uno, así:

* ./programa arg1 arg2 arg3 ... argn
* La cantidad de argumentos es arbitraria, es decir, se puede pasar 1 o muchos.
* Los argumentos serán números enteros.

Los programas deben almacenar en un arreglo de enteros los argumentos.

Un programa calcula el promedio, otro el el mínimo entero y el otro 
el máximo entero.

* Compila cada programa y genera un ejecutable por cada uno.
* Crea un cuarto programa. Este programa que reciba los mismos argumentos y luego realizará
  3 fork. Luego cada uno de los hijos cambiará su imagen por los ejecutables de los programas 
  que calculan el promedio, mínimo y máximo.
* El programa padre debe LANZAR los procesos en paralelo, es decir, una vez estén corriendo 
  todos los programas se puede esperar  a que terminen.

(Tiempo estimado: 2 horas 50 minutos)


..
  Ejercicio X
  ^^^^^^^^^^^^^

  En este `otro enlace <https://drive.google.com/file/d/1t_MhYGFmN7ti6U4TYNcpgigJESFgb7_H/view>`_
  puedes leer una explicación detallada de los pasos que ocurren al hacer un llamado al sistema.

  Explica en tus propias palabras cómo funciona un llamado al sistema. 

  Ejercicio X
  ^^^^^^^^^^^^^

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


  Ejercicio X
  ^^^^^^^^^^^^
  En `este <https://drive.google.com/file/d/1Z5mewc5DJ6hQqpYUL7nkp4k8WNA9i1JQ/view>`__
  pdf se pueden observar algunos llamados al sistema operativo. Analiza de nuevo
  el siguiente ejemplo, PERO usando eclipse y depurando el programa de tal manera
  que puedas controlar la ejecución de ambos procesos.

  Ejercicio X: repaso
  ^^^^^^^^^^^^^^^^^^^^

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


  Ejercicio 10 
  ^^^^^^^^^^^^

  Ahora vamos a familiarizarnos con el concepto de hilo. Ingresa 
  a `este <http://www.albahari.com/threading/>`__ sitio y lee detalladamente
  su contenido hasta la sección Creating and Starting Threads (sin incluirla,
  claro, a menos que quieras).

  * ¿Qué es un hilo?
  * ¿Cuál es la diferencia entre un método y un hilo?
  * ¿La ejecución de los hilos es determinística?
  * ¿Cuál es la diferencia entre un método estático y un
    método no estático?
  * ¿Cuál es la diferencia entre un hilo y un método estático?
  * ¿Para qué sirve un lock?

  Ejercicio 10
  ^^^^^^^^^^^^^^^

  En `este <https://drive.google.com/open?id=1I5G4rRNEzmAuOgpEtgDra8TPUTpIPHTXCTwzHF93wHE>`__
  enlace encontrarás 4 ejercicios que te mostrarán cómo crear hilos en C, cómo compilar
  un programa que tiene hilos, esperar a qué los hilos terminen, cómo lanzar varios hilos
  a la vez y esperar a que terminen.


  PROYECTO 1
  ^^^^^^^^^^^^

  Se tiene un archivo de entrada que tiene en cada línea dos cadenas de texto
  separadas por un espacio. A la primera cadena la llamaremos clave y a la segunda
  valor. Clave es una cadena de caracteres y valor es un número entero. 
  El archivo tendrá máximo 100 líneas, clave será máximo de 20 caracteres y valor
  será menor a 1000 y mayor a -1000.

  * Crea un programa llamado p1.c que lea el archivo de entrada y genere un archivo
    de salida con las parejas ordenadas por VALOR de mayor a menor. Una pareja por línea.

  * Crea un programa llamado p2.c que lea el archivo de entrada y escriba en un archivo de 
    salida cada pareja comenzando por la última y terminando por la primera, es decir,
    en orden contrario al que aparecen en el archivo de entrada.

  * Crea un programa llamado p3.c que cree dos procesos para ejecutar los programas anteriores.
    Los procesos deben lanzarse para que se ejecuten en paralelo. Una vez los dos procesos
    sean lanzados, p3 debe esperar a que terminen. Debe leer los archivos de salida generados
    por p1 y p2 e imprimir en pantalla los resultados.

  * TEN EN CUENTA QUE al final, en la terminal, solo lanzarás un proceso, el que corre a p3. p3
    se encarga del resto. Lanza el proceso así: ./p3 In Out1 Out2

  * p3 es el nombre del ejecutable principal, el proceso que crea los otros procesos. In es
    el archivo con la información de entrada y Out1 es el archivo de salida para p1 y Out2
    el archivo de salida para p2. Ten en cuenta que In, Out1 y Out2 son parámetros, es decir,
    puedes colocar cualquier nombre en ellos equivalente al nombre de los archivos.


  PROYECTO 2
  ^^^^^^^^^^^^

  Se tiene un archivo de entrada que posee por línea 3 cadenas de caracteres
  separadas por espacios:  nombre ocupación edad. 
  Nombre y ocupación son cadenas de caracteres que representan texto mientras 
  que edad representa valores numéricos. Se tendrán máximo 100 líneas y 
  20 caracteres máximo por cadena.


  * Crea un programa llamado prog.c que lea el archivo de entrada, luego debe organizar la información
    en una estructura de datos, luego debe IMPRIMA en pantalla el contenido de la estructura de datos.
    OJO no del archivo, sino de la información cargada en la estructura de datos proveniente del archivo.
    
  * Crea 2 hilos para procesar de diferente manera la información y finalmente imprima el contenido
    de los archivos de salida que producirá cada hilo. Los hilos deben lanzarse para que se ejecuten
    en paralelo, OJO, NO DE MANERA SECUENCIAL, SI EN PARALELO.

  * El Hilo 1 escribe en el archivo de salida1 los registros del archivo de entrada, pero en orden
    inverso, es decir, primero el último y de último el primero.

  * El Hilo 2 escribe en el archivo de salida 2 los registros ordenados por ocupación en orden alfabético.

  * NO OLVIDES Hilo 1 e Hilo 2 deben lanzarse a la vez. Una vez Hilo 1 e Hilo 2 finalicen se debe mostrar
    en pantalla el resultado de los archivos de salida.

  * El programa se ejecutará así: ./prog In Out1 Out2

  * prog es el nombre del ejecutable, In especifica el nombre del archivo de entrada
    Out1 y Out2 especifican el nombre de los los archivos de salida 1 y 2 respectivamente. RECUERDA que
    In, Out1 y Out2 son parámetros.