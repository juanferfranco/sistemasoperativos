Unidad 1: Lenguaje C
=======================

Introducción
--------------

Para poder abordar el curso de sistemas operativos con un enfoque
práctico necesitamos aprender un nuevo lenguaje de programación
llamado lenguaje C. Este lenguaje resulta muy apropiado para nuestros
propósitos por su gran cercanía con los conceptos que estudiaremos.

C en un lenguaje fácil de aprender y muy poderoso. En pocas semanas
estarás programando en este lenguaje.

Propósito de aprendizaje
***************************

Aplicar el lenguaje de programación C en la solución de problemas
simples haciendo uso de variables, estructuras de control, punteros,
estructuras de datos, funciones y archivo.

Trayecto de actividades
----------------------------

Sesión 1
*************
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 1: Introducción a Git y GitHub 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. toctree::
    :maxdepth: 1

    Introducción a Git y GitHub <./introGit>

Trabajo autónomo 1
*********************
(Tiempo estimado: 2 horas 50 minutos)

Ejercicio 2: terminar y darle una segunda pasada a la sesión 1
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Termina la guía de introducción a Git y GitHub y dale una segunda pasada. 

Ejercicio 3: entorno de trabajo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para poder trabajar en los ejercicios vas a necesitar un ambiente de trabajo basado en Linux.

Te voy a pedir que le des una mirada a  `este video <https://youtu.be/ZPpo-uViT_o>`__ para 
que te hagas una idea de qué es Linux.

Hay varias opciones para tener Linux funcionando en tu computador: lo puedes instalar en una 
memoria, en una partición de tu computador, en una máquina virtual o incluso en 
`WSL2 <https://docs.microsoft.com/en-us/windows/wsl/install-win10>`__.

La opción que te voy a recomendar es instalar el sistema operativo en una memoria USB externa.

Vas a necesitar dos memorias USB. Una grande (> 16GB), donde instalarás tu sistema operativo
y otra más pequeña (8GB) donde grabaras el instalador. Trata de utilizar la USB más rápida y
más grande para instalar tu sistema operativo.

Te voy a dejar unos videos de ayuda:

* Este `video <https://www.youtube.com/watch?v=zSGZe8NSEAc>`__ 
  te muestra como grabar en la USB pequeña el instalador. En este caso la distribución es PopOS,
  es la misma que yo uso; sin embargo, puedes grabar la que más te guste, por ejemplo Ubuntu.
  Ten presente que la versión del video no será la última. También, debes investigar
  cómo entrar al menú de configuración de tu BIOS para que ajustes el orden de boot. 
  Nota que debes darle prioridad a la USB para que al tenerla conectada arranques el 
  instalador del sistema operativo.

* Ahora, este video `video <https://www.youtube.com/watch?v=RR9Vgytjj24>`__ te mostrará
  cómo instalar, usando la USB pequeña con el instalador, tu sistema operativo en la USB grande.
  Te recomiendo iniciar a ver el video en el minuto 6:29, donde comienza en si el proceso
  de instalación. Una vez termines de instalar Linux en la USB grande, NO OLVIDES desconectar la USB
  pequeña para que tu computador inicie con la versión instalada de Linux en la USB grande.

* Si tu computador no arranca en Linux debes reiniciarlo y entrar el menu de boot (debes indagar 
  cómo hacerlo en tu computador) y seleccionar Linux.

Si lo anterior no te funciona, prueba con una `máquina virtual <https://youtu.be/tNUgLsXD7xg>`__ o con WSL2.
Ten presente que las versiones de los videos pueden no coincidir con las versiones actuales.

Ejercicio 4: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux funcionando debes instalar unas cuentas herramientas:

Abren la terminal y ejecuta los comandos:

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 5: instala un par de entornos de desarrollo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para el curso te recomiendo que instales dos entornos de desarrollo:

#. `Eclipse <https://www.eclipse.org/downloads/packages/>`__
#. `Visual Studio Code <https://code.visualstudio.com/>`__

Eclipse te permitirá tener un depurador visual de código, pero la verdad
es un poco lento. Visual Studio, no tiene un depurador visual tan rico, pero es
muy liviano. Yo uso ambos. Normalmente trabajo con Visual Studio Code y cuando
algo no me funciona lo pruebo con Eclipse.

Sesión 2
*************
(Tiempo estimado: 1 hora 40 minutos)

En esta sesión vas a trabajar con el profe en un taller guiado 
introductorio al lenguaje de programación. Aprenderás a compilar programas y 
explorarás el concepto de puntero.


Trabajo autónomo 2
*********************
(Tiempo estimado: 2 horas 50 minutos)

Ejercicio 6: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque vamos a introducir 
el lenguaje de programación con el cual estudiaremos todos los conceptos del curso: ``C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

