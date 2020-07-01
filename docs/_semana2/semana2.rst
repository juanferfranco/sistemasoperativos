Semana 2
===========
Esta semana continuaremos trabajando en la Unidad 1 del curso. Será una semana muy
movida porque abordaremos uno de los conceptos más poderosos de C: los punteros.
Adicionalmente, aprenderás sobre arreglos, memoria dinámica, estructuras de datos
y archivos.

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Fase 6 (RETO)
^^^^^^^^^^^^^^^^^^^^^
* Fecha: julio 13 y julio 17 de 2020 - 4 p.m. 
* Descripción: ejercicios para el reto.
* Recursos: realiza estos :ref:`ejercicios`.
* Duración de la actividad: 
  * Dos sesiones de 1 hora 40 minutos cada una para solución de dudas en tiempo real.
  * 5 horas de trabajo autónomo
* Forma de trabajo: individual.

.. _ejercicios:

Ejercicios
------------
Primero te voy a proponer que hagas dos guía para que trabajes los conceptos
básicos y luego una serie de ejercicios que te permitirán practicar varias
de las cosas que has hecho hasta ahora.


Guía 1: punteros, arreglos y memoria dinámica
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Realiza `esta <https://drive.google.com/file/d/19NmKVXEYB5Ud0SqbBwAe4HVYMD6LDHKD/view>`__ guía sobre punteros,
arreglos y memoria dinámica.

.. note::
        ¡Alerta de Spoiler!
    
    En este `enlace <https://docs.google.com/presentation/d/1eCo1pCzYd0YB1dYhTLJNV8w9lVAQVX6u4LQEq1oHtH0/edit#slide=id.p9>`__
    se encuentra la solución a la guía de punteros, arreglos y memoria dinámica.

Guía 2: estructuras de datos y archivos 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Realiza `esta <https://drive.google.com/open?id=1hBPkoUsGUmatr3tRm5ztr-s3hyc3OLhl>`__ guía sobre
estructuras de datos y archivos.

.. note::
        ¡Alerta de Spoiler!

    La solución a algunos puntos la puedes consultar `aquí <https://drive.google.com/file/d/1FWuPqJNWvEvHp89-ADvKu7XqdAZR6fx2/view?usp=sharing>`__

Ejercicio 1: entrada/salida
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
En la guía introductoria del lenguaje C se discutió la
función **scanf** para realizar operaciones de entrada en
C. Al realizar el ejercicios final, la calculadora,
¿Notaste algún comportamiento extraño del
programa al leer caracteres? Específicamente ``scanf("%c",&var)``.

Ten presente que al introducir texto en la terminal,
además de los caracteres visibles, se introduce un ENTER.
Así, por ejemplo, al introducir el número 325 y luego presionar
ENTER, se están ingresando 4 bytes: 0x33 0x32 0x35 0x0A. los
tres primeros bytes corresponden a los códigos ASCII de cada dígito
del número 325 y el 0x0A corresponde al código ASCII del ENTER
o nueva línea (NEW LINE).

Considere el siguiente código:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main()
    {
        int num;
        char key;
        printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
        scanf("%d",&num);
        printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
        scanf("%c",&key);
        
        return 0;
    }  

Ejecuta el código anterior. ¿Cuál es el resultado? ¿Por qué?

El primer scanf (``scanf("%d",&num);``) buscará en el flujo de entrada una
secuencia de bytes que comience con un carácter numérico y parará de leer
una vez detecte un carácter no numérico, el cual, dejará intacto en el flujo
de entrada. En este caso, ``scanf("%d",&num);`` sacará del flujo
los bytes 0x33 0x32 0x35, correspondientes a ``'3'`` ``'2'`` ``'5'``,
y dejará en el flujo el byte 0x0A (correspondiente al ENTER). Luego
convertirá la cadena de 3 bytes en ASCII al número que representan, es decir,
al 325 que en base 16 sería 0x0145 (comprueba esto con la calculadora del
sistema operativo)

El segundo scanf ``scanf("%c",&key);`` leerá un carácter del flujo de entrada.
En este caso dicho carácter está disponible y corresponde al ENTER dejado
por el scanf anterior.

¿Cómo solucionar este problema? Una posible solución será (aunque hay otras
más):

.. code-block:: c
    :linenos:

    #include <stdio.h>

        int main()
        {
            int num;
            char key;
            printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
            scanf("%d",&num);
            scanf("%c",&key); // Saco del flujo el ENTER
            printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
            scanf("%c",&key);
            return 0;
        }  

