Semana 5
===========

Esta semana realizaremos la primera evaluación sumativa.

Sesión 1
---------
`Esta <https://docs.google.com/document/d/1bPPd7DH6MWqq8dnZI-vNLEPcT9FZzemavu-Is9b1akI/edit?usp=sharing>`__
es la Evaluación sumativa para el grupo de 2 p.m. a 4 p.m.

`Esta <https://docs.google.com/document/d/1Q4RJiXNWULpySDfoo2_Vt5R7FIE677uOObtCVSzdzn4/edit?usp=sharing>`__
es la Evaluación sumativa para el grupo de 4 p.m. a 6 p.m.


Sesión 2
----------
Durante esta sesión realizaremos dos actividades relacionadas con el
proceso de evaluación. La primera activada será discutir una solución
para la evaluación y la segunda actividad consistirá en  realizar una
segunda evaluación como acción de mejora.

La valoración final de la evaluación sumativa será el promedio de las
dos evaluaciones.

`Esta <https://docs.google.com/document/d/1GIiKMAkSG_vhbTQxcS3zadkFWBS_2egn4XDT1KMZHsA/edit?usp=sharing>`__
es la acción de mejora para el grupo de 2 p.m. a 4 p.m.

`Esta <https://docs.google.com/document/d/112L39bDATrBDUCcPD7G6dSqfR_7JsbVpmiKt1LeqmRk/edit?usp=sharing>`__
es la acción de mejora para el grupo de 4 p.m. a 6 p.m.

Posibles soluciones a los problemas
-------------------------------------

Evaluación sumativa grupo 2 a 4:

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

Evaluación sumativa grupo 4 a 6:

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
