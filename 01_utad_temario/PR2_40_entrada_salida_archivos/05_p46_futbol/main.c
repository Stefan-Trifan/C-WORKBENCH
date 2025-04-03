/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado
        Lorem Ipsum
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BLOQUE 10

typedef struct
{
    char *nombre_apellidos;
    int   num_camiseta;
    int   num_golges;
}
datos_jugador_t;

// Funciones del programa

// Funciones auxiliares
char *pedirCadenaDinamica();
int pedirEnteroPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Declaracion de variables
    datos_jugador_t *jugador = (datos_jugador_t *)malloc(sizeof(datos_jugador_t));
    FILE *fd = fopen("equipos", "w+");
    int opcion = 0;

    // Comprobamos si tiene extio
	if(fd == NULL)
	{
		printf("Error al abrir el archivo\n");
		return EXIT_FAILURE;
	}

    // Introducimos jugadores
    do
    {
        printf("Quieres introducir un usuario?\n[0] Si\n[1] No\n-> ");
        opcion = pedirEnteroPos();

        if(opcion == 0)
        {
            printf("Introduce el nombre del jugador\n-> ");
            printf("Introduce el nombre del jugador\n-> ");
            printf("Introduce el nombre del jugador\n-> ");
        }
    } 
    while (opcion != 1);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares

char *pedirCadenaDinamica()
{
    char *p_texto_destino = malloc(sizeof(char) * TAM_BLOQUE);
    char c;
    int i = 0;
    int memoria_actual = TAM_BLOQUE;

    while ((c = getchar()) != '\n')
    {
        if (i == memoria_actual)
        {
            memoria_actual += TAM_BLOQUE;
            p_texto_destino = realloc(p_texto_destino, memoria_actual * sizeof(char));
        }
        p_texto_destino[i] = c;
        i++;
    }
    p_texto_destino[i] = '\0';

    return p_texto_destino;
}

int pedirEnteroPos()
{
    int num = 0, esValido = 0;
    do
    {
        esValido = scanf("%d", &num);
        clearBuffer();
        if (esValido == 0 || num < 0)
        {
            printf(
                "\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                "-> \033[0m"
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