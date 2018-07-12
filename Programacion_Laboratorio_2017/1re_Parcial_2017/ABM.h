
/**
 *@brief BUSCA UN ESPACIO LIBRE EN EL VECTOR, LUEGO BUSCA UNA ID, DESPUES INGRESAMOS EL NOMBRE Y SE DA DE ALTA EL USUARIO CON UN ESTADO OCUPADO.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL USUARIO SE DA DE ALTA SINO RETORNA -2,-3 O -4 EM CASO DE ALGUN ERROR.
 */
int alta_usuario(eProvedor listaUser[], int tamUser);

/**
 *@brief BUSCA EL ID DE UN USUARIO Y SI ESTA REGISTRADO LE MODIFICA EL NOMBRE.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL USUARIO SE MODIFICA SINO RETORNA -2,-3 O -4 EM CASO DE ALGUN ERROR.
 */
int modificar_usuario(eProvedor listaUser[], int tamUser);

/**
 *@brief BUSCA EL ID DE UN USUARIO Y LO DA DE BAJA CON SUS PRODUCTOS.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL USUARIO SE DA DE BAJA SINO RETORNA -2,-3 O -4 EM CASO DE ALGUN ERROR.
 */
int baja_usuario(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief BUSCA EL ID DE UN USUARIO Y DESPUES PIDE DATOS DEL PRODUCTOS PARA LUEGO DARLOS DE ALTA.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL PRODUCTO SE DA DE ALTA SINO RETORNA -2,-3 O -4 EM CASO DE ALGUN ERROR.
 */
int publicar_producto(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief BUSCA EL ID DE UN USUARIO, DEL PRODUCTO Y LUEGO MODIFICA EL PRODUCTO QUE ESCOGA EL USUARIO.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL PRODUCTO SE MODIFICA SINO RETORNA -2,-3,-4,-5,-6 O -7 EM CASO DE ALGUN ERROR.
 */
int modificar_publicacion(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief BUSCA EL ID DE UN USUARIO, DEL PRODUCTO Y LUEGO DA DE BAJA UN PRODUCTO.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL PRODUCTO SE DIO DE BAJA SINO RETORNA -2,-3,-4 O -5 EM CASO DE ALGUN ERROR.
 */
int cancelar_producto(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief MUESTRA UNA LISTA DE PRODUCTOS. Y LUEGO ELIGE UNA ID. SI LA ID ESTA REGISTRADA, COMPRA UN PRODUCTO.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI EL PRODUCTO fUE COMPRADO SINO RETORNA -2,-3,-4 O -5 EM CASO DE ALGUN ERROR.
 */
int comprar_producto(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief PIDE UNA ID DE UN PROVEDOR Y LISTA TODOS SUS PRODUCTOS.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@return 0 SI MUESTRA LOS PRODUCTOS DEL PROVEDOR SINO RETORNA -2,-3,-4 O -5 EM CASO DE ALGUN ERROR.
 */
int listar_publicaciones_de_usuario(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief LISTA TODOS LOS PRODUCTOS CON SUS PROVEDORES.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 *@param listaProd RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 */
void listar_publicaciones(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd);

/**
 *@brief LISTA TODOS LOS PROVEDORES.
 *@param listaUser RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD ELEMENTOS DE UN VECTOR.
 */
void listar_usuarios(eProvedor listaUser[], int tamUser);
