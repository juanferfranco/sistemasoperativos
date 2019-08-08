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