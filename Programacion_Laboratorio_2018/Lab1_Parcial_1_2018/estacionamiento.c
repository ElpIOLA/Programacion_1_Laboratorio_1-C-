#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "propietario.h"
#include "automovil.h"
#include "estacionamiento.h"
#include "funcionValidar.h"
#include "menu.h"

float recaudacion = 0, marca_ALPHA = 0, marca_FERRARI = 0, marca_AUDI = 0, marca_OTROS = 0;

void datos_hard_egresos(int tamAuto){
    int i;

    char marca[][31]= {"ALPHA_ROMEO","ALPHA_ROMEO","FERRARI","AUDI","FERRARI","FERRARI","AUDI","OTROS","ALPHA_ROMEO","ALPHA_ROMEO"};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    for(i=0;i<tamAuto;i++){
        if(strcmp(marca[i],"ALPHA_ROMEO")==0){
            marca_ALPHA += importe[i];
        }else if(strcmp(marca[i],"FERRARI")==0){
            marca_FERRARI += importe[i];
        }else if(strcmp(marca[i],"AUDI")==0){
            marca_AUDI += importe[i];
        }else if(strcmp(marca[i],"OTROS")==0){
            marca_OTROS += importe[i];
        }
    }
    recaudacion = (marca_ALPHA + marca_FERRARI + marca_AUDI + marca_OTROS);
}

int baja_propietario(ePropietario propietario[], int tamProp, eAuto automovil[], int tamAuto){

    int retorno = -1, id_prop, index, index_Auto;
    char aux_id[21],respuesta[21];
    float total = 0;

    if(tamAuto > 0 && tamProp > 0 && automovil != NULL && propietario != NULL){

        if(!getStringNumeros("\n\tINGRESE EL ID DEL PROPIETARIO A ELIMINAR: ",aux_id)){
            retorno = -2;
        }
        fflush(stdin);
        id_prop = atoi(aux_id);
        retorno = -3;
        index = eProp_buscarPorId(propietario,tamProp,id_prop);
        if(index >= 0){
            printf("\n\tPROPIETARIO ENCONTRADO: %s\n",propietario[index].nombre);
            retorno = -4;
            index_Auto = eAuto_buscarPorIdProp(automovil,tamAuto,id_prop);
            if(index_Auto >= 0){
                total = tarifa(automovil,tamAuto,id_prop,propietario);
                if(total >= 0){
                    printf("\n\tTOTAL A PAGAR: %.2f\n",total);
                    retorno = 0;
                    if(!getStringLetras("\n\tESTA SEGURO QUE DESEA DAR DE BAJA A EL PROPIETARIO?\n\t[s] = SI\n\t[n] = NO\n\tINGRESE RESPUESTA: ",respuesta)){
                        retorno = -5;
                    }
                    if(strcmp(respuesta,"s")==0 && retorno == 0){
                        propietario[index].estado = 0;
                    }else{
                        retorno = -6;
                    }
                }
            }
        }
    }
    return retorno;
}

