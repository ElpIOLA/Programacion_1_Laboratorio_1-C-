#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "C:\Users\ELpIOLA\Desktop\ElpIOLA\Programacion_1 Laboratorio_1\Funciones\FunCpIOLA.h"

int main()
{
    int a,b,resultado;

    while(a != 0 && b != 0)
    {
        a = getInt("\nIngrese valor A: ");
        b = getInt("\nIngrese valor B: ");
        resultado = a * b;
        printf("\nLa superficie del cuadrado es: %d", resultado);
    }

    printf("FIN DE PROGRAMA.");

    return 0;
}

