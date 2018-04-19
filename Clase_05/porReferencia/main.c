#include <stdio.h>
#include <stdlib.h>
#define CANT 5

void cambiarEntero(int n); //PASAJE POR VALOR
void cambiarVector(int listadoDeNumeros[]); //PASAJE POR REFERENCIA
void pedirVector(int listado[CANT]);

int main()
{
    int i, tamanioVector, tamanioElemento, cantidadElementos, listadoEdades[CANT] = {2,3,4};
    for(i=0;i<CANT;i++){
        printf("\n%d",listadoEdades[i]);
    }

    /**SIZEOF TE DA EL TAMA�O DEL VECTOR*/
    tamanioVector = sizeof(listadoEdades); //Tama�o total del vector en Bytes
    printf("\nTama�o Vector: %d",tamanioVector);

    tamanioElemento = sizeof(listadoEdades[0]); //Tama�o de un elemento
    printf("\nTama�o de Elementos: %d",tamanioElemento);

    cantidadElementos = tamanioVector / tamanioElemento; //Cantidad de elementos del vector
    printf("\nCantidad Elementos: %d", cantidadElementos);
    return 0;
}


void cambiarEntero(int n){ //PASAJE POR VALOR
    n = 666;
}

void cambiarVector(int listadoDeNumeros[]){ //PASAJE POR REFERENCIA
    listadoDeNumeros[0] = 666;
}
