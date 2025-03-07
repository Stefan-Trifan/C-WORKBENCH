/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    int numero1, numero2, resultado;

    printf("Introduce el primer numero: ");
    scanf("%d", &numero1); // Lee el primer numero

    printf("Introduce el segundo numero: ");
    scanf("%d", &numero2); // Lee el segundo numero

    // ERROR: Se realiza una resta en lugar de una suma
    resultado = numero1 - numero2;

    printf("La suma de %d y %d es: %d\n", numero1, numero2, resultado);

    // Otro ERROR: Mensaje incorrecto
    printf("Fin del programa (¿Ocurrio todo correctamente?)\n");
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}