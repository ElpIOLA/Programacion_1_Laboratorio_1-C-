#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/
int menu();

int main()
{
     char auxCad[100];
     char eliminar;
    int todoOk;
    int id;
    int desde;
    int hasta;
    int indice;
    char seguir = 's';
    ArrayList* subLista;
     Employee* auxEmpleado;
    ArrayList* lista = al_newArrayList();
    if(lista == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
    FILE* f = fopen("data.csv", "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    do
    {
        switch(menu())
        {

        case 1:
            todoOk = parserEmployee(f, lista);

            if(todoOk)
            {
                printf("\nError al parsear archivo\n\n");
            }
            else
            {
                printf("\nArchivo cargado con exito\n\n");
            }
            system("pause");

            break;

        case 2:
            printf("Lista de empleados\n\n");
            printf("id  Nombre   Apellido\n\n");
            for(int i=0; i < lista->len(lista); i++)
            {
                auxEmpleado = (Employee*)lista->get(lista, i);
                employee_print(auxEmpleado);
            }
            system("pause");
            break;

        case 3:
            if(lista->sort(lista, employee_compare, 1)==0){
                printf("\nLista Ordenada\n\n");
            }
            else{
                printf("\nProblema al ordenar la lista\n\n");
            }
            system("pause");
            break;

        case 4:

            auxEmpleado = employee_new();
            if(auxEmpleado != NULL){
            printf("**Alta Empleado**\n\n");
            printf("Ingrese id: ");
            scanf("%d", &id);
            // valido id
            employee_setId(auxEmpleado, id);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
            //validar cadena
            strcpy(auxEmpleado->name, auxCad);
            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(auxCad);
            //validar cadena
            strcpy(auxEmpleado->lastName, auxCad);
            auxEmpleado->isEmpty = 0;

            lista->add(lista, auxEmpleado);


            break;

        case 5:
            indice = -1;
            system("cls");
            printf("Ingrese id: ");
            scanf("%d", &id);
            for(int i=0; i < lista->len(lista); i++)
            {
                auxEmpleado = (Employee*)lista->get(lista, i);
                if(auxEmpleado->id == id){
                    indice = i;
                    break;
                }
            }
            if(indice == -1){
                printf("No existe un empleado con ese id\n\n");
            }
            else{
                auxEmpleado = (Employee*)lista->get(lista, indice);
                employee_print(auxEmpleado);

                printf("\nEliminar empleado? s/n: ");
                fflush(stdin);
                scanf("%c", &eliminar);

                if(eliminar == 's'){
                    lista->remove(lista, indice);
                    printf("\nEmpleado eliminado\n\n");
                }
                else{
                    printf("\nEliminacion cancelada\n\n");
                }
            }
            system("pause");

            break;

        case 6:
            system("cls");
            printf("Indique desde que indice quiere listar: ");
            scanf("%d", &desde);
             printf("Indique hasta que indice quiere listar: ");
            scanf("%d", &hasta);

            subLista = lista->subList(lista,desde, hasta);

            printf("Lista de empleados\n\n");
            printf("id  Nombre   Apellido\n\n");
            for(int i=0; i < subLista->len(subLista); i++)
            {
                auxEmpleado = (Employee*)subLista->get(subLista, i);
                employee_print(auxEmpleado);
            }
            system("pause");




            break;

        case 7:
            seguir = 'n';
            break;


        }
        }

    }
    while(seguir == 's');


    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. Parse del archivo data.csv\n");
    printf("2. Listar Empleados\n");
    printf("3. Ordenar por nombre\n");
    printf("4. Agregar un elemento\n");
    printf("5. Elimina un elemento\n");
    printf("6. Listar Empleados (Desde/Hasta)\n");
    printf("7. Salir\n");
    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



