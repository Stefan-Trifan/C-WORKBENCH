/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir despues de scanf
		limpiar()

*	Enunciado
		Pide al usuario que introduzca su edad e imprimela por pantalla. ¿Que ocurre si introducimos un caracter?
*/

#include <stdio.h>

int main(){

	int Edad;
	int ResultadoScanf = 0;
	printf("Introduce tu Edad: \n");

	while (ResultadoScanf == 0){

		ResultadoScanf = scanf("%d", &Edad);
		printf("el resultado de scanf es %d\n", ResultadoScanf);

		if (ResultadoScanf == 0){
			printf("No has introducido numero. Introduce un numero: \n");
			while (getchar() != '\n');
		}
	}
	
	printf("La Edad es %d\n", Edad);
}