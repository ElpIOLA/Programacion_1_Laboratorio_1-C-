#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "caracter.h"
#include "Set_Get.h"

eCaracter* new_caracter()
{
    eCaracter* auxiliar;
    auxiliar = (eCaracter*) malloc(sizeof(eCaracter));
    return auxiliar;
}

int buscarArchivo(char* direccion)
{
    int index = -1;
    if(direccion != NULL)
    {
        FILE* archivo = fopen(direccion,"r");
        if(archivo == NULL)
        {
            index = 0;
        }
        else
        {
            index = 1;
        }
    }
    return index;
}

int cargar_Archivo(ArrayList* this, char* link)
{
    int ret = -1;
    char linea[60], caracter, nombre[31], vocalAux[11], consonanteAux[11], numeroAux[11];
    int vocal, consonante, numero;

    if(this != NULL && link != NULL)
    {
        memset(linea, '\0',60);
        FILE* archivo =  fopen(link,"r");
        if(archivo != NULL)
        {
            fgets(linea,60,archivo);
            while(!feof(archivo))
            {
                caracter = strtok(linea,",")[0];
                strcpy(nombre,strtok(NULL,","));
                strcpy(vocalAux,strtok(NULL,","));
                vocal = atoi(vocalAux);
                strcpy(consonanteAux,strtok(NULL,","));
                consonante = atoi(consonanteAux);
                strcpy(numeroAux,strtok(NULL,"\n"));
                numero = atoi(numeroAux);

                cargar_Datos(this,caracter,nombre,vocal,consonante,numero);

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

int cargar_Datos(ArrayList* this, char caracter ,char* nombre, int vocal, int consonante, int numero)
{
    int ret = -1;
    eCaracter* caract;
    if(this != NULL)
    {
        caract = new_caracter();
        if(caract != NULL)
        {
            set_Caracter(caract,caracter);
            set_Nombre(caract,nombre);
            set_Vocal(caract,vocal);
            set_Consonante(caract,consonante);
            set_Numero(caract,numero);
        }
        system("cls");printf("\n\n");
        this->add(this,caract);
        ret = 1;
    }
    return ret;
}

int mostrar_Datos(eCaracter* this)
{
    int ret=-1;
    if(this != NULL)
    {
        printf("\n %10c\t%10s\t%10d\t%10d\t%10d", get_Caracter(this), get_Nombre(this), get_Vocal(this),get_Consonante(this), get_Numero(this));
        ret=0;
    }
    return ret;
}

int listaDeDatos(ArrayList* this)
{
    int index = 0, i, len;
    eCaracter* caracteres;
    if(this != NULL)
    {
        len = this->len(this);
        for(i=0;i<len;i++)
        {
            caracteres = (eCaracter*) this->get(this,i);
            filtroUnos_Ceros(caracteres);
            mostrar_Datos(caracteres);
        }
        index = 1;
    }
    return index;
}

ArrayList* listaOrdenadaAscendente(ArrayList* ListaVieja, ArrayList* ListaNueva)
{
    int i;
    int len = al_len(ListaVieja);
    eCaracter* letra;
    if(ListaVieja != NULL && ListaNueva != NULL)
    {
        for(i=0;i<len;i++)
        {
            letra = (eCaracter*) al_get(ListaVieja,i);
            if(comprobarSiEsRepetida(ListaNueva,letra) == 1)
            {
                al_add(ListaNueva,letra);
            }
        }
    }
    return ListaNueva;
}

int comprobarSiEsRepetida(ArrayList* ListaNueva, eCaracter* letra)
{
    int i, index = -1;
    eCaracter* aux;
    int len = al_len(ListaNueva);
    if(ListaNueva != NULL && letra != NULL)
    {
        for(i=0;i<len;i++)
        {
            index = 1;
            aux = (eCaracter*) al_get(ListaNueva,i);
            if(get_Caracter(aux) == get_Caracter(letra))
            {
                index = 0;
                break;
            }
        }
    }
    return index;
}

/*int repetido(ArrayList* this, char letra)
{
    int retorno = 1;
    int i;
    int cont=0;
    int len = this->len(this);
    eCaracter* aux = NULL;
    if(this != NULL)
    {
        for(i=0;i<len;i++)
        {
            aux = al_get(this,i);
            if(get_Caracter(aux) == letra)
            {
                cont++;
            }
            if(cont > 1)
            {
                break;
            }
        }
        if(cont == 1)
        {
            retorno = 0;
        }
    }
    return retorno;
}*/

ArrayList* listaDeNombresConUnCaracter(ArrayList* this, ArrayList* this2)
{
    int i;
    int len = al_len(this);
    char nombre;
    eCaracter* aux = NULL;
    if(this != NULL && this2 != NULL)
    {
        printf("\n\tIngrese caracter: ");
        fflush(stdin);
        scanf("%c",&nombre);
        for(i=0;i<len;i++)
        {
            aux = (eCaracter*) al_get(this,i);
            if(get_Caracter(aux) == nombre)
            {
                if(filtroUnCaracter(aux) == 1)
                {
                    this2->add(this2,aux);
                    break;
                }
                else
                {
                    system("cls");
                    printf("\n\n\t\tLA LETRA INGRESA TIENE UN NOMBRE CON MAS DE UN CARACTER!\n\n");
                    break;
                }
            }
        }
    }
    return this2;
}

int filtroUnCaracter(void* item)
{
    int index = -1, num;
    eCaracter* letras;
    if(item != NULL)
    {
        letras = (eCaracter*) item;
        num = strlen(get_Nombre(letras));
        if(num == 1)
        {
            index = 1;
        }
        if(num > 1)
        {
            index = 0;
        }
    }
    return index;
}

int filtroUnos_Ceros(void* item)
{
    int index = -1;
    eCaracter* letras;
    if(item != NULL)
    {
        letras = (eCaracter*) item;
        if(letras->caracter == 'a' || letras->caracter == 'e' || letras->caracter == 'i' || letras->caracter == 'o' || letras->caracter == 'u')
        {
            letras->vocal = 1;
        }
        if(letras->caracter != 'a' && letras->caracter != 'e' && letras->caracter != 'i' && letras->caracter != 'o' && letras->caracter != 'u')
        {
            letras->consonante = 1;
        }
        if(letras->caracter >= '0' && letras->caracter <= '9')
        {
            letras->numero = 1;
        }
    }
    return index;
}

int comparar(void* primero,void* segundo)
{
    int retorno = 0;
    eCaracter* primera = (eCaracter*) primero;
    eCaracter* segunda = (eCaracter*) segundo;

    if(get_Caracter(primera) > get_Caracter(segunda))
    {
        retorno = -1;
    }
    else if(get_Caracter(primera) < get_Caracter(segunda))
    {
        retorno = 1;
    }

    return retorno;
}

int guardar_en_archivo(ArrayList* this, char* direccion)
{
    int index = -1, i, len;
    FILE* archivo;
    archivo = fopen(direccion,"w");

    eCaracter* letras;
    letras = new_caracter();

    if(this != NULL)
    {
        len = this->len(this);
        if(archivo != NULL && len > 0)
        {
            for(i=0;i<len;i++){
                letras = (eCaracter*) this->get(this,i);
                if(letras != NULL)
                {
                    fprintf(archivo,"%c,",get_Caracter(letras));
                    fprintf(archivo,"%s,",get_Nombre(letras));
                    fprintf(archivo,"%d,",get_Vocal(letras));
                    fprintf(archivo,"%d,",get_Consonante(letras));
                    fprintf(archivo,"%d\n",get_Numero(letras));
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
