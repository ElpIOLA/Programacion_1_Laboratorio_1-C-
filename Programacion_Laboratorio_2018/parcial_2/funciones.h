#include "ArrayList.h"
typedef struct
{
     int id;
     char nombre[21];
     float sueldo;
     int edad;
     char profesion[41];
}eEmpleados;

/**
 *  \brief Se encarga de pedir memoria para el empleado.
 *  \return eEmpleados* Retorna un auxiliar con nueva memoria.
 */
eEmpleados* new_empleado();

/** \brief Se encarga de ingresar un dato a la estructura
 *  \param this eEmpleados* Puntero a estructura
 *  \param int id Entero a guardar
 *  \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
 */
int set_Id(eEmpleados* this, int id);

/** \brief Se encarga de mostrar un dato de la estructura
 *  \param this eEmpleados* Puntero a estructura
 *  \return int Retorna (1) si el dato es encontrado y mostrado sino retorna (-1)
 */
int get_Id(eEmpleados* this);

/** \brief Se encarga de ingresar un dato a la estructura
 *  \param this eEmpleados* Puntero a estructura
 *  \param palabra nombre* Puntero a string
 *  \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
 */
int set_Nombre(eEmpleados* this, char* nombre);

/** \brief Se encarga de mostrar un dato de la estructura
 * \param this eEmpleados* Puntero a estructura
 * \return int Retorna (1) si el dato es encontrado y mostrado sino retorna (-1)
 */
char* get_Nombre(eEmpleados* this);

/** \brief Se encarga de ingresar un dato a la estructura
 * \param this eEmpleados* Puntero a estructura
 * \param float sueldo Flotante a guardar
 * \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
 */
int set_Sueldo(eEmpleados* this, float sueldo);

/** \brief Se encarga de mostrar un dato de la estructura
 * \param this eEmpleados* Puntero a estructura
 * \return int Retorna (1) si el dato es encontrado y mostrado sino retorna (-1)
 */
float get_Sueldo(eEmpleados* this);

/** \brief Se encarga de ingresar un dato a la estructura
 * \param this eEmpleados* Puntero a estructura
 * \param int edad Entero a guardar
 * \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
 */
int set_Edad(eEmpleados* this, int edad);

/** \brief Se encarga de mostrar un dato de la estructura
 * \param this eEmpleados* Puntero a estructura
 * \return int Retorna (1) si el dato es encontrado y mostrado sino retorna (-1)
 */
int get_Edad(eEmpleados* this);

/** \brief Se encarga de ingresar un dato a la estructura
 *  \param this eEmpleados* Puntero a estructura
 *  \param char profesion es la cadena de caracteres a guardar
 *  \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
 */
int set_Profesion(eEmpleados* this, char* profesion);

/** \brief Se encarga de mostrar un dato de la estructura
 *  \param this eEmpleados* Puntero a estructura
 *  \return int Retorna (1) si el dato es encontrado y mostrado sino retorna (-1)
 */
char* get_Profesion(eEmpleados* this);

/** \brief SE ENCARGA DE AGREGAR UN NUEVO EMPLEADO
 *  \param this ArrayList* PUNTERO AL ArrayList
 *  \return int RETORNA (1) SI EL EMPLEADO ES DADO DE ALTA, SINO RETORNA (-1)
 */
int altaEmpleado(ArrayList* this);

/** \brief SE ENCARGA DE ELIMINAR UN EMPLEADO
 *  \param this ArrayList* PUNTERO AL ArrayList
 *  \return int RETORNA (1) SI EL EMPLEADO ES ELIMINADO, SINO RETORNA (-1)
 */
int bajaEmpleado(ArrayList* this);

/** \brief SE ENCARGA DE GUARDAR TODOS LOS EMPLEADOS EN EL ARCHIVO
 *  \param this ArrayList* PUNTERO AL ArrayList
 *  \param direccion char* RECIBE PUNTERO DE TIPO CARACTER
 *  \return int RETORNA (1) SI SE GUARDAN CON EXITO LOS EMPLEADOS, SINO RETORNA (-1)
 */
int guardar_en_archivo(ArrayList* this, char* direccion);

/** \brief SE ENCARGA LEER EL ARCHIVO
 *  \param this ArrayList* PUNTERO AL ArrayList
 *  \param direccion char* RECIBE PUNTERO DE TIPO CARACTER
 *  \return int RETORNA (1) SI LEE CON EXITO EL ARCHIVO, SINO RETORNA (-1)
 */
int cargar_Archivo(ArrayList* this, char* direccion);

/** \brief SE ENCARGA DE GUARDAR EN LA ESTRUCTURA LOS EMPLEADOS QUE SE ENCUENTRAN EN EL ARCHIVO
 *  \param listado ArrayList* PUNTERO AL ArrayList
 *  \param id int RECIBE DATO DE TIPO ENTERO
 *  \param nombre char* RECIBE PUNTERO DE TIPO CARACTER
 *  \param sueldo float RECIBE DATO DE TIPO FLOTANTE
 *  \param edad int RECIBE DATO DE TIPO ENTERO
 *  \param profesion char* RECIBE PUNTERO DE TIPO CARACTER
 *  \return int RETORNA (1) SI GUARDA CON EXITO LOS DATOS EN LA ESTRUCTURA, SINO RETORNA (-1)
 */
int cargar_Empleado(ArrayList* listado, int id, char* nombre, float sueldo, int edad, char* profesion);

/** \brief SE ENCARGA DE MOSTRAR UN EMPLEADO
 *  \param this eEmpleados* PUNTERO A LA ESTRUCTURA
 *  \return int RETORNA (1) SI THIS NO SE NULL, SINO RETORNA (-1)
 */
int mostrar_Empleados(eEmpleados* this);

/** \brief SE ENCARGA DE LISTAR TODOS LOS EMPLEADOS
 *  \param this ArrayList* PUNTERO AL ArrayList
 *  \return int RETORNA (1) SI THIS NO SE NULL, SINO RETORNA (-1)
 */
int listadoDePersonas(ArrayList* this);

/** \brief SE ENCARGA DE GENERAR OTRA LISTA CON LOS EMPLEADOS QUE PASARON EL FILTRO
 *  \param this ArrayList* PUNTERO AL ArrayList
 *  \return int RETORNA (1) SI SE LOGRA EL FILTRADO, SINO RETORNA (-1)
 */
ArrayList* listaMayoresDeTreinta(ArrayList* this);

/** \brief SE ENCARGA DE FILTRAR UN DATO
 *  \param item void* PUNTERO A VOID
 *  \return int RETORNA (1) SI EL DATO PASA EL FILTRO, SINO RETORNA (-1)
 */
int functionFilter(void* item);
