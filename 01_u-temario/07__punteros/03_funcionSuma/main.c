/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: todo

	* 	Enunciado X
		Crear función que lea 
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int leerCadena(char cadena[], int maxTam);
// int leerCadena(char *cadena, int maxTam);
void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
    
    char cadena[20];
	int tam = 0;
	printf("Introduce una cadena: ");
	tam = leerCadena(cadena, 20);
	

	printf("");
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int leerCadena(char cadena[], int maxTam){

}

void limpiarBuffer(){
	while (getchar() != '\n');
}