
/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO CHAR A LA ESTRUCTURA
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@param nombre char* RECIBE PUNTERO A DATO DE TIPO CHAR
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Nombre(eCaracter* persona, char* nombre);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO CHAR
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
char* get_Nombre(eCaracter* persona);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO CHAR A LA ESTRUCTURA
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@param apellido char* RECIBE PUNTERO A DATO DE TIPO CHAR
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Caracter(eCaracter* caracter, char carac);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO CHAR
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
char get_Caracter(eCaracter* caracter);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO CHAR A LA ESTRUCTURA
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@param direccion char* RECIBE PUNTERO A DATO DE TIPO CHAR
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Vocal(eCaracter* caracter, int vocal);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO CHAR
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
int get_Vocal(eCaracter* caracter);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO INT A LA ESTRUCTURA
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@param edad int RECIBE PUNTERO A DATO DE TIPO INT
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Consonante(eCaracter* caracter, int consonante);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO INT
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
int get_Consonante(eCaracter* caracter);

/**
 *@brief SE ENCARGA DE INGRESAR UN DATO DE TIPO INT A LA ESTRUCTURA
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@param legajo int RECIBE PUNTERO A DATO DE TIPO INT
 *@return RETORNA (1) SI EL DATO ES INGRESADO CON EXITO, SINO RETORNA (0)
 */
int set_Numero(eCaracter* caracter, int numero);

/**
 *@brief SE ENCARGA DE MOSTRAR UN DATO DE TIPO INT
 *@param persona eCaracter* RECIBE PUNTERO A ESTRUCTURA
 *@return RETORNA (1) SI EL DATO ES MOSTRADO CON EXITO, SINO RETORNA (0)
 */
int get_Numero(eCaracter* caracter);
