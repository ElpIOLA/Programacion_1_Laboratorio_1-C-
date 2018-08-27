#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 40;
    int *p_numero;

    p_numero = &numero;

    printf("Valor de la variable\n");
    printf("Dato: %d", numero);
    printf("\nDato: %d", *p_numero);
    printf("\n");
    printf("\nPosicion de memoria\n");
    printf("Posicion: %p", &numero);
    printf("\nposicion: %p", p_numero);

    return 0;
}
