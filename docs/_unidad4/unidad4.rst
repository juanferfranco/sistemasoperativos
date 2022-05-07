Unidad 4: Entrada-Salida
===========================

Introducción
--------------

Hasta es punto delcurso hemos estudiado dos abstracciones
fundamentales que brinda el sistema operativo: PROCESOS y MEMORIA
VIRTUAL. La primera permite utilizar los recursos de procesamiento y
la segunda la memoria temporal para los programas. Ahora, vamos a presentar
un nuevo servicio del sistema operativo: ENTRADA-SALIDA. Los servicios 
de entrada-salida le permiten al sistemas operativo comunicarse con el 
mundo exterior, ya sea para adquirir información o para producirla. 
En particular, en esta unidad, vamos a abordar los servicios de persistencia y 
de comunicación de procesos utilizando sockets.

Propósito de aprendizaje
***************************

Comprender y aplicar los conceptos de entrada-salida para persistir información
y para comunicar procesos que no necesariamente se encuentra en la misma máquina.


Trayecto de actividades
--------------------------

Sesión 1
***************************

Ejercicio 1: persistencia 
^^^^^^^^^^^^^^^^^^^^^^^^^^

En `este <https://docs.google.com/presentation/d/1or5HQ9cwZek70PfEYniwkDwiIV4YS0ptaejanL3znIw/edit?usp=sharing>`__
enlace se encuentra el material sobre los servicios de persistencia.


Trabajo autónomo sesión 1: reto persistencia
***********************************************
(Tiempo estimado 2 horas 50 minutos)

Realizar un programa que:

* Reciba como argumento la ruta absoluta o relativa de un directorio.
* El programa deberá imprimir el nombre de todos los archivos y subdirectorios que contenga
  el directorio y los subdirectorios.
* La idea es recorrer toda la jerarquía imprimiendo los nombres de subdirectorios y archivos.

Sesión 2
**********

Ahora vamos a introducir el mecanismo de sockets para comunicar procesos que pueden estar 
en la misma máquina o en máquinas diferentes.

Ejercicio 2: sockets
^^^^^^^^^^^^^^^^^^^^^

El material que estudiaremos en este ejercicio es tomado de 
`este <https://www.packtpub.com/extreme-c>`__ texto.

En `este <https://docs.google.com/presentation/d/19aRuRgFksgXz1vvCpDOU97Hf9RYKZ968w-HuUlBvZB8/edit?usp=sharing>`__
enlace encontrarás un material teórico FUNDAMENTAL para entender
los ejercicios que sigue.

Trabajo autónomo sesión 2: análisis
***********************************************
(Tiempo estimado: 2 horas 50 minutos)

Vas a analizar detenidamente el código que te presento en el ejercicio 3.

Ejercicio 3: análisis de un ejemplo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

En este ejemplo verás como comunicar dos procesos utilizando
sockets TCP.

