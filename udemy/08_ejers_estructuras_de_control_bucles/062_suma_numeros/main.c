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

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n___________________________START\n\n");

	int numMax = 0, resultado = 0;
    
    printf("Hasta que numero quieres sumar: ");
	scanf("%d", &numMax);

	for(int i = 0; i <= numMax; i++){
		resultado += i;
	};

	printf("\nLa suma de los digitos hasta el %d es: %d\n", numMax, resultado);

	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}