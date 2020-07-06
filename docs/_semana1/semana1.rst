Semana 1: Unidad 1
===================

Para poder abordar el curso de sistemas operativos con un enfoque
práctico necesitamos aprender un nuevo lenguaje de programación
llamado lenguaje C. Este lenguaje resulta muy apropiado para nuestros
propósitos por su gran cercanía con los conceptos que estudiaremos.

Propósitos de aprendizaje
--------------------------

Aplicar el lenguaje de programación C en la solución de problemas
simples haciendo uso de variables, estructuras de control, punteros,
estructuras de datos, funciones y archivo.

Actividad de aprendizaje
-------------------------

Se realizará las SEMANAS 1, 2 y 3

Lee con detenimiento el código de honor y luego los pasos que
debes seguir para evidenciar esta actividad.

Código de honor
^^^^^^^^^^^^^^^^^
Para realizar este reto se espera que hagas lo siguiente:

* Colabora con tus compañeros cuando así se indique.
* Trabaja de manera individual cuando la actividad así te lo
  proponga.
* NO DEBES utilizar sitios en Internet con soluciones o ideas para
  abordar el reto.
* NO DEBES hacer uso de foros para abordar la solución del reto.
* ¿Entonces qué hacer si no me funciona algo? te propongo que
  experimentes, crea hipótesis, experimenta de nuevo, observa y concluye.
* NO OLVIDES, este curso se trata de pensar y experimentar NO de
  BUSCAR soluciones en Internet.

Enunciado
^^^^^^^^^^
En un archivo se almacenará una secuencia de números enteros positivos, 
por ejemplo, considere este archivo:

12 23 43 55 67 765 213 12 1 4 90 34

PERO OJO: aquí solo se muestra un ejemplo, el archivo puede cambiar al
realizar las pruebas. Por tanto, te recomiendo probar con varios archivos.

Debes hacer un programa en C que llamaras reto1.c. El programa deberá
leer el archivo y generar uno nuevo. El archivo nuevo tendrá las siguientes
líneas:

* En la primera línea, los número ordenados de menor a mayor.
* En la segunda línea, el mayor número.
* En la tercer línea el menor número.
* En la cuarta línea el promedio.
* Tendrá una quinta línea pero estará vacía.

¿Qué debes entregar?
^^^^^^^^^^^^^^^^^^^^^

* Crea una carpeta que llamarás reto1.
* Guarda allí el archivo reto1.c
* En la primer línea del archivo reto1.c coloca tu ID así:
  // 000008716
* En la carpeta una copia de la `rúbrica <https://docs.google.com/spreadsheets/d/1tkbsx3ZSPIV5rB_66-k7MIVgkRCSo5Kd-x4bONz24g0/edit?usp=sharing>`__
  con tu autoevaluación diligenciada
* En la carpeta guarda un archivo .pdf donde colocarás cuatro cosas:
  
  * Muestra la línea de comando con la que compilaste el programa.
  * Muestra la línea de comando con la que ejecutaste el programa.
  * Una tabla de contenidos que indique el instante de tiempo en el cual se
    pueden encontrar cada una de las secciones solicitadas en el video.
  * El enlace a tu video. Puedes usar google drive o el one drive que tienes por ser estudiante UPB.

* Comprime la carpeta principal en formato .ZIP, ojo, solo .ZIP no uses otros
  formatos por favor.
* Entrega el archivo .ZIP `aquí <https://upbeduco-my.sharepoint.com/:f:/g/personal/juanf_franco_upb_edu_co/Em_gSIrgSIhBvnXJCQDU8HMBoxYQCyM092i2eWc-yhLVvw>`__.

¿Qué deberá tener el video de sustentación?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Máximo 20 minutos: debes planear el video muy bien.
* Cuida la calidad del audio y del video.
* Sección 1: introducción. Di tu nombre y si realizaste el RETO
  completo. Si no terminaste indica claramente qué te faltó y por qué. NO OLVIDES
  diligenciar la `rúbrica <https://docs.google.com/spreadsheets/d/1tkbsx3ZSPIV5rB_66-k7MIVgkRCSo5Kd-x4bONz24g0/edit?usp=sharing>`__
  con tu autoevaluación.
* Sección 2: modelado. Explica detalladamente cómo resolviste el problema, qué utilizaste,
  que alternativas de solución viste, justifica las razones para usar
  una alternativa sobre otras. Usa una aplicación de whiteboard. 
  Modela y explica tu programa con un diagrama de flujo. 
