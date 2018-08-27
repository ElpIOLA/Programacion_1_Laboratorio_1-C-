#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "funcionValidar.h"
#include "Set_Get.h"

ePersona* new_persona()
{
     ePersona* auxiliar = NULL;
     auxiliar = (ePersona*) malloc(sizeof(ePersona));
     if(auxiliar != NULL)
     {
          return auxiliar;
     }
     return auxiliar;
}

int listaPersonas(ArrayList* lista)
{
    int i, index = 0;
    int len = lista->len(lista);

    ePersona* persona;
    if(lista != NULL)
    {
        printf("-------------------------------------------------------------------");
        printf("\nIndice\tLegajo\tNombre\t  Apellido  Direccion\t    Edad     Sueldo\n\n");
        for(i=0;i<len;i++)
        {
            persona = (ePersona*) lista->get(lista,i);
            printf("\n%d %10d %10s %10s %10s %10d %10.2f\n\n",i,get_Legajo(persona),get_Nombre(persona),get_Apellido(persona),get_Direccion(persona),get_Edad(persona),get_Sueldo(persona));
            index = 1;
        }
    }
    return index;
}

int altaPersona(ArrayList* lista)
{
    int index = 0, legajo, edad;
    char auxLegajo[21], nombre[21], apellido[21], direccion[31], auxEdad[21], auxSueldo[21];
    float sueldo;
    ePersona* persona;

    if(lista != NULL)
    {
        persona = new_persona();
        if(persona != NULL)
        {
            if(!getStringNumeros("\n\t1.Ingrese legajo: ",auxLegajo)){printf("\nEl legajo ingresado no es valido!\n"); index = -1;}
            fflush(stdin);
            legajo = atoi(auxLegajo);

            //if(!getStringLetras("\n\t2.Ingrese nombre: ",nombre)){printf("\nEl nombre ingresado no es valido!\n"); index = -2;}
            printf("\n\t2.Ingrese Nombre: ");
            fflush(stdin);
            gets(nombre);

            //if(!getStringLetras("\n\t3.Ingrese apellido: ",apellido)){printf("\nEl apellido ingresado no es valido!\n"); index = -3;}
            printf("\n\t3.Ingrese Apellido: ");
            fflush(stdin);
            gets(apellido);

            printf("\n\t4.Ingrese direccion: ");
            fflush(stdin);
            gets(direccion);

            if(!getStringNumeros("\n\t5.Ingrese edad: ",auxEdad)){printf("\nLa edad ingresada no es valida!\n"); index = -4;}
            fflush(stdin);
            edad = atoi(auxEdad);

            if(!getStringNumerosFloat("\n\t6.Ingrese sueldo: ",auxSueldo)){printf("\nEl sueldo ingresado no es valido!\n"); index = -5;}
            fflush(stdin);
            sueldo = atof(auxSueldo);

            if(index != -1 && index != -2 && index != -3 && index != -4 && index != -5)
            {
                set_Legajo(persona,legajo);
                set_Nombre(persona,nombre);
                set_Apellido(persona,apellido);
                set_Direccion(persona,direccion);
                set_Edad(persona,edad);
                set_Sueldo(persona,sueldo);

                lista->add(lista,persona);
                index = 1;
            }
        }
    }
    return index;
}

ArrayList* bajaPersona(ArrayList* this, ArrayList* auxiliar)
{
    int i, indice, opcion = 0;
    int len;

    ePersona* persona;
    ePersona* aux;
    aux = new_persona();
    if(this != NULL)
    {
        listaPersonas(this);
        printf("\n\tIngrese indice: ");
        scanf("%d",&indice);

        len = this->len(this);

        if(indice <= len)
        {
            for(i=0;i<len;i++)
            {
                persona = (ePersona*) this->get(this,i);
                if(indice == i)
                {
                    printf("\n\tPersona: %10d %10s\n\n",get_Legajo(persona),get_Nombre(persona));
                    printf("\n\tDesea eliminar? ");
                    scanf("%d",&opcion);
                    if(opcion == 1)
                    {
                        //aux = (persona+indice);
                        //this->remove(this,indice);
                        aux = this->pop(this,indice);
                        break;
                    }
                }
            }
            if(aux != NULL)
            {
                auxiliar->add(auxiliar,aux);
                if(auxiliar != NULL)
                {
                    return auxiliar;
                }
            }
        }
    }
    return auxiliar;
}

