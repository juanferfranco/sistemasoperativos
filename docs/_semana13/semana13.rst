Semana 13: Unidad 4
=======================

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Actividad 9
^^^^^^^^^^^^^
* Fecha: septiembre 28 de 2020 - 4:00 p.m
* Descripción: discutir grupalmente las técnicas de comunicación
  entre procesos y dudas sobre el reto.
* Recursos: ingresa a Teams
* Duración de la actividad: 1 hora 40 minutos
* Forma de trabajo: individual con solución de dudas en tiempo real

Esta semana veremos otra de las estrategias de comunicación entre procesos: 
memoria compartida.

Material
###########
En `este enlace <https://docs.google.com/presentation/d/11FcbOrPy48FIgEZu1YsAye_bYe4uNe7V6d5KxO_IeGU/edit?usp=sharing>`__
se encuentra el material para esta semana.

Ejemplo 1
###########
El siguiente ejemplo muestra como dos procesos
pueden comunicarse utilizando memoria compartida.

El primer proceso crea la memoria compartida y
escribe información. El segundo proceso la lee
y destruye la memoria compartida.

Proceso 1:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/mman.h>
    #include <sys/stat.h>        /* For mode constants */
    #include <fcntl.h>           /* For O_* constants */
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>


    #define SH_SIZE 16

    int main(int argc, char * argv[]){

        int shm_fd = shm_open("shm0", O_CREAT | O_RDWR, 0600);
        if (shm_fd < 0) {
            perror("shm memory error: ");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Shared memory is created with fd: %d\n", shm_fd);
        
        if (ftruncate(shm_fd, SH_SIZE * sizeof(char)) < 0) {
            perror("Truncation failed: ");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "The memory region is truncated.\n");

        void* map = mmap(NULL, SH_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

        if (map == MAP_FAILED) {
            perror("Mapping failed: ");
            exit(EXIT_FAILURE);
        }

        char* ptr = (char*)map;
        ptr[0] = 'A';
        ptr[1] = 'B';
        ptr[2] = 'C';
        ptr[3] = '\n';
        ptr[4] = '\0';

        fprintf(stdout, "Data is written to the shared memory.\n");

        if (munmap(ptr, SH_SIZE) < 0) {
            perror("Unmapping failed: ");
            exit(EXIT_FAILURE);
        }

        
        if (close(shm_fd) < 0) {
            perror("Closing shm failed: ");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

Proceso 2:

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/mman.h>
    #include <sys/stat.h>        /* For mode constants */
    #include <fcntl.h>           /* For O_* constants */
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>

    #define SH_SIZE 16

    int main(int argc, char * argv[]){

        int shm_fd = shm_open("shm0", O_RDONLY, 0600);
        if (shm_fd < 0) {
            perror("shm memory error: ");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Shared memory is created with fd: %d\n", shm_fd);    

        void* map = mmap(NULL, SH_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

        if (map == MAP_FAILED) {
            perror("Mapping failed: ");
            exit(EXIT_FAILURE);
        }    

        char* ptr = (char*)map;
        fprintf(stdout, "The contents of shared memory object: %s\n", ptr);

    
        if (munmap(ptr, SH_SIZE) < 0) {
            perror("Unmapping failed: ");
            exit(EXIT_FAILURE);
        }

        
        if (close(shm_fd) < 0) {
            perror("Closing shm failed: ");
            exit(EXIT_FAILURE);
        }  
    
        if (shm_unlink("shm0") < 0) {
            perror("Unlink failed: ");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

Para ejecutar los programas sigue estos pasos:

.. code-block:: c
   :linenos:

    gcc -Wall p1.c -o p1 -lrt
    ./p1

El proceso 1 terminará pero abra dejado la zona
de memoria compartida lista y con datos. Para
verificarlo:

.. code-block:: c
   :linenos:

    ls /dev/shm
    cat /dev/shm/shm0

Ahora compile y ejecute el proceso 2.

.. code-block:: c
   :linenos:

    gcc -Wall p2.c -o p2 -lrt
    ./p2

Ejemplo 2
###########
El siguiente ejemplo muestra la necesidad de
incluir mecanismos de sincronización para evitar
condiciones de carrera.

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <string.h>
    #include <sys/mman.h>
    #include <sys/wait.h>

    #define SH_SIZE 4

    int shared_fd = -1;
    int32_t* counter = NULL;


    void init_shared_resource() {
    shared_fd = shm_open("shm0", O_CREAT | O_RDWR, 0600);
    if (shared_fd < 0) {
        perror("Failed to create shared memory: ");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Shared memory is created with fd: %d\n", shared_fd);
    }

    void shutdown_shared_resource() {
    if (shm_unlink("shm0") < 0) {
        perror("Unlinking shared memory failed: ");
        exit(EXIT_FAILURE);
    }
    }

    void inc_counter() {
    usleep(1);
    int32_t temp = *counter;
    usleep(1);
    temp++;
    usleep(1);
    *counter = temp;
    usleep(1);
    }


    int main(int argc, char** argv) {
    init_shared_resource();
    if (ftruncate(shared_fd, SH_SIZE * sizeof(char)) < 0) {
        perror("Truncation failed: ");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "The memory region is truncated.\n");
    void* map = mmap(0, SH_SIZE, PROT_WRITE, MAP_SHARED, shared_fd, 0);
    
    if (map == MAP_FAILED) {
        perror("Mapping failed: ");
        exit(EXIT_FAILURE);
    }

    counter = (int32_t*)map;
    *counter = 0;

    pid_t pid = fork();
    if (pid) { // The parent process
        inc_counter();
        fprintf(stdout, "The parent process sees the counter as %d.\n", *counter);
        int status = -1;
        wait(&status);
        fprintf(stdout, "The child process finished with status %d.\n", status);
    } else { // The child process
        inc_counter();
        fprintf(stdout, "The child process sees the counter as %d.\n", *counter);
    }


    if (munmap(counter, SH_SIZE) < 0) {
        perror("Unmapping failed: ");
        exit(EXIT_FAILURE);
    }

    if (close(shared_fd) < 0) {
        perror("Closing shared memory fd failed: ");
        exit(EXIT_FAILURE);
    }

    if (pid) {
        shutdown_shared_resource();
    }
    
    exit(EXIT_SUCCESS);
    }


Compila el código y luego ejecútela varias veces
hasta generar la condición de carrera.


.. code-block:: c
   :linenos:

    gcc -Wall p3.c -o p3 -lrt
    
    juanfranco@pop-os:~/tmp4$ ./p3 
    Shared memory is created with fd: 3
    The memory region is truncated.
    The parent process sees the counter as 1.
    The child process sees the counter as 2.
    The child process finished with status 0.
    
    juanfranco@pop-os:~/tmp4$ ./p3 
    Shared memory is created with fd: 3
    The memory region is truncated.
    The parent process sees the counter as 1.
    The child process sees the counter as 1.
    The child process finished with status 0.

El resultado esperado es que siempre el contador
quede en 2, pero a veces queda en uno.


Ejercicio 3
#############
Este ejercicio muestra cómo corregir el error
del ejercicio 2 debido a los problemas de sincronización

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <string.h>
    #include <sys/mman.h>
    #include <sys/wait.h>
    #include <semaphore.h>  

    #define SH_SIZE 4

    int shared_fd = -1;
    int32_t* counter = NULL;
    sem_t* semaphore = NULL;

    void init_control_mechanism() {
        semaphore = sem_open("sem0", O_CREAT, 0600, 1);
        if (semaphore == SEM_FAILED) {
            perror("Opening the semaphore failed: ");
            exit(EXIT_FAILURE);
        }
    }

    void shutdown_control_mechanism() {
        if (sem_close(semaphore) < 0) {
            perror("Closing the semaphore failed: ");
            exit(EXIT_FAILURE);
        }

        if (sem_unlink("sem0") < 0) {
            perror("Unlinking failed: ");
            exit(EXIT_FAILURE);
        }
    }

    void init_shared_resource() {
        shared_fd = shm_open("shm0", O_CREAT | O_RDWR, 0600);
        if (shared_fd < 0) {
            perror("Failed to create shared memory: ");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Shared memory is created with fd: %d\n", shared_fd);
    }

    void shutdown_shared_resource() {
        if (shm_unlink("/shm0") < 0) {
            perror("Unlinking shared memory failed: ");
            exit(EXIT_FAILURE);
        }
    }

    void inc_counter() {
        usleep(1);
        sem_wait(semaphore);
        int32_t temp = *counter;
        usleep(1);
        temp++;
        usleep(1);
        *counter = temp;
        sem_post(semaphore);
        usleep(1);
    }


    int main(int argc, char** argv) {
        init_shared_resource();
        init_control_mechanism();

        if (ftruncate(shared_fd, SH_SIZE * sizeof(char)) < 0) {
            perror("Truncation failed: ");
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "The memory region is truncated.\n");
        void* map = mmap(0, SH_SIZE, PROT_WRITE, MAP_SHARED, shared_fd, 0);
        
        if (map == MAP_FAILED) {
            perror("Mapping failed: ");
            exit(EXIT_FAILURE);
        }

        counter = (int32_t*)map;
        *counter = 0;

        pid_t pid = fork();
        if (pid) { // The parent process
            inc_counter();
            fprintf(stdout, "The parent process sees the counter as %d.\n", *counter);
            int status = -1;
            wait(&status);
            fprintf(stdout, "The child process finished with status %d.\n", status);
        } else { // The child process
            inc_counter();
            fprintf(stdout, "The child process sees the counter as %d.\n", *counter);
            if (sem_close(semaphore) < 0) {
                perror("Closing the semaphore failed: ");
            }
        }


        if (munmap(counter, SH_SIZE) < 0) {
            perror("Unmapping failed: ");
            exit(EXIT_FAILURE);
        }

        if (close(shared_fd) < 0) {
            perror("Closing shared memory fd failed: ");
            exit(EXIT_FAILURE);
        }

        if (pid) {
            shutdown_shared_resource();
            shutdown_control_mechanism();
        }
        
        exit(EXIT_SUCCESS);
    }

Ejercicio 4: RETO
###################
Crear un chat entre dos procesos utilizando memoria compartida,
hilos y semáforos. Cada proceso deberá esperar por la entrada de
su usuario y al mismo tiempo mostrar los mensajes enviados por el
otro usuario (es por ello que se requiere tener dos hilos por proceso).

El intercambio de mensajes se debe realizar utilizando memoria
compartida y semáforos para la sincronización.

Actividad 10
^^^^^^^^^^^^^
* Fecha: septiembre 28 a octubre 2 de 2020 
* Descripción: solución del reto
* Recursos: material teórico de la unidad
* Duración de la actividad: 5 horas
* Forma de trabajo: trabajo individual en la solución del reto


Actividad 11
^^^^^^^^^^^^^
* Fecha: octubre 2 de 2020 - 4:00 p.m
* Descripción: sustentación
* Recursos: ingresa a Teams
* Duración de la actividad: 1 hora 40 minutos
* Forma de trabajo: sustentación individual con cada estudiante.