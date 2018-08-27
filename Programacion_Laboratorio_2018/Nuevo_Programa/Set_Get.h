
/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO CHAR A LA ESTRUCTURA
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@param nombre char* RECIBE PUNTERO A DATO DE TIPO CHAR
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Nombre(ePersona* persona, char* nombre);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO CHAR
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
char* get_Nombre(ePersona* persona);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO CHAR A LA ESTRUCTURA
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@param apellido char* RECIBE PUNTERO A DATO DE TIPO CHAR
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Apellido(ePersona* persona, char* apellido);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO CHAR
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
char* get_Apellido(ePersona* persona);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO CHAR A LA ESTRUCTURA
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@param direccion char* RECIBE PUNTERO A DATO DE TIPO CHAR
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Direccion(ePersona* persona, char* direccion);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO CHAR
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
char* get_Direccion(ePersona* persona);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO INT A LA ESTRUCTURA
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@param edad int RECIBE PUNTERO A DATO DE TIPO INT
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Edad(ePersona* persona, int edad);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO INT
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
int get_Edad(ePersona* persona);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO INT A LA ESTRUCTURA
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@param legajo int RECIBE PUNTERO A DATO DE TIPO INT
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Legajo(ePersona* persona, int legajo);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO INT
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
int get_Legajo(ePersona* persona);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO FLOAT A LA ESTRUCTURA
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@param sueldo float RECIBE PUNTERO A DATO DE TIPO INT
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Sueldo(ePersona* persona, float sueldo);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO FLOAT
 *@param persona ePersona* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
float get_Sueldo(ePersona* persona);
