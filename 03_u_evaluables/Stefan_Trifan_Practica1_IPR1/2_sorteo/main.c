/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 2 
        Sorteo

    *   Testing
        Bien: ./main 1 Jose Steve 
        Bien: ./main 6 Megan Pepe Steve Ana Val Carlos Marcos Guada Gyan Mate

        Mal: ./main 1 Jose
        Mal: ./main 1 MaximilianoAlejandroFernandezRodriguezGonzalez Steve 
        Mal: ./main 1 Jose-Vicente 3- Steve       
        Mal: ./main = Steve Jose
*/

/* _________________________________________
   Inicio cabecera */

#include <stdio.h>
#include <stdlib.h> // Para strtol(), srand() y rand()
#include <time.h>   // Para time()

#define TAM_ARR 10
#define TAM_STR 41
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Funciones del programa
int procesarArgumentos
(
    int *cont_jugadores, 
    int *num_ganadores, 
    int argc, 
    char *argv[]
);
int comprobarNombres
(
    int i, 
    int argc, 
    char *argv[]
);
void guardarNombres
(
    int i, 
    char jugador[TAM_ARR][TAM_STR], 
    int argc,
    char *argv[]
);
void seleccionarGanador
(
    int num_ganadores, 
    int cont_jugadores, 
    char jugador[TAM_ARR][TAM_STR], 
    int numeroAleatorio[TAM_ARR - 1], 
    char ganador[TAM_ARR][TAM_STR]
);

// Funciones auxiliares
void clearBuffer();

/* _________________________________________
   Inicio main() */

int main(int argc, char *argv[])
{
    printf("\n_________________________________________START\n\n");

    // Definimos las variables
    char jugador[TAM_ARR][TAM_STR] = {0},
         ganador[TAM_ARR][TAM_STR] = {0};
    int numeroAleatorio[TAM_ARR - 1] = {0}, // Indices de los ganadores
        cont_jugadores = 0,
        num_ganadores  = 0, // Especifica si el usuario ha declarado un numero de jugadores
        error          = 0;
    
    // La funcion devuelve un codigo de error si se supera el limite de jugadores
    error = procesarArgumentos(&cont_jugadores, &num_ganadores, argc, argv);
    if(error)
        return 1;

    // La funcion devuelve un error si los nombres de los jugadores no son correctos
    if(num_ganadores)
        error = comprobarNombres(2, argc, argv); // Comenzamos en argv[2]
    else
        error = comprobarNombres(1, argc, argv); // Comenzamos en argv[1]
    if(error)
        return 1;
        
    // Guardamos en jugador[][] los jugadores
    if(num_ganadores)
        guardarNombres(2, jugador, argc , argv); // Comenzamos en argv[2]
    else
        guardarNombres(1, jugador, argc , argv); // Comenzamos en argv[1]

    // Seleccionamos los ganadores del sorteo de manera aleatoria
    seleccionarGanador(num_ganadores, cont_jugadores, jugador, numeroAleatorio, ganador);

    printf("\n_________________________________________END\n\n");
    return 0;
}

/* _________________________________________
   Inicio definicion de funciones */

// Funciones del programa
/**
 * Comprueba si el usuario:
 *     1: Ha introducido el numero correcto de argumentos
 *     2: Ha declarado un numero de ganadores y cuenta 
 *        los jugadores que participan para cada caso
 * 
 * @param[out] cont_jugadores : guarda el numero de ganadores que participan en el sorteo
 * @param[out] num_ganadores : guarda el numero de ganadores
 * @return Si hay un error, devuelve 1
 */
