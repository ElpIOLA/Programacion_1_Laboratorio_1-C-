#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinatarios.h"
#include "ArrayList.h"

eDestino* new_distinatario()
{
    eDestino* aux;
    aux = (eDestino*) malloc(sizeof(eDestino));
    return aux;
}

int setName(eDestino* this, char* name)
{
    int returnAux = -1;
    if(this != NULL && name != NULL)
    {
        strcpy(this->name,name);
        returnAux = 1;
    }
    return returnAux;
}

char* getName(eDestino* this)
{
    char* nameAux = NULL;
    if(this != NULL)
    {
        nameAux = this->name;
    }
    return nameAux;
}

int setEmail(eDestino* this, char* email)
{
    int returnAux = -1;
    if(this != NULL && email != NULL)
    {
        strcpy(this->email,email);
        returnAux = 1;
    }
    return returnAux;
}

char* getEmail(eDestino* this)
{
    char* emailAux = NULL;
    if(this != NULL)
    {
        emailAux = this->email;
    }
    return emailAux;
}

int setEstado(eDestino* this, int estado)
{
    int returnAux = -1;
    if(this != NULL && estado > 0)
    {
        this->estado = estado;
        returnAux = 1;
    }
    return returnAux;
}

int getEstado(eDestino* this)
{
    int index = -1;
    if(this != NULL)
    {
        index = this->estado;
    }
    return index;
}

int cargar_Destinatario(ArrayList* listado, char* direccion)
{
    eDestino* destinoActual;
    int returnAux = -1, estado, cont = 0;
    char linea[70], nameAux[21], emailAux[41];
    memset(linea, '\0',60);

    if(listado != NULL && direccion != NULL)
    {
        destinoActual = new_distinatario();
        FILE* archivo = fopen(direccion,"r");
        if(archivo != NULL)
        {
            fgets(linea,70,archivo);
            while(!feof(archivo))
            {
                    strcpy(destinoActual->name,strtok(linea,","));
                    strcpy(nameAux,destinoActual->name);
                    setName(destinoActual, nameAux);

                    strcpy(destinoActual->email,strtok(NULL,"\n"));
                    strcpy(emailAux,destinoActual->email);
                    setEmail(destinoActual, emailAux);

                    estado = 0;
                    setEstado(destinoActual,estado);

                    listado->add(listado, destinoActual);
                    printf("\n\t-NOMBRE: %s -EMAIL: %s\n",getName(destinoActual),getEmail(destinoActual));
                    cont++;

                    memset(linea, '\0', 70);
                    fgets(linea, 70, archivo);
            }
            fclose(archivo);
            printf("\n\tPERSONAS EN LA LISTA: %d \n", cont);
        }
        returnAux = 1;
    }
    return returnAux;
}

int comparar_Destinatarios(void* destinatarioA,void* destinatarioB)
{
    eDestino* destinatario1;
    eDestino* destinatario2;

    destinatario1 = (eDestino*) destinatarioA;
    destinatario2 = (eDestino*) destinatarioB;

    return strcmp(destinatario1->email, destinatario2->email);
}

int depurar_Destinatarios(ArrayList* listaDestinatarios, ArrayList* listaNegra, ArrayList* destinatarioDepurados, char* listDepurados)
{
    eDestino* depurados;
    int  i, j, returnAux = -1;

    if(listaDestinatarios != NULL && listaNegra != NULL && destinatarioDepurados != NULL)
    {
        depurados = new_distinatario();
        for(i=0;i<listaNegra->len(listaNegra);i++)
        {
            for(j=0;j<listaDestinatarios->len(listaDestinatarios);j++)
            {
                if(*(listaNegra->pElements+i) == *(listaDestinatarios->pElements+j))
                {
                    depurados= (eDestino*) *(listaDestinatarios->pElements+j);
                    setEstado(depurados,1);
                    break;
                }
            }
            destinatarioDepurados->add(destinatarioDepurados,*(depurados+i));
        }
        FILE* archivoDepurados=fopen(listDepurados,"w");

        returnAux = -2;
        if(archivoDepurados != NULL)
        {
            for(i=0;i<destinatarioDepurados->len(destinatarioDepurados);i++)
            {
                if(depurados->estado==0)
                {
                    fprintf(archivoDepurados,"\n%s,%s\n",(depurados+i)->name,(depurados+i)->email);
                    printf("\n%s,%s\n",getName(depurados+i),getEmail(depurados+i));
                }
                else
                {
                    destinatarioDepurados->clear(destinatarioDepurados);
                }
            }
            returnAux=1;
            fclose(archivoDepurados);
        }
    }
    return returnAux;
}

int listarEnvioDeCorreo(ArrayList* listaDepurados)
{
    int returnAux = -1, i;
    if(listaDepurados != NULL)
    {
        for(i=0;i<listaDepurados->len(listaDepurados);i++)
        {
            printf("\n%s\n",(char* )listaDepurados->get(listaDepurados,i));
            returnAux = 1;
        }
    }
    return returnAux;
}
