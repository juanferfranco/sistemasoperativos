Introducción al control de versión con git y GitHub
====================================================

Con esta guía aprenderás los herramientas básicas para realizar 
todos los proyectos y ejercicios del curso bajo control de versión.

Lecturas, ejercicios y retos
---------------------------------

Lectura 1: ¿Qué es un sistema de control versión?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cuando estás desarrollando software, alguna vez te ha pasado que terminas 
con nombres de archivos marcados con frases tales como:

* Versión buena con un error
* Versión casi lista con un bug
* Versión para compartir con Camila
* Versión para enviar al profesor
* Esta versión si está bien
* Versión 1, versión 1.1, versión 2, versión 3
* versión enero 11 de 2022.
  
Lo anterior es muy posible que te pase si no usas un sistema de control 
de versión. 

Pero entonces ¿Qué haces si quieres mantener la historia de cambios de tus 
archivos? ¡Fácil! usas un sistema de control de versión. Un sistema de control 
de versión te ayuda a evitar la necesidad de guardar tus archivos con nombres 
diferentes a medida que realizas cambios, incluyes nuevas características 
o tienes alguna nueva receta de archivos para producir tu programa. El sistema 
de control de versión te ayudará a gestionar la versión de los archivos 
de manera automática evitando procesos manuales tediosos y susceptibles al error.

El sistema de control de versión ES UN PROGRAMA (que instalas en tu computador)
que te permitirá trazar y guardar información de los cambios que haces a tus 
archivos en el tiempo. Podrás recuperar incluso una versión pasada de un archivo si 
descubres que cometiste un error. 

¿Te va sonando?

Quiero contarte además que hoy en día prácticamente es impensable una 
empresa que desarrolle cualquier producto de software que NO TENGA control 
de versión.

Lectura 2: ¿Qué es Git y GitHub?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Git es un sistema de control de versión libre y de código abierto que instalas 
en tu computador para realizar el control de versión de tus proyectos. 
Por su parte GitHub te permite guardar tus proyectos de software en un servidor 
en Internet con la información del control de versión que tienes en tu computador. 
¿Para qué quieres esto? Para compartir tu código, para hacer copias de seguridad, 
para mostrar tus habilidades y portafolio y SOBRE TODO para trabajar en EQUIPO. 

Por medio de GitHub, las aportaciones de cada miembro del equipo se pueden 
sincronizar y compartir. De esta manera, es posible construir productos de software 
muy complejos en los cuales participen MUCHOS desarrolladores.

Ejercicio 1: instala Git
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Recuerda seleccionar la versión correcta según tu sistema operativo.

Si estás utilizando Windows, al momento de instalar te recomiendo que ajustes 
el PATH con la opción: ``Git from the command line and also from 3rd-party software``.
Esta opción te permitirá usar Git con varias aplicaciones.

Una vez esté instalado Git vas a abrir una terminal en Linux o MacOS. En windows 
puedes abrir varias opciones: Git bash (que es instalada con Git), 
el símbolo del sistema (Command Prompt o CMD) o PowerShell. Verifica 
cuál de las opciones que te da Windows funciona mejor para ti. Para los ejercicios 
que siguen puedes usar Git bash; sin embargo, puedes explorar los comandos de 
Windows equivalentes `aquí <https://www.lemoda.net/windows/windows2unix/windows2unix.html>`__ 
que puedes emplear en Command Prompt o PowerShell. 

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

    /home/jfupb

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

Te estarás preguntando, qué es ``.`` y ``..``. Lo primero es que son directorios. ``.``
se refiere al directorio actual y ``..`` se refiere al directorio padre. Entonces, si 
escribes este comando:

.. code-block:: bash 

    cd ..

¿Cuál crees que sea el resultado? ¿Perdido? No te preocupes. Repitamos el proceso juntos. 
Supón que la posición actual es:

.. code-block:: bash 

    pwd
    /home/jfupb/demo1

Luego de ejecutar el comando:

.. code-block:: bash 

    cd ..

El resultado será:

.. code-block:: bash 

    pwd
    /home/jfupb

Ahora vuelve a cambiarte al directorio demo1:

.. code-block:: bash 

    cd ./demo1

¿Te diste cuenta? Al salirte de demo1 quedas en el directorio padre de este. Una 
vez allí, ``.`` se refiere al directorio padre de ``demo1``. 
Por tanto, ``./demo1`` será la ruta RELATIVA de demo1 con respecto a su padre. 

