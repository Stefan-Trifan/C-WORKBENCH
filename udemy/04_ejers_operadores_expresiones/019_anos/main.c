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

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	int edad = 0, meses = 0, dias = 0, horas = 0;
	float semanas = 0;
    
    printf("Digita tu edad\n");
	scanf("%i", &edad);

	meses = edad * 12;
	semanas = meses * 4.34;
	dias = semanas * 7;
	horas = dias * 24;

	printf("edad:    %i\n", edad);
	printf("meses:   %i\n", meses);
	printf("semanas: %f\n", semanas);
	printf("meses:   %i\n", dias);
	printf("horas:   %i\n", horas);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}