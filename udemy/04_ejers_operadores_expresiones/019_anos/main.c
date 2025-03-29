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

	int edad = 0, meses = 0, dias = 0, horas = 0;
	float semanas = 0;
    
    printf("Digita tu edad\n");
	scanf("%d", &edad);

	meses = edad * 12;
	semanas = meses * 4.34;
	dias = semanas * 7;
	horas = dias * 24;

	printf("edad:    %d\n", edad);
	printf("meses:   %d\n", meses);
	printf("semanas: %f\n", semanas);
	printf("meses:   %d\n", dias);
	printf("horas:   %d\n", horas);
    
	printf("\n\033[1;32m___________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}