Ejercicio 3: experimenta
^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora tómate unos minutos para experimentar. ¿Cómo? trata de ejecutar los comandos, 
pero antes de hacerlo ESCRIBE cuál será el resultado. Si el resultado es como 
te lo imaginaste, en hora buena, vas bien. Si no es así, MUCHO mejor, tienes una 
oportunidad de oro para aprender. Entonces trata de explicar qué está mal, discute 
con otros compañeros y si quieres habla con el profe.

Ejercicio 4: recuerda (evaluación formativa)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

De nuevo tómate unos minutos para:

#. Listar cada uno de los comandos que has aprendido hasta ahora y escribe al 
   frete de cada uno qué hace.
#. ¿Qué es una ruta absoluta?
#. ¿QUé es una ruta relativa?

Ejercicio 5: configura Git
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para hacer tus primeros experimentos con Git vas a realizar unas configuraciones 
mínimas para informarle a Git un nombre de usuario y un correo. Esta información
permite que Git identifique a la persona responsable de realizar los cambios 
a un archivo. Recuerda que Git está diseñado para que puedas trabajar en equipo.

Escribe los siguientes comandos:

.. code-block:: bash 

    git config --global user.name "Coloca tu nombre"
    git config --global user.email "tu correo electrónico"


Ejercicio 6: crea un repositorio
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cámbiate al directorio demo1 de antes. Más adelante vas a simular la creación 
de un proyecto de software en este directorio. Antes de comenzar a realizar 
el proyecto vas a crear en el directorio un ``REPOSITORIO DE GIT``. 
En este repositorio Git guardará toda la información relacionada con los cambios e historia 
de los archivos de tu proyecto necesarios para realizar el proceso 
de control de versión. Puedes pensar que el repositorio es una especie de base de 
datos donde Git lleva la cuenta de qué está pasando con cada uno de los archivos 
de tu proyecto.

Escribe el siguiente comando:

.. code-block:: bash

    git init

El resultado será similar a esto:

.. code-block:: bash

    hint: Using 'master' as the name for the initial branch. This default branch name
    hint: is subject to change. To configure the initial branch name to use in all
    hint: of your new repositories, which will suppress this warning, call:
    hint: 
    hint: 	git config --global init.defaultBranch <name>
    hint: 
    hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
    hint: 'development'. The just-created branch can be renamed via this command:
    hint: 
    hint: 	git branch -m <name>
    Initialized empty Git repository in /home/jfupb/demo1/.git/

Ahora observa el contenido del directorio:

.. code-block:: bash

    ls -al
    total 12
    drwxrwxr-x  3 jfupb jfupb 4096 Jan 11 17:14 .
    drwxr-x--- 37 jfupb jfupb 4096 Jan 11 17:15 ..
    drwxrwxr-x  7 jfupb jfupb 4096 Jan 11 17:14 .git

Se creará una carpeta oculta ``.git``. Si quieres ver esta carpeta en el modo
gráfico de tu sistema operativo, por ejemplo Windows Explorer en Windows, debes 
habilitar la posibilidad de ver archivos y directorio ocultos. Busca en Internet 
cómo hacer eso en tu sistema operativo.

Ejercicio 7: para pensar
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

¿Qué crees qué pase si borras el directorio ``.git`` en relación con el historial
de cambios de tus archivos?

Ejercicio 8: reconocer el estado del repositorio 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora ejecuta el siguiente comando:

.. code-block:: bash 

    git status

Verás algo así:

.. code-block:: bash 

    On branch master

    No commits yet

    nothing to commit (create/copy files and use "git add" to track)

El resultado por ahora es muy interesante. Verás que estás trabajando en la 
rama (branch) master. Las ramas son una característica MUY útil de git. Como 
su nombre indica te puedes ir por las ramas. Te lo explico con una historia. 
Supón que estás trabajando en tu proyecto y se te ocurre una idea, algo nuevo 
para implementar; sin embargo, no quieres dañar tu proyecto principal. Entonces 
lo que haces es que te creas una rama que tomará como punto de partida el estado 
actual de tu proyecto. En esa nueva rama realizas los ensayos que quieras. Si 
al final no te gusta el resultado simplemente destruyes la rama y tu proyecto 
seguirá como lo habías dejado antes de crear la rama. Pero si el resultado te gusta 
entonces podrás hacer un MERGE e incorporar las ideas de la nueva rama a la rama 
inicial. Más adelante te propondré algunos ejercicios para que practiques lo anterior.

