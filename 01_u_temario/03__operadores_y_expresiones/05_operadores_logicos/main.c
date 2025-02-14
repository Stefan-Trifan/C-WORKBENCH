/*	{
 *		"Autor": "Stefan Trifan", 
 *		"Compilar": {
 *			"mac": "gcc main.c -o main;",
 *			"windows": "gcc main.c -o main.exe;"
 *		},
 *		"Introducir despues de scanf": "limpiar()",
 *		"Enunciado": "Generar un programa que pida 4 numeros en coma flotante, y almacenarlos en 4 variables distintas. Mostrar el 		*		resultado de calcular las siguientes condiciones:
 *			▪ Si el primero es mayor que el segundo "y" el primero es mayor que el tercero
 *			▪ Si el cuadrado del tercero es menor que el segundo por el cuarto "o" el tercero por 2
 *				menor que el segundo
 *			▪ Si el resto de la division entre el primero y el cuarto es mayor que el tercero "y" el
 *				primero es mayor que el cuarto
 *			▪ Si la division entre el segundo y el cuarto "no es" distinta al primero"
 *	}
*/

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(int argc, char *argv[]){

	// Declaramos los float
	float num1 = 0, num2 = 0, num3 = 0, num4 = 0;

	int resultado1 = 0, resultado2 = 0, resultado3 = 0, resultado4 = 0;


	// Pedimos los numeros de coma flotante
	printf("Introduce los 4 numeros separados por espacios\n");
	scanf("%f %f %f %f", &num1, &num2, &num3, &num4);
	printf("Tus numeos son %f %f %f %f\n", num1, num2, num3, num4);

	// Si el primero es mayor que el segundo "y" el primero es mayor que el tercero
	resultado1 = (num1 > num2)  &&  (num1 > num3);

	// Si el cuadrado del tercero es menor que el segundo por el cuarto "o" el tercero por 2 menor que el segundo
	resultado2 = (num3 * num3 < num2 * num4) || (num3 * 2 < num2);

	// Si el resto de la division entre el primero y el cuarto es mayor que el tercero "y" el primero es mayor que el cuarto
	resultado3 = ((int)num1 % (int)num4 > num3) && (num1 > num4);

	// Si la division entre el segundo y el cuarto "no es" distinta al primero
	resultado4 = num2 / num4 != num1;

	printf("El resultado de las operaciones son:\n"
	"\t1: %d\n"
	"\t2: %d\n"
	"\t3: %d\n"
	"\t4: %d\n", resultado1, resultado2, resultado3, resultado4);
}