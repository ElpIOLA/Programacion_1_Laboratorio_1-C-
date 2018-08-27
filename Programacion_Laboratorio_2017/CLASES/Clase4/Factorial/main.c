#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"
int main()
{
    int numero, result;

    printf("Ingrese el numero: ");
    scanf("%d", &numero);
    result = factorial(numero);
    printf("El factorial de %d es %d", numero, result);
    return 0;
}