int tarifa(eAuto automovil[], int tamAuto, int index, ePropietario propietario[]){
    int  hora = devolverHorasEstadia(), i;
    float pago0 = 0, pago1 = 0, pago2 = 0, pago3 = 0, total = 0;
    int cont_ALPHA = 0, cont_AUDI = 0, cont_OTROS = 0, cont_FERRARI = 0;

    if(tamAuto > 0 && automovil != NULL && propietario != NULL){
        menu_precios();
        for(i=0;i<tamAuto;i++){
            if(automovil[i].estado == 1){
                if(automovil[i].id_propietario == index){
                    if(strcmp(automovil[i].marca,"ALPHA_ROMEO")==0){
                        cont_ALPHA++;
                        pago0 = (150 * hora) * cont_ALPHA;
                        marca_ALPHA += pago0;
                        automovil[i].estado = 0;
                        printf("\n\tCANTIDAD DE ALPHA_ROMEO: %d. Horas: %d\n",cont_ALPHA,hora);
                    }else if(strcmp(automovil[i].marca,"FERRARI")==0){
                        cont_FERRARI++;
                        pago1 = (175 * hora) * cont_FERRARI;
                        marca_FERRARI += pago1;
                        automovil[i].estado = 0;
                        printf("\n\tCANTIDAD DE FERRARI: %d. Horas: %d\n",cont_FERRARI,hora);
                    }else if(strcmp(automovil[i].marca,"AUDI")==0){
                        cont_AUDI++;
                        pago2 = (200 * hora) * cont_AUDI;
                        marca_AUDI += pago2;
                        automovil[i].estado = 0;
                        printf("\n\tCANTIDAD DE AUDI: %d. Horas: %d\n",cont_AUDI,hora);
                    }else if(strcmp(automovil[i].marca,"OTROS")==0){
                        cont_OTROS++;
                        pago3 = (250 * hora) * cont_OTROS;
                        marca_OTROS += pago3;
                        automovil[i].estado = 0;
                        printf("\n\tCANTIDAD DE OTROS: %d. Horas: %d\n",cont_OTROS,hora);
                    }
                }
            }
        }

    total = (pago0 + pago1 + pago2 + pago3);
    recaudacion += total;
    }
    return total;
}

int devolverHorasEstadia(){
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;
}