* Sección 3: implementación. Muestra que tu programa compila correctamente y sin errores
  o advertencias problemáticas. Explica el código fuente tu programa.
* Sección 4: vectores de prueba. Define y diseña los escanarios de prueba para verificar tu programa.
  Estos escenarios deben cubrir todas las características solicitadas.
* Sección 5: pruebas. Muestra claramente que tu programa pasa todos los vectores de prueba
  definidos.

* Tus explicaciones deben ser claras, precisas y completas. No olvides planear 
  bien tu video de sustentación.

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Fase 1 (motivación)
^^^^^^^^^^^^^^^^^^^^^^

* Fecha: julio 6 de 2020 - 4 p.m.
* Descripción: asiste al encuentro sincrónico donde se introducirá la actividad de
  aprendizaje de la unidad 1 correspondiente a las semanas 1, 2 y 3.
* Recursos: ingresa al grupo de `Teams <https://teams.microsoft.com/l/team/19%3aec7d6340525b46c4abbaa6d1bd635915%40thread.tacv2/conversations?groupId=4663acce-bac4-4fad-b4fe-fda49031f817&tenantId=618bab0f-20a4-4de3-a10c-e20cee96bb35>`__
* Duración de la actividad: 20 minutos sincrónicos.
* Forma de trabajo: grupal

Fase 2 (diagnóstico-repaso)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* Fecha: julio 6 de 2020 - 2:30 p.m
* Descripción: lee las preguntas y ejercicios orientadores para autoevaluar si tienes
  los conocimientos necesarios para abordar el RETO.
* Recursos:

  * revisa este material de :ref:`diagnóstico` para que evalues cómo están tus conocimientos.
  * Ingresa al grupo de `Teams <https://teams.microsoft.com/l/team/19%3aec7d6340525b46c4abbaa6d1bd635915%40thread.tacv2/conversations?groupId=4663acce-bac4-4fad-b4fe-fda49031f817&tenantId=618bab0f-20a4-4de3-a10c-e20cee96bb35>`__
    para que resuelvas tus dudas en tiempo real con el docente.

* Duración de la actividad: 1 hora 10 minutos
* Forma de trabajo: individual con solución de dudas en tiempo real

Fase 3 (fundamentación)
^^^^^^^^^^^^^^^^^^^^^^^^^
* Fecha: julio 6 al 10 de 2020
* Descripción: realiza la sección de fundamentos conceptuales.
* Recursos: revisa este material sobre los :ref:`fundamentos` de la unidad
* Duración de la actividad: 3 hora de trabajo autónomo 
* Forma de trabajo: individual

Fase 4 (ejercicios y discusión)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* Fecha: julio 6 al 10 de 2020
* Descripción: realiza los ejercicios propuestos. Acuerda reuniones con tus 
  compañeros para trabajar de manera ``colaborativa``
* Recursos: realiza estos :ref:`ejercicios`.
* Duración de la actividad: 2 horas de trabajo autónomo y colaborativo. Acuerda reuniones con tus compañeros.
* Forma de trabajo: individual y colaborativa.

Fase 5 (retroalimentación): 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* Fecha: julio 10 de 2020 - 4 p.m.
* Descripción: encuentro sincrónico para compartir y discutir los ejercicios. 
* Recursos: 
  
  * Ingresar al grupo de `Teams <https://teams.microsoft.com/l/team/19%3aec7d6340525b46c4abbaa6d1bd635915%40thread.tacv2/conversations?groupId=4663acce-bac4-4fad-b4fe-fda49031f817&tenantId=618bab0f-20a4-4de3-a10c-e20cee96bb35>`__
  * Corrige tus ejercicios (acciones de mejora)

* Duración de la actividad: 50 minutos de discusión y 50 minutos para que hagas
  las acciones de mejora sobre tu trabajo.
* Forma de trabajo: colaborativo con solución de dudas en tiempo real y 
  trabajo individual en la acción de mejora.

.. _diagnóstico:

Preguntas y ejercicios orientadores de autodiagnóstico
-------------------------------------------------------

Ejercicio 1
^^^^^^^^^^^^
En tu lenguaje de programación favorito construye un programa
tipo calculadora con las siguientes características:

* Solicita al usuario el primer número
* Solicita al usuario el segundo número
* Solicita una operación que puede ser: +,-,*,/,módulo.
* Imprime el resultado
* Pregunta al usuario si desea continuar y vuelve a comenzar,
  de lo contrario termina el programa.