int procesarArgumentos(int *cont_jugadores, int *num_ganadores, int argc, char *argv[])
{
    char *endptr;
    // Si el usuario ejecuta el programa sin argumentos devuelve error
    if(argc == 1)
    {
        printf(RED
            "ERROR: Tienes que introducir minimo 2 jugadores.\n"YELLOW
            "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
            "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED
            "\n_________________________________________FAIL\n\n"RESET);
        return 1; // error
    }
    // Si el segundo argumento es el numero de ganadores
    else if(argv[1][0] >= '0' && argv[1][0] <= '9' && argv[1][1] == '\0')
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 4 || argc > TAM_ARR + 2)
        {
            printf(RED
                "ERROR: Tienes que introducir entre 2 y 10 jugadores.\n"YELLOW
                "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED
                "\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 2;
        *num_ganadores = strtol(argv[1], &endptr, 10);
        // Comprobamos que no hay mas ganadores que jugadores
        if(*num_ganadores >= *cont_jugadores) 
        {
            printf(RED
            "ERROR: El numero de ganadores debe ser inferior al numero de participantes\n"
            "\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
    }
    // Si el 2 argumento no es un numero
    else
    {
        // Comprobamos que el usuario introduce entre 2 y 10 jugadores
        if(argc < 3 || argc > TAM_ARR + 1)
        {
            printf(RED
                "ERROR: Tienes que introducir entre 2 y 10 jugadores.\n"YELLOW
                "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED
                "\n_________________________________________FAIL\n\n"RESET);
            return 1; // error
        }
        *cont_jugadores = argc - 1;
    }
    return 0;
}

/**
 * Comprueba que ningun jugador supere el  de caracteres que pueda almacenar un string
 * Comprobamos que los nombres de los jugadores no tengan numeros o nombres compuestos
 * Le pasamos como argumento el indice desde el cual tiene que comprobar los nombres
 * 
 * @param[in] i : 
 *      Especifica el indice de argv dese el cual la funcion comprueba si los nombres 
 *      son correctos dependiendo si hay numero de ganadores o no
 * @return devuelve un error si:
 *      Los nombres de los jugadores contienen numero o son compuestos
 *      El numero de caracteres de un jugador supera el tamaño soportado por el string
 */
int comprobarNombres(int i, int argc, char *argv[])
{
    int num_letras_argumento = 0; // Cuenta el numero de caracteres por string

    for(; i < argc; i++)
    {
        int j = 0;
        num_letras_argumento = 0;
        while(argv[i][j] != '\0')
        {
            num_letras_argumento++;
            // Jugadores llevan algun caracter que no sea letra
            if(!( (argv[i][j] >= 'a' && argv[i][j] <= 'z') || 
                  (argv[i][j] >= 'A' && argv[i][j] <= 'Z') ))
            {
                printf(RED
                    "ERROR: Los nombres de los jugadores no pueden \n"
                    "empezar por numero o tener nombres compuestos\n"YELLOW
                    "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                    "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED
                    "\n_________________________________________FAIL\n\n"RESET);
                return 1; // error
            }
            // Nombre jugador supera el tamaño que puede tener un string
            if(num_letras_argumento > TAM_STR - 1)
            {
                printf(RED
                    "ERROR: El nombre excede el límite de %d caracteres.\n"YELLOW
                    "USO 1 (1 ganador)        : ./main [nombre] [nombre]...[nombre]\n"
                    "USO 2 (varios ganadores) : ./main [num_ganadores] [nombre] [nombre]...[nombre]\n"RED
                    "\n_________________________________________FAIL\n\n"RESET, TAM_STR - 1);
                return 1; // error
            }
            j++;
        }
    }
    return 0;
}

/**
 * Asignamos el nombre de cada jugador a las cadenas de nuestro array por referencia
 * 
 * @param[in] i :
 *      Especifica el indice de argv dese el cual la funcion guarda nombres en el array
 * @param[out] jugador : 
 *      Arreglo de string que guarda los nombres de los jugadores
 */
void guardarNombres(int i, char jugador[TAM_ARR][TAM_STR], int argc, char *argv[])
{
    int i_inicio = i;
    for(; i < argc; i++)
        {
            int j = 0;
            while(argv[i][j] != '\0')
            {
                jugador[i - i_inicio][j] = argv[i][j];
                j++;
            }
            if(argv[i][j] == '\0')
                jugador[i - i_inicio][j] = '\0';
        }
}

/**
 * Funcion que selecciona los ganadores
 * 
 * @param[in] numeroAleatorio Arreglo que almacena los indices de los ganadores
 * @param[in] ganador Arreglo que almacena los nombres de los ganadores
 */
void seleccionarGanador(
    int num_ganadores, 
    int cont_jugadores, 
    char jugador[TAM_ARR][TAM_STR], 
    int numeroAleatorio[TAM_ARR - 1], 
    char ganador[TAM_ARR][TAM_STR])
{
    int random   = 0,
        repetido = 0;

    // Si el usuario no especifica que hay ganadores por defecto debe haber 1 ganador
    if(num_ganadores == 0)
        num_ganadores = 1;

    srand(time(NULL)); 
    // Generamos de manera aleatoria un indice para cada ganador
    // Los indices no se pueden repetir (un jugador no puede ganar 2 veces el mismo sorteo)
    for(int i = 0; i < num_ganadores; i++)
    {
        do
        {
            repetido = 0;
            random = rand() % cont_jugadores;
            numeroAleatorio[i] = random;
            // Comprobamos si el mismo indice ya ha salido
            for(int j = 0; j < i; j++)
            {
                if(numeroAleatorio[j] == numeroAleatorio[i])
                    repetido = 1;
            }
        } 
        while(repetido);
    }

    // Asignamos los los indices de los ganadores a nuestro array de ganadores
    if(num_ganadores == 1)
        printf(GREEN"GANADOR: \n\n"RESET);
    else
        printf(GREEN"GANADORES: \n\n"RESET);
    for(int i = 0; i < num_ganadores; i++)
    {
        for(int j = 0; j <= TAM_STR; j++)
        {
            ganador[i][j] = jugador[numeroAleatorio[i]][j];
        }
        printf(GREEN"%dº: %s\n"RESET, i + 1, ganador[i]); // Imprimimos los ganadores
    }
}

// Funciones auxiliares
void clearBuffer()
{
    while (getchar() != '\n');
}

/*
    DEBUG LOG
    printf("\n_________________________________________DEBUG\n\n");

    printf("DEBUG random i = %d: %d\n", i, random);

    printf("\n\n");
    printf("DEBUG numeroAleatorio[0]: %d\n", numeroAleatorio[0]);
    printf("DEBUG numeroAleatorio[1]: %d\n", numeroAleatorio[1]);
    printf("DEBUG numeroAleatorio[2]: %d\n", numeroAleatorio[2]);
    printf("DEBUG numeroAleatorio[3]: %d\n", numeroAleatorio[3]);
    printf("DEBUG numeroAleatorio[4]: %d\n", numeroAleatorio[4]);
    printf("DEBUG numeroAleatorio[5]: %d\n", numeroAleatorio[5]);
    printf("\n\n");

    printf("DEBUG Argc          : %d\n", argc);
    printf("DEBUG Num Ganadores : %d\n", num_ganadores);
    printf("DEBUG Num Jugadores : %d\n", cont_jugadores);
    printf("DEBUG Jugador 0 : %s\n", jugador[0]);
    printf("DEBUG Jugador 1 : %s\n", jugador[1]);
    printf("DEBUG Jugador 2 : %s\n", jugador[2]);
    printf("DEBUG Jugador 3 : %s\n", jugador[3]);
    printf("DEBUG Jugador 4 : %s\n", jugador[4]);
    printf("DEBUG Jugador 5 : %s\n", jugador[5]);
    printf("DEBUG Jugador 6 : %s\n", jugador[6]);
    printf("DEBUG Jugador 7 : %s\n", jugador[7]);
    printf("DEBUG Jugador 8 : %s\n", jugador[8]);
    printf("DEBUG Jugador 9 : %s\n", jugador[9]);
    printf("\n_________________________________________DEBUG\n\n");
*/