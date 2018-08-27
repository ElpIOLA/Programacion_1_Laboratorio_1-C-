#include <stdio.h>
#include <stdlib.h>
#include "caracter.h"
#include "ArrayList.h"
int main()
{
    ArrayList* lista;
    lista = al_newArrayList();

    ArrayList* listaAscendente;
    listaAscendente = al_newArrayList();

    ArrayList* listaDescendente;
    listaDescendente = al_newArrayList();

    char nombre[21];
    char completo[] = "completo.csv";
    char depurado[] = "depurado.csv";
    char repetido[] = "repetido.csv";
    int index = 0, opcion = 0, index2 = 0;

    if(lista != NULL)
    {
        while(opcion != 5)
        {
            printf("\n\t1.ABRIR ARCHIVO!");
            printf("\n\t2.LISTA COMPLETA DE DATOS");
            printf("\n\t3.CREAR LISTA ORDENADA ASCENDETE");
            printf("\n\t4.CREAR LISTA ORDENADA DESCENDETE");
            printf("\n\t5.LISTAS");
            printf("\n\t6.GUARDAR EN EL ARCHIVO");
            printf("\n\t7.SALIR!");
            printf("\n\tELIGA OPCION: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    printf("\n\tINGRESE NOMBRE DEL ARCHIVO: ");
                    scanf("%s",nombre);
                    index = buscarArchivo(nombre);
                    if(index == 1)
                    {
                        index2 = cargar_Archivo(lista,nombre);
                        if(index2 == 1)
                        {
                            system("cls");
                            printf("\n\tARCHIVO CARGADO!\n");
                        }
                    }
                    else
                    {
                        printf("\n\tEL ARCHIVO NO EXISTE!");
                    }
                    break;
                case 2:
                    index = listaDeDatos(lista);
                    if(index != 1)
                    {
                        printf("\n\t\tNO SE PUDO CARGAR LA LISTA!\n");
                    }
                    break;
                case 3:
                    listaAscendente = listaOrdenadaAscendente(lista,listaAscendente);
                    if(listaAscendente != NULL)
                    {
                        printf("\n\t\tLISTA CREADA CON EXITO!\n");
                    }
                    else
                    {
                        printf("\n\t\tNO SE PUDO CREAR LA LISTA!\n");
                    }
                    break;
                case 4:
                    listaDescendente = listaDeNombresConUnCaracter(lista,listaDescendente);
                    if(listaDescendente != NULL)
                    {
                        printf("\n\tLETRA AGREGADA CON EXITO!\n");
                    }
                    else
                    {
                        printf("\n\t\tNO SE PUDO CARGAR LA LISTA!\n");
                    }
                    break;
                case 5:
                    printf("\n\t\tLISTA ASCENDENTE!\n");
                    al_sort(listaAscendente,comparar,1);
                    listaDeDatos(listaAscendente);
                    printf("\n\n");
                    printf("\n\t\tLISTA DESCENDENTE!\n");
                    al_sort(listaDescendente,comparar,0);
                    listaDeDatos(listaDescendente);
                    printf("\n\n");
                case 6:
                    guardar_en_archivo(lista,completo);
                    guardar_en_archivo(listaAscendente,repetido);
                    guardar_en_archivo(listaDescendente,depurado);
                case 7:
                    opcion = 7;
                    break;
                default:
                    printf("\n\tLA OPCION ELEGIDA NO ES CORRECTA!");
            }
        }
    }
    else
    {
        printf("\n\tLISTA NULL!");
    }
    return 0;
}
