#include <stdio.h>
#include <stdlib.h>

/**
*
*@param
*@return
*/
int main()
{
    char nombre;
    printf("Ingrese su nombre: ");
    scanf("%c", &nombre);

    float sueldo, sueldoFinal;
    printf("Ingrese su sueldo: ");
    scanf("%f", &sueldo);

    int aumento;
    printf("Ingrese el aumento: ");
    scanf("%d", &aumento);

    sueldoFinal = ((sueldo * aumento) / 100) + sueldo;

    printf("%c tiene un aumento del: %d%%\nSu sueldo final es: %.2f\n",nombre,aumento,sueldoFinal);
    return 0;
}
