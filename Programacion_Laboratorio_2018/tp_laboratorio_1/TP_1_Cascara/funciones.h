
/**
 *\brief Valida un float
 *\param mensaje El mensaje recibido
 *\param mensajeError El mensaje recibido
 *\param ope Flotante recibido
 *\return Retorna un flotante.
 */
float validarFloat(char mensaje[], char mensajeError[], float ope);

/**
 *\brief Verifica que ambos operandos no esten en 0
 *\param a Entero recibido
 *\param b Entero recibido
 *\return Retorna 0 si ambos operandos se encuentran no tienen valor y retorna 1 si alguno o ambos tiene algun valor.
 */
float verificacion(float a, float b);

/**
 *\brief Suma dos flotantes
 *\param a Flotante recibido
 *\param b Flotante recibido
 *\return Retorna la suma de los dos flotantes.
 */
void sumar(float a,float b);

/**
 *\brief Resta dos flotantes
 *\param a Flotante recibido
 *\param b Flotante recibido
 *\return Retorna la resta de los dos flotantes.
 */
void resta(float a, float b);

/**
 *\brief Divide dos flotantes
 *\param a Flotante recibido
 *\param b Flotante recibido
 *\return Retorna la division de los dos flotantes.
 */
void division(float a, float b);

/**
 *\brief Multiplica dos flotantes
 *\param a Flotante recibido
 *\param b Flotante recibido
 *\return Retorna la multiplicacion de los dos flotantes.
 */
void multiplicacion(float a, float b);

/**
 *\brief Calcula el factorial de un numero entero
 *\param a Entero recibido
 *\return Retorna el factorial de !A
 */
int factorial(int a);
