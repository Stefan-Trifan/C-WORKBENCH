#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv) {
    // Informacion sobre char
    printf("El numero de bits de un char es        :   %d\n", CHAR_BIT);
    printf("El numero de bytes de un char es       :   %d\n", sizeof(char));
    printf("El menor valor de un signed char es    :   %d\n", CHAR_MIN);
    printf("El mayor valor de un signed char es    :   %d\n", CHAR_MAX);
    printf("El mayor valor de un unsigned char es  :   %d\n\n", UCHAR_MAX);

    // Informacion sobre int
    printf("El numero de bytes de un int es        :   %d\n", sizeof(int));
    printf("El menor valor de un int es            :   %d\n", INT_MIN);
    printf("El mayor valor de un int es            :   %d\n", INT_MAX);
    printf("El mayor valor de un unsigned int es   :   %u\n\n", (unsigned int) UINT_MAX);

    // Informacion sobre short
    printf("El numero de bytes de un short es      :   %d\n", sizeof(short));
    printf("El menor valor de un short es          :   %d\n", SHRT_MIN);
    printf("El mayor valor de un short es          :   %d\n", SHRT_MAX);
    printf("El mayor valor de un unsigned short es :   %d\n\n", (unsigned short) USHRT_MAX);

    // Informacion sobre long
    printf("El numero de bytes de un long es       :   %d\n", sizeof(long));
    printf("El menor valor de un long es           :   %ld\n", (long) LONG_MIN);
    printf("El mayor valor de un long es           :   %ld\n", (long) LONG_MAX);
    printf("El mayor valor de un unsigned long es  :   %lu\n", (unsigned long) ULONG_MAX);

    return 0;
}