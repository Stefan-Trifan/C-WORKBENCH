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

// Declaración de la función para limpiar el buffer de entrada
void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");
	
	// Declaración de variables para el precio inicial y final
	float precioInicial = 0, precioFinal = 0;

	// Solicita al usuario que introduzca el precio inicial
	printf("Introduce el precio Inicial: ");
	scanf("%f", &precioInicial);

	// Calcula el precio final aplicando un descuento del 15%
	precioFinal = precioInicial - 0.15*precioInicial;

	// Muestra el precio final
	printf("Precio Final es: %f", precioFinal);

	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Definición de la función para limpiar el buffer de entrada
void limpiarBuffer(){
	while (getchar() != '\n');
}