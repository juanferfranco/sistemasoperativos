Semana 5
===========

Esta semana continuaremos trabajando en la Unidad 2 del curso.
Continuaremos con más ejercicios para que sigas creciendo
en el manejo del lenguaje C.

Trayecto de acciones, tiempos y formas de trabajo
---------------------------------------------------

Fase 6 (RETO)
^^^^^^^^^^^^^^^^^^^^^
* Fecha: agosto 3 al 7. 
* Descripción: continuar con los ejercicios propuestos
* Recursos: sección de ejercicios.
* Duración de la actividad: 
  
  * Dos sesiones de 1 hora 40 minutos cada una para solución de dudas en tiempo real.
  * 5 horas de trabajo autónomo

* Forma de trabajo: individual.


Ejercicios 
-----------

Ejercicio 1
^^^^^^^^^^^^

Este ejercicio corresponde a un parcial de semestres anteriores:

`Parcial <https://docs.google.com/document/d/1bPPd7DH6MWqq8dnZI-vNLEPcT9FZzemavu-Is9b1akI/edit?usp=sharing>`__

Ejercicio 2
^^^^^^^^^^^^

Este ejercicio corresponde a un parcial de semestres anteriores:

`Parcial <https://docs.google.com/document/d/1Q4RJiXNWULpySDfoo2_Vt5R7FIE677uOObtCVSzdzn4/edit?usp=sharing>`__

Ejercicio 3
^^^^^^^^^^^^
Este ejercicio corresponde a un parcial de semestres anteriores:

`Parcial <https://docs.google.com/document/d/1GIiKMAkSG_vhbTQxcS3zadkFWBS_2egn4XDT1KMZHsA/edit?usp=sharing>`__

Ejercicio 4
^^^^^^^^^^^^
Este ejercicio corresponde a un parcial de semestres anteriores:

`Parcial <https://docs.google.com/document/d/112L39bDATrBDUCcPD7G6dSqfR_7JsbVpmiKt1LeqmRk/edit?usp=sharing>`__

.. note::
    ¡Alerta de Spoiler!

Posibles soluciones 
------------------------------------------

¿Estas serán las soluciones de cuáles ejercicios?

.. code-block:: c
   :linenos:

    #include <stdio.h>

    int main(int argc, char *argv[]){

        FILE *fin = fopen(argv[1], "r");
        FILE *fout = fopen(argv[2], "w");

        int data;
        while(1){
            data = fgetc(fin);
            if(data == EOF) break;
            fprintf(fout, "%.2hhX ",data);
        }
        fclose(fin);
        fclose(fout);
        return 0;
    }

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <limits.h>

    int main(int argc, char *argv[]){

        FILE *fin = fopen(argv[1], "r");
        FILE *fout = fopen(argv[2], "w");

        int data;
        unsigned int min = UINT_MAX;
        unsigned int max = 0;
        unsigned int sum = 0;
        unsigned int counter = 0;

        while(1){
            int status = fscanf(fin,"%u",&data);
            if(status != 1) break;
            fprintf(fout,"%u ",data );
            if(data < min) min = data;
            if(data > max) max = data;
            sum += data;
            counter++;
        }
        fprintf(fout,"\n%u",max);
        fprintf(fout,"\n%u",min);
        fprintf(fout,"\n%u\n",sum/counter);
        fclose(fin);
        fclose(fout);
        return 0;
    }

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main(int argc, char * argv[]){

    FILE *fin = fopen(argv[1],"r");
    FILE *fout = fopen(argv[2],"w");
    char *pclave = argv[3];

    // Prueba 2
    fprintf(fout,"%s\n",argv[0]);

    // Prueba 3
    char * buffer = malloc(sizeof(char)*1000);
    fgets(buffer, 1000,fin);
    fprintf(fout,"%s",buffer);


    // Prueba 4
    fgets(buffer, 1000,fin);
    char *pbufferEnd = buffer + strlen(buffer)  - 2 ;
    for(; pbufferEnd > buffer;pbufferEnd--){
        fputc(*pbufferEnd,fout);
    }
    fputc(*pbufferEnd,fout);

    // Prueba 5

    while(1){
        fgets(buffer, 1000,fin);
        char *pdata = strstr(buffer, pclave);
        if(pdata != NULL){
            pdata = pdata + strlen(pclave) + 1;

            char *pop = NULL;
            pop = pdata;
            do{
                pop = strpbrk(pop,"+-%*/");
                pop++;

            }while( (*pop >= 0x030) &&  (*pop  <= 0x039));

            char op = * (pop-1);
            *(pop - 2) = 0;

            int num = 0;
            char *endp = NULL;
            int res = (int) strtol(pdata,&endp,10);
            pdata = endp + 1;
            while(1){
                num = (int) strtol(pdata,&endp,10);
                pdata = endp + 1;
                switch(op){
                case '+':
                    res = res + num;
                    break;
                case '-':
                    res = res - num;
                    break;
                case '%':
                    res = res % num;
                    break;
                case '*':
                    res = res*num;
                    break;
                case '/':
                    res = res/num;
                    break;
                }
                if(*endp == 0) break;
            }

            fprintf(fout,"\n%d\n",res);
            break;
        }
    }

    fclose(fout);
    fclose(fin);
    free(buffer);
    return EXIT_SUCCESS;
    }