Server.c:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <signal.h>

    #define PORT 6666
    #define BUF_SIZE 128

    struct client_t{
        int socket;
        int rxState;
    };

    void * readThread(void *arg){
        struct client_t *client = ((struct client_t *)arg);
        ssize_t numOfBytes;
        char buf[BUF_SIZE];

        while(1){
            numOfBytes = read(client->socket, buf, BUF_SIZE);
            if(0 == numOfBytes){
                printf("client closed the socket end\n");
                break;
            }
            else if(-1 == numOfBytes){
                perror("ReadThread read() fails: ");
                break;
            }
            else{
                printf("from client: %s\n",buf);
            }
        }
        printf("Terminate Pthread for reading\n");
        client->rxState = 0;
        return NULL;
    }

    int main(int argc, char *argv[]){

        char buf[BUF_SIZE];
        int status;
        int enable = 1;
        int server_sd;
        int client_sd;
        pthread_t rxThreadId;
        struct client_t client;

        // 1. Ignore SIGPIPE 
        signal(SIGPIPE, SIG_IGN);

        // 2. Create socket
        server_sd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sd == -1) {
            perror("Socket creation fails\n");
            exit(EXIT_FAILURE);
        }
        printf("Socket created\n");
        
        // 3. turn off bind address checking
        status = setsockopt(server_sd, SOL_SOCKET, SO_REUSEADDR,(int *) &enable, sizeof(enable));
        if (-1 == status){
            perror("setsockopt error: ");
        }

        //4. BIND the socket to an address
        // Prepare the address
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(PORT);

        status = bind(server_sd, (struct sockaddr*)&addr, sizeof(addr));
        if (-1 == status) {
            perror("Bind fails: ");
            close(server_sd);
            exit(EXIT_FAILURE);
        }
        printf("Socket binded\n");

        // 5. Set backlog 

        status = listen(server_sd, 1);
    
        if (-1 == status) {
            perror("Listen fails: ");
            close(server_sd);
            exit(EXIT_FAILURE);
        }

        printf("Server listening\n");

        while(1){
            // 6. Accept:
            printf("Waiting for a client\n");
            client_sd = accept(server_sd, NULL, NULL);

            printf("Client connected\n");
            if(-1 == client_sd){
                perror("Accept fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
            }
            // 7. Create a thread for receiving messages from client
            client.socket = client_sd;
            client.rxState = 1;
            
            printf("Create Pthread for reading\n");
            status = pthread_create(&rxThreadId,NULL,&readThread,&client);
            if(-1 == status){
                perror("Pthread read fails: ");
                close(server_sd);
                exit(EXIT_FAILURE);
            }


            while(1){
                if(0 == client.rxState){
                    printf("Client closed the socket\n");
                    break;
                }
                
                if ( fgets(buf,BUF_SIZE,stdin) == NULL){
                    printf("Fgets NULL\n");
                }

                if( buf[ strlen(buf)-1 ] == '\n') buf[ strlen(buf) - 1 ] = 0;
                
                status = write(client.socket, buf, strlen(buf)+1);
                if(-1 == status){
                    perror("Server write to client fails: ");
                    break;
                }
            }
            close(client.socket);
        }

        exit(EXIT_SUCCESS);
    }


Client.c:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <signal.h>
    #include <arpa/inet.h>

    #define PORT 6666
    #define BUF_SIZE 128

    struct client_t{
        int socket;
        int rxState;
    };

    void * readThread(void *arg){
        struct client_t *client = ((struct client_t *)arg);
        ssize_t numOfBytes;
        char buf[BUF_SIZE];

        while(1){
            numOfBytes = read(client->socket, buf, BUF_SIZE);
            if(0 == numOfBytes){
                printf("Server closed the socket end\n");
                break;
            }
            else if(-1 == numOfBytes){
                perror("ReadThread read() fails: ");
                break;
            }
            else{
                printf("from server: %s\n",buf);
            }
        }
        printf("Terminate Pthread for reading\n");
        client->rxState = 0;
        return NULL;
    }

    int main(int argc, char *argv[]){

        char buf[BUF_SIZE];
        int status;
        int server_sd;
        pthread_t rxThreadId;
        struct client_t client;

        // 1. Ignore SIGPIPE 
        signal(SIGPIPE, SIG_IGN);

        // 2. Create socket
        server_sd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sd == -1) {
            perror("Socket creation fails\n");
            exit(EXIT_FAILURE);
        }
        printf("Socket created\n");
        
        //3. Connect to the server 127.0.0.1:PORT
        // Prepare the address
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        addr.sin_port = htons(PORT);

        status = connect(server_sd, (struct sockaddr*)&addr, sizeof(addr));
        if(-1 == status){
            perror("Connect fails\n");
            close(server_sd);
            exit(EXIT_FAILURE);
        }

        printf("Server connected\n");

        // 4. Create a thread for receiving messages from client
        client.socket = server_sd;
        client.rxState = 1;
        printf("Create Pthread for reading\n");
        
        status = pthread_create(&rxThreadId,NULL,&readThread,&client);
        if(-1 == status){
            perror("Pthread read fails: ");
            close(server_sd);
            exit(EXIT_FAILURE);
        }

        while(1){
            if(0 == client.rxState){
                printf("Server closed the socket\n");
                break;
            }
                
            if ( fgets(buf,BUF_SIZE,stdin) == NULL){
                printf("Fgets NULL\n");
            }
            if( 0 == strncmp(buf,":exit",strlen(":exit")) ){
                printf("Clinet exit\n");
                break;
            }

            if( buf[ strlen(buf)-1 ] == '\n') buf[ strlen(buf) - 1 ] = 0;
                
            status = write(client.socket, buf, strlen(buf)+1);
            if(-1 == status){
                perror("Server write to client fails: ");
                break;
            }
        }
        close(client.socket);
        exit(EXIT_SUCCESS);
    }

