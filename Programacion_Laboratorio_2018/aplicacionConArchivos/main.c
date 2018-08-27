#include <stdio.h>
#include <stdlib.h>
#include "destinatarios.h"
#include "ArrayList.h"
#define TAM 10
int main()
{
    int opcion, index = -1;

    char* listNegraDirec="black_list.csv";
    char* listDestDirec="destinatarios.csv";
    char* listDepurados="Archivo_depurados.txt";

    ArrayList* TotalDestinatarios;
    TotalDestinatarios= al_newArrayList();

    ArrayList* ListaNegraDestinatarios;
    ListaNegraDestinatarios= al_newArrayList();

    ArrayList* ListaDepurar;
    ListaDepurar = al_newArrayList();

    do
    {
        printf("\n\t1. CARGAR DESTINATARIO\n\t2. CARGAR LISTA NEGRA\n\t3. DEPURAR\n\t4. LISTAR\n\t5. SALIR\n\tELEGIR OPCION: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                index = cargar_Destinatario(TotalDestinatarios,listDestDirec);
                if(index == 1)
                {
                    printf("\n\tCARGA COMPLETA!\n");
                }
                break;
            case 2:
                index =  cargar_Destinatario(ListaNegraDestinatarios,listNegraDirec);
                if(index == 1)
                {
                    printf("\n\tCARGA COMPLETA!\n");
                }
                break;
            case 3:
                index = depurar_Destinatarios(TotalDestinatarios,ListaNegraDestinatarios,ListaDepurar,listDepurados);
                if(index == 1)
                {
                    printf("\n\tLISTAS DEPURADAS!\n");
                }
                else if(index == -1)
                {
                    system("cls");
                    printf("\n\tARRAYLIST NULL\n");
                }
                else if(index == -2)
                {
                    printf("\n\tARCHIVO NULL\n");
                }
                break;
            default:
            printf("\n\tLA OPCION INGRESADA NO ES CORRECTA!\n");
        }
    }while(opcion != 5);
    return 0;
}
