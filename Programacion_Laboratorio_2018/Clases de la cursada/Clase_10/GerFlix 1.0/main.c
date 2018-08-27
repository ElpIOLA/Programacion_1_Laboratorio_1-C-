#include <stdio.h>
#include <stdlib.h>

#include "funcionValidar.h"
#include "Usuario.h"

#define TAMSERIE 20
#define TAMUSUARIO 100

int main()
{
    int opcion = 0, auxBaja, auxModi;
    char seguir = 's', auxOpcion[21], aux_baja[21], aux_modi[21];

    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);

    while(seguir == 's'){

    printf("\n\t1.ALTA\n");
    printf("\n\t2.BAJA\n");
    printf("\n\t3.MODIFICAR\n");
    printf("\n\t4.Mostrar Lista de Series.\n");
    printf("\n\t5.Mostrar Lista de Usuarios.\n");
    printf("\n\t6.Mosrtar Usuarios con su Series.\n");
    printf("\n\t7.Mostrar Series con su Usuarios.\n");

    if(!getStringNumeros("\n\tRespuesta: ",auxOpcion)){
        system("cls");
        printf("\n\tERROR! La respuesta debe ser un numero!\n");
    }
    opcion = atoi(auxOpcion);

        switch(opcion){
            case 1:
                alta_usuario(listaDeUsuarios,15);
                alta_serie(listaDeSeries,5);
                break;
            case 2:
                if(!getStringNumeros("\n\tQue desea dar de baja?\n\t[1] = Usuario\n\t[2] = Serie\n\tRespuesta: ",aux_baja)){
                    printf("\n\tERROR! La respuesta debe ser un numero.");
                    break;
                }
                auxBaja = atoi(aux_baja);

                if(auxBaja == 1){
                    baja_usuario(listaDeUsuarios,15);
                    break;
                }else if(auxBaja == 2){
                    baja_serie(listaDeSeries,5);
                    break;
                }else{
                    printf("\n\tNo eligio ninguna opcion.\n");
                    break;
                }
                break;
            case 3:
                if(!getStringNumeros("\n\tQue desea modificar?\n\t[1] = Usuario\n\t[2] = Serie\n\tRespuesta: ",aux_modi)){
                    printf("\n\tERROR! La respuesta debe ser un numero.");
                    break;
                }
                auxModi = atoi(aux_modi);

                if(auxModi == 1){
                    modificar_User(listaDeUsuarios,15);
                    break;
                }else if(auxModi == 2){
                    modificar_Serie(listaDeSeries,5);
                    break;
                }else{
                    printf("\n\tNo eligio ninguna opcion.\n");
                    break;
                }
                break;
            case 4:
                mostrarListaSeries(listaDeSeries,5);
                break;
            case 5:
                mostrarListaUsuarios(listaDeUsuarios,TAMUSUARIO);
                break;
            case 6:
                mostrarUsuarioConSuSerie(listaDeUsuarios,TAMUSUARIO,listaDeSeries,TAMSERIE);
                break;
            case 7:
                mostrarSerieConSuUser(listaDeSeries,TAMSERIE,listaDeUsuarios,TAMUSUARIO);
                break;
            case 8:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

