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
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#define TAM 30
void pedirNombre(char *nombre_antigo);
void copiarArray(char *nombre_nuevo, char *nombre_antigo, int num_letras);
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
    char nombre_antigo[TAM] = {0}, nombre_nuevo[TAM] = {0};
	int num_letras = 0;

	// Pedimos el nombre
	pedirNombre(nombre_antigo);

	// Imprimimos el nombre antigo
	printf("Gracias, tu nombre en el arr antiguo es: \n");
	for(int i = 0; nombre_antigo[i] != '\0'; i++)
	{
		printf("%c", nombre_antigo[i]);	
		num_letras++;
	}
	printf("\n\n");

	// Este bloque imprime el nombre, pero con un while. Es un bloque prescindible
	/* 	
		while(nombre_antigo[num_letras] != '\0')
		{
			printf("%c", nombre_antigo[num_letras]);	
			num_letras++;
		}
		printf("\n\n");
	*/

	// Copiamos el array de antiguo a nuevo
	copiarArray(nombre_nuevo, nombre_antigo, num_letras);

	// Imprimimos el nombre nuevo
	printf("Tu nombre en el arr nuevo es: \n");
	for(int i = 0; i < num_letras; i++)
	{
		printf("%c", nombre_nuevo[i]);	
	}
    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

void pedirNombre(char *nombre_antigo)
{
	printf("Introduce tu nombre: \n");
	for(int i = 0; i < TAM; i++)
	{
		nombre_antigo[i] = getchar();

		if (nombre_antigo[i] == '\n') // Si el usuario presiona ENTER, termina la lectura
		{ 
            nombre_antigo[i] = '\0'; // Reemplaza '\n' por '\0' para que sea una cadena valida
            break;
        }
	}
	printf("\n");
}

void copiarArray(char *nombre_nuevo, char *nombre_antigo, int num_letras)
{
	printf("Copiando...");
	for(int i = 0; i < num_letras; i++)
	{
		nombre_nuevo[i] = nombre_antigo[i];
	}
	printf("\n\n");
}

void clearBuffer()
{
	while (getchar() != '\n');
}



