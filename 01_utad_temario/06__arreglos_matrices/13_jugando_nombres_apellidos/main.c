/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: doing

	* 	Enunciado
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
	printf("\n___________________________START\n\n");

	char first_name[25];
	char newChar;
	char cadena[25];
	int pos = 0;
    
	// Pedimos el nombre
	printf("Introduce tu nombre: ");
	while((newChar = getchar()) != '\n'){
		cadena[pos] = newChar;
		pos++;
	}
	cadena[pos] = '\0';

	// Pedimos el apellido
	char last_name[25];
	printf("Introduce tu apellido: ");
	while((newChar = getchar()) != '\n'){
		cadena[pos] = newChar;
		pos++;
	}
	cadena[pos] = '\0';

	// Hacemos la concatenacion
	char full_name[50];
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}