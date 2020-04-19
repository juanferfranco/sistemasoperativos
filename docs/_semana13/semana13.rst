Semana 13
===========

RECUERDEN QUE ESTA SEMANA NO TENDREMOS ENCUENTROS SINCRÓNICOS.

TENEMOS 9 horas en TOTAL para resolver el problema y hacer la sustentación
en video.

Evaluación acumulativa 4
--------------------------

Esta semana realizaremos la evaluación sumativa número 4.
Se trata de un RETO en el cual les plantearé un problema y ustedes deberán
seleccionar cómo solucionarlo con las herramientas vistas en el curso.

Enunciado
^^^^^^^^^^

Realice un chat estilo GRUPO Whatsapp al que se puedan conectar MAS de 3 procesos. 
Cada proceso debe tener su propia ventana de terminal, es decir, al correr el chat tendré tantas
ventanas como procesos. 

Considere lo siguiente:
^^^^^^^^^^^^^^^^^^^^^^^^

* NO BUSQUE LA SOLUCIÓN EN INTERNET: se trata de un reto para pensar NO PARA BUSCAR.
* SOLO DEBE UTILIZAR LOS SERVICIOS ESTUDIADOS EN EL CURSO. 
* NO DEBE UTILIZAR SOCKETS.
* NO DEBE UTILIZAR SOCKETS.
* NO DEBE UTILIZAR SOCKETS.
* Hay muchas soluciones en Internet que usan sockets. Nosotros vamos
  a practicar únicamente los mecanismos de comunicación y sincronización estudiados en el curso.
* NO DEBE UTILIZAR SOCKETS.
* Realice dos programas llamados server.c y client.c. SOLO se deben crear esos dos tipos de programas.
* El programa server.c servirá para crear el proceso que le dará vida al chat.
* Cada proceso que quiera conectarse al char deberá ejecutar el programa client.c y conectarse al SERVER.
* Corra cada programa en un PROCESO independiente.
* Solo se lanzará un proceso server y todos los procesos client que se deseen, PERO 3 o más de 3.
* Cada proceso cliente debe ser capaz de ATENDER al mismo tiempo los mensajes que llegan al grupo y
  la interfaz de usuario.
* Los mensajes que escriba cada proceso client en su terminal deberán ser enviados a todos los
  clientes conectados al server.
* El server deberá enviar automáticamente a todos los clientes QUE ESTÉN conectados estos eventos:

    * Grupo cerrado
    * Nuevo cliente conectado
    * Cliente desconectado

* Si el grupo se cierra, cada cliente deberá informar al usuario y posteriormente cerrarse.
* Gestione la destrucción correcta de los servicios usados del sistema operativo.
* Seleccione los mecanismo de comunicación, sincronización y concurrencia para solucionar el problema.
* Se debe lanzar primero el server para iniciar el grupo. 
* Luego cada cliente se irá conectando y desconectando a necesidad.
* Cada cliente deberá incluir un comando para desconectarse y otro para conectarse.
* Además de los mensajes, cada cliente tendrá la oportunidad de enviar a los demás clientes
  el contenido de un archivo de texto, por tanto, debe incluir un comando que permita hacer esto.

Entrega
^^^^^^^^^^
* Crear una carpeta con tres archivos: server.c, client.c, sustentacion.pdf.
* COMPRIMA LA CARPETA como un archivo .ZIP, solo .ZIP, no rar, no 7zip, SOLO .ZIP.
* El archivo sustentacion.pdf debe tener SOLO un enlace a el de video-sustentación.
* El video sustentación debe tener los siguientes elementos:

    * INTRODUCCIÓN: hacer un introducción donde diga su nombre, grupo y si implementó completamente todo lo solicitado.
      En caso contrario, indique claramente qué le faltó.
    * DEMOSTRACIÓN: mostrar cómo se compila cada código, mostar cómo se lanza cada programa y mostrar funcionando
      cada característica solicitada.
    * EXPLICACIÓN: explicar detalladamente cada programa. OJO: no se trata de mostar solo las partes del programa,
      se trata de explicar detalladamente cómo funciona así:

      * Primero explicar en un tablero (DIGITAL, por ejemplo sketch.io) cuál es la arquitectura de
        los programas, que partes tienen, qué servicios del sistema operativo usa, cómo es el concepto de su solución
        y por qué lo solucionó de esta manera.
      * Segundo, explicar el código.
      * Tercero, indicar qué dificultades tuvo haciendo los programas y cómo las superó.

* Subir el trabajo `aquí <https://www.dropbox.com/request/fMYhXnO7Hfvx6gn5IMAk>`__
* El plazo es hasta el VIERNES 24 de abril hasta las 6:00 P.M.
