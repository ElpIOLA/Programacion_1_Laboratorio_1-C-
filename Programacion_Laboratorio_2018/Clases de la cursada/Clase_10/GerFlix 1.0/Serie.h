
typedef struct{
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
}eSerie;

/**
 *\brief INICIALIZA EL ESTADO DE LAS SERIES EN 0.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void inicializarSeriesEstado(eSerie[], int);

/**
 *\brief DA DE ALTA UNA SERIE.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void alta_serie(eSerie[],int);

/**
 *\brief DA DE BAJA UNA SERIE.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void baja_serie(eSerie[], int);

/**
 *\brief MODIFICA EL NOMBRE, EL GENERO Y LA CANTIDAD DE TEMPORADAS DE LA SERIE.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void modificar_Serie(eSerie[], int);
/**
 *\brief MUESTRA UNA LISTA CON TODAS LAS SERIES ORDENADAS POR SU ID.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void mostrarListaSeries(eSerie[], int);

