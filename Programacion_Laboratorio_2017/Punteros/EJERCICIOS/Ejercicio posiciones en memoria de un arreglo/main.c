#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n[] = {1, 2, 3, 4, 4, 7, 8, 9, 5, 4};
    int *p_n;

    p_n = n; /** p_n = n[0]; */

    for(i = 0; i < 10; i++)
    {
        printf("Dato: n[%d]: %d",i,*p_n);
        printf("\nPosicion: %p", p_n);
        printf("\n\n");
        p_n++;
    }

    return 0;
}
