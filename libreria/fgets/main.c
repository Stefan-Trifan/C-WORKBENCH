/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 5
// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char nombre[TAM] = {0};

	printf("Tu nombre (max %d caracteres): ", TAM - 1);
	fgets(nombre, sizeof(nombre), stdin);

	printf("Tu nombre es: %s", nombre);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}