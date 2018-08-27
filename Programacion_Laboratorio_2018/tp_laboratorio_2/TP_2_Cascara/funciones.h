#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[20];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista El array se pasa como parametro.
 * \param tem Tamaño del array.
 * \return El primer indice disponible.
 */
int obtenerEspacioLibre(EPersona *lista, int tem);

/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista El array se pasa como parametro.
 * \param dni El dni a ser buscado en el array.
 * \param tem Tamaño del array.
 * \return El indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarPorDni(EPersona *lista, int dni, int tem);

/**
 * \brief Da de alta un usuario y su estado cambia a 1.
 * \param lista el array se pasa como parametro.
 * \param tem Tamaño del array.
*/
void agregarPersona(EPersona *lista, int tem);

/**
 * \brief Da de baja un usuario y su estado cambia a 0.
 * \param lista el array se pasa como parametro.
 * \param tem Tamaño del array.
*/
void borrarPersona(EPersona *lista, int tem);

/**
 * \brief Ordena por nombre la lista del array.
 * \param lista el array se pasa como parametro.
 * \param tem Tamaño del array.
*/
void listaOrdenadaPorNombre(EPersona *lista, int tem);

/**
 * \brief Hace un grafico de edades.
 * \param lista el array se pasa como parametro
 * \param tem Tamaño del array.
*/
void graficoEdades(EPersona *lista, int tem);

#endif // FUNCIONES_H_INCLUDED
