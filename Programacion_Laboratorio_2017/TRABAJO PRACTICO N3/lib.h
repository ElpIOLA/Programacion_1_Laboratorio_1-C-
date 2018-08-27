#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    int legajo;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movies);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movies);

int ModificarPelicula(EMovie *movies);
void toString(EMovie *movies);
void listar(EMovie *movies);
int guardarEnArchivo(EMovie *x);
int cargarDesdeArchivo(EMovie *x);
int buscarLibre(EMovie *movies);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI ES NUMERICO Y 0 SI NO LO ES
 */
int esNumerico(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES SOLO LETRAS
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI CONTIENE SOLO ' ' Y LETRAS Y 0 SI NO LO ES
 */
int esSoloLetras(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES SOLO NUMERICO
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI ES NUMERICO Y 0 SI NO LO ES
 */
int esNumericoFlotante(char str[]);

/**
 * \brief SOLICITA UN TEXTO AL USUARIO Y LO DEVUELVE
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO
 * \return void
 */
void getString(char mensaje[], char input[]);

/**
 * \brief SOLICITA UN TEXTO AL USUARIO Y LO DEVUELVE
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO
 * \return 1 SI EL TEXTO CONTIENE SOLO LETRAS
 */
int getStringLetras(char mensaje[], char input[]);

/**
 * \brief SOLICITA UN TEXTO NUMERICO AL USUARIO Y LO DEVUELVE
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO
 * \return 1 SI EL TEXTO CONTIENE SOLO NUMEROS
 */
int getStringNumeros(char mensaje[], char input[]);


/**
 * \brief SOLICITA UN TEXTO NUMERICO AL USUARIO Y LO DEVUELVE
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO
 * \return 1 SI EL TEXTO CONTIENE SOLO NUMEROS
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);
#endif // FUNCIONES_H_INCLUDED
