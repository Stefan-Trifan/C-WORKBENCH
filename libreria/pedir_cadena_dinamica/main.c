/*
    *	Autor
        Stefan Trifan

    *   Estado

    * 	Enunciado
        Esta funcion se queda solo con los caracteres necesarios
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>

#define TAM_BLOQUE 5

// Funciones del programa
char *pedirCadenaDinamica();

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    char *texto;
    printf("Introduce tu texto: ");
    texto = pedirCadenaDinamica();
    printf("Texto es: %s\n", texto);

    free(texto);

    printf("\n_________________________________________EXIT\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
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

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}