int modificarPersona(ArrayList* this)
{
    int index = 0, i, len, indice, opcion = 0, edad, legajo;
    char nombre[21], apellido[21], direccion[31], auxLegajo[21], auxEdad[21], auxSueldo[21];
    float sueldo;
    ePersona* persona;
    if(this != NULL)
    {
        listaPersonas(this);
        printf("\n\tIngrese indice: ");
        scanf("%d",&indice);

        len = this->len(this);
        if(indice <= len)
        {
            for(i=0;i<len;i++)
            {
                persona = (ePersona*) this->get(this,i);
                if(indice == i)
                {
                    printf("\n\tPersona: %10d %10s\n\n",get_Legajo(persona),get_Nombre(persona));
                    printf("\n\tDesea modificar? ");
                    scanf("%d",&opcion);
                    if(opcion == 1)
                    {
                        if(!getStringNumeros("\n\t1.Ingrese nuevo legajo: ",auxLegajo)){printf("\nEl legajo ingresado no es valido!\n"); index = -1;}
                        fflush(stdin);
                        legajo = atoi(auxLegajo);

                        printf("\n\t2.Ingrese nuevo Nombre: ");
                        fflush(stdin);
                        gets(nombre);

                        printf("\n\t3.Ingrese nuevo Apellido: ");
                        fflush(stdin);
                        gets(apellido);

                        printf("\n\t4.Ingrese nueva direccion: ");
                        fflush(stdin);
                        gets(direccion);

                        if(!getStringNumeros("\n\t5.Ingrese nueva edad: ",auxEdad)){printf("\nLa edad ingresada no es valida!\n"); index = -4;}
                        fflush(stdin);
                        edad = atoi(auxEdad);

                        if(!getStringNumerosFloat("\n\t6.Ingrese nueva sueldo: ",auxSueldo)){printf("\nEl sueldo ingresado no es valido!\n"); index = -5;}
                        fflush(stdin);
                        sueldo = atof(auxSueldo);
                        break;
                    }
                }
            }
            if(index != -1 && index != -2 && index != -3 && index != -4 && index != -5)
            {
                set_Legajo(persona,legajo);
                set_Nombre(persona,nombre);
                set_Apellido(persona,apellido);
                set_Direccion(persona,direccion);
                set_Edad(persona,edad);
                set_Sueldo(persona,sueldo);

                index = 1;
            }
        }
    }
    return index;
}

ArrayList* restaurarPersonaBorrada(ArrayList* listaBorrados, ArrayList* listaPersona)
{
    int indice, len, i, opcion;

    ePersona* persona;
    ePersona* auxiliar;
    if(listaBorrados != NULL)
    {
        listaPersonas(listaBorrados);
        len = listaBorrados->len(listaBorrados);
        if(len > 0)
        {
            printf("\n\tIngrese indice de la persona a restaurar: ");
            scanf("%d",&indice);

            if(indice <= len)
            {
                for(i=0;i<len;i++)
                {
                    persona = (ePersona*) listaBorrados->get(listaBorrados,i);
                    if(indice == i)
                    {
                        printf("\n\tPersona: %10d %10s\n\n",get_Legajo(persona),get_Nombre(persona));
                        printf("\n\tEsta seguro que desea restaurar la persona? ");
                        scanf("%d",&opcion);
                        if(opcion == 1)
                        {
                            auxiliar = listaBorrados->pop(listaBorrados,indice);
                            break;
                        }
                        else
                        {
                            printf("\n\t\tCANCELO LA RESTAURACION!\n");
                            break;
                        }
                    }
                }
                if(auxiliar != NULL)
                {
                    listaPersona->add(listaPersona,auxiliar);
                    if(listaPersona != NULL)
                    {
                        return listaPersona;
                    }
                }
            }
        }
        else
        {
            printf("\n\t\tNO TIENE PERSONAS ELIMINADAS!\n");
        }
    }
    return listaPersona;
}

