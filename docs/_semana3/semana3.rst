Semana 3
===========
Durante esta semana continuaremo explorando el lenguaje de programación C. 
En particular arreglos, memoria dinámica y estructuras de datos. 

Material de clase
------------------
El material que vamos a trabajar esta semana en clase lo pueden encontrar en este
`enlace <https://drive.google.com/file/d/19NmKVXEYB5Ud0SqbBwAe4HVYMD6LDHKD/view?usp=sharing>`__ 
Y en este otro `enlace <https://drive.google.com/open?id=1hBPkoUsGUmatr3tRm5ztr-s3hyc3OLhl>`__.

.. note::
    ¡Alerta de Spoiler!

En este `enlace <https://docs.google.com/presentation/d/1eCo1pCzYd0YB1dYhTLJNV8w9lVAQVX6u4LQEq1oHtH0/edit?usp=sharing>`__ 
se encuentra la solución a algunos puntos de la primera guía y en este otro 
`enlace <https://drive.google.com/file/d/1FWuPqJNWvEvHp89-ADvKu7XqdAZR6fx2/view?usp=sharing>`__ 
la solución de algunos puntos para la segunda.

Ejercicio en clase
-------------------

.. code-block:: c
   :linenos:

    #include <stdio.h>
    #define MAX 100

    void printArray(int *pdata,int n){

        printf("\n The array is: \n");

        for(int i = 0; i< n ;i++) {
            printf("data[%d]: %d\n",i,  *(pdata+i) );
        }
    }

    int main(){
        int n;
        int data[MAX];
        int position;

        printf("Enter the length of the array: ");
        scanf("%d", &n);
        printf("Enter %d elements of the array \n",n);

        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
        }
        printArray(data, n);

        printf("\n Enter the position where to insert: ");
        scanf("%d", &position);
        position--;
        for(int i = n-1;i >= position; i--){
            data[i+1] = data[i];
        }
        printf("\nEnter the value: ");
        scanf("%d", &data[position]);

        printArray(data,n+1);
        return 0;
    }

