#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    char matriz[2][3] = {{'a','b','c'},{'z','y','w'}};
    int i,j;

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
    getch();
    return 0;
}
