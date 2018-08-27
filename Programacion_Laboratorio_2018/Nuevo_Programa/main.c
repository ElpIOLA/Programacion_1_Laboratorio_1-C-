#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "Set_Get.h"
#include "ArrayList.h"
#include "menu.h"

int main()
{
    ArrayList* lista;
    lista = al_newArrayList();

    ArrayList* listaBorrados;
    listaBorrados = al_newArrayList();

    char direccion[] = "personas.txt";
    char direccionBorrados[] = "personasBorradas.txt";
    int index = 0, index2 = 0;

    index = cargar_Archivo(lista,direccion);
    index2 = cargar_Archivo(listaBorrados,direccionBorrados);
    if(index == 1 && index2 == 1){
        printf("\n\t\t\tARCHIVO CARGADO!\n\n");
    }
    else{
        printf("\n\t\t\tERROR AL LEER EL ARCHIVO!");
    }

    if(lista != NULL && listaBorrados != NULL)
    {
        while(index != 8)
        {
        index = nuevo_Menu();

            if(index != 0 && index != -1)
            {
                switch (index)
                {
                    case 1:
                        index = altaPersona(lista);
                        if(index == 1)
                        {
                            printf("\n\t\t\tPERSONA AGREGADA CON EXITO\n");
                        }
                         break;
                    case 2:
                        listaBorrados = bajaPersona(lista,listaBorrados);
                        if(listaBorrados != NULL)
                        {
                            system("cls");
                            printf("\n\t\tBORRADO CON EXITO!\n\n");
                        }
                        else
                        {
                            system("cls");
                            printf("\n\t\tNO SE PUDO ELIMINAR!\n\n");
                        }
                        break;
                    case 3:
                        index = modificarPersona(lista);
                        if(index == 1)
                        {
                            system("cls");
                            printf("\n\t\tMODIFICADO CON EXITO!\n\n");
                        }
                        else
                        {
                            system("cls");
                            printf("\t\tNO SE PUDO MODIFICAR!\n\n");
                        }
                        break;
                    case 4:
                        system("cls");
                        printf("\n\t\tLISTA DE PERSONAS\n");
                        listaPersonas(lista);
                        printf("\n\t\tLISTA DE BORRADOS\n");
                        listaPersonas(listaBorrados);
                        break;
                    case 5:
                        index = guardar_en_archivo(lista,direccion);
                        index2 = guardar_en_archivo(listaBorrados,direccionBorrados);
                        if(index == 1 && index2 == 1)
                        {
                            system("cls");
                            printf("\n\t\tCAMBIOS GUARDADOS!\n\n");
                        }
                        break;
                    case 6:
                        index = crear_Archivo();
                        if(index == 1)
                        {
                            system("cls");
                            printf("\n\t\tARCHIVO CREADO CON EXITO!\n\n");
                        }
                        else
                        {
                            printf("\t\tNO SE PUDO CREAR EL ARCHIVO!\n\n");
                        }
                        break;
                    case 7:
                        lista = restaurarPersonaBorrada(listaBorrados,lista);
                        if(lista != NULL)
                        {
                            system("cls");
                            printf("\n\t\tPERSONA RESTAURADA CON EXITO!\n");
                        }
                        else
                        {
                            system("cls");
                            printf("\n\t\tNO SE PUEDE RESTAURAR!\n\n");
                        }
                        break;
                    case 8:
                        index = 8;
                        printf("\n\t\t\tFIN DEL PROGRAMA\n");
                        break;
                    default:
                        printf("\n\t\tLA OPCION INGRESADA NO ES CORRECTA!\n");
                }
            }
            else
            {
                printf("\n\t\tLA OPCION INGRESADA NO ES CORRECTA!\n");
            }
        }
    }
    else
    {
        printf("\n\tARRAYLIST NULL!\n");
    }
    return 0;
}
