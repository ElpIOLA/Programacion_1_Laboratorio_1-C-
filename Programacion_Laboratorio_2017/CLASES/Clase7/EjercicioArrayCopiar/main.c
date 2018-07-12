#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void copiandoArrays(int a[], int b[], int tamanio[]);
int main()
{
    int array1[5] = {4,3,6,1,8};
    int array2[5];

    printf("Copiando Arrays\n\n");
    copiandoArrays(array1,array2,5);

    getch();
    return 0;
}

// a[] = array1
// b[] = array2
void copiandoArrays(int a[], int b[], int tamanio[]){
    int i;

    for(i=0;i<tamanio;i++)
    {
        b[i] = a[i];
    }

    for(i=0;i<tamanio;i++){
        printf("%d", b[i]);
    }
}
