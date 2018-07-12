#include <stdio.h>
#include <stdlib.h>

int main()
{
    char array[5] = {'u','a','i','e','o'};
    int i,posi,aux;

    for(i=0;i<5;i++)
    {
        posi = i;
        aux = array[i];
        while(posi > 0 && aux < array[posi - 1])
        {
            array[posi] = array[posi - 1];
            posi --;
        }
        array[posi] = aux;
    }
    printf("Ascendente: \n");
    for(i=0;i<5;i++)
    {
        printf("%c", array[i]);
    }

    printf("\nDescendente: \n");
    for(i=4;i>=0;i--)
    {
        printf("%c", array[i]);
    }

    return 0;
}
