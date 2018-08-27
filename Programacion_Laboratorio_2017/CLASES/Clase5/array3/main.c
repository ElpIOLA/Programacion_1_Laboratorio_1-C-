#include <stdio.h>
#include <stdlib.h>
#define cant 4
int main()
{
    int i, max, min, vec[cant];
    for(i == 0; i < cant ; i++)
    {
        printf("Ingrese numeros: ");
        scanf("%d", &vec[i]);
    }

    if(i == 0  || vec[i] > max)
        {
            max = vec[i];
            printf("Vector Maximo: %d", max);
        }
        if(i == 0  || vec[i] < min)
        {
            min = vec[i];
            printf("Vector Maximo: %d", min);
        }
    return 0;
}
