#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 3

float calcularPromedio(int not1, int not2, int not3){
    float promedio = 0;
    int i;

    for(i=0;i<CANT;i++){
        promedio = (float)(not1 + not2 + not3) / CANT;
    }
    return promedio;
}

void mostrarAlumno(char nom[][30], int leg[], float prom[], int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        printf("\n\tAlumno: %s\n\tLegajo: %d\n\tPromedio %.2f\n",nom[i],leg[i],prom[i]);
    }
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

void ordenamientoString(char vecNom[][30], int tam){
    int i, j;
    char aux[20];

    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(strcmp(vecNom[i],vecNom[j])>0){
                strcpy(aux,vecNom[i]);
                strcpy(vecNom[i],vecNom[j]);
                strcpy(vecNom[j],aux);
            }
        }
    }
}