Ahora observa el mensaje ``No commits yet``. Este mensaje quiere decir que aún no has guardado 
nada en el repositorio. Finalmente, ``nothing to commit`` te está diciendo que no 
hay nada para guardar en el repositorio porque no has hecho nada hasta ahora; sin embargo,
observa que git te da pistas de lo que puedes hacer: ``(create/copy files and use "git add" to track)``. 
Te propone usar el comando ``git add``. Con este comando le puedes decir a Git  
qué archivos quieres observar o hacerles ``TRACK``. Es lógico, ¿Cierto? No siempre 
quieres mantener la historia de todos los archivos o simplemente algunos archivos 
son generados en procesos de compilación de código fuente a código ejecutable. En 
esos casos solo vas a querer mantener bajo control de versión los archivos de código fuente.

Ejercicio 9: adicionar un archivo al repositorio 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Para hacer las cosas más simples por el momento vas a simular 
la creación de un proyecto de software usando archivos de texto 
simples.

Crea un archivo de texto así:

.. code-block:: bash 

    touch f1.txt 

Luego de este comando deberías tener el directorio demo1 así:

.. code-block:: bash 

    ls -al

    total 12
    drwxrwxr-x  3 jfupb jfupb 4096 Jan 12 15:52 .
    drwxr-x--- 22 jfupb jfupb 4096 Jan 12 15:52 ..
    -rw-rw-r--  1 jfupb jfupb    0 Jan 12 15:52 f1.txt
    drwxrwxr-x  7 jfupb jfupb 4096 Jan 12 15:32 .git

Ahora ejecuta el comando:

..  code-block:: bash 

    git status

Verás esto:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt

    nothing added to commit but untracked files present (use "git add" to track)

Nota entonces que ya tienes en el directorio tu primer archivo, pero aún no 
le has pedido a Git que te haga ``tracking`` de ese archivo. Entonces ejecuta el 
comando:

.. code-block:: bash 

    git add f1.txt 

Y de nuevo observa el estado del repositorio:

.. code-block:: bash 

    git status

    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)
        new file:   f1.txt

Te explico con una metáfora lo que está pasando. Imagina que Git 
le toma fotos al estado de tu proyecto cada que se lo solicitas; sin embargo, 
antes de tomar la foto tienes que decirle a Git (``con add``) a qué archivos 
le tomarás la foto. Todos los archivos que serán tenidos en cuenta para la 
próxima foto se ubican en zona lógica denominada el STAGE. Mira el mensaje 
``(use "git rm --cached <file>..." to unstage)``. Observa que Git te está diciendo
que f1.txt ya está listo para la foto, pero si quieres sacarlo de la foto puedes 
ejecutar el comando sugerido. Prueba sacar de la foto a f1.txt:

.. code-block:: bash 

    git rm --cached f1.txt

Mira el estado del repositorio:

.. code-block:: bash 

    git status
    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt

    nothing added to commit but untracked files present (use "git add" to track)

¿Te das cuenta? Hemos sacado de la foto (DEL STAGE) a f1.txt. Volvamos a invitar 
a f1.txt a la foto:

.. code-block:: bash 

    git add f1.txt 

Ahora ``TOMA LA FOTO``:

.. code-block:: bash 

    git commit -m "adicionamos f1.txt al repositorio"

Consulta el estado del repositorio:

.. code-block:: bash 

    On branch master
    nothing to commit, working tree clean

Puedes ver que Git está observando todo lo que pasa en el directorio de tu 
proyecto. Por ahora Git sabe que no has hecho nada más, por eso te dice 
``nothing to commit, working tree clean``.

Lo último que te voy a pedir que hagas con este ejercicio es que le preguntes 
a Git qué fotos (``COMMITS``) se han tomado en el repositorio:

.. code-block:: bash 

    git log 

El resultado es:

