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
		Hacer una lista de 10 numeros, luego pedirle al usuario que digite un numero,
		con una busqueda secuencial determinar si el numero existe en la lista o no 
		e indicar en que posicion se encuentra
*/



/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
int pedirEntero();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
	printf("\n_________________________________________START\n\n");
    
	// Array de numeros impares
	int array[10]={2,4,6,8,0,1,3,5,7,9};
    char numeroEncontrado = 'F';
	int num = 0, posicion = 0, i;

	printf("Introduce un numero: \n");
	num = pedirEntero();

	i = 0;
	while(numeroEncontrado == 'F' && i < 10)
	{
		if(array[i] == num)
		{
			printf("Numero encontrado!\n");
			numeroEncontrado = 'V';
			break;
		}
		i++;
	}

	if(numeroEncontrado == 'V')
	{
		printf("El numero %d esta en la posicion %d\n", num, i + 1);
	}
	else if(numeroEncontrado == 'F')
	{
		printf("El numero no pertenece a la lista");		
	}
	else
	{
		printf("\033[1;31mERROR: Ha habido un error\n\033[0m");
	}


    
	printf("\n_________________________________________END\n\n");
	return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

int pedirEntero()
{
	int num = 0, esValido = 1;
	printf("-> ");
	do
	{
		esValido = scanf("%d", &num);
		clearBuffer();
		if (esValido == 0)
		{
			printf(
				"\033[1;31mERROR: El tipo de dato introducido no es valido. "
				"Por favor, intentelo de nuevo. \n\033[0m" 
				"\033[1;31m-> \033[0m"
			);
			esValido = 0;
		}
	}
	while (esValido != 1);
	return num;
}

void clearBuffer()
{
	while (getchar() != '\n');
}
