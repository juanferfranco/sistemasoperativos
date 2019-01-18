#include <stdio.h>

int main(void)
{
	char c;
	float primerDigito;
	float segundoDigito;
	float resultado;
	int operacion;
	char seguir;

	seguir = 's';

	printf("\n\nBienvenido a mi sistema de calculadora simple");
	printf("\n*********************************************\n");

	while (seguir != 'q'){

		printf("\nIngrese el primer operando\n");
		scanf("%f", &primerDigito);
		printf("El primer operando es: %.3f\n", primerDigito);

		printf("\nIngrese el segundo operando\n");
		scanf("\n%f",&segundoDigito );
		printf("El segundo operando es: %.3f\n", segundoDigito);

		printf("\nIndique la operación\n 1: suma\n 2: resta\n 3: multiplicación\n 4: división\n");
		scanf("\n%d",&operacion);	

		switch(operacion){
		case 1:
			printf("\nLa operación es suma");
			resultado = primerDigito + segundoDigito;
			break;

		case 2:
			printf("\nLa operación es resta");
			resultado = primerDigito - segundoDigito;
			break;

		case 3:
			printf("\nLa operación es multiplicación");
			resultado = primerDigito * segundoDigito;
			break;

		case 4:
			printf("\nLa operación es división");
			resultado = primerDigito / segundoDigito;
			break;

		default:
			printf("\nOperación no válida: \n");
			return(0);			
		}

		printf("\n\nEl resultado de la operación es: %.3f\n", resultado);

		printf("Desea continuar?\n");
		printf("Responda s para si, q para no.\n");
		scanf("\n%c",&seguir);
	}
	return(0);
	
}