.. _fundamentos:

Fundamentos conceptuales
-------------------------
Para realizar la siguiente guía vas a necesitar un entorno de
prueba. En la sección :ref:`ejercicios` te he dejado información para
que tengas ese entorno en tu computador local; sin embargo, para que
puedas comenzar de una vez te voy a recomendar dos sitios donde puedes
compilar y ejecutar programas online. Usa el que más te guste.

#. `Online GDB <https://www.onlinegdb.com/>`__
#. `repl.it <https://repl.it/>`__

En este `enlace <https://drive.google.com/file/d/1wiyBZL0kf1cQekHPfa7URcOxSpnfKE7-/view?usp=sharing>`__
encontrarás una guía básica del lenguaje C.

.. note::
    ¡Alerta de Spoiler!

    En este `enlace <https://drive.google.com/file/d/174GYcz_in94R_z6NklA02yzmsj3OuD5f/view?usp=sharing>`__
    , se encuentra la solución a algunos puntos de la guía introductoria a C (ojo, no todos). 
    Te recomiendo hacer los ejercicios sin recurrir a la solución.

.. _ejercicios:

Ejercicios
------------

Ejercicio 1: entorno de trabajo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Para poder trabajar en los ejercicios de este curso vas
a necesitar un ambiente de trabajo. Te propongo que instales en una USB o en una
partición de tu computador el sistema operativo Linux. Te 
preguntarás si puedes instalarlo en una máquina virtual.
Lo puedes hacer pero usualmente no lo recomiendo porque la
experiencia de uso no resulta agradable si tu sistema es muy lento.

Vas a necesitar dos memorias USB. Una grande (> 16GB), donde instalarás tu sistema operativo
y otra más pequeña (8GB) donde grabaras el instalador. Trata de utilizar la USB más rápida y
más grande para instalar tu sistema operativo.

Te voy a dejar unos videos de ayuda:

* Este `video <https://www.youtube.com/watch?v=zSGZe8NSEAc>`__ 
  te muestra como grabar en la USB pequeña el instalador. En este caso la distribución es PopOS,
  es la misma que yo uso; sin embargo, puedes grabar la que más te guste, por ejemplo Ubuntu.
  Ten presente que la versión del video no será la última. También, debes investigar
  cómo entrar al menú de configuración de tu BIOS para que ajustes el orden de boot. 
  Nota que debes darle prioridad a la USB para que al tenerle conectada arranques el 
  instalador del sistema operativo.

* Ahora, este video `video <https://www.youtube.com/watch?v=RR9Vgytjj24>`__ te mostrará
  cómo instalar, usando la USB pequeña con el instalador, tu sistema operativo en la USB grande.
  Te recomiendo iniciar a ver el video en el minuto 6:29, donde comienza en si el proceso
  de instalación. Una vez termines de instalar Linux en la USB grande, NO OLVIDES desconectar la USB
  pequeña para que tu computador inicie con la versión instalada de Linux en la USB grande.

Ejercicio 2: instala las herramientas 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Abren la terminal y ejecuta los comandos:

.. code-block:: c
   :linenos:

    $ sudo apt update
    $ sudo apt upgrade
    $ sudo apt install build-essential
    $ sudo apt install gdb

Ejercicio 3: instala un par de entornos de desarrollo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Para el curso te recomiendo que instales dos entornos de desarrollo:

#. Eclipse
#. Visual Studio Code

Eclipse te permitirá tener un depurador visual de código, pero la verdad
es un poco lento. Visual Studio, no tiene un depurador visual tan rico, pero es
muy liviano. Yo uso ambos. Normalmente trabajo con Visual Studio Code y cuando
algo no me funciona lo pruebo con Eclipse.

Ejercicio 4: línea de comandos
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
`Este material <https://drive.google.com/open?id=11tTtbCuVjYcBBYPrULbCeb0PABJLyhGEtzRGKMRG5u0>`__
es opcional y solo si no te acuerdas cómo manejar la línea de comandos.

Ejercicio 5: Pruebas
^^^^^^^^^^^^^^^^^^^^^
Con este último ejercicio vas a probar si todo te quedó bien. Toma cualquier de
los programas de la sección :ref:`fundamentos`. Compila y ejecuta el programa usando:

#. Eclipse
#. Visual Studio Code (pueden lanzar una consola en la misma herramienta)
#. Desde la consola


