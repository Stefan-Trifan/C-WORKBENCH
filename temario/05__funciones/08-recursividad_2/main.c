/*
*	Autor
		Stefan Trifan

*	Compilar
		mac     : gcc main.c -o main
		windows : gcc main.c -o main.exe
			    : ./main.exe

*	Introducir después de scanf
		limpiar()

*	Enunciado
		Hacer un programa que calcule el mínimo, el máximo y la media 
		de tres números enteros que deban ser leídos de la entrada estandar

		La funcionalidad debe ser realizada mediante una función denominada calculos()
		que reciba como parámetros los 3 números y devuelva los 3 resultados del siguiente modo:
			la media será entregada como resultado de la funcion 
			mientras que el minimo y el maximo de los valores se devolveran en los parametros de la funcion 
			por lo que seran pasados por referencia
 */

#include <stdio.h>

// Llamamos con limpiar()
void limpiar(){
	while(getchar() != '\n');
}

int main(){

}