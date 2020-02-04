Semana 3
===========

Durante esta semana continuaremos explorando el lenguaje de programación C.
En particular, memoria dinámica, estructuras de datos y archivos.


Material de clase
------------------

En este `enlace <https://drive.google.com/file/d/19NmKVXEYB5Ud0SqbBwAe4HVYMD6LDHKD/view?usp=sharing>`__
encontraremos el material de la semana pasada sobre punteros,
arreglos y memoria dinámica. Y en este otro `enlace <https://drive.google.com/open?id=1hBPkoUsGUmatr3tRm5ztr-s3hyc3OLhl>`__.
estará el material sobre estructuras de datos y archivos.

.. note::
    ¡Alerta de Spoiler!

La solución a algunos puntos del material sobre arreglos y memoria
dinámica está `aquí <https://docs.google.com/presentation/d/1eCo1pCzYd0YB1dYhTLJNV8w9lVAQVX6u4LQEq1oHtH0/edit?usp=sharing>`__
. Para la parte de estructuras de datos y archivos, consultar `aquí <https://drive.google.com/file/d/1FWuPqJNWvEvHp89-ADvKu7XqdAZR6fx2/view?usp=sharing>`__


Ejercicio para la clase
-------------------------

Se propone realizar un programa que:

* Solicite el tamaño de un arreglo.
* Solicite uno por uno sus elementos.
* Realice una función para imprimir el contenido del arreglo. A esta
  función deberá pasar la dirección del arreglo y el tamaño.
* Permita insertar un nuevo elemento en el arreglo mediante la
  selección de la posición deseada en el arreglo que irá desde 1
  hasta el tamaño del arreglo.

.. note::
    ¡Alerta de Spoiler!

El siguiente código muestra una posible solución:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #define MAX 100

    void printArray(int *pdata,int n){

        printf("\n The array is: \n");

        for(int i = 0; i< n ;i++) {
            printf("data[%d]: %d\n",i,  *(pdata+i) );
        }
    }

    int main(){
        int n;
        int data[MAX];
        int position;

        printf("Enter the length of the array: ");
        scanf("%d", &n);
        printf("Enter %d elements of the array \n",n);

        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
        }
        printArray(data, n);

        printf("\n Enter a position where you want to insert: ");
        scanf("%d", &position);
        position--;
        for(int i = n-1;i >= position; i--){
            data[i+1] = data[i];
        }
        printf("\nEnter the value: ");
        scanf("%d", &data[position]);

        printArray(data,n+1);
        return 0;
    }

Ejercicio: archivos
--------------------

Complementar con las siguientes lecturas el manejo de archivos
en C:

* `Manejo básico <https://www.geeksforgeeks.org/basics-file-handling-c/>`__
* `¿Fin de un archivo o un error? <https://www.geeksforgeeks.org/eof-and-feof-in-c/>`__
* `¿Cómo vamos a gestionar los errores en C? <https://www.geeksforgeeks.org/error-handling-c-programs/>`__

Ejercicio: analizar 
--------------------

Analizar el funcionamiento de este ejemplo. Utilizar el *debugger* de eclipse.

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

Ejercicio: problema
--------------------

Escriba una función que permita encontrar los elementos comunes de
dos arreglos de enteros. El encabezado de la función es:

.. code-block:: c
   :linenos:


    uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize)

* La función debe recibir las direcciones de memoria de los dos arreglos
  a comparar y del arreglo resultado. También debe recibir el tamaño de
  cada arreglo.
* Debe devolver la cantidad de elementos comunes encontrados o 0 si no
  encuentra.
* Incluya el archivo de cabeceras ``#include <stdint.h>`` para que el
  compilador encuentra la definición de ``uint8_t``.
* Cree un programa que solicite el tamaño de los arreglos y sus
  elementos.
* El programa debe mostrar el resultado de la función.
* Antes de insertar un elemento en el arreglo resultado debe verificar
  que este no exista en el arreglo, es decir, el arreglo resultado
  no debe tener elementos repetidos.

El flujo del programa será:

* Solicite el tamaño del primer arreglo.
* Ingrese los elementos del primer arreglo.
* Solicite el tamaño del segundo arreglo.
* Ingrese los elementos del segundo arreglo.
* Indicar cuántos elementos comunes se encontraron y el arreglo
  con dichos elementos.

Ejercicio: problema
--------------------

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
