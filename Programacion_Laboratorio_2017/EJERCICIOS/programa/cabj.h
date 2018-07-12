
typedef struct{
    char description[51];
    int code;
    int qty;
    float price;
    int status; /** Active(1) or Inactive(2) */
}Product;

/**
 * \brief INICIALIZA EL STATUS EN UN ARRAY DE PRODUCTOS
 * \param productArray ES EL ARRAY EN EL CUAL BUSCAR
 * \param arrayLenght INDICA LA LONGITUD DEL ARRAY
 * \param value ES EL VALOR QUE SE ASIGNARA A STATUS
 * \return
 */
void setStatus(Product productArray[], int arrayLenght, int value);

/**
 * \brief BUSCA EL PRIMER LUGAR NO UTILIZADO EN EL ARRAY
 * \param productArray ES EL ARRAY EN EL CUAL BUSCAR
 * \param arrayLenght INDICA LA LONGITUD DEL ARRAY
 * \return SI NO HAY LUGARES LIBRES (-1) Y SI HAY LA POSICION DEL MISMO (I)
 */
int findEmptyPlace(Product productArray[], int arrayLenght);

/**
 * \brief BUSCA LA PRIMER OCURRENCIA DE UN PRODUCTO MEDIANTE SU CODIGO
 * \param productArray ES EL ARRAY EN EL CUAL BUSCAR
 * \param arrayLenght INDICA LA LONGITUD DEL ARRAY
 * \param code ES EL VALOR QUE SE BUSCA
 * \return SI NO HAY OCURRENCIA (-1) Y SI LA HAY LA POSICION DEL MISMO (I)
 */
int findProductByCode(Product productArray[], int arrayLenght, int code);
