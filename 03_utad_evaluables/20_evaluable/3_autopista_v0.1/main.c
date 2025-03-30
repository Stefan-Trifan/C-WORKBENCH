/*
    *   Autor
        Stefan Trifan

    *   Estado

    *   Enunciado 3 - Autopista
        Se debe desarrollar un programa que simule el funcionamiento de una autopista.
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 50
#define TAM_MATRICULA 11
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

typedef enum
{
    MOTO,
    COCHE,
    CAMION
} tipo_vehiculo_t;

// Estructura que almacena nuevos vehiculos en la autopista
typedef struct
{
    char matricula[TAM_MATRICULA];
    tipo_vehiculo_t tipo_vehiculo; // (0=Moto, 1=Coche, 2=Camión)
    char nombre[TAM_STR];
    int carril;   // (1-3)
    int posicion; // [0, 300]
    float velocidad;
    int es_accidentado; // 1: Es accidentado, 0: No es accidentado
} coche_t;

// Funciones del programa
void crearVehiculo(
    coche_t coche[], 
    int     *num_coches);
void actualizarPosiciones(
    coche_t *coche, 
    int     *num_coches, 
    int     *num_accidentes);
void finalizarPrograma(
    coche_t *coche, 
    int     *num_coches, 
    int     *dinero_recaudado, 
    int     num_accidentes);
void mostrarMenu();

// Funciones auxiliares
void pedirCadena(char *text, int tam);
int pedirEnteroPos();
float pedirFloatPos();
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // * Declaracion de variables
    int opcion           = 0,
        dinero_recaudado = 0,
        num_accidentes   = 0;

    // * PRODUCCION
    // coche_t coche[100];
    // int num_coches = 0;

    // * TESTING
    coche_t coche[100] = 
    {
        // X / tipo_vehiculo / X / carril / posicion / velocidad / es_accidentado
        {"1111 111", 1, "Mateo", 1, 150, 0, 0},
        {"2222 222", 1, "Luna ", 1, 350, 0, 0},
        // {"3333 333", 1, "Steve", 1, 0, 50, 0},
        // {"4444 444", 1, "Pepe ", 1, 0, 76, 0}
    };
    int num_coches = 2;

    // * Menu
    do
    {
        mostrarMenu();
        opcion = pedirEnteroPos();

        switch (opcion)
        {
            case 1:
                crearVehiculo(coche, &num_coches);
                break;
            case 2:
                actualizarPosiciones(coche, &num_coches, &num_accidentes);;
                break;
            default: break;
        }
        printf("\n");
    } while (opcion != 3);

    finalizarPrograma(coche, &num_coches, &dinero_recaudado, num_accidentes);

    printf("\n_________________________________________EXIT\n\n");
    return EXIT_SUCCESS;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa

/**
 * Añade un nuevo vehiculo a la autopista
 */
void crearVehiculo(coche_t coche[], int *num_coches)
{
    // matricula
    printf("Ingrese matrícula: ");
    pedirCadena(coche[*num_coches].matricula, TAM_MATRICULA);

    // tipo_vehiculo
    do
    {
        printf("Tipo de vehículo (0=Moto, 1=Coche, 2=Camión): ");
        coche[*num_coches].tipo_vehiculo = pedirEnteroPos();
    } while (coche[*num_coches].tipo_vehiculo < 0 || coche[*num_coches].tipo_vehiculo > 2);

    // nombre
    printf("Nombre del conductor: ");
    pedirCadena(coche[*num_coches].nombre, TAM_STR);

    // carril
    do
    {
        printf("Carril (1-3): ");
        coche[*num_coches].carril = pedirEnteroPos();
    } while (coche[*num_coches].carril < 1 || coche[*num_coches].carril > 3);

    // velocidad
    printf("Velocidad (km/iteración): ");
    coche[*num_coches].velocidad = pedirFloatPos();

    (*num_coches)++;
    printf(GREEN "Nuevo vehiculo aniadido\n" RESET);
}

/**
 * Actualiza la posicion de cada vehiculo en la autopista
 * Comrpueba si han habido accidentes
 * - En caso positivo elimina los vehiculos accidentados
 * Realiza el recuento de los peajes
 */
