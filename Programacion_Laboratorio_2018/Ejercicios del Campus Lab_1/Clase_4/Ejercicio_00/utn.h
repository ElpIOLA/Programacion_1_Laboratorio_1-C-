

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
char calcularNumeroAleatorio(int desde,int hasta, int iniciar);

/** \brief SE LE PASA UN NUMERO ENTERO Y LO DEVUELVE SI EL NUMERO ES DE TIPO ENTERO.
 * \param pResultado int* PUNTERO AL NUMERO A SER VALIDADO
 * \return int RETORNA EL NUMERO.
 */
int getInt(int* pResultado);


/** \brief RECIBE UNA CADENA Y VALIDA SI LA CADENA CONTIENE SOLO NUMEROS.
 * \param cadena char* PUNTERO A CADENA DE CARACTERES
 * \return int RETORNA EL NUMERO
 */
int esNumerica(char* cadena);

float getFloat(float* pResultado);

float esFlotante(char* cadena);

int getString(char* input);

int esSoloLetras(char* str);

int getNumeroConSigno(int* pResultado);

int esNumeroConSigno(char* cadena);
