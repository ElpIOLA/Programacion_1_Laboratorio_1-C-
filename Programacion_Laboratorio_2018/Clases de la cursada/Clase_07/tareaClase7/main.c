#include <stdio.h>
#include <stdlib.h>
#define CANT 5

/**
    UNA FUNCION QUE RECIBA EL VECTOR DE LEGAJOS, QUE RECIBA EL TAMAÑO DE VECTOR DE LEGAJOS Y QUE RECIBA UN NUMERO DE LEGAJO.
    DEVUELVE EL INDICE DEL LEGAJO SI ES QUE LO ENCUENTRA O SINO -1.
*/
int funcionLegajo(int vecLeg[], int tamLeg, int numLeg);
int validarInt(char mensaje[],char mensajeError[],int ope);

int main()
{
    int legajo[CANT], i, auxLeg, leg;

    for(i=0;i<CANT;i++){
        legajo[i] = validarInt("\n\tIngrese un numero: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",legajo[i]);
    }

    printf("\n\tQue legajo desea buscar?\n\tRespuesta: ");
    scanf("%d",&leg);
    auxLeg = funcionLegajo(legajo,CANT,leg);

    if(auxLeg == -1){
        printf("\n\tNO EXISTE ESTE LEGAJO!\n");
    }else{
        printf("\n\tLEGAJO ENCONTRADO: %d\n",auxLeg);
    }

    return 0;
}

int funcionLegajo(int vecLeg[], int tamLeg, int numLeg){
    int index = -1, i;

    for(i=0;i<tamLeg;i++){
        if(vecLeg[i] == numLeg){
            index = numLeg;
        }
    }
    return index;
}

int validarInt(char mensaje[],char mensajeError[],int ope){
    char aux[20];
    do{
        printf("%s",mensaje);
        scanf("%s",aux);
        ope = atoi(aux);
        if(ope!=0){
            break;
        }else{
            printf("%s",mensajeError);
        }
    }while(ope==0);
    return ope;
}