void actualizarPosiciones(coche_t *coche, int *num_coches, int *num_accidentes) 
{
    // Actualiza la posicion de cada vehiculo en la autopista
    for (int i = 0; i < *num_coches; i++)
    {
        coche[i].posicion += coche[i].velocidad;
    }

    // Detecta accidentados
    for (int i = 0; i < *num_coches; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (
                coche[i].posicion == coche[j].posicion && 
                coche[i].carril   == coche[j].carril)
            {
                printf(
                    YELLOW 
                    "ATENCION: Accidente entre %s y %s en la posición %d\n" RESET, 
                    coche[i].matricula, coche[j].matricula, coche[i].posicion);

                // Marcamos los coches accidentados
                coche[i].es_accidentado = 1;
                coche[j].es_accidentado = 1;

                (*num_accidentes)++;
            }
        }
    }

    // Elimina los coches accidentados
    int indice_coche_intacto = 0;
    for (int i = 0; i < *num_coches; i++)
    {
        if (coche[i].es_accidentado == 0)
        {
            coche[indice_coche_intacto++] = coche[i];
        }
    }
    *num_coches = indice_coche_intacto;
}

/**
 * Muestra el numero de vehiculos que han completado el recorrido
 * Muestra el total recaudado en peajes
 * Muestra el total de accidentes
 */
void finalizarPrograma(coche_t *coche, int *num_coches, int *dinero_recaudado, int num_accidentes) 
{
    // Realiza el recuento del dinero recaudado los peajes
    for(int i = 0; i < *num_coches; i++)
    {
        if(coche[i].tipo_vehiculo == MOTO && coche[i].posicion >= 300)
        {
            *dinero_recaudado += 5;
        }
        else if(coche[i].tipo_vehiculo == COCHE && coche[i].posicion >= 300)
        {
            *dinero_recaudado += 10;
        }
        else if(coche[i].tipo_vehiculo == CAMION && coche[i].posicion >= 300)
        {
            *dinero_recaudado += 20;
        }
    }

    // Realiza el recuento de los coches que han finalizado el recorrido
    int num_coches_final = *num_coches;
    for(int i = 0; i < *num_coches; i++)
    {
        if(coche[i].posicion < 300)
        {
            num_coches_final--;
        }
    }

    // Muestra la informacion final
    printf("\n");
    printf("Vehículos que completaron el recorrido: %d\n", num_coches_final);
    printf("Total recaudado en peajes: %d\n", *dinero_recaudado);
    printf("Número de accidentes: %d\n", num_accidentes);
}

void mostrarMenu()
{
    printf("-------- Menú de la Autopista --------\n"
           "1. Crear vehículo\n"
           "2. Actualizar posiciones\n"
           "3. Finalizar programa\n"
           "Seleccione una opción: ");
}

// Funciones auxiliares
void pedirCadena(char *text, int tam)
{
    int i, esValido;
    char c;
    do
    {
        i = 0;
        esValido = 1;
        while (i < tam - 1)
        {
            c = getchar();
            if (c == '\n')
                break;
            text[i] = c;
            i++;
        }
        text[i] = '\0';

        if (i == tam - 1)
        {
            c = getchar();
            if (c != '\n')
            {
                printf("\033[1;33mHas introducido demasiados caracteres\n"
                       "Intentalo de nuevo\n"
                       "-> \033[0m");
                clearBuffer();
                esValido = 0;
            }
        }
    } while (esValido != 1);
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
            printf("\033[1;31mERROR: El tipo de dato introducido no es válido.\n"
                   "-> \033[0m");
            esValido = 0;
        }
    } while (esValido != 1);
    return num;
}

float pedirFloatPos()
{
    float num = 0;
    int esValido = 0;
    do
    {
        esValido = scanf("%f", &num);
        clearBuffer();
        if (esValido == 0 || num < 0)
        {
            printf("\033[1;31mERROR: El tipo de dato introducido no es válido. \n"
                   "\033[1;31m-> \033[0m");
            esValido = 0;
        }
    } while (esValido != 1);
    return num;
}

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

// TODO comvertir coche_t.nombre y coche_t a memoria dinamica
// TODO eliminar mensajes de DEBUG
// TODO resetear estructura para test

// DEBUG Imprimir todos los vehiculos
// printf("\n\n");
// for (int i = 0; i < num_coches; i++)
// {
//     printf("COCHE %d\n", i);
//     printf("matricula      = %s  \n", coche[i].matricula);
//     printf("tipo_vehiculo  = %d  \n", coche[i].tipo_vehiculo);
//     printf("nombre         = %s  \n", coche[i].nombre);
//     printf("carril         = %d  \n", coche[i].carril);
//     printf("posicion       = %d  \n", coche[i].posicion);
//     printf("velocidad      = %.2f\n", coche[i].velocidad);
//     printf("es_accidentado = %d  \n", coche[i].es_accidentado);
//     printf("\n");
// }