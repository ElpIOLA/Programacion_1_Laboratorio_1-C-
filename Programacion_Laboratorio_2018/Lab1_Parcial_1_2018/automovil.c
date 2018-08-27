#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "propietario.h"
#include "automovil.h"
#include "funcionValidar.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

void inicializar_auto(eAuto automovil[], int tamAuto){
    int i;

    for(i=0;i<tamAuto;i++){
        automovil[i].id_auto = 0;
        automovil[i].estado = 0;
    }
}

void datos_hard_autos(eAuto automoviles[], int tamAuto){
    int i;

    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    char marca[][41]= {"ALPHA_ROMEO","AUDI","AUDI","FERRARI","FERRARI","AUDI","AUDI","OTROS","AUDI","ALPHA_ROMEO"};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    inicializar_auto(automoviles,tamAuto);

    for(i=0;i<10;i++){
        automoviles[i].id_auto = id[i];
        strcpy(automoviles[i].patente,patente[i]);
        strcpy(automoviles[i].marca,marca[i]);
        automoviles[i].id_propietario = propietario[i];
        automoviles[i].estado = 1;
    }
}

void lista_autos(eAuto automoviles[], int tamAuto){
    int i;

    for(i=0;i<tamAuto;i++){
        if(automoviles[i].estado == 1){
            printf("\n\t%d - %s - %s - %d\n",automoviles[i].id_auto,automoviles[i].patente,automoviles[i].marca,automoviles[i].id_propietario);
        }
    }
}

int eAuto_buscarLugarLibre(eAuto automovil[], int tamAuto){
    int retorno = -1;
    int i;
    if(tamAuto > 0 && automovil != NULL){
        retorno = 0;
        for(i=0;i<tamAuto;i++){
            if(automovil[i].estado == 0){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAuto_siguienteId(eAuto automovil[], int tamAuto){
    int retorno = 0;
    int i;
    if(tamAuto > 0 && automovil != NULL){
        for(i=0; i<tamAuto; i++){
            if(automovil[i].estado == 1){
                if(automovil[i].id_auto>retorno){
                     retorno=automovil[i].id_auto;
                }
            }
        }
    }

    return retorno+1;
}

int eAuto_buscarPorId(eAuto automovil[], int tamAuto, int id){
    int retorno = -1;
    int i;
    if(tamAuto > 0 && automovil != NULL){
        retorno = -2;
        for(i=0;i<tamAuto;i++){
            if(automovil[i].estado == 1 && automovil[i].id_auto == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAuto_buscarPorIdProp(eAuto automovil[], int tamAuto, int id){
    int retorno = -1;
    int i;
    if(tamAuto > 0 && automovil != NULL){
        retorno = -2;
        for(i=0;i<tamAuto;i++){
            if(automovil[i].estado == 1 && automovil[i].id_propietario == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**----------------------------ABM------------------------------------------------*/

int alta_automovil(eAuto automovil[], int tamAuto, ePropietario propietario[], int tamProp){

    int retorno = -1, id_propietario, index_prop, index_auto, id_auto;
    char aux_id[21], aux_patente[21], aux_marca[21];

    if(tamAuto > 0 && tamProp > 0 && automovil != NULL && propietario != NULL){

        if(!getStringNumeros("\n\tINGRESE ID DEL PROPIETARIO: ",aux_id)){
            retorno = -2;
        }
        id_propietario = atoi(aux_id);
        retorno = -3;
        index_prop = eProp_buscarPorId(propietario,tamProp,id_propietario);
        if(index_prop >= 0){
            printf("\n\tPROPIETARIO ENCONTRADO: %s\n",propietario[index_prop].nombre);
            retorno = -4;
            index_auto = eAuto_buscarLugarLibre(automovil,tamAuto);
            if(index_auto >= 0){
                retorno = -5;
                id_auto = eAuto_siguienteId(automovil,tamAuto);
                if(index_auto > 0){
                    retorno = 0;

                    if(!getStringLetras("\n\tINGRESE PATENTE: ",aux_patente)){
                        retorno = -6;
                    }
                    fflush(stdin);
                    if(!getStringNumeros("\n\tINGRESE MARCA\n\tLA MARCA DEBE SER ENTRE[1 - 4]\n\tINGRESE RESPUESTA: ",aux_marca)){
                        retorno = -7;
                    }
                    fflush(stdin);

                    if(strcmp(aux_marca,"1")>=0&&strcmp(aux_marca,"4")<=0){
                        if(retorno == 0){

                            automovil[index_auto].id_auto = id_auto;
                            strcpy(automovil[index_auto].patente,aux_patente);
                            automovil[index_auto].id_propietario = id_propietario;

                            if(strcmp(aux_marca,"1")==0){
                                strcpy(aux_marca,"ALPHA_ROMEO");
                                strcpy(automovil[index_auto].marca,aux_marca);
                            }else if(strcmp(aux_marca,"2")==0){
                                strcpy(aux_marca,"FERRARI");
                                strcpy(automovil[index_auto].marca,aux_marca);
                            }else if(strcmp(aux_marca,"3")==0){
                                strcpy(aux_marca,"AUDI");
                                strcpy(automovil[index_auto].marca,aux_marca);
                            }else if(strcmp(aux_marca,"4")==0){
                                strcpy(aux_marca,"OTROS");
                                strcpy(automovil[index_auto].marca,aux_marca);
                            }
                            automovil[index_auto].estado = 1;
                        }
                    }else{
                        retorno = -8;
                    }
                }
            }
        }
    }
    return retorno;
}

