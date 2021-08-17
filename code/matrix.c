#include <stdio.h>
#include <stdint.h>

char nombres[3][20] = {"fulano", "mengano", "perano"};



int main(void){
    char *a;
    char (*b)[20];
    char (*c)[3][20];

    a = nombres[0];

    printf("Imprime el contenido de la dirección almacenada en a: %s\n",a);
    printf("Imprime el contenido de la dirección almacenada en a+1: %s\n",a+1);

    b = nombres;
    uint8_t sizeOfNombresElement = sizeof(nombres)/sizeof(nombres[0]);

    for(uint8_t i = 0; i < sizeOfNombresElement; i++){
        printf("Imprime el contenido de la dirección almacenada en b+%d: %s\n",i, (char *)(b+i));
    }

    c = &nombres;
    printf("Imprime el contenido de la dirección almacenada en c: %s\n", (char *) c);
    printf("Imprime el contenido de la dirección almacenada en c+1: %20s\n", (char *) (c+1) );

    printf("a  : %p\n",a);
    printf("a+1: %p\n",a+1);
    printf("b  : %p\n",b);
    printf("b+1: %p\n",b+1);
    printf("c  : %p\n",c);
    printf("c+1: %p\n",c+1);

    return 0;
}
