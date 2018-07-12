#include "ArrayList.h"

typedef struct
{
    int legajo;
    int estado;
    char nombre[21];
    char apellido[21];
    char fechaNacimiento[21];
    char direccion[41];
    char localidad[21];
    int codigoPostal;
    long int numTelefonico;
    long int numDocumento;
    char email[41];
}ePerson;

ePerson* new_Persona();

/** \brief INGRESA UN ENTERO, LO VERIFICA Y LO GUARDA EN LA ESTRUCTURA
 * \param this ePerson* PUNTERO A ARRAYLIST
 * \param palabra char* PUNTERO A STRING
 * \return int RETORNA (-1) SI EL PUNTERO A ARRAYLIST ES NULL. RETORNA (-2) SI NO ES ENTERO EL DATO A INGRESAR.
 *         RETORNA (1) SI DEVUELVE UN ENTERO.
 */
int set_Legajo(ePerson* this, char* palabra);

/** \brief BUSCA Y DEVUELVE UN ENTERO
 * \param this ePerson* PUNTERO A ARRAYLIST
 * \return int RETORNA (-1) SI EL PUNTERO A ARRAYLIST ES NULL. RETORNA (1) SI DEVUELVE UN ENTERO.
 */
int get_Legajo(ePerson* this);

int set_Nombre(ePerson* this, char* palabra);
char* get_Nombre(ePerson* this);

int set_Apellido(ePerson* this, char* palabra);
char* get_Apellido(ePerson* this);

int set_FechaNacimiento(ePerson* this, char* palabra);
char* get_FechaNacimiento(ePerson* this);

/***********************************************************************************************/
/** \brief MUESTRA UN PRINTF CON VARIOS GET
 * \param this ePerson* PUNTERO A ARRAYLIST
 * \return int RETORNA (1) SI NO HAY ERROR DE LO CONTRARIO RETORNA (-1)
 */
int mostrarPersona(ePerson* this);


/** \brief RECORRE Y MUESTRA TODOS LOS ELEMENTOS DEL ARRAYLIST
 * \param this ArrayList* PUNTERO A ARRAYLIST
 * \return int RETORNA (1) SI NO HAY ERROR DE LO CONTRARIO RETORNA (-1)
 */
int listadoDePersonas(ArrayList* this);
/***********************************************************************************************/

int add_Persona(ArrayList* lista);
int delete_Persona(ArrayList* lista,ArrayList* listaBorrar);
int modificar_Persona(ArrayList* lista);
