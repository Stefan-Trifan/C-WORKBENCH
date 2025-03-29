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

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define NUM_ROWS 3
#define NUM_COLS 3

// tipoDeDato nombreDelArray [numFilas][numColumnas]

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    int matriz[NUM_ROWS][NUM_COLS] = 
	{
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};

	// Ejemplo de otra manera de inicializar una matriz:
	int matriz_ejemplo[NUM_ROWS][NUM_COLS] = {0};

	printf("Matriz inicial: \n");
	for(int row = 0; row < NUM_ROWS; row++)
	{
		for(int col = 0; col < NUM_COLS; col++)
		{
			printf("%6d ", matriz[row][col]);
		}
		printf("\n");
	}

	printf("\n\nIntroduce los datos que desees (numeros con 6 cifras o menos): \n");
	for(int row = 0; row < NUM_ROWS; row++)
	{
		for(int col = 0; col < NUM_COLS; col++)
		{
			printf("M(%d,%d) = ", row + 1, col + 1);
			scanf("%d", &matriz[row][col]);
		}
	}


	printf("\n\nMatriz final: \n");
	for(int row = 0; row < NUM_ROWS; row++)
	{
		for(int col = 0; col < NUM_COLS; col++)
		{
			printf("%6d ", matriz[row][col]);
		}
		printf("\n");
	}


    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}