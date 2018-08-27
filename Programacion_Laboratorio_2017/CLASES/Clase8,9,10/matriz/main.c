#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int matriz[2][3];
    int i,j;

    for(i = 0;i < 2;i++)
    {
        for(j = 0;j < 3; j++)
        {
            printf("Matriz [%d][%d] \n",i+1,j+1);
            printf("Ingrese numero: ");
            scanf("%d",&matriz[i][j]);
        }
    }

    for(i=0;i<2;i++)
    {
        for(j = 0;j < 3; j++)
        {
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }

    getch();
    return 0;
}
