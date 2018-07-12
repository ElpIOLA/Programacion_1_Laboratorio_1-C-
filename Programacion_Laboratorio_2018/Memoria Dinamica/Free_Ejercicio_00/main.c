#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1;

    p1 = (int *)malloc(sizeof(int));
    if(p1 == NULL){
        printf("\n\tMEMORIA LLENA\n");
    }else{
        printf("\n\tHAY ESPACIO\n");
        *p1 = 15;
        printf("\n\t%d\n",*p1);
    }

    free(p1); //LIBERA ESPACIO QUE APUNTA P1.
    printf("\n\t%d\n",*p1);

    return 0;
}
