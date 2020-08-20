Semana 7: Unidad 3
====================

En esta unidad vamos a estudiar el concepto de proceso.

Propósitos de aprendizaje
--------------------------

Comprender el concepto de proceso, programa, hilo y su diferencia.


Actividad de aprendizaje
-------------------------

Se realizará las SEMANAS 7, 8 y 9

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

El reto de esta unidad consiste realmente en dos retos:

RETO 1:
*********
Se tiene un archivo de entrada que tiene en cada línea dos cadenas de texto
separadas por un espacio. A la primera cadena la llamaremos clave y a la segunda
valor. Clave es una cadena de caracteres y valor es un número entero. 
El archivo tendrá máximo 100 líneas, clave será máximo de 20 caracteres y valor
será menor a 1000 y mayor a -1000.

* Crea un programa llamado p1.c que lea el archivo de entrada y genere un archivo
  de salida con las parejas ordenadas por VALOR de mayor a menor. Una pareja por línea.

* Crea un programa llamado p2.c que lea el archivo de entrada y escriba en un archivo de 
  salida cada pareja comenzando por la última y terminando por la primera, es decir,
  en orden contrario al que aparecen en el archivo de entrada.

* Crea un programa llamado p3.c que cree dos procesos para ejecutar los programas anteriores.
  Los procesos deben lanzarse para que se ejecuten en paralelo. Una vez los dos procesos
  sean lanzados, p3 debe esperar a que terminen. Debe leer los archivos de salida generados
  por p1 y p2 e imprimir en pantalla los resultados.

* TEN EN CUENTA QUE al final, en la terminal, solo lanzarás un proceso, el que corre a p3. p3
  se encarga del resto. Lanza el proceso así: ./p3 In Out1 Out2

* p3 es el nombre del ejecutable principal, el proceso que crea los otros procesos. In es
  el archivo con la información de entrada y Out1 es el archivo de salida para p1 y Out2
  el archivo de salida para p2. Ten en cuenta que In, Out1 y Out2 son parámetros, es decir,
  puedes colocar cualquier nombre en ellos equivalente al nombre de los archivos.


RETO 2:
*********
Se tiene un archivo de entrada que posee por línea 3 cadenas de caracteres
separadas por espacios:  nombre ocupación edad. 
Nombre y ocupación son cadenas de caracteres que representan texto mientras 
que edad representa valores numéricos. Se tendrán máximo 100 líneas y 
20 caracteres máximo por cadena.


* Crea un programa llamado prog.c que lea el archivo de entrada, luego debe organizar la información
  en una estructura de datos, luego debe IMPRIMA en pantalla el contenido de la estructura de datos.
  OJO no del archivo, sino de la información cargada en la estructura de datos proveniente del archivo.
  
* Crea 2 hilos para procesar de diferente manera la información y finalmente imprima el contenido
  de los archivos de salida que producirá cada hilo. Los hilos deben lanzarse para que se ejecuten
  en paralelo, OJO, NO DE MANERA SECUENCIAL, SI EN PARALELO.

* El Hilo 1 escribe en el archivo de salida1 los registros del archivo de entrada, pero en orden
  inverso, es decir, primero el último y de último el primero.

* El Hilo 2 escribe en el archivo de salida 2 los registros ordenados por ocupación en orden alfabético.

* NO OLVIDES Hilo 1 e Hilo 2 deben lanzarse a la vez. Una vez Hilo 1 e Hilo 2 finalicen se debe mostrar
  en pantalla el resultado de los archivos de salida.

* El programa se ejecutará así: ./prog In Out1 Out2

* prog es el nombre del ejecutable, In especifica el nombre del archivo de entrada
  Out1 y Out2 especifican el nombre de los los archivos de salida 1 y 2 respectivamente. RECUERDA que
  In, Out1 y Out2 son parámetros.


¿Qué debes entregar?
^^^^^^^^^^^^^^^^^^^^^^^

* Crea una carpeta que llamarás unidad3.
* Guarda allí dos carpetas, una para el reto 1 y otra para el reto 2.
* Almacena en cada carpeta SOLO LOS ARCHIVOS .c, los archivos de entrada y los archivos de salida
  correspondientes a cada reto.
* En la primer línea cada archivo coloca tu ID así: // tu_id
* Guarda una copia de la rúbrica CON TU autoevaluación diligenciada. NO OLVIDES justificar cada nota
  Aquí está la `rúbrica <https://docs.google.com/spreadsheets/d/1ptF-HuMpvYpmy-7lATj3n0kJupDPn5NvgCCzcdHNZGM/edit?usp=sharing>`__
* Comprime la carpeta unidad3 en formato .ZIP, ojo, solo .ZIP no uses otros
  formatos por favor.
* Entrega el archivo .ZIP `aquí <https://auladigital.upb.edu.co/mod/assign/view.php?id=625755>`__.

¿Cómo será la sustentación?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Máximo 5 minutos po estudiante.
* En la última sesión de la semana 9 se habilitará la reunión por Teams. Solo ingresará
  un estudiante a la vez que será llamado por el docente siempre que su trabajo se encuentre
  en el aula digital.
* Debes estudiar tu implementación y prepararte para responder preguntas sobre tu trabajo.

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Actividad 1
^^^^^^^^^^^^

* Fecha: agosto 21 de 2020 - 4 p.m.
* Descripción: asiste al encuentro sincrónico para introducir de manera teórica los conceptos.
* Recursos: ingresa al grupo de Teams.
* Duración de la actividad: 1 hora.
* Forma de trabajo: grupal

Material
***********
El material que vamos a trabajar en esta sesión lo encuentras en este
`enlace <https://drive.google.com/open?id=1xojM0NJibnQdIT_UzzrnlS1Fj5NSNtkVNfCnJNBIBYs>`__.

En este `otro enlace <https://drive.google.com/file/d/1t_MhYGFmN7ti6U4TYNcpgigJESFgb7_H/view>`_
pueden leer una explicación detallada de los pasos que ocurren al
hacer un llamado al sistema.

