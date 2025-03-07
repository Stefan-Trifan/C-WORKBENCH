/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	* 	Introducir despues de scanf
		limpiar()

	* 	Enunciado 8
		LoremIpsum
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAM_ARRAY 3

// Llamamos con limpiar()
void limpiar(){
	while (getchar() != '\n');
}

int generaNumero0a30();

int main(int argc, char *argv[]){
	printf("\n________________________________________________\n\n");

	// srand(unsigned int seed): Inicializa la semilla para el generador de numeros pseudoaleatorios.
	// getpid(): Obtiene el identificador de proceso unico del programa que se esta ejecutando.
	srand(getpid());

	int array[TAM_ARRAY];
	int numUser  = 0;
	int encontrado = 0;

	// Generamos el array con numeros aleatorios
	for(int i = 0; i < TAM_ARRAY; i++){
		array[i] = generaNumero0a30();
	}

	// Imprimimos el array
	for(int i = 0; i < TAM_ARRAY; i++){
		printf("%d\n", array[i]);
	}

	// Pedimos un numero entre 0 al 30
	printf("Introduce un numero del 0 al 30: ");
	scanf("%d", &numUser);

	// Comprobamos si esta en el array
	for(int i = 0; i < TAM_ARRAY; i++){

		if(array[i] == numUser){
			printf("El numero esta en el array\n");
			encontrado = 1;
			break;
		}

	}

	if(encontrado == 0){
		printf("El numero no esta en el array");
	}

	printf("\n________________________________________________\n\n");
	return 0;
}

int generaNumero0a30(){
	// rand(): Genera numeros pseudoaleatorios.
	return((int)rand() % 31);
}