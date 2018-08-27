#include <stdio.h>
#include <stdlib.h>
int pedirEntero(int min, int max);
float pedirFloat(int min, int max);

int main(){

    int indice, i, min, max;
    float precio, listadoPrecios[5];

    pedirEntero(min,max);
    precio = pedirFloat(0,1000);
    listadoPrecios[indice] = precio;

    for(i=0;i<5;i++){
        printf("Indice[%d]: %.2f",indice,listadoPrecios[indice]);
    }
    return 0;
}

void pedirEntero(int min, int max){
    int j, i, vec[max];
    max = vec[0];
    for(i=0;i<max;i++){
        if(vec[i]>max){
            max = vec[i];
        }
    }
    min = vec[0];
    for(j=0;j<max;i++){
        if(vec[j]<min){
            min = vec[j];
        }
    }
}

float pedirFloat(int min, int max){
    int i;
    float vect[max];
    for(i=0;i<max;i++){
        printf("Ingrese precio: ");
        scanf("%f",&vect[i]);
    }
    return vect[i];
}








/**
int main()
{
    int edad, listadoEdades[5] = {22,33,44,11,55};
    float precio, listadoPrecios[5];

    edad = 66;
    printf("\nEdad: %d",edad);
    printf("\nEdad: %d",&edad);

    printf("\n&listadoEdades: %d",&listadoEdades);
    printf("\nlistadoEdades: %d",listadoEdades);
    printf("\nlistadoEdades[0]: %d",listadoEdades[0]);
    printf("\n&listadoEdades[0]: %d",&listadoEdades[0]);
    printf("\nlistadoEdades[4]: %d",listadoEdades[4]);
    printf("\nlistadoEdades[5]: %d",listadoEdades[5]);
    return 0;
}
*/
