#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "Validaciones.h"
#include "Caracteres.h"

int main()
{
    ArrayList* listaPrincipal = al_newArrayList();
    ArrayList* listaRepetidos = al_newArrayList();
    ArrayList* listaDepurados = al_newArrayList();

    int opcion = 0, index = 0;
    char direccion[101],
    completo[21] = "completo.csv",
    repetidos[21] = "repetidos.csv",
    depurados[21] = "depurados.csv",
    caracter,
    flag = 0;

    do
    {
        printf("\n 1. BUSCAR ARCHIVO");
        printf("\n 2. COMPLETAR LISTA");
        printf("\n 3. ORDENAMIENTO ASCENDENTE Y SIN REPETIR");
        printf("\n 4. ORDENAMIENTO DESCENDENTE QUE CONTENGA CARACTER INGRESADO");
        printf("\n 5. ESCRIBIR ARCHIVOS");
        printf("\n 6. SALIR");
        printf("\n INGRESE OPCION: ");
        opcion = set_integer(opcion);

        if(opcion == 1)
        {
            flag = 1;
        }

        switch(opcion)
        {
            case 1:
            system("cls");
            printf("\n INGRESE DIRECCION: ");
            scanf("%s",direccion);
            index = buscarArchivo(direccion);
            if(index)
            {
                index = lectura(listaPrincipal,direccion);
                if(index)
                {
                    printf("\n ARCHIVO LEIDO CON EXITO!\n");
                    listaDeDatos(listaPrincipal);
                }
                else
                {
                    printf("\n NO SE PUDO LEER EL ARCHIVO!\n");
                }
            }
            else
            {
                printf("\n NO EXISTE UN ARCHIVO CON ESA DIRECCION!\n");
            }
            break;
            case 2:
                if(flag)
                {
                    system("cls");
                    listaDeDatosUnosYCeros(listaPrincipal);
                }
                else
                {
                    printf("\n\tERROR! DEBE LEER UN ARCHIVO ANTES DE LISTAR\n");
                }
                break;
            case 3:
                if(flag)
                {
                    system("cls");
                    filtrarRepetidos(listaPrincipal,listaRepetidos);
                    listaRepetidos->sort(listaRepetidos,comparar,0);
                    listaDeDatosUnosYCeros(listaRepetidos);
                }
                else
                {
                    printf("\n\tERROR! DEBE LEER UN ARCHIVO ANTES DE LISTAR\n");
                }
                break;
            case 4:
                if(flag)
                {
                    system("cls");
                    printf("\n\tINGRESE UN CARACTER: ");
                    scanf("%c",&caracter);

                    filtrarDepurados(listaPrincipal,listaDepurados,caracter);
                    listaDepurados->sort(listaDepurados,comparar,1);

                    printf("\n\tLISTA DE NOMBRES QUE CONTENGAN LA LETRA: %c\n",caracter);
                    listaDeDatosUnosYCeros(listaDepurados);
                }
                else
                {
                    printf("\n\tERROR! DEBE LEER UN ARCHIVO ANTES DE LISTAR\n");
                }
                break;
            case 5:
                if(flag)
                {
                    system("cls");
                    escritura(listaPrincipal,completo);
                    escritura(listaRepetidos,repetidos);
                    escritura(listaDepurados,depurados);
                }
                else
                {
                    printf("\n\tERROR! DEBE LEER UN ARCHIVO ANTES DE LISTAR\n");
                }
                break;
            case 6:
                opcion = 6;
                printf("\n\tFIN DEL PROGRAMA\n");
                break;
            default:
                printf("\n\tLA OPCION INGRESADA NO ES CORRECTA!\n");
                break;
        }
    }while(opcion != 6);

    return 0;
}
