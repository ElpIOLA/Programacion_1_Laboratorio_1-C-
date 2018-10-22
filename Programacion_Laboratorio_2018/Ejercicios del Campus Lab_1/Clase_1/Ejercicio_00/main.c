/**
    Limpie la pantalla
    Solicite dos valores numéricos al usuario distintos de cero
    Asigne a las variables numero1 y numero2 los valores obtenidos
    Realice la resta de dichas variables
    Muestre el resultado por pantalla
    Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor
    Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2;
    float resultado = 0;
    system("cls");
    system("color 05");

    do
    {
        printf("\nIngrese dos numeros: ");
        scanf("%f %f",&num1,&num2);
    }while(num1 == 0 || num2 == 0);

    resultado = num1 - num2;

    if(resultado > 0)
    {
        printf("\nEl resultado es positivo: %.2f\n\n", resultado);
    }
    else
    {
        printf("\nEl resultado es negativo: %.2f\n\n", resultado);
    }
    return 0;
}
