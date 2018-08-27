#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "propietario.h"
#include "funcionValidar.h"

void inicializar_propietario(ePropietario propietario[], int tamProp){
    int i;

    for(i=0;i<tamProp;i++){
        propietario[i].id_propietario = 0;
        propietario[i].estado = 0;
    }
}

void datos_hard_propietario(ePropietario propietario[], int tamProp){

    int id_pro[]= {1,2,3,4},i;
    char nombree[][20]= {"Juan","Luis","Maria","Jose"};
    char apellido[][20]= {"Franco","Sanchez","Gomez","Lopez"};
    char tarjeta[][40]= {"111-111","222-222","333-333","444-444"};
    char direccion[][40]= {"mitre","urquiza","belgrano","alsina"};

    inicializar_propietario(propietario,tamProp);

    for(i=0;i<4;i++){
        propietario[i].id_propietario = id_pro[i];
        strcpy(propietario[i].nombre,nombree[i]);
        strcpy(propietario[i].apellido,apellido[i]);
        strcpy(propietario[i].num_tarjeta_credito,tarjeta[i]);
        strcpy(propietario[i].direccion,direccion[i]);
        propietario[i].estado = 1;
    }
}

void lista_propietario(ePropietario propietario[], int tamProp){
    int i;

    for(i=0;i<tamProp;i++){
        if(propietario[i].estado == 1){
            printf("\n\t%d - %s - %s - %s - %s\n",propietario[i].id_propietario,propietario[i].nombre,propietario[i].apellido,propietario[i].direccion,propietario[i].num_tarjeta_credito);
        }
    }
}

int eProp_buscarLugarLibre(ePropietario propietario[], int tamProp){
    int retorno = -1;
    int i;
    if(tamProp > 0 && propietario != NULL){
        retorno = 0;
        for(i=0;i<tamProp;i++){
            if(propietario[i].estado == 0){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProp_siguienteId(ePropietario propietario[], int tamProp){
    int retorno = 0;
    int i;
    if(tamProp > 0 && propietario != NULL){
        for(i=0; i<tamProp; i++){
            if(propietario[i].estado == 1){
                if(propietario[i].id_propietario>retorno){
                     retorno=propietario[i].id_propietario;
                }
            }
        }
    }

    return retorno+1;
}

int eProp_buscarPorId(ePropietario propietario[], int tamProp, int id){
    int retorno = -1;
    int i;
    if(tamProp > 0 && propietario != NULL){
        retorno = -2;
        for(i=0;i<tamProp;i++){
            if(propietario[i].estado == 1 && propietario[i].id_propietario == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**-------------------------------ABM--------------------------------------------------------*/

int alta_propietario(ePropietario propietario[], int tamProp){
    int retorno = -1, id_pro, index;
    char aux_nom[21], aux_apellido[21], aux_direccion[21], aux_numTarjeta[21];

    if(tamProp > 0 && propietario != NULL){

        retorno = -2;
        index = eProp_buscarLugarLibre(propietario,tamProp);
        if(index >= 0){
            retorno = -3;
            id_pro = eProp_siguienteId(propietario,tamProp);
            if(index > 0){
                retorno = 0;

                if(!getStringLetras("\n\tINGRESE NOMBRE: ",aux_nom)){
                    retorno = -4;
                }
                fflush(stdin);

                if(!getStringLetras("\n\tINGRESE APELLIDO: ",aux_apellido)){
                    retorno = -5;
                }
                fflush(stdin);

                if(!getStringLetras("\n\tINGRESE DIRECCION: ",aux_direccion)){
                    retorno = -6;
                }
                fflush(stdin);

                if(!getStringLetrasConSigno("\n\tINGRESE NUMERO DE TARJETA: ",aux_numTarjeta)){
                    retorno = -7;
                }
                fflush(stdin);

                if(retorno == 0){
                    propietario[index].id_propietario = id_pro;
                    strcpy(propietario[index].nombre,aux_nom);
                    strcpy(propietario[index].apellido,aux_apellido);
                    strcpy(propietario[index].direccion,aux_direccion);
                    strcpy(propietario[index].num_tarjeta_credito,aux_numTarjeta);
                    propietario[index].estado = 1;
                }
            }
        }
    }
    return retorno;
}

int modificar_propietario(ePropietario propietario[], int tamProp){
    int retorno = -1, id_pro, index;
    char aux_id[21], respuesta[21], aux_tarjeta[21];

    if(tamProp > 0 && propietario != NULL){

        if(!getStringNumeros("\n\tINGRESE ID DEL PROPIETARIO A MODIFICAR: ",aux_id)){
            retorno = -2;
        }
        id_pro = atoi(aux_id);

        retorno = -3;
        index = eProp_buscarPorId(propietario,tamProp,id_pro);
        if(index >= 0){
            printf("\n\tPROPIETARIO ENCONTRADO: %s",propietario[index].nombre);
            if(!getStringLetras("\n\tESTA SEGURO QUE DESEA MODIFICAR LA TARJETA?\n\t[s] = SI\n\t[n] = NO\n\tRESPUESTA: ",respuesta)){
                retorno = -4;
            }
            fflush(stdin);
            if(stricmp(respuesta,"s")==0){
                retorno = 0;

                if(retorno == 0){
                    if(!getStringLetrasConSigno("\n\tINGRESE LA NUEVA TARJETA DE CREDITO: ",aux_tarjeta)){
                        retorno = -5;
                    }
                    fflush(stdin);
                    strcpy(propietario[index].num_tarjeta_credito,aux_tarjeta);
                }
            }else if(stricmp(respuesta,"n")==0){
                retorno = -6;
            }else{
                retorno = -7;
            }
        }
    }
    return retorno;
}

