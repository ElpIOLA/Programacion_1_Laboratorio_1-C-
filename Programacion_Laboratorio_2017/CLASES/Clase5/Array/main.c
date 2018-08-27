#include <stdio.h>
#include <stdlib.h>

#define cant 2

int main()
{
    int i;
    int edad[cant];
    float salario[cant];
    int legajo[cant];
    for(i = 0; i < cant; i++)
    {
        printf("Ingresa una edad: ");
        scanf("%d", &edad[i]);
        printf("Ingrese el salario: ");
        scanf("%f", &salario[i]);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo[i]);
    }
    for(i = 0; i < cant; i++)
    {
        printf("Edad es: %d y cobra $%.2f y su legajo es: %d\n",edad[i], salario[i], legajo[i]);
    }
    return 0;
}