Sesión 3
*************
(Tiempo estimado: 1 hora 40 minutos)

En esta sesión vas a continuar trabajando con el ejercicio 6.


Trabajo autónomo 3
*********************
(Tiempo estimado: 2 horas 50 minutos)

Continuarás avanzando con el ejercicio 6.

Sesión 4
*************
(Tiempo estimado: 1 hora 40 minutos)

En esta sesión vas a continuar trabajando con el ejercicio 6.


Trabajo autónomo 4
*********************
(Tiempo estimado: 2 horas 50 minutos)

Continuarás avanzando con el ejercicio 6.

Sesión 5
*************
(Tiempo estimado: 1 hora 40 minutos)

En esta sesión terminarás el ejercicio 6.

Trabajo autónomo 5
*********************
(Tiempo estimado: 2 horas 50 minutos)

Prepárate para la sesión de RETOS antes de la evaluación. Revisa 
el material que llevamos hasta hoy, insiste con los ejercicios 
que más dificultad te dieron.

Sesión 6
*************
(Tiempo estimado: 1 hora 40 minutos)

Ejercicio 7: RETO 
^^^^^^^^^^^^^^^^^^

Clona este `este <https://github.com/juanferfranco/evaluacionUnidad1-2021-20>`__ 
repositorio.

Crea un programa que lea información de un archivo de entrada 
la procese y luego almacene el resultado en un archivo de salida. 

El programa se debe ejecutar en la línea de comandos así:

.. code-block:: bash

    $ ./main pathInFileName pathOutFileName

* ``main`` es el nombre del archivo ejecutable.
* pathInFileName y pathOutFileName son dos cadenas con el path absoluto o 
  relativo a los archivos de entrada y de salida respectivamente.

En los archivos que clonaste implementa las siguientes características:

* feature1: lee la primer línea del archivo de entrada y la escribe en 
  la primer línea del archivo de salida.
* feature2: lee la segunda línea del archivo de entrada, invierte su orden y 
  la escribe en la segunda línea del archivo de salida.
* feature3: lee el arreglo de enteros de la tercera línea del archivo de entrada, calcula la suma y 
  almacena el resultado en la tercera línea del archivo de salida.
* feature4: lee el arreglo de enteros de la cuarta línea del archivo de entrada así como la operación 
  especificada luego del arreglo.
* feature5: recibe la dirección del arreglo y de la operación leída en la feature anterior 
  realiza la operación y guarda el resultado en la cuarta línea del archivo de salida. 
  La operación puede ser avg, max, min correspondientes al promedio, 
  máximo o mínimo. TODOS los resultados deben ser ENTEROS, NO en punto flotante.
* feature6: lee la quinta línea del archivo de entrada y con esta información debes configurar los valores 
  de la siguiente estructura de datos cuya dirección se pasará a la función.

  .. code-block:: c 

      struct Obj_t{
        char *nombre;
        int cedula;
      };

* feature7: recibe la dirección en memoria de la estructura anterior y la guarda en la quinta línea del 
  archivo de salida primero la cédula, seguido por una coma y finalizando con el nombre.
* feature8: lee la sexta línea del archivo de entrada que contiene un número entero positivo que especifica 
  la cantidad de cursos que un estudiante cursó en un semestre. Luego solicita al usuario ingresar el nombre 
  del curso, los créditos y la nota así:

  .. code-block:: bash

    ingresa el curso 1: curso,créditos,nota
    ingresa el curso 2: curso,créditos,nota
    .
    .
    .
    ingresa el curso n: curso, créditos,nota

  La función debe devolver la dirección en memoria de una arreglo de estructuras de datos con la información 
  de cada curso y la el tamaño del arreglo.

* feature9: finalmente, calcula el `promedio ponderado <https://en.wikipedia.org/wiki/Weighted_arithmetic_mean>`__ 
  del semestre. Pregunta al usuario si desea almacenar la información la información en el archivo de salida así:

  .. code-block:: bash

    deseas almacenar la información (s) o (n):
  
  Si el usuario contesta n, debes guardar en la línea 6 del archivo de salida el promedio ponderado. Si el usuario 
  contesta y, debes guardar, desde la línea 6 del archivo de salida, la información ingresada así:
  
  .. code-block:: bash

      curso,créditos,nota
      curso,créditos,nota
      .
      .
      .
      curso,créditos,nota
      promedio ponderado: valor_calculado

* feature10: libera correctamente TODA la memoria reservada y cerrar todos 
  los archivos abiertos.

Trabajo autónomo 6
*********************
(Tiempo estimado: 2 horas 50 minutos)

Termina el reto de la sesión. En la sesión del lunes resolveremos dudas 
de la unidad 1 y del reto.