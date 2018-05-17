#include <stdio.h>
#include <stdlib.h>

/**1era funcion: Recibe el array como vector y accede a los datos utilizando notación vectorial ([])*/
void funcion_MostrarUno(int array[], int cant);

/**2da funcion: Recibe el array como vector y accede a los datos utilizando aritmetica de punteros*/
void funcion_MostrarDos(int array[], int cant);

/**3era funcion: Recibe el array como puntero y accede a los datos utilizando notación vectorial ([])*/
void funcion_MostrarTres(int *array, int cant);

/**4da funcion: Recibe el array como puntero y accede a los datos utilizando aritmetica de punteros*/
void funcion_MostrarCuarto(int *array, int cant);
int main()
{
    int primerArray[] = {9,99,999};
    printf("-----------FUNCION 1--------------");
    funcion_MostrarUno(primerArray,3);
    printf("-----------FUNCION 2--------------");
    funcion_MostrarDos(primerArray,3);
    printf("-----------FUNCION 3--------------");
    funcion_MostrarTres(primerArray,3);
    printf("-----------FUNCION 4--------------");
    funcion_MostrarCuarto(primerArray,3);
    return 0;
}

void funcion_MostrarUno(int array[], int cant){
    int i;

    for(i=0;i<cant;i++)
        printf("\n[%d] - %d\n",i,array[i]);

}

void funcion_MostrarDos(int array[], int cant){
    int i;

    for(i=0;i<cant;i++)
        printf("\n[%d] - %d\n",i,*(array+i));

}

void funcion_MostrarTres(int *array, int cant){
    int i;

    for(i=0;i<cant;i++)
        printf("\n[%d] - %d\n",i,array[i]);
}

void funcion_MostrarCuarto(int *array, int cant){
    int i;

    for(i=0;i<cant;i++)
        printf("\n[%d] - %d\n",i,*(array+i));
}
