// Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares hay
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont;
    int numero = 0, acum = 0, contImpares = 0;
    for(cont = 1;cont <= 10;cont++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        acum += numero;

        if(numero%2==0)
        {

        }
            else
            {
                contImpares++;
            }
    }

    printf("La cantidad de numeros impares son: %d", contImpares);
    return 0;
}
