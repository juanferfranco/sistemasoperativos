Semana 14 Unidad 5: entrada-salida
====================================

Hasta es punto en el curso hemos estudiado dos abstracciones
fundamentales que brinda el sistema operativo: PROCESOS y MEMORIA
VIRTUAL. La primera permite utilizar los recursos de procesamiento y
la segunda memoria temporal para los programas. Ahora, vamos a presentar
un nuevo servicio del sistema
operativo: ENTRADA-SALIDA. Los servicios de entrada-salida le permiten
al sistemas operativo comunicarse con el mundo exterior, ya sea para adquirir
información o para producirla. En particular, en esta unidad, vamos a abordar
los servicios de persistencia y de comunicación de procesos utilizando sockets.


Propósitos de aprendizaje
--------------------------
Comprender y aplicar los conceptos de entrada-salida para persistir información
y para comunicar procesos que no necesariamente se encuentra en la misma máquina.

Actividades de aprendizaje
---------------------------
Se realizarán las SEMANAS 14, 15 y 16 (octubre 5 a octubre 23 de 2020)

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
Vamos a realizar dos RETOS para esta unidad: un reto de persistencia
y otro reto de comunicación usando sockets. El reto de persistencia
tiene un peso en la nota del 30% y el reto de sockets del 70%.

¿Qué debes entregar?
^^^^^^^^^^^^^^^^^^^^^^^

* Crea una carpeta que llamarás unidad5.
* Guarda en la carpeta los códigos fuente del RETO.
* Guarda en la carpeta un diagrama y un texto que explique
  la arquitectura de la solución: OJO no es explicar el código, se trata
  de explicar qué partes tiene la solución y cómo se relacionan entre ellas,
  es decir, la arquitectura de la solución.
* No olvides incluir la rúbrica.
  Aquí está la `rúbrica <https://docs.google.com/spreadsheets/d/1ptF-HuMpvYpmy-7lATj3n0kJupDPn5NvgCCzcdHNZGM/edit?usp=sharing>`__
* Comprime la carpeta formato .ZIP, ojo, solo .ZIP no uses otros
  formatos por favor.
* Entrega el archivo .ZIP del RETO 1: persistencia `aquí <https://auladigital.upb.edu.co/mod/assign/view.php?id=652940>`__.
* Entrega el archivo .ZIP del RETO 2: sockets `aquí <https://auladigital.upb.edu.co/mod/assign/view.php?id=652941>`__.

¿Cómo será la sustentación para cada reto?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Máximo 5 minutos por estudiante.
* El reto 1 no tendrá sustentación.
* La sustentación del RETO 2 será el viernes 23 de octubre de 2020.
* Debes estudiar tu implementación y prepararte para responder preguntas sobre tu trabajo.

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Actividad 1
^^^^^^^^^^^^
* Fecha: octubre 5 de 2020 - 4 p.m.
* Descripción: introducción a la unidad 5: persistencia
* Recursos: ingresa al grupo de Teams.
* Duración de la actividad: 1 hora 20 minutos.
* Forma de trabajo: grupal

Actividad 2
^^^^^^^^^^^^
* Fecha: octubre 5 a octubre 9 de 2020 - 4 p.m.
* Descripción: repasa el material y ejercicios y comienza con el reto
* Recursos: observa el material
* Duración de la actividad: 5 horas
* Forma de trabajo: individual


Actividad 3
^^^^^^^^^^^^
* Fecha: octubre 9 de 2020 - 4 p.m.
* Descripción: sesión de trabajo en el RETO y para resolver dudas
  sobre el material y los ejercicios.
* Recursos: ingresa al grupo de Teams.
* Duración de la actividad: 1 hora 20 minutos.
* Forma de trabajo: grupal

Material
###########

En `este <https://docs.google.com/presentation/d/1or5HQ9cwZek70PfEYniwkDwiIV4YS0ptaejanL3znIw/edit?usp=sharing>`__
enlace se encuentra el material introductorio.

Reto 
###########

Realizar un programa que:

* Reciba como argumento la ruta absoluta o relativa de un directorio.
* El programa deberá imprimir el nombre de todos los archivos y subdirectorios que contenga
  el directorio y los subdirectorios.
* La idea es recorrer toda la jerarquía imprimiendo los nombres de subdirectorios y archivos.