Ejercicio 2: entrada/salida
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Para complementar el ejercicio anterior, se propone analizar otros ejemplos
(Tomados de este `enlace <http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html>`__).


.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        int a = 10;
        printf("enter a number: ");
        scanf("%d", &a);
        printf("You entered %d.\n", a);
    }  

Ingresa un número y ENTER. ¿Qué ocurre? Ahora ingresa una palabra y ENTER.
¿Qué ocurre? ¿Por qué?

Ejercicio 3: scanf return
^^^^^^^^^^^^^^^^^^^^^^^^^^
scanf devuelve la cantidad de conversiones realizadas. Analiza
este ejemplo (ingresa CRTL+C si algo sale mal):

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        int a;
        printf("enter a number: ");
        while (scanf("%d", &a) != 1)
        {
            // input was not a number, ask again:
            printf("enter a number: ");
        }
        printf("You entered %d.\n", a);
    }

¿Por qué funciona así el programa? Recuerda el ejercicio 1.

Ejercicio 4: cadenas
^^^^^^^^^^^^^^^^^^^^^
Compila el código que se muestra a continuación así:
``gcc -Wall -fno-stack-protector tmp.c -o tmp``

Ejecuta el programa con estos vectores de prueba cuando se pregunte
por el nombre:

* juan
* juan-fernan
* juan-fernando-franco

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[12];
        printf("What's your name? ");
        scanf("%s", name);
        printf("Hello %s!\n", name);
    }

Explique cómo funciona el programa en cada caso.

Ejercicio 5
^^^^^^^^^^^

Repite el ejercicio anterior pero esta vez compilando
sin ``-fno-stack-protector``.

Ejercicio 6
^^^^^^^^^^^^

Finalmente repita el ejercicio anterior, pero esta vez
usando el siguiente código y compilando sin ``-fno-stack-protector``

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        scanf("%39s", name);
        printf("Hello %s!\n", name);
    }

Explica por qué en scanf especificamos un 39 sabiendo que name puede almacenar 
40 caracteres. Recuerda, de la primera guía, que todas las cadenas en C deben terminar
con un 0.

Ejercicio 7
^^^^^^^^^^^^
Usando el código anterior ingresa:  juan fernado franco.
¿Cuál es el resultado?

Ejercicio 8
^^^^^^^^^^^^^
Escribe el siguiente código:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        scanf("%39[^\n]", name);
        printf("Hello %s!\n", name);
    }

Nota la línea:``scanf("%39[^\n]", name);``. En este caso le estamos diciendo a
scanf que lea hasta 39 caracteres y hasta que encuentre un ENTER (``\n``). También
es posible indicarle a scanf que lea mientras que los caracteres estén en una
lista, por ejemplo: ``scanf("%39[a-z]", name);``.

Ejercicio 9
^^^^^^^^^^^^
¿Entonces qué usamos para leer la entrada?

Ahora que conocemos mejor los punteros y los arreglos podemos explorar la
función fgets: ``char *fgets(char *str, int n, FILE *stream)``. A esta
función le debemos pasar la dirección del buffer donde queremos colocar
los caracteres, la cantidad de caracteres y el flujo. fgets termina de leer
el flujo cuando encuentre un ENTER. Dicho ENTER se saca del flujo

Analiza el funcionamiento de fgets:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        if (fgets(name, 40, stdin))
        {
            printf("Hello %s!\n", name);
        }
    }

NOTA que en **name** quedará también el ENTER. Entonces para eliminarlo
simplemente hacemos: 

.. code-block:: c
    :linenos:

    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        char name[40];
        printf("What's your name? ");
        if (fgets(name, 40, stdin))
        {
            name[strcspn(name, "\n")] = 0;
            printf("Hello %s!\n", name);
        }
    }

**strcspn** buscará en la cadena **name** el primer *match* con
``\n`` y devolverá la posición en **name** en la cual fue encontrado
el *match*. 

Ejercicio 10
^^^^^^^^^^^^^^
(Este ejercicio es tomado de `aquí <https://www.geeksforgeeks.org/pointer-array-array-pointer/>`__)

Relación arreglos y punteros

.. code-block:: c
    :linenos:

    #include<stdio.h> 

    int main() 
    { 
        int *p;  
        int (*ptr)[5];  
        int arr[5]; 
        
        p = arr; 
        ptr = &arr;  
        printf("p = %p, ptr = %p\n", p, ptr); 
        p++;  
        ptr++; 
        printf("p = %p, ptr = %p\n", p, ptr); 
        return 0; 
    }

