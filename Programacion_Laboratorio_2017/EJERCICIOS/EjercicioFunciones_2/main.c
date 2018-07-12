#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "func.h"

int main()
{
    int a,b, resultado;
    char respuesta = 's';

    while(respuesta != 'n')
    {
        printf("Ingrese el valor A: ");
        scanf("%d", &a);
        printf("Ingrese el valor B: ");
        scanf("%d", &b);
        respuesta = intvalidaS_N();
    }

    resultado = a + b;
    printf("El resultado final es: %d", resultado);
    return 0;
}
