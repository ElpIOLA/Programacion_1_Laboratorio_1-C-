#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Validaciones.h"
#include "parser.h"
#include "Letra.h"

int main()
{
    ArrayList* listaDatos = al_newArrayList();
    ArrayList* repetidos = al_newArrayList();
    ArrayList* depurados = al_newArrayList();

    int opcion = 0, flag = 0;
    char cadena[21];

    do
    {
        printf("\n\t\t\t*********************\n\t\t\t* %-10s *\n\t\t\t*********************\n","MENU DEL PROGRAMA");
        printf("\n\t\t1- LEER ARCHIVO\n");
        printf("\n\t\t2- COMPLETAR LISTA\n");
        printf("\n\t\t3- ORDENAMIENTO\n");
        printf("\n\t\t4- CREAR ARCHIVOS\n");
        printf("\n\t\t5- SALIR\n");
        printf("\n\t\tINGRESE OPCION: ");
        opcion = set_integer(opcion);

        if(opcion == 1){
            flag = 1;
        }
        switch(opcion)
        {
            case 1:
                system("cls");
                lectura(listaDatos);
                imprimirTodos(listaDatos);
                printf("\n\tPRESIONE ENTER...");
                getchar();
            break;
            case 2:
                system("cls");
                if(flag)
                {
                    completarLetra(listaDatos);
                    imprimirTodos(listaDatos);
                    printf("\n\tPRESIONE ENTER...");
                    getchar();
                }
                else
                {
                    system("cls");
                    printf("\n\tPOR FAVOR PRIMERO LEA EL ARCHIVO DE DATOS INGRESANDO LA OPCION 1.\n");
                }
                break;
            case 3:
                if(flag)
                {
                    printf("\n\t\tINGRESE UN TEXTO: ");
                    fflush(stdin);
                    fgets(cadena,21,stdin);

                    filtrarRepetidos(listaDatos, repetidos, cadena);
                    repetidos->sort(repetidos, comparar, 1);
                    imprimirTodos(repetidos);

                    printf("\n\tPRESIONE ENTER...");
                    getchar();

                    filtrarDepurados(listaDatos, depurados, cadena);
                    depurados->sort(depurados, comparar, 0);
                    imprimirTodos(depurados);

                    printf("\n\tPRESIONE ENTER...");
                    getchar();
                }
                else
                {
                    system("cls");
                    printf("\n\tPOR FAVOR PRIMERO LEA EL ARCHIVO DE DATOS INGRESANDO LA OPCION 1.\n");
                }
                break;
            case 4:
                if(flag)
                {
                    escritura(listaDatos, "completo.csv");
                    escritura(repetidos, "repetidos.csv");
                    escritura(depurados, "depurados.csv");
                    printf("\n\tARCHIVOS GENERADOS!\n");
                    printf("\n\tPRESIONE ENTER...");
                    getchar();
                }
                else
                {
                    system("cls");
                    printf("\n\tPOR FAVOR PRIMERO LEA EL ARCHIVO DE DATOS INGRESANDO LA OPCION 1.\n");
                }
                break;
            case 5:
                printf("\n\t\tPROGRAMA FINALIZADO\n");
                break;
            default:
                printf("\n\t\tOPCION INVALIDA\n");
                break;
        }
    }while(opcion != 5);
    return 0;
}
