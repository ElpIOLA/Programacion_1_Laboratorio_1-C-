/** Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, max = 0, min = 0, acumulador = 0;
    float promedio = 0;
    int flag = 0;

    system("color 03");

    for(int i = 1; i <= 5; i++)
    {
        printf("\n%d-. Ingrese un numero: ",i);
        scanf("%d",&numero);
        acumulador += numero;
        if(flag == 0)
        {
            max = numero;
            min = numero;
            flag = 1;
        }

        if(max < numero)
        {
            max = numero;
        }
        if(min > numero)
        {
            min = numero;
        }
    }

    promedio = acumulador / 5;

    printf("\nEl promedio es: %.2f\n",promedio);
    printf("\nEl numero mas alto es: %d\n", max);
    printf("\nEl numero mas chico es: %d\n", min);
    return 0;
}
