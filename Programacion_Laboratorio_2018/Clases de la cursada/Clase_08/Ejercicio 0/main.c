#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 6

void ordenamientoString(char vecNom[][30], int tam);

int main()
{
    int i;
    char vectorNombre[CANT][30] = {"Juan","Santiago","Mario","Hernan","Anahi","Ana"};

    ordenamientoString(vectorNombre,CANT);

    for(i=0;i<CANT;i++){
        printf("\n\t%s\n",vectorNombre[i]);
    }

    return 0;
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

