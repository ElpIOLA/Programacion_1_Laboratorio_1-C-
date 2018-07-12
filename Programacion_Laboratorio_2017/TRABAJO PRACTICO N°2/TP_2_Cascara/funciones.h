#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * @brief Recorre el array y lo inicializa en 0
 * @param persona el array se pasa como parametro
 * @return el indice inicializado en 0
 */
int init(EPersona persona[]);

/**
 * @brief Solicita ingresar datos de una persona
 * @param solicita que se ingrese el nombre
 * @param solicita que se ingrese la edad
 * @param solicita que se ingrese el DNI
 * @return los datos ingresados
 */
int agregarEPersona(EPersona persona[]);

/**
 * @brief Borra mediante DNI la persona ingresada
 * @param Solicita como parametro a ingresar el DNI
 * @return el registro completo sin los datos borrados
 */
int borrarPersona(EPersona persona[]);

/**
 * @brief Ordena por nombre alfabeticamente el registro de datos
 * @param persona el array se pasa como parametro
 * @return la lista de personas orndenadas por nombre
 */
int listaOrdenadaPorNombre(EPersona persona[]);

/**
 * @brief Muestra un gráfico de barras vertical sobre las edades
 * @param menor referencia a la edad
 * @param mayor referencia a la edad
 * @param viejo referencia a la edad
 * @return gráfico de barras vertical simbolizado por asteriscos
 */
int graficoEdades(EPersona persona[]);

#endif // FUNCIONES_H_INCLUDED
