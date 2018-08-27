#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[50];
}ePersona;

int ePersona_setId(ePersona*,int);
int ePersona_setNom(ePersona*,char*);

int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

int main()
{
    ePersona* pPersona;

    pPersona = (ePersona*) malloc(sizeof(ePersona));

    if(pPersona != NULL){
        if(ePersona_setId(pPersona,21)==-1){
            printf("\nID INCORRECTO!\n");
        }else{
            printf("\n%d -",ePersona_getId(pPersona));
        }

        if(ePersona_setNom(pPersona,"Hernan")==-1){
            printf("\nNOMBRE INCORRECTO!\n");
        }else{
            printf("- %s\n",ePersona_getNombre(pPersona));
        }
    }
    return 0;
}

int ePersona_setId(ePersona* this,int id){

    int ret = -1;

    if(this != NULL && id > 0){
        ret = 1;
        this->id = id;
    }
    return ret;
}

int ePersona_setNom(ePersona* this,char* nombre){
    int ret = -1;

    if(this != NULL && nombre != NULL && strlen(nombre)>4){
        ret = 1;
        strcpy(this->nombre,nombre);
    }
    return ret;
}

int ePersona_getId(ePersona* this){
    int ret = -1;

    if(this != NULL){
        ret = this->id;
    }

    return ret;
}

char* ePersona_getNombre(ePersona* this){
    char* ret = NULL;

    if(this != NULL){
        ret = this->nombre;
    }

    return ret;
}
