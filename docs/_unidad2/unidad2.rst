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


Trayecto de actividades
------------------------

Sesión 1
**********

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

    int main(int argc, char *argv[])
    {
        pid_t pid_hijo;

        printf("Este proceso va a crear otro proceso\n\n");
        printf("El pid del programa padre es: %d\n", (int)getpid());
        pid_hijo = fork();
        switch (pid_hijo)
        {
        case -1:
        { /* Error */
            printf("Error al crear el proceso");
            return -1;
            break;
        }
        case 0:
        { /* Código ejecutado por el hijo */
            printf("PROCESO HIJO:\n");
            printf("Soy el hijo, mi PID es %d\n", (int)getpid());
            break;
        }
        default:
        { /* Código ejecutado por el padre */
            printf("PROCESO PADRE: Proceso hijo con PID %d creado\n", (int)pid_hijo);
            break;
        }
        }
        /* Esta línea será ejecutada por ambos procesos, pero en
        en diferente contexto (el de cada proceso) */
        printf("Soy el proceso %d terminando \n", (int)getpid());
        exit(EXIT_SUCCESS);
    }

Trabajo autónomo 1
***********************

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
*****************************

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

Sesión 3: concepto de hilo
****************************

Ejercicio 10 
^^^^^^^^^^^^^

Vamos al tablero para introducir el concepto general de hilo.

Ejercicio 11
^^^^^^^^^^^^^^

Ahora si, vamos a crear un hilo en Linux:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    void* imprime_x(void *param){
        while(1) printf("x");
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID;
        pthread_create(&threadID,NULL,&imprime_x,NULL);
        while(1) printf("o");
        exit(EXIT_SUCCESS);
    }

Compila el código así:

.. code-block:: bash

    gcc -Wall main.c -o main -lpthread

Ejecuta el código como siempre, pero esta vez para terminar el programa debes enviar 
la señal ``CRTL+C`` a la terminal.

Ejecuta en la terminal: 

.. code-block:: bash

  man pthread_create

* ¿Cuáles son los argumentos y para qué sirven?

Ejercicio 12
^^^^^^^^^^^^^^

* Modifica el ejercicio anterior de tal manera que cada hilo ejecute 1000 veces la impresión 
  en pantalla.
* Observa la ejecución y repite varias. ¿Notas algún cambio? ¿Podrías intentar explicar qué 
  está pasando?

Ejercicio 13
^^^^^^^^^^^^^^

Ahora vas a escribir este código, compilarlo y ejecutarlo:

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    struct threadParam_t
    {
        char character;
        int counter;
    };


    void* imprime(void *parg){
        struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
        for(int i = 0; i < pargTmp->counter;i++){
            printf("%c",pargTmp->character);
        }
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID1;
        pthread_t threadID2;

        struct threadParam_t threadParam1 = {'a',30000};
        struct threadParam_t threadParam2 = {'b',20000};

        pthread_create(&threadID1,NULL,&imprime, &threadParam1);
        pthread_create(&threadID2,NULL,&imprime, &threadParam2);

        exit(EXIT_SUCCESS);
    }

* ¿Qué pasó al ejecutarlo? 
* Notaste que el programa no hace nada, te animas a proponer un hipótesis 
  al respecto de lo que puede estar ocurriendo?

Ejercicio 14
^^^^^^^^^^^^^^

El problema con el código anterior es que el proceso está terminando antes 
que los hilos puedan comenzar incluso a funcionar. Por tanto, será necesario 
que el hilo principal espere a que los dos hilos creados terminen antes de 
que el terminar. 

.. code-block:: c

    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>

    struct threadParam_t
    {
        char character;
        int counter;
    };


    void* imprime(void *parg){
        struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
        for(int i = 0; i < pargTmp->counter;i++){
            printf("%c",pargTmp->character);
        }
        return NULL;
    }


    int main(int argc, char *argv[]){
        pthread_t threadID1;
        pthread_t threadID2;

        struct threadParam_t threadParam1 = {'a',30000};
        struct threadParam_t threadParam2 = {'b',20000};

        pthread_create(&threadID1,NULL,&imprime, &threadParam1);
        pthread_create(&threadID2,NULL,&imprime, &threadParam2);

        pthread_join(threadID1,NULL);
        pthread_join(threadID2,NULL);

        exit(EXIT_SUCCESS);
    }

* ¿Qué debes hacer para esperara a que un hilo en particular termine?
* Considera los siguientes fragmentos de código y piensa cuál puede ser la 
  diferencia entre ambos:

.. code-block:: c

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_join(threadID1,NULL);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);
    pthread_join(threadID2,NULL);


.. code-block:: c

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);
    pthread_join(threadID1,NULL);
    pthread_join(threadID2,NULL);

Trabajo autónomo 3
***********************


Ejercicio 15: condiciones de carrera
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
(Tiempo estimado: 20 minutos)

Escribe y ejecuta el siguiente código:

.. code-block:: c

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

* ¿El resultado era el esperado?
* Aumenta el número de iteraciones a 1000, luego a 10000, luego a 100000. ¿Qué pasa 
  cuando ejecutas el código varias veces?
* Te animas a explicar qué está ocurriendo? (no te preocupes, si no te lo imaginas está 
  bien porque ese será una de los temas de la próxima unidad).
* ¿Qué propones para solucionar el problema anterior?



Ejercicio 16: RETO
^^^^^^^^^^^^^^^^^^^^
(Tiempo estimado: 2 horas 30 minutos)

