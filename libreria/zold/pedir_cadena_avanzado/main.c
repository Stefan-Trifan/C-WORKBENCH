/*
	*	Autor
		Stefan Trifan

	*   Estado

	* 	Enunciado
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

// Funciones del programa

// Funciones auxiliares
void pedirCadena(char texto[], int tam);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");
    
    
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
void pedirCadena(char texto[], int tam)
{
	int esValido = 1, i = 0;
	char newChar;

	printf("(Max. %d caracteres):\n", tam - 1);
	printf("-> ");

	do
	{
		esValido = 1;
		i = 0;
		// Leer la entrada hasta '\n' o hasta que se llene el array (dejando espacio para '\0')
		while (((newChar = getchar()) != '\n') && (i < tam - 1))
		{
			texto[i] = newChar;
			i++;
		}
		texto[i] = '\0'; // Finalizar la cadena

		if (i == tam - 1 && newChar != '\n')
		{
			printf("\033[1;31mERROR: Has superado el tamaño. Por favor, intentelo de nuevo. \n\033[0m"
				   "\033[1;31m-> \033[0m");
			clearBuffer();
			esValido = 0;
		}
	} while (!esValido);
}

// Funciones auxiliares
void clearBuffer()
{
	while (getchar() != '\n');
}