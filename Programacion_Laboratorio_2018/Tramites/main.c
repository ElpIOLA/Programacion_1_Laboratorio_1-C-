#include <stdio.h>
#include <stdlib.h>
#include "tramite.h"
#include "ArrayList.h"

int main()
{
    int opcion;

    int ultimoIdTramiteUrgente = 0;
    int ultimoIdTramiteRegular = 0;
    char dni[10];

    ArrayList* listaUrgente;
    ArrayList* listaRegular;

    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    listaUrgente = al_newArrayList();
    listaRegular = al_newArrayList();
    atendidosUrgentes = al_newArrayList();
    atendidosRegulares = al_newArrayList();

    do
    {
        printf("\n1. Tramite Urgente\n2. Tramite Regular\n3. Proximo\n4. Listar\n5. Informar atendidos\n6. Salir\nElija opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("\n\tTURNO URGENTE\n");
                ultimoIdTramiteUrgente ++;
                printf("\n\tINGRESE DNI: ");
                fflush(stdin);
                gets(dni);
                cargarTramite(listaUrgente,ultimoIdTramiteUrgente,dni);
                break;
            case 2:
                printf("\n\tTURNO REGULAR\n");
                ultimoIdTramiteRegular ++;
                printf("\n\tINGRESE DNI: ");
                fflush(stdin);
                gets(dni);
                cargarTramite(listaRegular,ultimoIdTramiteRegular,dni);
                break;
            case 3:
                if(!listaUrgente->isEmpty(listaUrgente))
                {
                    printf("\n\tCLIENTE A SER ATENDIDO [URGENTE]: ");
                    atenderTramite(listaUrgente,atendidosUrgentes);
                }
                else
                {
                    if(!listaRegular->isEmpty(listaRegular))
                    {
                        printf("\n\tCLIENTE A SER ATENDIDO [REGULAR]: ");
                        atenderTramite(listaRegular,atendidosRegulares);
                    }
                    else
                    {
                        printf("\n\tNO HAY CLIENTES POR ATENDER!\n");
                    }
                }
                break;
            case 4:
                if(!listaUrgente->isEmpty(listaUrgente))
                {
                    printf("\n\tTRAMITES URGENTES\n");
                    mostrarListaTramite(listaUrgente);
                }
                if(!listaRegular->isEmpty(listaRegular))
                {
                    printf("\n\tTRAMITES REGULARES\n");
                    mostrarListaTramite(listaRegular);
                }
                break;
            case 5:
                if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
                {
                    atendidosUrgentes->sort(atendidosUrgentes,ordenamientoPorDni,1);
                    printf("\n\tTRAMITES URGENTES\n");
                    mostrarListaTramite(atendidosUrgentes);
                }

                if(!atendidosRegulares->isEmpty(atendidosRegulares))
                {
                    atendidosRegulares->sort(atendidosRegulares,ordenamientoPorDni,0);
                    printf("\n\tTRAMITES REGULARES\n");
                    mostrarListaTramite(atendidosRegulares);
                }
                break;
        }
    }while(opcion != 6);
    return 0;
}
