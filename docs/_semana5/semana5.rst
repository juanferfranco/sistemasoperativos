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




