
typedef struct{
    int id_propietario;
    char nombre[21];
    char apellido[21];
    char direccion[21];
    char num_tarjeta_credito[31];
    int estado;
}ePropietario;

/**
 *@brief INICIALIZA LA ID Y EL ESTADO DE TODOS LOS PROPIETARIOS.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 */
void inicializar_propietario(ePropietario propietario[], int tamProp);

/**
 *@brief INGRESA DATOS CARGADOS AL VECTOR DE PROPIETARIOS.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 */
void datos_hard_propietario(ePropietario propietario[], int tamProp);

/**
 *@brief MUESTRA UNA LISTA DE PROPIETARIOS.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 */
void lista_propietario(ePropietario propietario[], int tamProp);

/**
 *@brief RECORRE TODO EL VECTOR Y RETORNA LA PRIMERA POSICION QUE TENGA EL ESTADO EN 0.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 *@return LA POSICION LIBRE.
 */
int eProp_buscarLugarLibre(ePropietario propietario[], int tamProp);

/**
 *@brief RECORRE TODO EL VECTOR DE PROPIETARIO Y BUSCA UNA LA PRIMERA POSICION OCUPADA Y AUMENTA EN 1 SU ID.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 *@return LA ID INCREMENTADA +1.
 */
int eProp_siguienteId(ePropietario propietario[], int tamProp);

/**
 *@brief RECIBE UNA ID Y RECORRE TODO EL VECTOR Y BUSCA LA POSICION DE MEMORIA DONDE ESTE UBICADA ESA ID.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 *@return LA POSICION DE MEMORIA DONDE ESTA UBICADA LA ID.
 */
int eProp_buscarPorId(ePropietario propietario[], int tamProp, int id);

/**----------------------------ABM------------------------------------------------*/

/**
 *@brief BUSCA UN LUGAR LIBRE, UN ID Y AGREGA DATOS AL VECTOR DEL PROPIETARIO.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 *@return 0 SI EL PROPIETARIO ES DADO DE ALTA. SINO RETORNARA UN NUMERO NEGATIVO SEGUN EL ERROR QUE HAYA TENIDO.
 */
int alta_propietario(ePropietario propietario[], int tamProp);

/**
 *@brief BUSCA UN ID Y SI EL PROPIETARIO EXISTE LE MODIFICA EL NUMERO DE TARJETA DE CREDITO.
 *@param ePropietario RECIBE EL VECTOR DE LA ESTRUCTURA PROPIETARIO.
 *@param tamProp RECIBE LA CANTIDAD DE POSICIONES QUE TENDRA EL VECTOR DE PROPIETARIO.
 *@return 0 SI SE MODIFICA LA TARJETA DE CREDITO. SINO RETORNARA UN NUMERO NEGATIVO SEGUN EL ERROR QUE HAYA TENIDO.
 */
int modificar_propietario(ePropietario propietario[], int tamProp);