Se tiene un archivo de entrada que posee por línea 3 cadenas de caracteres
separadas por espacios así:  nombre ocupación edad. 
Nombre y ocupación son cadenas de caracteres que representan texto mientras 
que edad representa valores numéricos. Se tendrán máximo 100 líneas y 
20 caracteres máximo por cadena.

* Crea un programa llamado prog.c que lea el archivo de entrada, luego debe organizar la información
  en una estructura de datos, luego debe IMPRIMIR en pantalla el contenido de la estructura de datos.
  OJO no del archivo, sino de la información cargada en la estructura de datos proveniente del archivo.
  
* Crea 2 hilos para procesar de diferente manera la información. Los hilos deben lanzarse para que se ejecuten
  en paralelo, OJO, NO DE MANERA SECUENCIAL, SI EN PARALELO.

* El Hilo 1 escribe en el archivo de salida1 los registros del archivo de entrada, pero en orden
  inverso, es decir, primero el último y de último el primero.

* El Hilo 2 escribe en el archivo de salida 2 los registros ordenados por ocupación en orden alfabético.

* NO OLVIDES Hilo 1 e Hilo 2 deben lanzarse a la vez. Una vez Hilo 1 e Hilo 2 finalicen, el hilo 
  principal debe abrir los archivos de salida e imprimir el resultado, primero del Hilo 1 y luego del 
  Hilo 2

* El programa se ejecutará así: ./prog In Out1 Out2

* prog es el nombre del ejecutable, In especifica el nombre del archivo de entrada
  Out1 y Out2 especifican el nombre de los los archivos de salida 1 y 2 respectivamente. RECUERDA que
  In, Out1 y Out2 son parámetros.




Sesión 4
************

En esta sesión vamos a revisar el concepto de hilo en otro lenguaje de 
programación popular: C#. Adicionalmente vamos refinar un poco más 
algunos conceptos asociados.

Ejercicio 17
^^^^^^^^^^^^^^

Vamos a calentar motores analizando previamente este código entre todos:

.. code-block:: c

    using System;

    namespace typeValueVsReference
    {
        internal struct VectorValue
        {
            public int X { get; set; }
            public int Y { get; set; }

            public VectorValue(int x, int y)
            {
                X = x;
                Y = y;
            }
            
            public void Print()
            {
                Console.WriteLine($"VectorValue: {X},{Y}");
            }
        }

        internal class VectorReference
        {
            public int X { get; set; }
            public int Y { get; set; }

            public VectorReference(int x, int y)
            {
                X = x;
                Y = y;
            }

            public void Print()
            {
                Console.WriteLine($"VectorReference: {this.X},{this.Y}");
            }
        }


        internal static class Program
        {
            private static void Main(string[] args)
            {
                var vectorValue = new VectorValue(1, 2);
                var vectorReference = new VectorReference(3, 4);
                
                Console.WriteLine("Vectors before:");
                vectorValue.Print();
                vectorReference.Print();
                
                ChangeVector(vectorValue);
                ChangeVector(vectorReference);
                
                Console.WriteLine("Vectors after: ");
                vectorValue.Print();
                vectorReference.Print();
            }

            private static void ChangeVector(VectorValue vector)
            {
                vector.X = vector.X * 10;
                vector.Y = vector.Y * 10;
            }

            private static void ChangeVector(VectorReference vector)
            {
                vector.X = vector.X * 10;
                vector.Y = vector.Y * 10;
            }
        }
    }

Ejercicio 18
^^^^^^^^^^^^^

Ahora vamos a familiarizarnos con el concepto de hilo en C#. Ingresa 
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

Trabajo autónomo 4
*********************
(Tiempo estimado: 2 horas 50 minutos)

En este bloque de trabajo autónomo te voy a pedir que le des una 
nueva iteración a esta unidad, mira de nuevo cada ejercicio y las 
notas que tomaste y revisa de nuevo la solución a ejercicios y RETOS.


Evaluación de la Unidad
---------------------------
(Tiempo total estimado: 9 horas).

Te voy a proponer para esta evaluación dos proyectos para realizar. 
Uno de los proyectos se enfoca en procesos y el otro en hilos. 

.. warning:: ESCOGE ENTRE pzip y wish

    Vas a seleccionar uno de los dos problemas wish (PROCESOS) o pzip (hilos)


.. note:: LOS PROYECTOS SON TOMADOS DEL LIBRO Operating Systems: Three Easy Pieces

    Los proyectos se pueden ver `aquí <https://github.com/remzi-arpacidusseau/ostep-projects>`__. 


Consideraciones
*****************

#. Ingresa a tu repositorio privado para esta evaluación 
   `aquí <https://classroom.github.com/a/DDbCG7wQ>`__.
#. En el repositorio encontrarás realmente tres proyectos: process-shell (wish), 
   concurrency-pzip (pzip) y wzip. Los que nos ocupan son process-shell y 
   pzip; sin embargo, pzip es una versión concurrente, usando hilos, de 
   wzip. Por tanto, tendrás que solucionar wzip para luego pasar a 
   paralelizarlo Y COMPARAR la ganancia.
#. En esta evaluación, como los repositorios son privados, no vas a correr 
   la solución en GitHub. La solución y los vectores de prueba se realizarán 
   localmente. 
#. En el archivo README.md vas a explicar cómo solucionaste cada problema. 
   NO OLVIDES comparar pzip con wzip.
#. Criterio de evaluación: 

   * wish: 2 unidades.
   * pzip: 2 unidades.
   * Sustentación: 0.5 unidades cada problema.

