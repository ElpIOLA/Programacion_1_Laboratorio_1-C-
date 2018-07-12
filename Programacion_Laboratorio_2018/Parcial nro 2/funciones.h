#include "ArrayList.h"
typedef struct
{
     int id;
     char nombre[21];
     float sueldo;
     int edad;
     char profesion[21];
}eEmpleados;

/**
 * \brief Se encarga de pedir memoria para el empleado.
 * \return eEmpleados* Retorna un auxiliar con nueva memoria.
 */
eEmpleados* new_empleado();

/** \brief Se encarga de ingresar un dato a la estructura
 * \param this eEmpleados* Puntero a estructura
 * \param int id Entero a guardar
 * \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
 */
int set_Id(eEmpleados* this, int id);

/** \brief Se encarga de mostrar un dato de la estructura
 * \param this eEmpleados* Puntero a estructura
 * \return int Retorna (1) si el dato es encontrado y mostrado sino retorna (-1)
 */
int get_Id(eEmpleados* this);

/** \brief Se encarga de ingresar un dato a la estructura
 * \param this eEmpleados* Puntero a estructura
 * \param palabra nombre* Puntero a string
 * \return int Retorna (1) si fue ingresado el dato sino retorna (-1) o (-2)
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

int set_Profesion(eEmpleados* this, char* profesion);
char* get_Profesion(eEmpleados* this);

int cargar_Archivo(ArrayList* lista, char* direccion);
int cargar_Empleado(ArrayList* listado, int id, char* nombre, float sueldo, int edad, char* profesion);
int mostrar_Empleados(eEmpleados* this);
int listadoDePersonas(ArrayList* this);

int listaMayoresDeTreinta(ArrayList* this, ArrayList* this2);
int functionFilter(void* item);
