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

Posibles soluciones a algunas ejercicios
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
