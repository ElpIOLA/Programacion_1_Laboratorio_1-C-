#include "ArrayList.h"

typedef struct {
     char nombre[21];
     char apellido[21];
     char direccion[31];
     int edad;
     int legajo;
     float sueldo;
}ePersona;

/**
 *@brief ESTA FUNCION SE ENCARGA DE RESERVAR MEMORIA PARA LA ESTRUCTURA
 *@return RETORNA UN PUNTERO AL TIPO DE DATO CON MEMORIA RESERVADA
 */
ePersona* new_persona();

/**
 *@brief ESTA FUNCION SE ENCARGA DE MOSTRAR LOS DATOS DE TODAS LAS PERSONAS QUE TENGA EL ArrayList
 *@param lista ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@return RETORNA (1) SI SE MUESTRA CON EXITO LAS PERSONAS, SINO RETORNA (0)
 */
int listaPersonas(ArrayList* lista);

/**
 *@brief ESTA FUNCION SE ENCARGA DE AGREGAR UNA NUEVA PERSONA EN EL ArrayList
 *@param lista ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@return RETORNA (1) SI LA PERSONA ES AGREGADA CON EXITO, SINO RETORNA (0)
 */
int altaPersona(ArrayList* lista);

/**
 *@brief ESTA FUNCION SE ENCARGA DE ELIMINAR UNA PERSONA Y GUARDARLA EN OTRO ArrayList
 *@param this ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@param auxiliar ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@return RETORNA EL NUEVO ArrayList CON LAS PERSONAS ELIMINADAS, SINO RETORNA (NULL)
 */
ArrayList* bajaPersona(ArrayList* this, ArrayList* auxiliar);

/**
 *@brief ESTA FUNCION SE ESCARGA DE MODIFICAR UNA PERSONA
 *@param this ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@return RETORNA (1) SI LA PERSONA ES MODIFICADA, SINO RETORNA (0)
 */
int modificarPersona(ArrayList* this);

/**
 *@brief ESTA FUNCION SE ESCARGA DE PASAR UNA PERSONA DESDE EL PRIMER ArrayList AL OTRO
 *@param listaBorrados ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@param listaPersona ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@return RETORNA UN ArrayList CON LA PERSONA NUEVA AGREGADA
 */
ArrayList* restaurarPersonaBorrada(ArrayList* listaBorrados, ArrayList* listaPersona);

/**
 *@brief ESTA FUNCION SE ENCARGA DE CREAR UN ARCHIVO
 *@return RETORNA (1) SI EL ARCHIVO ES CREADO CON EXITO, SINO RETORNA (0)
 */
int crear_Archivo();

/**
 *@brief ESTA FUNCION SE ENCARGA DE LEER TODOS LOS DATOS DEL ARCHIVO
 *@param lista ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@param link char* RECIBE PUNTERO DE TIPO CHAR QUE GUARDA LA DIRECCION DEL ARCHIVO
 *@return RETORNA (1) SI EL ARCHIVO ES LEIDO CON EXITO, SINO RETORNA (0)
 */
int cargar_Archivo(ArrayList* this, char* link);

/**
 *@brief ESTA FUNCION SE ENCARGA DE GUARDAR LOS DATOS DEL ARCHIVO EN EL ArrayList
 *@param this ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@param legajo int RECIBE UN DATO DE TIPO INT
 *@param nombre char* RECIBE UN PUNTERO DE TIPO CHAR
 *@param apellido char* RECIBE UN PUNTERO DE TIPO CHAR
 *@param direccion char* RECIBE UN PUNTERO DE TIPO CHAR
 *@param edad int RECIBE UN DATO DE TIPO INT
 *@param sueldo float RECIBE UN DATO DE TIPO FLOAT
 *@return RETORNA (1) SI LOS DATOS SON GUARDADOS CON EXITO, SINO RETORNA (0)
 */
int cargar_Datos(ArrayList* this, int legajo ,char* nombre, char* apellido, char* direccion, int edad, float sueldo);

/**
 *@brief ESTA FUNCION SE ENCARGA DE GUARDAR LOS DATOS DEL ArrayList EN EL ARCHIVO
 *@param lista ArrayList* RECIBE UN PUNTERO AL TIPO DE DATO ArrayList
 *@param link char* RECIBE PUNTERO DE TIPO CHAR QUE GUARDA LA DIRECCION DEL ARCHIVO
 *@return RETORNA (1) SI LOS DATOS SON GUARDADOS CON EXITO, SINO RETORNA (0)
 */
int guardar_en_archivo(ArrayList* this, char* link);

/**
 *@brief ESTA FUNCION SE ENCARGA DE COMPARAR DOS ELEMENTOS
 *@param PersonaA void* RECIBE PUNTERO DE TIPO VOID
 *@param PersonaB void* RECIBE PUNTERO DE TIPO VOID
 *@return RETORNA (1) SI LOS ELEMENTOS SON COMPARADOS CON EXITO, SINO RETORNA (0)
 */
int comparar_Empleadoss(void* PersonaA, void* PersonaB);

/**
 *@brief ESTA FUNCION SE ENCARGA DE PASAR POR UN FILTRO EL ITEM QUE RECIBE
 *@param item void* RECIBE PUNTERO DE TIPO VOID
 *@return RETORNA (1) SI EL ELEMENTO ES MAYOR A 18, SI ES MENOR RETORNA (0), SI EL ITEM ES NULL RETORNA (-1)
 */
int filtroEdades(void* item);


