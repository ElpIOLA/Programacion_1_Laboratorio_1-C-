#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char auxInt[10];
    char auxNombre[51];
    char auxApellido[51];
    char auxEmpty[10];
    Employee* nuevoEmpleado;

    if(pFile == NULL || pArrayListEmployee == NULL){
            return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

    while(!feof(pFile)){
         fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

         nuevoEmpleado = employee_new();
         if(nuevoEmpleado !=NULL){
            nuevoEmpleado->id = atoi(auxInt);
            strcpy(nuevoEmpleado->name, auxNombre);
            strcpy(nuevoEmpleado->lastName, auxApellido);
            if(strcmp(auxEmpty, "false")== 0){
                nuevoEmpleado->isEmpty = 0;
            }
            else{
                nuevoEmpleado->isEmpty = 1;
            }

            pArrayListEmployee->add(pArrayListEmployee, nuevoEmpleado);
           // al_add(pArrayListEmployee, nuevoEmpleado);

            }

         }

    return 0;
}