.. code-block:: bash 

    commit c14b43cde2ebac63a56377ba1f6faa67316d48ff (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 16:10:17 2022 -0500

        adicionamos f1.txt al repositorio
    (END)

Nota que el commit está identificado con el hash ``c14b43cde2ebac63a56377ba1f6faa67316d48ff``, 
el autor, correo, fecha, hora y la descripción del commit.

Ejercicio 10: retos 
^^^^^^^^^^^^^^^^^^^^^

Para un momento. Repasa los ejercicios anteriores, actualiza tu lista 
de comandos con la explicación de qué hacen. Una vez estés en este punto 
realiza los siguientes retos:

#. Crea un nuevo commit con el archivo f2.txt
#. Crea un nuevo commit que incluya los archivos f3.txt y f4.txt

NOTA: no olvides escribir ``git status`` entre cada comando que ejecutes 
para que puedas ir leyendo qué va ocurriendo con el repositorio.

Al finalizar este ejercicio deberías ver algo así:

.. code-block:: bash 

    git log 

    commit 7ec66fb9215999518fe5907c8c1360036906476e (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:19:14 2022 -0500

        Add f3.txt and f4.txt

    commit 11950128c3d3dc6cc7b3cfda7a3e5a8ed566c235
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:16:59 2022 -0500

        add f2.txt

    commit c14b43cde2ebac63a56377ba1f6faa67316d48ff
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 16:10:17 2022 -0500

        adicionamos f1.txt al repositorio
    (END)


    git status  

    On branch master
    nothing to commit, working tree clean

Ejercicio 11: modificar el contenido de un archivo 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modifica el contenido del archivo f1.txt añadiendo tres líneas de texto 
(escribe lo que tu corazón te dicte). Salva el archivo.

Al verificar el estado del repositorio verás:

.. code-block:: bash 

    git status

    On branch master
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git restore <file>..." to discard changes in working directory)
        modified:   f1.txt

    no changes added to commit (use "git add" and/or "git commit -a")

¿Ves la diferencia con respecto al momento en el que creaste el archivo? Déjame recordarte 
el mensaje:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt

    nothing added to commit but untracked files present (use "git add" to track)

Nota que al crear el archivo, Git te dice que no le está haciendo seguimiento (untracked); 
sin embargo, una vez está creado el archivo y lo modificas, Git te dice 
``Changes not staged for commit``. 

En este caso, Git le hace tracking a tu archivo, pero tu no has decidido pasar el 
archivo a STAGE para poderle tomar la foto con los cambios que tiene ahora. 
¿Cómo lo haces? Mira que en el mensaje Git te dice: ``git add f1.txt``. Nota que Git 
también te dice que puedes descartar los cambios en el archivo con 
``git restore f1.txt``. ¿Por qué no haces la prueba?

Escribe:

.. code-block:: bash 

    git restore f1.txt

Luego para ver en la terminal el contenido del archivo:

.. code-block:: bash

    cat f1.txt

¿Ya no hay nada, cierto? Mira el estado del repositorio:

.. code-block:: bash 

    git status

    On branch master
    nothing to commit, working tree clean

Vuelve a modificar f1.txt, pero esta vez si guardarás los cambios 
en el repositorio. Recuerda los pasos:

#. Cambias el archivo
#. Verifica el estado del repositorio (status)
#. Adiciona los cambios en el STAGE (add) 
#. Toma la foto (commit)
#. Verifica de nuevo el estado del repositorio (status)
#. Verifica el historial del repositorio (log)

Te debe quedar algo así:

.. code-block:: bash 

    commit 3c8fee79d84b5e1bee87eebd67d06db821168951 (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 08:15:26 2022 -0500

        update f1.txt

    commit 7ec66fb9215999518fe5907c8c1360036906476e
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:19:14 2022 -0500

        Add f3.txt and f4.txt

    commit 11950128c3d3dc6cc7b3cfda7a3e5a8ed566c235
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 17:16:59 2022 -0500

        add f2.txt

    commit c14b43cde2ebac63a56377ba1f6faa67316d48ff
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Wed Jan 12 16:10:17 2022 -0500

        adicionamos f1.txt al repositorio


Ejercicio 12: ¿Y si ya tienes un proyecto creado? 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Supón que ya tienes un proyecto creado o justo acabas de crear un 
proyecto y quieres iniciar desde ese punto el control de versión.

Vamos a simular esta situación. Abre la terminal. Si la tenías abierta 
cámbiate al directorio padre de demo1. Crea lo que te mostraré ahora:

.. code-block:: bash 

    ./demo2
    ├── f1.txt
    ├── f2.txt
    └── f3.txt

Adiciona algunas líneas de texto a cada archivo. Piensa entonces 
que esto que acabas de hacer es el resultado de la reciente creación 
de un proyecto de software, pero aún sin control de versión.

Para adicionar control de versión al proyecto:

#. Cámbiate al directorio ``demo2`` (cd)
#. Inicia un nuevo repositorio (init)
#. Verifica el estado del repositorio (status)

El resultado esperado es este:

.. code-block:: bash 

    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        f1.txt
        f2.txt
        f3.txt

    nothing added to commit but untracked files present (use "git add" to track)

¿Te parece familiar lo que ves? Ahora solo es que le digas a Git que haga 
tracking a los archivos que quieras. Para este ejercicio dile que todos los archivos.

.. code-block:: bash 

    git add .

Y el resultado cuando verifiques el estado del repositorio (status) será:

.. code-block:: bash 

    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)
        new file:   f1.txt
        new file:   f2.txt
        new file:   f3.txt

Entonces recuerda. Lo que acabas de hacer es decirle a Git que haga tracking a 
f1.txt, f2.txt y f3.txt. Además acabas de preparar en el STAGE los archivos 
que entrarán en la foto (commit). Realiza el commit y verifica el estado.

Si verificas el historial en este punto, verás que acabas de iniciar el control 
de versión.

.. code-block:: bash 

    commit 6c2e0fc824981b406c68dccc9ef34ad86f9ea8e4 (HEAD -> master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 09:11:27 2022 -0500

        init repo

Ejercicio 13: configura GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ahora te pediré que compartas el repositorio local ``demo2`` con el mundo. 
Para hacerlo necesitarás usar GitHub.

#. Crea una cuenta en GitHub o usa la que ya tienes.
#. Descarga e instala la `GitHub cli <https://cli.github.com/>`__ de GitHub 
   `aquí <https://github.com/cli/cli#installation>`__. Recuerda seleccionar 
   la opción adecuada según tu sistema operativo y plataforma de hardware.
#. Abre una terminal y ejecuta el comando:

   .. code-block:: bash 

       gh auth login

   El comando anterior te permitirá autorizar el acceso de tu computador 
   a tu cuenta en GitHub por medio de un proceso interactivo entre la terminal 
   y el browser.

Ejercicio 14: comparte tu trabajo usando GitHub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Abre la terminal y cámbiate al directorio demo2. Ejecuta el siguiente comando:

.. code-block:: bash 

    gh repo create demo2 --public --source=. --push --remote=upstream

``gh repo create demo2`` te permiten crear el repositorio remoto demo2 en 
GitHub. ``--public`` hace que el repositorio sea público y lo puedas compartir 
con cualquier persona. ``--source=.`` especifica en dónde está el 
repositorio. ``--push`` permite enviar todos los commits locales al repositorio 
remoto. Finalmente, ``--remote=upstream`` permite asignarle un nombre corto 
al servidor remoto, en este caso upstream.

Ingresa al sitio: https://github.com/TU_USUARIO/demo2 para observar tu repositorio 
en GitHub. NO OLVIDES modificar la cadena ``TU_USUARIO`` con tu nombre de usuario 
en GitHub.

Ejercicio 15: actualiza tu repositorio remoto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Realiza los siguientes pasos:

#. Modifica f1.txt
#. Realiza un commit con los cambios

Verifica el estado del repositorio:

.. code-block:: bash 

    git status

    On branch master
    Your branch is ahead of 'upstream/master' by 1 commit.
    (use "git push" to publish your local commits)

    nothing to commit, working tree clean

Observa el mensaje ``Your branch is ahead of 'upstream/master' by 1 commit.`` 
Git detecta que tu repositorio local está adelantado un commit con respecto 
al repositorio remoto. Observa que el propio Git te dice cómo actualizar 
el repositorio remoto:

.. code-block:: bash 

    git push 

Vuelve el verificar el estado:

.. code-block:: bash 

    git status

    On branch master
    Your branch is up to date with 'upstream/master'.

    nothing to commit, working tree clean

Y finalmente el historial:

.. code-block:: bash 

    commit 74f273a64864279df506e95ba496dc2a521cb876 (HEAD -> master, upstream/master)
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 11:31:50 2022 -0500

        add LINEA 14 to test my remote

    commit 6c2e0fc824981b406c68dccc9ef34ad86f9ea8e4
    Author: jfupb <juanf.franco@upb.edu.co>
    Date:   Thu Jan 13 09:11:27 2022 -0500

        init repo

Mira el texto ``(HEAD -> master, upstream/master)``. Indica que tu repositorio 
local y remoto apuntan al mismo commit.