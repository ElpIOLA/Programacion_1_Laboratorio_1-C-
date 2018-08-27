
/**------------------FUNCIONES DE INVOCACION------------------*/

/**
 * \brief MUESTRA UN MENSAJE.
 * \param MENSAJE[] RECIBE UN MENSAJE.
 * \return RETORNA UN PRINTF MOSTRANDO UN DATO DE TIPO INT.
*/
int getInt(char mensaje[]);

/**
 * \brief MUESTRA UN MENSAJE.
 * \param MENSAJE - RECIBE UN MENSAJE MENSAJE.
 * \param INPUT - RECIBE UN DATO DE TIPO CHAR.
*/
void getString(char mensaje[], char input[]);

/**
 * \brief SOLICITA UN TEXTO AL USUARIO Y LO DEVUELVE.
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO.
 * \param INPUT[] ARRAY DONDE SE CARGARA EL TEXTO INGRESADO.
 * \return RETORNA 1 SI EL TEXTO CONTIENE SOLO LETRAS. DE LO CONTRARIO 0.
*/
int getStringLetras(char mensaje[], char input[]);

/**
 * \brief SOLICITA UN TEXTO NUMERICO AL USUARIO Y LO DEVUELVE.
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO.
 * \param INPUT[] ARRAY DONDE SE CARGARA EL TEXTO INGRESADO.
 * \return RETORNA 1 SI EL TEXTO CONTIENE SOLO NUMEROS. DE LO CONTRARIO 0.
 */
int getStringNumeros(char mensaje[], char input[]);

/**
 * \brief SOLICITA UN TEXTO NUMERICO AL USUARIO Y LO DEVUELVE.
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO.
 * \param INPUT[] ARRAY DONDE SE CARGARA EL TEXTO INGRESADO.
 * \return RETORNA 1 SI EL TEXTO CONTIENE SOLO NUMEROS. DE LO CONTRARIO 0.
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**------------------FUNCIONES DE VALIDACION------------------*/

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES SOLO LETRAS.
 * \param STR[] ARRAY CON LA CADENA A SER ANALIZADA.
 * \return RETORNA 1 SI CONTIENE SOLO ' ' Y LETRAS. DE LO CONTRARIO 0.
 */
int esSoloLetras(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO ENTERO.
 * \param STR[] ARRAY CON LA CADENA A SER ANALIZADA.
 * \return RETORNA 1 SI ES NUMERICO Y 0 SI NO LO ES.
 */
int esNumerico(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO FLOTANTE.
 * \param STR[] ARRAY CON LA CADENA A SER ANALIZADA.
 * \return RETORNA 1 SI ES NUMERICO Y 0 SI NO LO ES.
 */
int esNumericoFlotante(char str[]);
