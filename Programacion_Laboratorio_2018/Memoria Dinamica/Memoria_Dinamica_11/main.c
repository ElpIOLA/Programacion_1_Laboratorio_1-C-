#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nombre[50];
}ePersona;

ePersona* newPersona();

int main()
{
    ePersona* pPersona;

    pPersona = newPersona();

    if(pPersona != NULL){
        pPersona->id = 21;
        printf("\n\t%d\n",pPersona->id);
    }
    return 0;
}

ePersona* newPersona(){
    ePersona* pPersona;

    pPersona = (ePersona*) malloc(sizeof(ePersona));

    return pPersona;
}
