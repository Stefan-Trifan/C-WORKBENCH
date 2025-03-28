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

struct Persona
{
	char nombre[20];
	float edad;
	float altura;
};

void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	struct Persona persona1;

	persona1.nombre[20] = " ";
	persona1.edad = 27;
	persona1.altura = 186;

	printf("Nombre: %s\n", persona1.nombre);
	printf("Edad: %.2f\n", persona1.edad);
	printf("Altura: %.2f cm\n", persona1.altura);
    
    
	printf("\n\033[1;32m_________________________________________EXIT_SUCCESS\033[0m\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void clearBuffer()
{
	while (getchar() != '\n');
}