/*
	*   Autor
		Stefan Trifan

	*   Estado

	*   Enunciado
		Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones del programa
void calcular_estadisticas(float *lista, int num, float *max, float *min, float *media);

// Funciones auxiliares
float pedirFloat();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");

	// Declaracion de variables
	float *lista;
	float maximo;
	float minimo;
	float media;
	int tam_lista;

	// Preguntamos que el tamanio que debe tener la lista
	printf("Introduce un numero\n-> ");
	


	printf("\n_________________________________________EXIT\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Función que calcula las estadísticas 
 * a partir de los valores de la lista de números
 */
void calcular_estadisticas(float *lista, int num, float *max, float *min, float *media)
{

}

// Funciones auxiliares
float pedirFloat()
{
	float num = 0;
	int esValido = 0;
	do
	{
		esValido = scanf("%f", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es válido. \n"
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}