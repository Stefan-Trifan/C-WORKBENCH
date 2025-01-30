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
		LoremIpsumDummyText
*/

// TipoDeDato NombreDelArray[tamaño] = {valor1, valor2, ..., valorN};

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int array[3] = {24,5,26};

	printf("Posicion 0: %d\n", array[0]);
	printf("Posicion 1: %d\n", array[1]);
	printf("Posicion 2: %d\n", array[2]);

	array[0] = 4;
	array[2] = 6;

	printf("Los nuevos valores son: %d %d %d", array[0], array[1], array[2]);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}