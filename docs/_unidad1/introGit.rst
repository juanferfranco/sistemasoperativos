Introducción al control de versión con git y Github
====================================================

Con esta guía aprenderás los herramientas básicas para realizar 
todos los proyectos y ejercicios del curso bajo control de versión.

Prerrequisitos
-----------------

Instala un cliente de git apropiado para tu sistema operativo.
Si tu sistema operativo es Windows podrás descargarlo en 
`este <https://git-scm.com/downloads>`__ sitio.

Lecturas, ejercicios y retos
---------------------------------

Lectura 1: ¿Qué es un sistema de control versión?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cuando estás desarrollando software alguna vez te ha pasado  tu y tus compañeros de equipo podrán mantener sincronizado el 
software en sus computadores personales enviando y recibiendo información a Github 
a medida que cada uno va aportando al proyecto.

* Versión para compartir con Camila
* Versión para enviar al profesor
* Esta versión si está bien
  
Es muy posible que esto te pase si no usas un sistema de control 
de versión.

Cuando construyes software, usualmente, debes modificar archivos. 
Un sistema de control de versión te ayuda a evitar la necesidad de  
guardar tus archivos con nombres diferentes a medida que realizas cambios, 
incluyes nuevas características o tienes alguna nueva receta de archivos 
para producir tu programa. El sistema de control de versión te ayudará 
a gestionar la versión de los archivos de manera automática, 
evitando procesos manuales tediosos y susceptibles al error.

El sistema de control de versión ES UN PROGRAMA (que instalas en tu computador)
que te permitirá trazar y guardar información de los cambios que haces a tus 
archivos en el tiempo. Podrás recuperar incluso una versión pasada de un archivo si 
descubres que cometiste un error. 

¿Te va sonando?

Quiero contarte además que hoy en día prácticamente es impensable una 
empresa que desarrolle cualquier producto de software que NO TENGA control 
de versión.

Lectura 2: ¿Qué es Git y Github?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Git es un sistema de control de versión libre y de código abierto que instalas 
en tu computador para realizar el control de versión de tus proyectos. 
Por su parte Github te permite guardar tus proyectos de software en un servidor 
en Internet con la información del control de versión que tienes en tu computador. 
¿Para qué quieres esto? Para compartir tu código, para hacer copias de seguridad, 
para mostrar tus habilidades y portafolio y SOBRE TODO para trabajar en EQUIPO. 

Por medio de Github, las aportaciones de cada miembro del equipo se pueden 
sincronizar y compartir. De esta manera es posible construir productos de software 
muy complejos en los cuales participen MUCHOS desarrolladores.

Ejercicio 1: instala Git
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Recuerda seleccionar la versión correcta según tu sistema operativo. 

Una vez esté instalado Git vas a abrir Git Bash si estás en Windows o una terminal si 
estás usando Linux o MacOS. Escribe el comando:

.. code-block:: bash

    git

Verás algo como esto:

.. code-block:: bash

    usage: git [--version] [--help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--bare]
           [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]
           <command> [<args>]

    These are common Git commands used in various situations:

    start a working area (see also: git help tutorial)
    clone             Clone a repository into a new directory
    init              Create an empty Git repository or reinitialize an existing one

    work on the current change (see also: git help everyday)
    add               Add file contents to the index
    mv                Move or rename a file, a directory, or a symlink
    restore           Restore working tree files
    rm                Remove files from the working tree and from the index
    sparse-checkout   Initialize and modify the sparse-checkout

    ...

Ejercicio 2: la terminal
^^^^^^^^^^^^^^^^^^^^^^^^^

Es posible que esta sea tu primera experiencia con la terminal. La terminal 
es un programa que te permite interactuar con el sistema operativo y los programas 
que tienes instalados por medio de comandos. Es por ello que a la terminal 
también la conocemos como interfaz de línea de comandos.

Si cerraste la aplicación Git Bash o la terminal ábrele de nuevo. Escribe el 
siguiente comando:

.. code-block:: bash

    pwd

En mi caso (en tu caso será distinto) el resultado es:

.. code-block:: bash 
Ejercicio 2: la terminal
^^^^^^^^^^^^^^^^^^^^^^^^^en el directorio home que a su 
vez está ubicado en la raiz del sistema de archivos. La raiz es el punto de partida. 
Si estás usando Windows, la raiz será, posiblemente, ``C:\``. 

Conocer la Ruta en la cual estás posicionado en el sistema de archivos es muy 
importante porque muchos de los comandos que ejecutarás dependerán de dicha posición. 
Por ejemplo, si creas un nuevo DIRECTORIO, este será creado en 
ese punto. Escribe el siguiente comando para crear un directorio:

.. code-block:: bash 

    mkdir demo1

Ahora te vas a cambiar a ese nuevo directorio, así:

.. code-block:: bash 

    cd demo1

Para observar el contenido del nuevo directorio deberás escribir el comando:

.. code-block:: bash

    ls -al 

Verás algo como esto:

.. code-block::

    total 8
    drwxrwxr-x  2 jfupb jfupb 4096 Jan 11 15:40 .
    drwxr-x--- 37 jfupb jfupb 4096 Jan 11 15:43 ..

Te estarás preguntando, qué es es ``.`` y ``..``. Lo primero es que son directorios. ``.``
se refiere al directorio actual y ``..`` se refiere al directorio padre. Entonces, si 
escribes este comando:

.. code-block:: bash 

    cd ..

¿Cuál crees que sea el resultado?

Mira, antes de ejecutar el comando, la posición actual es:

.. code-block:: bash 

    pwd
    /home/jfupb/demo1

Luego de ejecutar el comando:

.. code-block:: bash 

    pwd
    /home/jfupb

Ahora vuelve a cambiarte al directorio demo1:

.. code-block:: bash 

    cd ./demo1

¿Te diste cuenta? Al salirte de demo1 quedas en el directorio padre de este. Una 
vez en este directorio ``.`` se refiere al directorio padre. Por tanto, ``./demo1``
será la ruta RELATIVA de demo1 con respecto a su padre, siempre que estés posicionado 
en el padre.

Ejercicio 3: experimenta
^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora tómate unos minutos para experimentar. ¿Cómo? trata de ejecutar los comandos, 
pero antes de hacerlo ESCRIBE cuál será el resultado. Si el resultado es como 
te lo imaginaste, en hora buena, vas bien. Si no es así, MUCHO mejor, tienes una 
oportunidad de oro para aprender. Entonces trata de explicar qué está mal, discute 
con otros compañeros y si quieres habla con el profe.