Ejecuta el programa anterior. El resultados es:

.. code-block:: c
    :linenos:
    
    p = 0x7fff4f32fd50, ptr = 0x7fff4f32fd50
    p = 0x7fff4f32fd54, ptr = 0x7fff4f32fd64


En la expresión ``int * p;`` p es una variable de tipo
``int *``. En este tipo de variables se almacenan las
``direcciones`` de variables de tipo ``int``. Por tanto, ``*p``
(sin colocar int antes del ``*``) es de tipo ``int`` porque 
p es de tipo ``int *``.

En la expresión ``int (*ptr)[5];`` ptr es una variable de tipo
``int (*)[5]``. En este tipo de variables se almacenan direcciones
de variables de tipo ``int [5]``, es decir, variables de tipo
arreglo de cinco posiciones. Por tanto, ``*ptr`` es de tipo 
``int [5]`` porque ptr es de tipo ``int (*)[5]``.

En la expresión ``p = arr;`` arr es el nombre del arreglo y un puntero
al primer elemento del arreglo.
En este caso `arr` es de tipo ``int *`` porque el primer elemento
del arreglo es de tipo ``int``. Por tanto, ``*arr`` 
será tipo ``int``.

En la expresión ``ptr = &arr;`` ``&arr`` es la dirección del arreglo.
``&arr`` es tipo ``int (*)[5]``.

La expresión ``printf("p = %p, ptr = %p\n", p, ptr);`` imprime el
contenido de p y ptr. Según el resultado
``(p = 0x7fff4f32fd50, ptr = 0x7fff4f32fd50`)``, la dirección del
arreglo y del primer elemento del arreglo es la misma; sin embargo,
como p es tipo ``int *``, la expresión ``p++`` hará que p apunte
(almacene la dirección) al siguiente entero. En cambio, en la
expresión ``ptr++;`` ptr apuntará al siguiente arreglo de 5
enteros (5 enteros ocupan 20 bytes en memoria considerando
que cada entero ocupa 4 bytes), ya que ptr es de tipo
``int (*)[5]``.

Ejercicio 11: análisis de una expresión más compleja
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

El siguiente ejercicio es más complejo que el anterior, sin embargo,
se analiza de igual manera. Considera el siguiente código:

.. code-block:: c
    :linenos:

    #include <stdio.h>

    int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

    int main(void) {
        int (*p)[3][4] = &arr;
        printf("%d\n", ( (*p)[2] )[3] );
        printf("%d\n", *( *(*p + 2) + 3 ) );
        return 0;
    }


``arr`` es un arreglo de arreglos, es decir, es una arreglo de 3 arreglos
de 4 enteros cada uno.

``arr`` es el nombre del arreglo de arreglos y un puntero al primer elemento
del arreglo. Por tanto, ``arr`` es de tipo ``int (*)[4]`` ya que el primer elemento
de arr es un arreglo de tipo ``int [4]``.

``p`` es un puntero que almacena la dirección de un arreglo de arreglos.
Por tanto, p es de tipo ``int (*)[3][4]``.

Si ``p`` es de tipo ``int (*)[3][4]`` entonces ``*p`` será de tipo ``int [3][4]`` o
``int (*)[4]`` (un puntero al primer elemento del arreglo de arreglos).

El operador ``[]`` en la expresión ``(*p)[2]`` es equivalente a ``*( *p + 2)``.
Como el tipo de ``(*p + 2)`` es ``int (*)[4]`` el tipo de ``*( *p + 2)``
será ``int [4]``. la expresión ``(*p)[2]`` accede al tercer elemento de arr, es
decir, a ``{9,10,11,12}`` que es de tipo ``int [4]``.

Por último, como ``(*p)[2]`` es tipo ``int [4]``, entonces ``( (*p)[2] )[3] )`` es
tipo int y corresponderá al cuarto elemento del tercer arreglo de arr.

Nota que ``( (*p)[2] )[3] )`` es equivalente a ``*( (*p)[2] + 3)`` que a su
vez es equivalente a  ``*( * ( *p + 2)+ 3)``

El programa imprimirá el número ``12``.

La expresión ``printf("%d\n", *( * ( *p + 2)+ 3));`` al ser equivalente a
``printf("%d\n", ( (*p)[2] )[3] );`` también mostrará un ``12``.