int baja_auto(eAuto automovil[], int tamAuto, ePropietario propietario[], int tamProp){

    int retorno = -1, id_auto, i, j;
    char aux_id_auto[21],respuesta[21];
    int hora = devolverHorasEstadia();
    float tarifa = 0;

    if(tamAuto > 0 && tamProp > 0 && automovil != NULL && propietario != NULL){
        if(!getStringNumeros("\n\tINGRESE ID DEL AUTO A EGRESAR: ",aux_id_auto)){
            retorno = -2;
        }
        id_auto = atoi(aux_id_auto);

        if(retorno != -2){
            menu_precios();
            for(i=0;i<tamAuto;i++){
                if(automovil[i].estado == 1){
                    if(automovil[i].id_auto == id_auto){
                        if(strcmp(automovil[i].marca,"ALPHA_ROMEO")==0){
                            tarifa = 150 * hora;
                            marca_ALPHA += tarifa;
                        }else if(strcmp(automovil[i].marca,"FERRARI")==0){
                            tarifa = 175 * hora;
                            marca_FERRARI += tarifa;
                        }else if(strcmp(automovil[i].marca,"AUDI")==0){
                            tarifa = 200 * hora;
                            marca_AUDI += tarifa;
                        }else if(strcmp(automovil[i].marca,"OTROS")==0){
                            tarifa = 250 * hora;
                            marca_OTROS += tarifa;
                        }
                        for(j=0;j<tamProp;j++){
                            if(propietario[j].id_propietario == automovil[i].id_propietario){
                                retorno = 0;
                                if(!getStringLetras("\n\tESTA SEGURO QUE DESEA EGRESAR EL AUTO?\n\t[s] = SI\n\t[n] = NO\n\tINGRESE RESPUESTA: ",respuesta)){
                                    retorno = -3;
                                }
                                if(strcmp(respuesta,"s")==0 && retorno == 0){
                                    recaudacion+=tarifa;
                                    printf("\n\t\tTICKET\n");
                                    printf("\n-Propietario: %s -Patente: %s -Marca: %s -Tarifa: %.2f Horas: %d\n",propietario[j].nombre,automovil[i].patente,automovil[i].marca,tarifa,hora);
                                    automovil[i].estado = 0;
                                }else{
                                    retorno = -4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

float recaudacion_Total(){

    return recaudacion;
}

void recaudacion_por_marca(){
    printf("----------------------------------------------------\n");
    printf("\n------\tRECAUDACION TOTAL POR ALPHA_ROMEO: %.2f\n",marca_ALPHA);
    printf("\n------\tRECAUDACION TOTAL POR FERRARI: %.2f\n",marca_FERRARI);
    printf("\n------\tRECAUDACION TOTAL POR AUDI: %.2f\n",marca_AUDI);
    printf("\n------\tRECAUDACION TOTAL POR OTROS: %.2f\n",marca_OTROS);
    printf("----------------------------------------------------\n");
}

int listado_Propietario_ConAutos(ePropietario propietario[], int tamProp, eAuto automovil[], int tamAuto){
    int i, id_prop, retorno = -1, index;
    char aux_prop[21];

    if(tamAuto > 0 && tamProp > 0 && automovil != NULL && propietario != NULL){
        if(!getStringNumeros("\n\tINGRESE ID DEL PROPIETARIO A LISTAR: ",aux_prop)){
            retorno = -2;
        }
        id_prop = atoi(aux_prop);
        retorno = -3;
        index = eProp_buscarPorId(propietario,tamProp,id_prop);
        if(index >= 0){
            for(i=0;i<tamAuto;i++){
                if(automovil[i].estado == 1){
                    retorno = -4;
                    if(automovil[i].id_propietario == id_prop){
                        retorno = 0;
                        if(retorno == 0){
                            printf("\n\t-Propietario: %s -Patente: %s -Marca: %s\n",propietario[index].nombre,automovil[i].patente,automovil[i].marca);
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

void listado_Audi(eAuto automovil[], int tamAuto, ePropietario propietario[], int tamProp){
    int i, j;

    for(i=0;i<tamAuto;i++){
        if(automovil[i].estado == 1){
            if(strcmp(automovil[i].marca,"AUDI")==0){
                for(j=0;j<tamProp;j++){
                    if(propietario[j].estado == 1){
                        if(automovil[i].id_propietario == propietario[j].id_propietario){
                            printf("\n-ID: %d -Nombre: %s -Apellido: %s -Direccion: %s -Tarjeta: %s\n",propietario[j].id_propietario,propietario[j].nombre,propietario[j].apellido,propietario[j].direccion,propietario[j].num_tarjeta_credito);
                        }
                    }
                }
            }
        }
    }
}

void listado_por_patente(eAuto automovil[], int tamAuto, ePropietario propietario[]){
    int i, j, h, f, aux_id_auto, aux_prop;
    char aux_patente[21],aux_marca[21];

    for(i=0;i<tamAuto-1;i++){
        if(tamAuto > 0 && automovil != NULL && propietario != NULL && automovil[i].estado == 1){
            for(j=i+1;j<tamAuto;j++){
                if((strcmp(automovil[j].patente,automovil[i].patente)<0) && automovil[j].estado == 1){

                    strcpy(aux_patente,automovil[j].patente);
                    strcpy(automovil[j].patente,automovil[i].patente);
                    strcpy(automovil[i].patente,aux_patente);

                    strcpy(aux_marca,automovil[j].marca);
                    strcpy(automovil[j].marca,automovil[i].marca);
                    strcpy(automovil[i].marca,aux_marca);

                    aux_id_auto = automovil[j].id_auto;
                    automovil[j].id_auto = automovil[i].id_auto;
                    automovil[i].id_auto = aux_id_auto;

                    aux_prop = automovil[j].id_propietario;
                    automovil[j].id_propietario = automovil[i].id_propietario;
                    automovil[i].id_propietario = aux_prop;
                }
            }
        }
    }
        for(h=0;h<20;h++){
            if(automovil[h].estado == 1){
                for(f=0;f<tamAuto;f++){
                    if(automovil[h].id_propietario == propietario[f].id_propietario && propietario[f].estado == 1){
                        printf("\n\t-Pantente: %s -Marca: %s -ID_Auto: %d -ID_Propietario: %d\n",automovil[h].patente,automovil[h].marca,automovil[h].id_auto,automovil[h].id_propietario);
                    }
                }
            }
        }

}
