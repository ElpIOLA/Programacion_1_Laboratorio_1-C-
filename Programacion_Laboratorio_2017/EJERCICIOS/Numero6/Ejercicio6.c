// De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero.

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define true 0

int main()
{
    int num, cont = 0, acum = 0, contMax = 0, contMin = 0, max, min, bandera = true;


    while(cont < 10)
    {
        cont ++;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        acum += num;

        if (bandera == true)
        {
            max = num;
            min = num;
            bandera = 0;
        }
            else if(num > max)
            {
                max = num;
                contMax++;
            }
                else if(num < min)
                {
                    min = num;
                    contMin++;
                }
        return 0;
    }

    printf("La cantidad de numeros positivos son: %d\n", contMax);
    printf("La cantidad de numeros negativos son: %d\n", contMin);

}
