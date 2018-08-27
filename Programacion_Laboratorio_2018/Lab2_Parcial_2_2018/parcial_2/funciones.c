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

int altaEmpleado(ArrayList* this)
{
    char nombre[21], profesion[21], idAux[11], sueldoAux[21], edadAux[11];
    int index = -1;
    eEmpleados* empleado;
    empleado = new_empleado();

    if(this != NULL)
    {
        system("cls");
        printf("\n\n\t\t*********** AGREGANDO EMPLEADO **************\t\t\n\n");

        if(!getStringNumeros("\n\t1.Ingrese ID: ",idAux)){index = -2;}
        fflush(stdin);
        empleado->id = atoi(idAux);;

        if(!getStringLetras("\n\t2.Ingrese Nombre: ",nombre)){index = -3;}
        fflush(stdin);
        strcpy(empleado->nombre,nombre);

        if(!getStringNumerosFloat("\n\t3.Ingrese Sueldo: ",sueldoAux)){index = -4;}
        fflush(stdin);
        empleado->sueldo = atof(sueldoAux);

        if(!getStringNumeros("\n\t4.Ingrese Edad: ",edadAux)){index = -5;}
        fflush(stdin);
        empleado->edad = atoi(edadAux);

        if(!getStringLetras("\n\t5.Ingrese Profesion: ",profesion)){index = -6;}
        fflush(stdin);
        strcpy(empleado->profesion,profesion);


        if(index != -2 && index != -3 && index != -4 && index != -5 && index != -6)
        {
            index = 1;
            this->add(this,empleado);
        }
    }
    return index;
}

int bajaEmpleado(ArrayList* this)
{
    int index = -1, i, id, opcion;
    int len = this->len(this);
    eEmpleados* empleado;
    empleado = new_empleado();
    if(this != NULL && len > 0)
    {
        printf("\n\tINGRESE ID DEL EMPLEADO A ELIMINAR: ");
        scanf("%d",&id);
        for(i=0;i<len;i++)
        {
            empleado = (eEmpleados*) this->get(this,i);
            if(empleado != NULL)
            {
                if(id == empleado->id)
                {
                    printf("\n\t*************** USUARIO ENCONTRADO! ****************");
                    printf("\n\n\t******** %d - %s *********\n",get_Id(empleado),get_Nombre(empleado));
                    printf("\n\tDESEA ELIMINAR?\n\tSI = [1]\n\tNO = [2]\n\tRESPUESTA: ");
                    scanf("%d",&opcion);
                    if(opcion == 1)
                    {
                        this->remove(this,id-1);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        index = 1;
    }
    return index;
}

int guardar_en_archivo(ArrayList* this, char* direccion)
{
    int index = -1, i, len;
    FILE* archivo;
    archivo = fopen(direccion,"w");

    eEmpleados* empleado;
    empleado = new_empleado();

    if(this != NULL)
    {
        len = this->len(this);
        if(archivo != NULL && len > 0)
        {
            for(i=0;i<len;i++){
                empleado = (eEmpleados*) this->get(this,i);
                if(empleado != NULL)
                {
                    fprintf(archivo,"%d,",get_Id(empleado));
                    fprintf(archivo,"%s,",get_Nombre(empleado));
                    fprintf(archivo,"%.2f,",get_Sueldo(empleado));
                    fprintf(archivo,"%d,",get_Edad(empleado));
                    fprintf(archivo,"%s\n",get_Profesion(empleado));
                }
            }
            index = 1;
        }
        else
        {
            return index;
        }
    }
    fclose(archivo);
    return index;
}

int cargar_Archivo(ArrayList* this, char* direccion)
{
    int ret = -1;
    char linea[60], idAux[31], nombreAux[31], profeAux[31], edadAux[31], sueldoAux[21];
    int id, edad;
    float sueldo;

    if(this != NULL && direccion != NULL)
    {
        memset(linea, '\0',60);
        FILE* archivo =  fopen(direccion,"r");
        if(archivo != NULL)
        {
            fgets(linea,60,archivo);
            while(!feof(archivo))
            {
                strcpy(idAux,strtok(linea,","));
                id = atoi(idAux);
                strcpy(nombreAux,strtok(NULL,","));
                strcpy(sueldoAux,strtok(NULL,","));
                sueldo = atof(sueldoAux);
                strcpy(edadAux,strtok(NULL,","));
                edad = atoi(edadAux);
                strcpy(profeAux,strtok(NULL,"\n"));

                cargar_Empleado(this,id,nombreAux,sueldo,edad,profeAux);

                memset(linea, '\0', 60);
                fgets(linea, 60, archivo);
            }
            fclose(archivo);
            ret = 1;
        }
        else
        {
            printf("\n\tError! El archivo es NULL!\n\n");
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

ArrayList* listaMayoresDeTreinta(ArrayList* this)
{
    ArrayList* this2 = NULL;
    if(this != NULL)
    {
        if(al_isEmpty(this) == 0)
        {
            this2 = this->filter(this,functionFilter);
        }
    }
    return this2;
}

int functionFilter(void* item)
{
    int ret = 0;
    eEmpleados* empleado;
    empleado = (eEmpleados*) item;

    if(item != NULL)
    {
        if(empleado->edad > 30 && strcmp(empleado->profesion,"programador")==0)
        {
            ret = 1;
        }
    }
    return ret;
}
