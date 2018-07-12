#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10, *p_n = &n;
    float n2 = 10.6, *p_n2 = &n2;
    char n3 = 'a', *p_n3 = &n3;

    printf("Variable Entera: \n");
    printf("Dato: %d", *p_n);
    printf("\nPosicion: %p", p_n);

    printf("\n\nVariable Flotante: \n");
    printf("Dato: %.2f", *p_n2);
    printf("\nPosicion: %p", p_n2);

    printf("\n\nVariable Caracter: \n");
    printf("Dato: %c", *p_n3);
    printf("\nPosicion: %p", p_n3);
    return 0;
}
