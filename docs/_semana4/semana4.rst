Semana 4
===========
Esta semana continuaremos explorando el lenguaje de programación C. Continuamo con la
última parte de la guía relacionada con archivos.

Material de clase
------------------
El material que vamos a trabajar esta semana en clase lo pueden encontrar en este
`enlace <https://drive.google.com/open?id=1hBPkoUsGUmatr3tRm5ztr-s3hyc3OLhl>`__.

.. note::
    ¡Alerta de Spoiler!

En este `enlace <https://drive.google.com/file/d/1FWuPqJNWvEvHp89-ADvKu7XqdAZR6fx2/view?usp=sharing>`__ 
se encuentra la solución a algunos puntos de la guía.

Códigos segunda sesión
------------------------
En la segunda sesión de esta semana analizaremos este ejemplo:

.. code-block:: c
   :linenos:

    #include <stdio.h>

    char nombres[3][20] = {"fulano","mengano","perano"};

    int main (void){
        char *a;
        char (*b)[20];
        char *c;
        char (*d)[3][20];

        a = &nombres[0][0];
        printf("el nombre es %s \n", a);
        b = nombres;
        c = &nombres[0][0];
        d = &nombres;
        for(int i = 0; i < 3; i++ ){
            printf("char (*)[] el nombre[%d] es %s \n", i , (char * ) (b+i));
            printf("char *: el nombre[%d] es %s \n", i , (char * ) ( c + (i*2) ));
            printf("char (*)[][]: el nombre[%d] es %s \n", i , (char * ) (d+i));
            
        } 
        return 0;
    }

También analizaremos el ejemplo que está en 
`este <https://www.geeksforgeeks.org/pointer-array-array-pointer/>`__ sitio

Ejercicio 1
-------------
Considere el problema de encontrar los elementos comunes entre dos arreglos.

* Se debe crear una función que busque los elementos comunes entre dos arreglos.
* Cree un programa que solicite el tamaño de los arreglos y los elementos de estos.
* Los elementos son números enteros.
* La función debe recibir las direcciones de memoria de los arreglos y debe devolver 1 si
  encuentra elementos y 0 si no los encuentra.
* El programa debe mostrar el resultado.
* Antes de insertar un elemento en el arreglo resultado debe verificar que este no exista 
  en el arreglo, es decir, el arreglo resultado no debe tener elementos repetidos.

El flujo del programa será:

* Solcita el tamaño del primer arreglo.
* Ingresa los elementos del primer arreglo.
* Solicita el tamaño del segundo arreglo.
* Ingresa los elementos del segundo arreglo.
* Si hay elementos comunes muestra la cadena The common elements in the two arrays are
  y luego los elementos, de lo contrario muestra la cadena There are no 
  common elements in the two arrays.

