#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define QTY_USUARIOS 200

void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor);
int buscarPrimerOcurrencia(int array[], int cantidad_de_elementos, int valor);

int main()
{
    char arrayNombres[QTY_USUARIOS][50];
    char arrayApellido[QTY_USUARIOS][50];
    char arrayLegajos[QTY_USUARIOS];

    char auxiliarNombresStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;

    inicializarArrayInt(arrayLegajos, QTY_USUARIOS, -1) /**< SE INDICO CON -1 QUE ESA POSICION ESTA VACIA. */
    while(opcion != 6)
    return 0;
}

/**
 *  \brief INICIALIZA UN ARRAY DE ENTEROS CON EL VALOR RECIBIDO.
 *  \param ARRAY ES EL ARRAY A SER INICIALIZADO.
 *  \param CANTIDAD_DE_ELEMENTOS INDICA LA LONGITUD DEL ARRAY.
 *  \param VALOR ES EL VALOR QUE SERA CARGADO EN CADA POSICION.
 *  \return
 */
void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor)
{
    int i;
    for(i = 0;i < cantidad_de_elementos; i++)
    {
        array[i] = valor;
    }
}

/**
 *  \brief BUSCA LA PRIMER OCURRENCIA DE UN VALOR EN UN ARRAY DE ENTEROS.
 *  \param ARRAY ES EL ARRAY EN EL CUAL BUSCAR.
 *  \param CANTIDAD_DE_ELEMENTOS INDICA LA LONGITUD DEL ARRAY.
 *  \param VALOR ES EL VALOR QUE SE BUSCA.
 *  \return SI NO HAY OCURRENCIA (-1) Y SI LA HAY LA POSICION DE LA MISMA (I).
 */
int buscarPrimerOcurrencia(int array[], int cantidad_de_elementos, int valor)
{
    int i;
    for(i = 0; i < cantidad_de_elementos; i++)
    {
        if(array[i] == valor)
        {
            return 1;
        }
    }
    return -1;
}
