#include <stdio.h>
#include <stdlib.h>
#define cant 5
#define false 0
#define true 1

int main()
{
    char seguir;
    int i, suma, prom, nota, edad[cant];
    float notas[cant];

    for (i = 0; i < cant ; i ++)
    {
        edad[i] = false;
        notas[i] = false;
    }
    while(seguir == 's')
    {
        printf("Ingrese la edad: ");
        scanf("%d", &edad[i]);
        printf("Ingrese el sueldo: ");
        scanf("%d", &nota);
        notas[i] = nota;

        printf("Desea continuar?");
        scanf("%c", &seguir);
     }

    for(i = 0; i < cant; i++)
    {
        suma += notas[i];
    }

    prom = suma / cant;
    printf("El promedio de notas es %.2f\n", prom);

    return 0;
}
