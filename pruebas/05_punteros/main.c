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
    
	// Primer puntero
    int var1 = 3;
	int *pvar1 = &var1;
	printf("%i\n", var1);

	// Segundo puntero
	int casa = 0;
	int* direccion;
	direccion = &casa;

	int* direccion2;
	direccion2 = direccion;

	printf("Casa: %i direccion: %i direccion2: %i\n", casa, *direccion, *direccion2);
	casa = 1;
	printf("Casa: %i direccion: %i direccion2: %i\n", casa, *direccion, *direccion2);

	
	int var3, var4;
	int *p;
	
	var3 = 5;
	p = &var3;
	var4 = *p;
	*p =10;
	printf("%i", var3);
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void limpiarBuffer(){
	while (getchar() != '\n');
}