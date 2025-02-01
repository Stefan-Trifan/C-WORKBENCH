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

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define max_row 3
#define max_col 3

// tipoDeDato nombreDelArray [numFilas][numColumnas]

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
	printf("\n_________________________________________START\n\n");
    
    int tabla[max_row][max_col] = {{0,0,0},{0,0,0},{0,0,0}};

	printf("Matriz inicial: \n");
	for(int row = 0; row < max_row; row++)
	{
		for(int col = 0; col < max_col; col++)
		{
			printf("%d  ", tabla[row][col]);
		}
		printf("\n");
	}

	printf("\n\nAhora introduce los datos que tu deseas tener: \n");
	for(int row = 0; row < max_row; row++)
	{
		for(int col = 0; col < max_col; col++)
		{
			printf("M(%i,%i) = ", row + 1, col + 1);
			scanf("%i", &tabla[row][col]);
		}
	}


	printf("\n\nMatriz final: \n");
	for(int row = 0; row < max_row; row++)
	{
		for(int col = 0; col < max_col; col++)
		{
			printf("%d  ", tabla[row][col]);
		}
		printf("\n");
	}


    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}