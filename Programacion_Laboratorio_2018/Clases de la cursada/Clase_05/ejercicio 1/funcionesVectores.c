#include <stdio.h>
#include <stdlib.h>

void ejemploCargaSecuencial(void){
    int  listadoEdades[5], i,j;
    float  listadoPrecios[5];

    for(i=0;i<5;i++){
        printf("VectorInt[%d]\nIngrese el numero: ", i);
        scanf("%d",&listadoEdades[i]);
    }
    for(j=0;j<5;j++){
        printf("VectorFloat[%d]\nIngrese un numero: ", j);
        scanf("%f",&listadoPrecios[j]);
    }

    for(i=0;i<5;i++){
        printf("\nVectorInt[%d]: %d",i,listadoEdades[i]);
        printf("\nVectorFloat[%d]: %.1f",i,listadoPrecios[i]);
    }
}