int crear_Archivo()
{
    int index = 0;
    char nombre[31];
    FILE* archivo;

    printf("\n\tIngrese el nombre y el tipo de archivo: ");
    fflush(stdin);
    gets(nombre);

    archivo = fopen(nombre,"r");
    if(archivo == NULL)
    {
        archivo = fopen(nombre,"w");
        if(archivo != NULL)
        {
            index = 1;
        }
    }
    else
    {
        printf("\n\n\t\tEL ARCHIVO YA EXISTE!\n\n");
    }
    return index;
}

int cargar_Archivo(ArrayList* this, char* link)
{
    int ret = -1;
    char linea[60], nombre[31], apellido[31], direccion[31], legajoAux[21], sueldoAux[21], edadAux[21];
    int legajo, edad;
    float sueldo;

    if(this != NULL && link != NULL)
    {
        memset(linea, '\0',60);
        FILE* archivo =  fopen(link,"r");
        if(archivo != NULL)
        {
            fgets(linea,60,archivo);
            while(!feof(archivo))
            {
                //letra = strtok(linea,",")[0];
                strcpy(legajoAux,strtok(linea,","));
                legajo = atoi(legajoAux);
                strcpy(nombre,strtok(NULL,","));
                strcpy(apellido,strtok(NULL,","));
                strcpy(direccion,strtok(NULL,","));
                strcpy(edadAux,strtok(NULL,","));
                edad = atoi(edadAux);
                strcpy(sueldoAux,strtok(NULL,"\n"));
                sueldo = atof(sueldoAux);

                cargar_Datos(this,legajo,nombre,apellido,direccion,edad,sueldo);

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

int cargar_Datos(ArrayList* this, int legajo ,char* nombre, char* apellido, char* direccion, int edad, float sueldo)
{
    int ret = -1;
    ePersona* persona;
    if(this != NULL)
    {
        persona = new_persona();
        if(persona != NULL)
        {
            set_Legajo(persona,legajo);
            set_Nombre(persona,nombre);
            set_Apellido(persona,apellido);
            set_Direccion(persona,direccion);
            set_Edad(persona,edad);
            set_Sueldo(persona,sueldo);
        }
        system("cls");printf("\n\n");
        this->add(this,persona);
        ret = 1;
    }
    return ret;
}

int guardar_en_archivo(ArrayList* this, char* link)
{
    int index = -1, i, len;
    FILE* archivo;
    archivo = fopen(link,"w");

    ePersona* persona;

    if(this != NULL)
    {
        len = this->len(this);
        if(archivo != NULL && len > 0)
        {
            for(i=0;i<len;i++){
                persona = (ePersona*) this->get(this,i);
                if(persona != NULL)
                {
                    fprintf(archivo,"%d,",get_Legajo(persona));
                    fprintf(archivo,"%s,",get_Nombre(persona));
                    fprintf(archivo,"%s,",get_Apellido(persona));
                    fprintf(archivo,"%s,",get_Direccion(persona));
                    fprintf(archivo,"%d,",get_Edad(persona));
                    fprintf(archivo,"%.2f\n",get_Sueldo(persona));
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

int comparar_Empleadoss(void* PersonaA, void* PersonaB)
{
    ePersona* Persona1;
    ePersona* Persona2;

    Persona1= (ePersona*) PersonaA;
    Persona2= (ePersona*) PersonaB;

    return strcmp(Persona1->nombre, Persona2->nombre);
}

int filtroEdades(void* item)
{
    int index = -1;
    ePersona* persona;
    persona = (ePersona*) item;
    if(persona != NULL)
    {
        if(persona->edad > 18)
        {
            index = 1;
        }
        else
        {
            index = 0;
        }
    }
    return index;
}

