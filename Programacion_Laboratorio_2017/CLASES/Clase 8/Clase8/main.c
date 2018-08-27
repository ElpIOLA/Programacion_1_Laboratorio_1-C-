#include <stdio.h>
#include <stdlib.h>
#include "ElpIOLA.h"

int main()
{

    struct alumno alu;

    printf("Ingrese el legajo: ");
    scanf("%d", &alu.legajo);

    printf("Ingrese su nombre: ");
    fflush(stdin);
    scanf("%[^\n]", alu.nombre);

    printf("\nIngrese 1ra Nota: ");
    scanf("%d", &alu.notaUno);
    printf("\nIngrese 2da Nota: ");
    scanf("%d", &alu.notaDos);
    printf("\nIngrese 3ra Nota: ");
    scanf("%d", &alu.notaTres);

    alu.prom = pRom(alu.notaUno, alu.notaDos, alu.notaTres);

    printf("Hola %s, su legajo es: %d", alu.nombre,alu.legajo);
    printf("\nEl promedio de las notas es: %.2f", alu.prom);
    return 0;
}
