
typedef struct
{
    char clie_nom[51];
    char clie_ape[51];
    long int clie_dni;
    int clie_id;
}cLiente;

typedef struct
{
    int id_cliente;
    int id_alquiler;
    int equipo;
    char estado[40];
    int operador;
    int tiempo_estimado;
    int tiempo_real;
}aLquiler;

/**
 * \brief INGRESA LOS DATOS A LA STRUCT CLIENTE, ALQUILER Y CLIENTE_ALQUILER
 * \param cliente[] SOLICITA LOS DATOS
 * \param alquiler[] SOLICITA LOS DATOS
 * \param cliente_alquiler[] SOLICITA LOS DATOS
 * \return DEVUELVE LOS ESTADOS DE CADA STRUCT EN 0
 */
int inicializar_prog(cLiente cliente[]);

/**
 * \brief INGRESA LOS DATOS A LA STRUCT CLIENTE
 * \param cliente[] SOLICITA LOS DATOS
 * \return LOS VALORES INGRESADOS
 */
int alta(cLiente cliente[]);

/**
 * \brief MODIFICA LOS DATOS DEL CLIENTE
 * \param cliente[] SOLICITA LOS DATOS
 * \return LOS VALORES MODIFICADOS
 */
int modificar(cLiente cliente[]);

/**
 * \brief DA DE BAJA UN CLIENTE
 * \param cliente[] SOLICITA LOS DATOS
 * \return EL ESTADO DEL CLIENTE 0
 */
int baja(cLiente cliente[]);

/**
 * \brief INGRESA LOS DATOS PARA EL ALQUILER
 * \param cliente[] SOLICITA LOS DATOS
 * \param alquiler[] SOLICITA LOS DATOS
 * \return EL NUEVO ALQUILER
 */
int nuevoAlquiler(cLiente cliente[], aLquiler alquiler[]);

/**
 * \brief INGRESA LOS DATOS PARA EL ALQUILER
 * \param cliente[] SOLICITA LOS DATOS
 * \param alquiler[] SOLICITA LOS DATOS
 * \return EL FIN DEL ALQUILER
 */
int finDeAlquiler(aLquiler alquiler[]);

/**
 * \brief MUESTRA OPCIONES PARA INFORMAR Y LLAMA 3 FUNCIONES
 * \param cliente[] SOLICITA LOS DATOS CLIENTE
 * \param alquiler[] SOLICITA LOS DATOS ALQUILER
 */
void informar(cLiente cliente[],aLquiler alquiler[]);

void pRomedios(cLiente cliente[], aLquiler alquiler[]);
void client_Max_Alqui(cLiente cliente[], aLquiler alquiler[]);
void equiP_mAx_Alqui(aLquiler alquiler[]);

/**
 * \brief SOLICITA UN NUMERO AL USUARIO Y DEVUELVE EL RESULTADO
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \return EL NUMERO INGRESADO POR EL USUARIO
 */
int getInt(char mensaje[]);

/**
 * \brief BUSCA EL PRIMER LUGAR NO UTILIZADO EN EL ARRAY
 * \param productArray ES EL ARRAY EN EL CUAL BUSCAR
 * \param arrayLenght INDICA LA LONGITUD DEL ARRAY
 * \return SI NO HAY LUGARES LIBRES (-1) Y SI HAY LA POSICION DEL MISMO (I)
 */
int disponibilidadAlquiler(aLquiler alquilarArray[], int recorrer);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI ES NUMERICO Y 0 SI NO LO ES
 */
int esNumerico(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO FLOTANTE
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI ES NUMERICO Y 0 SI NO LO ES
 */
int esNumericoFlotante(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES SOLO LETRAS
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI CONTIENE SOLO ' ' Y LETRAS Y 0 SI NO LO ES
 */
int esSoloLetras(char str[]);

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
