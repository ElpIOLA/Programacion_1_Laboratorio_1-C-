#include "ArrayList.h"

/**
 * @brief RECIBE UNA DIRECCION Y VERIFICA SI EXISTE UN ARCHIVO CON TAL DIRECCION.
 * @param RECIBE LA DIRECCION DEL ARCHIVO.
 * @return RETORNA 1 SI EXISTE EL ARCHIVO. SINO RETORNA 0.
 */
int buscarArchivo(char* direccion);

/**
 * @brief LEE EL ARCHIVO Y GUARDA LOS DATOS EN UN ARRAYLIST.
 * @param ArrayList* RECIBE LA LISTA.
 * @param char* DIRECCION DEL ARCHIVO.
 * @return RETORNA 1 SI EL ARCHIVO ES LEIDO CON EXITO. SINO RETORNA -1.
 */
int lectura(ArrayList* lista, char*);

/**
 * @brief GUARDA LOS DATOS DEL ARRAYLIST EN UN ARCHIVO.
 * @param ArrayList* ARRAYLIST DONDE ESTAN LOS DATOS A GUARDAR.
 * @param char* RECIBE LA DIRECCION DEL ARCHIVO.
 */
void escritura(ArrayList* lista, char*);
