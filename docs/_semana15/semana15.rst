Semana 15
===========

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Actividad 1
^^^^^^^^^^^^
* Fecha: octubre 16 de 2020 - 4 p.m.
* Descripción: introducción a la comunicación mediante sockets.
* Recursos: ingresa al grupo de Teams.
* Duración de la actividad: 1 hora 20 minutos.
* Forma de trabajo: grupal

Material
#########

El material que estudiaremos será tomado de 
`este <https://www.packtpub.com/extreme-c>`__ texto.

En `este <https://docs.google.com/presentation/d/19aRuRgFksgXz1vvCpDOU97Hf9RYKZ968w-HuUlBvZB8/edit?usp=sharing>`__
enlace está el material teórico para esta semana.

No olvides entonces que tenemos estas opciones:

* *Socket UDS* (*Unix domain socket*) sobre un *stream channel*.
* *Socket UDS* sobre un *datagram channel*.
* *Socket network* sobre un *stream channel*. 
* *Socket network* sobre un *datagram channel*.

Ejemplo
##########
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

Actividad 2
^^^^^^^^^^^^
* Fecha: octubre 16 a octubre 19 de 2020 - 4 p.m.
* Descripción: trabajo en el RETO. 
* Recursos: observa el material
* Duración de la actividad: 5 horas
* Forma de trabajo: individual

RETO
#####

El último reto se trata de crear una aplicación tipo GRUPO de whatsapp así:

#. Crea un programa servidor que sea capaz de atender hasta 10 clientes.
#. Crea un programa cliente que se conecte al servidor.
#. Cualquier mensaje que envíes al servidor será replicado a todos
   los clientes que estén conectados.
#. Ten presente que los cliente deberán ser capaces de enviar y recibir
   mensajes a la vez.
#. Permite que el servidor pueda recibir comandos a la vez que atiende a
   todos los clientes. Los comandos serían: mostrar los clientes conectados,
   desconectar un cliente.
#. Cuando un cliente detecte que el servidor lo desconectó debe terminar
   adecuadamente el programa gestionando los errores que se puedan presentar
   al intentar leer o escribir el socket.

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
* Entrega el archivo .ZIP del RETO 2: sockets `aquí <https://auladigital.upb.edu.co/mod/assign/view.php?id=652941>`__.