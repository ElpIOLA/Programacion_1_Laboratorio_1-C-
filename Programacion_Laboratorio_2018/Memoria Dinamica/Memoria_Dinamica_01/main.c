#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int* pVector, i, *aux;

    pVector = (int*) malloc(sizeof(int)*TAM);

    if(pVector != NULL){
        for(i=0;i<TAM;i++){
            *(pVector+i) = i+1;
        }
        for(i=0;i<TAM;i++){
            printf("\n%d\n",*(pVector+i));
        }
        /**---------------------------------------------*/
        aux = (int*) realloc(pVector,sizeof(int)*(TAM*2));

        if(aux != NULL){
            pVector = aux;

            for(i=TAM;i<(TAM*2);i++){
                *(pVector+i) = i+1;
            }
            printf("\n\tLUEGO DE REALLOC\n");

            for(i=TAM;i<(TAM*2);i++){
                printf("\n%d\n",*(pVector+i));
            }
            /**---------------------------------------------*/
            aux = (int*) realloc(pVector,sizeof(int)*4);
            if(aux != NULL){
                pVector = aux;

                for(i=0;i<2;i++){
                    printf("\n%d\n",*(pVector+i));
                }
            }
        }
        free(pVector);
    }

    return 0;
}
