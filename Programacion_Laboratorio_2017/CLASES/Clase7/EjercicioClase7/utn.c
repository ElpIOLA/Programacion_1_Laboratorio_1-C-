
/**
 *  \brief VERIFICA SI EL VALOR RECIBIDO CONTIENE SOLO LETRAS.
 *  \param STR ARRAY CON LA CADENA A SER ANALIZADA
 *  \return 1 SI CONTIENE SOLO ' ' Y LETRAS Y 0 SI NO LO ES.
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && str[i] < 'A' || str[i] > 'Z')
        {
            return 0;
            i++;
        }
        return 1;
    }
}

/**
 *  \brief VERIFICA SI EL VALOR RECIBIDO ES NUMERICO.
 *  \param STR ARRAY CON LA CADENA A SER ANALIZADA
 *  \return 1 SI ES NUMERICO Y 0 SI NO LO ES.
 */
 int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
            i++;
        }
        return 1;
    }
}

/**
 *  \brief SOLICITA UN TEXTO AL USUARIO Y LO DEVUELVE.
 *  \param MENSAJE, ES EL MENSAJE A SER MOSTRADO.
 *  \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO.
 *  \return VOID
 */
void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

/**
 *  \brief SOLICITA UN TEXTO AL USUARIO Y LO DEVUELVE.
 *  \param MENSAJE, ES EL MENSAJE A SER MOSTRADO.
 *  \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO.
 *  \return 1 SI EL TEXTO CONTIENE SOLO LETRAS.
 */
 int getStringLetras(char mensaje[], char input[])
 {
     char aux[256];
     getString(mensaje, aux);
     if(esSoloLetras(aux))
     {
         strcpy(input, aux);
         return 1;
     }
     return 0;
 }

 /**
 *  \brief SOLICITA UN TEXTO NUMERICO AL USUARIO Y LO DEVUELVE.
 *  \param MENSAJE, ES EL MENSAJE A SER MOSTRADO.
 *  \param INPUT ARRAY DONDE SE CARGARA EL TEXTO INGRESADO.
 *  \return 1 SI EL TEXTO CONTIENE SOLO NUMEROS.
 */
int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}
