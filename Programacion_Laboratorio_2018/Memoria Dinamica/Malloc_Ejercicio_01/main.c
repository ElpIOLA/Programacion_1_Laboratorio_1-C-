#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT 100

/**
    3. Reservar memoria con malloc para un array de tipo double para 1000 numeros, y comprobar si el puntero
    es valido (si el puntero devuelve NULL, significa que no hay suficiente memoria).
*/

int main()
{
    double *p_numero;
    int i;
    p_numero = (double *)malloc(CANT * sizeof(double));

    if(p_numero == NULL){
        printf("\n\tERROR EN LA ASIGNACION DE MEMORIA\n");
        return -1; //INTENTAMOS RECUPERAR MEMORIA
    }else{
        srand(time(NULL));
        for(i=0;i<CANT;i++){
            p_numero[i] = 1 + rand() % ((CANT+1)-1);
            printf("%lf\n",p_numero[i]);
        }
    }
    return 0;
}
