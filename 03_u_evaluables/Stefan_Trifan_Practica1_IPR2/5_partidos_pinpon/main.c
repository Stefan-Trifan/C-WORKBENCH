/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 5 
        Partidos de ping pong

    *   Testing
        
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>

#define TAM_STR 40

typedef struct jugador_t
{
    char nombre[TAM_STR];
    char apellidos[TAM_STR];
    int edad;
}jugador_t;

typedef struct fecha_t
{
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
}fechas_t;

typedef struct partido_t
{
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
}jugador_t;

// Funciones del programa

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main()
{
    printf("\n_________________________________________START\n\n");



    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}