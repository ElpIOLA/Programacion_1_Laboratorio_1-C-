#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL){

    Employee* empA = (Employee*) pEmployeeA;
    Employee* empB = (Employee*) pEmployeeB;
    return strcmp(empA->name, empB->name);
    }
    return 0;
}

int employee_compareApe(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL){

    Employee* empA = (Employee*) pEmployeeA;
    Employee* empB = (Employee*) pEmployeeB;
    return strcmp(empA->lastName, empB->lastName);
    }
    return 0;
}


void employee_print(Employee* this)
{
    if(this != NULL){
        printf("%d %s %s \n", this->id, this->name, this->lastName);
    }
}


Employee* employee_new(void)
{
    Employee* returnAux;
    returnAux = (Employee*)malloc(sizeof(Employee));
    if(returnAux !=NULL){
       returnAux->id = 0;
       strcpy(returnAux->name, "");
       strcpy(returnAux->lastName, "");
       returnAux->isEmpty = 1;
    }
    return returnAux;

}

void employee_delete(Employee* this)
{
    if(this != NULL){
        this->isEmpty = 1;
    }

}

int employee_setId(Employee* this, int id)
{
 if(this != NULL){
       if(id > 0 && id < 100000){
        this->id = id;
        return 0;
       }
    }
    return -1;

}

int employee_getId(Employee* this)
{
    int id = -1;
     if(this != NULL){
            id = this->id;
     }
    return id;

}


