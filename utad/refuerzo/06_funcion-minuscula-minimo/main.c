/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp
				  run
				  brun
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Enunciado X
		Escribe un programa en C que le pida al usuario que introduzca un caracter y que compruebe si es minuscula o numero. El origrama debe seguir pidiendo caracter mientras que el usuario no introduzca un caracter o una minuscula
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

int esMinuscula(char caracter);
int esNumero(char caracter);

void limpiarBuffer();

/* _________________________________________
   Inicio main() */

int main(){
	printf("\n_________________________________________START\n\n");

	char caracter = ' ';

	// printf("Introduce un caracter: ");
	// scanf(" %c", &caracter);
	// printf("%i", esMinuscula(caracter));
	// printf("%i", esNumero(caracter));

    
	do{
		printf("Introduce un caracter: ");
		scanf(" %c", &caracter);
	}while(esNumero(caracter) == 0 && esMinuscula(caracter) == 0);
	
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Función que comprueba si es minuscula
int esMinuscula(char caracter){

	int resultado = 0;
	if(caracter >= 'a' && caracter <= 'z'){
		resultado = 1;
	} else {
		resultado = 0;
	}
	return resultado;
}

// Funcion que comprueba si es numero
// Devuelve si es minuscula o si no
int esNumero(char caracter){

	int resultado = 0;
	if(caracter >= '0' && caracter <= '9'){
		resultado = 1;
	} else {
		resultado = 0;
	}
	return resultado;

}

void limpiarBuffer(){
	while (getchar() != '\n');
}