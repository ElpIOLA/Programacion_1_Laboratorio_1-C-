#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "funcionValidar.h"


eEmpleados* new_empleado()
{
    eEmpleados* aux;
    aux = (eEmpleados*) malloc(sizeof(eEmpleados));
    return aux;
}

int set_Id(eEmpleados* this, int id)
{
    int ret = -1;
    if(this != NULL && id >= 0)
    {
        this->id =id;
        ret = 1;
    }
    return ret;
}

int get_Id(eEmpleados* this)
{
    int ret = -1;
    if(this != NULL)
    {
        ret = this->id;
    }
    return ret;
}

int set_Nombre(eEmpleados* this, char* nombre)
{
    int ret = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        ret = 1;
    }
    return ret;
}

char* get_Nombre(eEmpleados* this)
{
    char* ret = NULL;
    if(this != NULL)
    {
        ret = this->nombre;
    }
    return ret;
}

int set_Sueldo(eEmpleados* this, float sueldo)
{
    int ret = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        ret = 1;
    }
    return ret;
}

float get_Sueldo(eEmpleados* this)
{
    float ret = -1;
    if(this != NULL)
    {
        ret = this->sueldo;
    }
    return ret;
}

int set_Edad(eEmpleados* this, int edad)
{
    int ret = -1;
    if(this != NULL && edad >= 0)
    {
        this->edad = edad;
        ret = 1;
    }
    return ret;
}

int get_Edad(eEmpleados* this)
{
    int ret = -1;
    if(this != NULL)
    {
        ret = this->edad;
    }
    return ret;
}

int set_Profesion(eEmpleados* this, char* profesion)
{
    int ret = -1;
    if(this != NULL && profesion != NULL)
    {
        strcpy(this->profesion,profesion);
        ret = 1;
    }
    return ret;
}

char* get_Profesion(eEmpleados* this)
{
    char* ret = NULL;
    if(this != NULL)
    {
        ret = this->profesion;
    }
    return ret;
}

int cargar_Archivo(ArrayList* lista, char* direccion)
{
    int ret = -1;
    char linea[70], idAux[31], nombreAux[31], profeAux[31], edadAux[31], sueldoAux[21];
    int id, edad;
    float sueldo;

    if(lista != NULL && direccion != NULL)
    {
        memset(linea, '\0',70);
        FILE* archivo =  fopen(direccion,"r");
        if(archivo != NULL)
        {
            fgets(linea,70,archivo);
            while(!feof(archivo))
            {
                strcpy(idAux,strtok(linea,","));
                id = atoi(idAux);
                strcpy(nombreAux,strtok(NULL,","));
                strcpy(sueldoAux,strtok(NULL,","));
                sueldo = atof(sueldoAux);
                strcpy(edadAux,strtok(NULL,","));
                edad = atoi(edadAux);
                strcpy(profeAux,strtok(NULL,","));

                cargar_Empleado(lista,id,nombreAux,sueldo,edad,profeAux);

                memset(linea, '\0', 70);
                fgets(linea, 70, archivo);
            }
            fclose(archivo);
            ret = 1;
        }
    }
    return ret;
}

int cargar_Empleado(ArrayList* listado, int id, char* nombre, float sueldo, int edad, char* profesion)
{
    int ret = -1;
    eEmpleados* empleado;
    if(listado != NULL)
    {
        empleado = new_empleado();
        if(empleado != NULL)
        {
            set_Id(empleado,id);
            set_Nombre(empleado,nombre);
            set_Sueldo(empleado,sueldo);
            set_Edad(empleado,edad);
            set_Profesion(empleado,profesion);
        }
        system("cls");printf("\n\n");
        listado->add(listado,empleado);
        ret = 1;
        listadoDePersonas(listado);
    }
    return ret;
}

int mostrar_Empleados(eEmpleados* this)
{
    int ret=-1;
    if(this != NULL)
    {
        printf("\n  -ID: %d -Nombre: %s -Sueldo: %.2f Edad: %d -Profecion: %s\n", get_Id(this), get_Nombre(this), get_Sueldo(this),get_Edad(this),get_Profesion(this));
        ret=0;
    }
    return ret;
}

int listadoDePersonas(ArrayList* this)
{
    int ret = -1, i;
    int len;
    eEmpleados* empleado;
    if(this!=NULL)
    {
        len = this->len(this);
        for(i=0;i<len;i++)
        {
            empleado = (eEmpleados*)this->get(this,i);
            mostrar_Empleados(empleado);
        }
        ret = 1;
    }
    return ret;
}

int listaMayoresDeTreinta(ArrayList* this, ArrayList* this2)
{
    int ret = -1,len;
    eEmpleados* empleado;
    empleado = new_empleado();
    if(this != NULL)
    {
        len = this->len(this);

            this2 = al_filter(this,functionFilter(this->get(this,len)));
            if(this2 != NULL)
            {
                empleado = (eEmpleados*) this2;
                this2->add(this2,empleado);
                ret = 1;
            }
            else
            {
                printf("\n\tEMPLEADO NULL\n");
            }

    }
    return ret;
}

int functionFilter(void* item)
{
    int ret = 1;
    eEmpleados* empleado;
    empleado = (eEmpleados*) item;

    if(empleado->edad > 30 && strcmp(empleado->profesion,"programador")==0)
        ret = 0;
    return ret;
}