Sesión 3: análisis del ejercicio anterior
**********************************************

En esta sesión vamos a analizar juntos el ejercicio anterior, presentar la evaluación 
y resolver dudas generales para esta.


Evaluación de la Unidad 4
---------------------------

Para esta evaluación te pido que revises la el problema anterior y lo ajustes para que funcione con 
un mecanismo de comunicación basado en sockets TCP.

.. warning:: FECHA MÁXIMA DE ENTREGA

    Viernes 13 de mayo en CLASE. Debes ir a clase a mostrar y sustentar.

.. warning:: TRABAJO EN EQUIPO

    Puedes realizar este trabajo máximo entre dos personas.


Enunciado
*************

Vas a construir dos aplicaciones que llamaremos servidor y cliente. Solo 
tendrás una instancia del servidor, pero una cantidad ARBITRARIA de clientes.
El servidor publicará EVENTOS. Los clientes le manifestarán de manera explícita 
al servidor su interés en algunos eventos específicos; sin embargo, en un momento dado,
también podrán indicarle que ya no están interesados en algunos en particular. 
Por cada evento, el servidor mantendrá una lista de interesados que irá cambiando 
a medida que entran y salen interesados. Al generarse un evento en el servidor, 
este publicará a todos los interesados. 

Para desplegar las aplicaciones, lanzarás el servidor y cada cliente en una terminal 
para cada uno. No olvides hacer pruebas con VARIOS clientes.

Estas son las características a implementar en el servidor:

El servidor :

* Debe recibir commandos desde la línea de comandos y al mismo tiempo debe 
  ser capaz de escuchar las peticiones de los clientes.
* Cada petición de un cliente será visualizada con un mensaje 
  en la terminal que incluirá el identificador del cliente y el mensaje de la petición.
* Los comandos que recibirá el servidor son: 

  * exit: termina el servidor y deberá publicar este evento a TODOS los clientes.
  * add event_name: adiciona el evento event_name.
  * remove event_name: elimina el evento event_name.
  * trigger event_name: publica el evento event_name.
  * list event_name: lista todos los clientes suscritos a event_name.

Estas son las características a implementar en el cliente:

* El cliente debe visualizar en la terminal cada que sea notificado de un evento.
* El cliente debe soportar los siguientes comandos:

  * sub event_name: se suscribe al evento event_name
  * unsub event_name: se desuscribe del evento event_name
  * list: lista todos los eventos a los cuales está suscrito.
  * ask: le pregunta al servidor cuáles eventos hay disponibles.

¿Qué debes entregar?
***************************

Muestra tu aplicación funcionando en las sesiones de clase de la SEMANA 16.

Criterios de evaluación
****************************

La evaluación tendrá los siguientes vectores cada uno con igual valor:

#. El servidor atiende una ``cantidad arbitraria`` de clientes.
#. El servidor muestra cada petición que realiza un cliente mostrando en la terminal  
   la ``identificación del cliente y el contenido de la petición``.
#. El servidor soporta ``concurrencia`` (escuchar peticiones y comandos locales al mismo tiempo).
#. El servidor ``crea`` correctamente eventos con su lista de interesados.
#. El servidor ``destruye`` correctamente eventos y sus recursos asociados.
#. El servidor recibe la orden de ``publicar`` un evento y lo publica correctamente 
   a todos los interesados.
#. El servidor ``lista`` todos los clientes suscritos a un evento.
#. El cliente soporta ``concurrencia`` 
   (escuchar notificaciones y comandos locales al mismo tiempo).
#. El cliente muestra en la terminal la ``notificación`` de los eventos.
#. El cliente le ``pregunta`` al servidor y muestra en la terminal todos 
   los eventos disponibles en el servidor.
#. El cliente ``lista`` todos los eventos a los cuales está suscrito.
#. El cliente se ``suscribe`` a un evento.
#. El cliente se ``desuscribe`` a un evento.
#. En el server el comando ``exit`` funciona correctamente. Los clientes terminan
   al igual que el servidor. TODOS los recursos creados en el sistema operativo
   son liberados.
#. El cliente gestiona correctamente el comando ``exit`` en el servidor.

La calificación estará dada por: `Nota = 5*(VectoresQueFuncionan*Sustentacion/TotalVectores)`.










