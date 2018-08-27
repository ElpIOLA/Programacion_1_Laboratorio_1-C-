/****************************************************************************************
 ************************ SOLICITAR INT, FLOAT Y CHAR ***********************************
 ***************************************************************************************/

/**
 * \brief SOLICITA UN NUMERO AL USUARIO Y DEVUELVE EL RESULTADO
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \return EL NUMERO INGRESADO POR EL USUARIO
 */
float getFloat(char mensaje[]);

/**
 * \brief SOLICITA UN NUMERO AL USUARIO Y DEVUELVE EL RESULTADO
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \return EL NUMERO INGRESADO POR EL USUARIO
 */
int getInt(char mensaje[]);

/**
 * \brief SOLICITA UN NUMERO AL USUARIO Y DEVUELVE EL RESULTADO
 * \param MENSAJE[] ES EL MENSAJE A SER MOSTRADO
 * \return EL NUMERO INGRESADO POR EL USUARIO
 */
char getChar(char mensaje[]);

/**
 * \brief GENERA UN NUMERO ALEATORIO
 * \param DESDE, NUMERO ALEATORIO MINIMO
 * \param HASTA, NUMERO ALEATORIO MAXIMO
 * \param INICIAR, INDICA SI SE TRATA DEL PRIMER NUMERO SOLICITADO 1 INDICA QUE SI
 * \return EL NUMERO ALEATORIO GENERADO
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI ES NUMERICO Y 0 SI NO LO ES
 */
int esNumerico(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO CONTIENE NUMEROS, + Y -
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI CONTIENE SOLO NUMEROS, ESPACIO Y UN GUION
 */
int esTelefono(char str[]);

/**
 * \brief VERIFICA SI EL VALOR RECIBIDO CONTIENE LETRAS Y NUMEROS
 * \param STR ARRAY CON LA CADENA A SER ANALIZADA
 * \return 1 SI CONTIENE SOLO ESPACIO O NUMEROS Y LETRAS Y 0 SI NO LO ES
 */
int esAlfaNumerico(char str[]);

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

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 */
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 */
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);

/**
 * \brief Hace un clear, similar al system("clear")
 * \param -
 * \return -
 */
void clearScreen(void);

/**
 * \brief Hace una pausa, similar al system("pause")
 * \param -
 * \return -
 *
 */
void pause(void);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 */
void clearStdin(void);



/****************************************************************************************
 ************************** FIN DE FUNCIONES ********************************************
 ***************************************************************************************/
