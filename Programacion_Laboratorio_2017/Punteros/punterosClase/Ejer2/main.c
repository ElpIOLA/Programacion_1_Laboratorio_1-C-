#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, vec[5];
    int *p_tro;

    for(i = 0; i < 5;i++)
    {
        vec[i] = (i+3);
    }

    for(i = 0; i < 5; i++)
    {
        printf("\n%d",vec[i]);
    }

    p_tro = vec;

     for(i = 0; i < 5; i++)
    {
        printf("\n%d", *(p_tro+i));
    }
    return 0;
}