El vector de prueba usado es este:

.. code-block:: html
    :linenos:

    Esta es la primera linea
    Esta es la segunda linea del archivo
    Esta es la tercera linea del archivo de entrada
    Esta es la cuarta hola 1 2 3 -4 5 6 -7 8 9 + fin de la linea
    Esta es la quinta linea
    Esta es la sexta linea

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    int main(int argc, char * argv[]){

    FILE *fin = fopen(argv[1],"r");
    FILE *fout = fopen(argv[2],"w");
    char *pclave = argv[3];

    // Prueba 2
    fprintf(fout,"%s\n",argv[2]);

    // Prueba 3
    char *buffer = malloc(sizeof(char) * 1000);
    fgets(buffer, 1000,fin);
    for(char *pbuf = buffer ; *pbuf != '\n'; pbuf++){
        fputc( toupper(*pbuf), fout);
    }
    fputc('\n',fout);


        // Prueba 4
        fgets(buffer, 1000,fin);
        char *pletter = buffer;
        int counter = 0;

        while(1){
            if(*pletter == ' '){
                fprintf(fout, "%d ", counter);
                counter = -1;
            }
            else if( *pletter == '\n' ){
                fprintf(fout, "%d ", counter);
                break;
            }

            counter++;
            pletter++;
        }
        fputc('\n',fout);

    // Prueba 5
    while(1){
        fgets(buffer,1000,fin );
        char *pdata = strstr(buffer, pclave);

            if(pdata != NULL){
                char *pLastWord = buffer + strlen(buffer) - 1;
                *pLastWord = 0;
                for(; *pLastWord != ' ' ; pLastWord--);
                char wordNum = strlen(pLastWord  + 1);
                pdata = pdata + strlen(pclave) + 1;

                char *token = strtok(pdata, " ");
                while(token != NULL){
                    if(strlen(token) == wordNum) fprintf(fout, "%s ", token);
                    token = strtok(NULL, " ");
                    if(token == (pLastWord  + 1)) break;
                }
                break;
        }
        }

    fclose(fout);
    fclose(fin);
    free(buffer);
    return EXIT_SUCCESS;
    }

El vector de prueba usado es este:

.. code-block:: html
    :linenos:

    Esta es la primera linea
    Esta es la segunda linea del archivo
    Esta es la tercera linea del archivo de entrada
    Esta es la cuarta hola linea casas del archivo de entrada mundo
    Esta es la quinta linea
    Esta es la sexta linea
