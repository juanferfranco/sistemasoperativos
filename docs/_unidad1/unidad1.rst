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
^^^^^^^^^^^^^^^^^^^^^^^^^^

Aplicar el lenguaje de programación C en la solución de problemas
simples haciendo uso de variables, estructuras de control, punteros,
estructuras de datos, funciones y archivo.


Lecturas y ejercicios
------------------------

Ejercicio 1: entorno de trabajo
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

Ejercicio 2: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Una vez tengas Linux funcionando debes instalar una cuentas herramientas:

Abren la terminal y ejecuta los comandos:

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 3: instala un par de entornos de desarrollo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para el curso te recomiendo que instales dos entornos de desarrollo:

#. `Eclipse <https://www.eclipse.org/downloads/packages/>`__
#. `Visual Studio Code <https://code.visualstudio.com/>`__

Eclipse te permitirá tener un depurador visual de código, pero la verdad
es un poco lento. Visual Studio, no tiene un depurador visual tan rico, pero es
muy liviano. Yo uso ambos. Normalmente trabajo con Visual Studio Code y cuando
algo no me funciona lo pruebo con Eclipse.

Ejercicio 4: línea de comandos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te propongo que te familiarices un poco más con la terminal o línea de comandos 
de tu sistema operativo.

Para ello te propongo realizar la siguiente
`guía <https://drive.google.com/open?id=11tTtbCuVjYcBBYPrULbCeb0PABJLyhGEtzRGKMRG5u0>`__.

Ten presente que en los comentarios de la guía podrás consultar la solución a las preguntas; 
sin embargo, trata de pensar primero en la respuesta y luego compara con la explicación.

Ejercicio 5: lenguaje de programación C
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Este será uno de los ejercicios más largos de la unidad porque vamos a introducir 
el lenguaje de programación con el cual estudiaremos todos los conceptos del curso: ``C``.

.. toctree::
    :maxdepth: 3

    Introducción a C <./introC>

Ejercicio 6: herramientas
^^^^^^^^^^^^^^^^^^^^^^^^^^

En este ejercicio comprenderás en detalle los pasos necesarios para transformar un programa en C a 
lenguaje de máquina.

.. toctree::
  :maxdepth: 3

  Herramientas <./tools>


PROYECTO EVALUATIVO DE LA UNIDAD 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Enunciado de la evaluación
################################

Realiza un fork de `este <https://github.com/juanferfranco/evaluacionUnidad1-2021-20>`__ repositorio en 
tu cuenta y realiza un clon para trabajar en un tu equipo local.

Debes hacer al menos un commit por feature implementada y probada.

Crea un programa que lea información de un archivo de entrada 
la procese y luego la almacene en un archivo de salida. El programa se debe ejecutar 
en la línea de comandos así:

.. code-block:: bash

    $ ./main pathInFileName pathOutFileName

* ``main`` es el nombre del archivo ejecutable.
* pathInFileName y pathOutFileName son dos cadenas con el path absoluto o relativo a los archivos 
  de entrada y de salida respectivamente.

Para entender cómo leer el path de los archivos de entrada y de salida vas a analizar el 
siguiente programa:

.. code-block:: c

  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char *argv[]){

      for(int i = 0; i < argc; i++){
          printf("argv[%d]: %s\n",i,argv[i]);
      }
      return EXIT_SUCCESS;
  }

Ahora ejecuta el programa así:

.. code-block:: bash

    $ ./main

y así:

.. code-block:: bash

    $ ./main arg1 arg2 arg3

Implementa las siguientes características:


* feature1: lee la primer línea del archivo de entrada y la escribe en la primer línea del archivo 
  de salida.
* feature2: lee la segunda línea del archivo de entrada, invierte su orden y la escribe en la segunda 
  línea del archivo de salida.
* feature3: lee el arreglo de enteros de la tercera línea del archivo de entrada, calcula la suma y 
  almacena el resultado en la tercera línea del archivo de salida.
* feature4: lee el arreglo de enteros de la cuarta línea del archivo de entrada así como la operación 
  especificada luego del arreglo, separada por un espacio.
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

Entregables
##############

Sube a `este <https://www.dropbox.com/request/00FNXAYWLqVG5dkCQoRr>`__ 
enlace un archivo pdf nombrado con los nueve dígitos que componen tu ID. 
Por ejemplo: 000008716.pdf. El archivo debe tener lo siguiente:

* Tu nombre completo.
* Evaluación de la unidad 1 y la fecha en la cual vas subir el archivo.
* Sección 1: la dirección https de tu repositorio en GitHub para poder clonar el proyecto. La URL 
  debe comenzar con ``https`` y terminar con ``.git``.
* Sección 2: el enlace a un video que muestre todas las features solicitadas funcionando.

Criterios de evaluación
##########################

Cada feature completa y con TODOS los requisitos solicitados te da los puntos que se muestran. Ten presenta 
que no se darán puntos intermedios por una feature incompleta o que no cumpla todos los requisitos.

* feature1: 0.5 
* feature2: 0.5
* feature3: 0.5
* feature4: 0.5
* feature5: 0.5
* feature6: 0.5
* feature7: 0.5
* feature8: 0.5
* feature9: 0.5
* Liberar correctamente TODA la memoria reservada y cerrar todos los archivos abiertos: 0.5