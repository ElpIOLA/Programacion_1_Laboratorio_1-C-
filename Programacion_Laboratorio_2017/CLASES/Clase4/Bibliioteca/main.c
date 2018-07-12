#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
int main()
{
    int num1, num2, resultado;

    printf("Ingrese numero uno: ");
    scanf("%d", &num1);
    printf("Ingrese numero dos: ");
    scanf("%d", &num2);
    system("cls");
    printf("¿Que operacion desea hacer?");
    printf("\n[1] SUMAR:\n[2] RESTAR:\n");
    printf("¿Cual elige? ");
    scanf("%d", &resultado);
    system("cls");
    switch(resultado)
    {
        case 1:
            resultado = sumar(num1, num2);
            break;
        case 2:
            resultado = restar(num1, num2);
            break;
    }
    printf("El total es: %d\n", resultado);
    return 0;
}
