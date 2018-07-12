
typedef struct{
    char nombre[21];
    float calificacion;
    int id_Provedor;
    int estado;
}eProvedor;

typedef struct{
    char nombre[21];
    float precio;
    int id_Producto;
    int id_usuario;
    int stock;
    int cantidad_vendida;
    int estado;
}eProducto;

/**
 *@brief MUESTRA UN MENU Y RETORNA UN VALOR.
 *@return RETORNA -2 SI EL USUARIO INGRESA UN STRING. DE LO CONTRARIO, RETORNA EL ENTERO INGRESADO.
 */
int menu();

/**
 *@brief RECORRE LOS VECTORES DE AMBAS ESTRUCTURAS Y INICIALIZA ESTADO EN "LIBRE" Y EL ID EN 0.
 *@param eProvedor RECIBE EL VECTOR DEL PROVEDOR.
 *@param eProducto RECIBE EL VECTOR DEL PRODUCTO.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProg_init(eProvedor listaUser[], eProducto listaProd[], int limite);

/**
 *@brief RECORRE EL VECTOR DEL PROVEDOR Y BUSCA UNA POSICION "LIBRE" Y LA RETORNA.
 *@param eProvedor RECIBE EL VECTOR DEL PROVEDOR.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProve_buscarLugarLibre(eProvedor listaUser[], int limite);

/**
 *@brief RECORRE EL VECTOR DEL PROVEDOR Y BUSCA UNA POSICION "LIBRE" Y LA RETORNA.
 *@param eProducto RECIBE EL VECTOR DEL PRODUCTO.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProduc_buscarLugarLibre(eProducto listaProd[], int limite);

/**
 *@brief RECORRE EL VECTOR DEL PROVEDOR, BUSCA UNA ID, LA INCREMENTA Y LA RETORNA.
 *@param eProvedor RECIBE EL VECTOR DEL PROVEDOR.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProve_siguienteId(eProvedor listaUser[],int limite);

/**
 *@brief RECORRE EL VECTOR DEL PRODUCTO, BUSCA UNA ID, LA INCREMENTA Y LA RETORNA.
 *@param eProducto RECIBE EL VECTOR DEL PRODUCTO.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProduc_siguienteId(eProducto listaProd[],int limite);

/**
 *@brief RECORRE EL VECTOR DEL PROVEDOR, BUSCA UNA ID Y LA RETORNA.
 *@param eProvedor RECIBE EL VECTOR DEL PROVEDOR.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES.
 *@param id RECIBE EL ID A BUSCAR.
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProve_buscarPorId(eProvedor listaUser[] ,int limite, int id);

/**
 *@brief RECORRE EL VECTOR DEL PRODUCTO, BUSCA UNA ID Y LA RETORNA.
 *@param eProducto RECIBE EL VECTOR DEL PROVEDOR.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES.
 *@param id RECIBE EL ID A BUSCAR.
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProduc_buscarPorId(eProducto listaProd[] ,int limite, int id);

/**
 *@brief RECORRE EL VECTOR DEL PROVEDOR, BUSCA UNA ID Y LA RETORNA.
 *@param eProducto RECIBE EL VECTOR DEL PRODUCTO.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES.
 *@param id RECIBE EL ID A BUSCAR.
 *@return RETORNA 0 SI NO OCURRIO NINGUN ERROR, DE LO CONTRARIO RETORNA -1.
 */
int eProduc_buscarPorIdUsuario(eProducto listaProd[] ,int limite, int id);

/**
 *@brief RECORRE EL VECTOR DEL PROVEDOR Y MUESTRA SUS ELEMENTOS.
 *@param eProvedor RECIBE EL VECTOR DEL PROVEDOR.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 */
void lista_usuarios(eProvedor listaUser[], int tamUser);

/**
 *@brief RECORRE EL VECTOR DEL PRODUCTO Y MUESTRA SUS ELEMENTOS.
 *@param eProducto RECIBE EL VECTOR DEL PRODUCTO.
 *@param limite RECIBE LA CANTIDAD DE INTERACCIONES
 */
void listar_productos(eProducto listaProd[], int tamProd);

/**
 *@brief RECORRE EL VECTOR DE PRODUCTOS Y EL USUARIO Y LISTA LOS PRODUCTOS.
 *@param eProvedor RECIBE EL VECTOR DEL PROVEDOR.
 *@param tamUser RECIBE LA CANTIDAD DE INTERACCIONES DEL USUARIO.
 *@param eProducto RECIBE EL VECTOR DEL PRODUCTO.
 *@param tamProd RECIBE LA CANTIDAD DE INTERACCIONES DEL PRODUCTO
 *@param id_user RECIBE EL ID DEL USUARIO.
 */
void lista_UsuarioConSuProducto(eProvedor listaUser[],int tamUser, eProducto listaProd[], int tamProd, int id_user);


float promedio(eProvedor listaUser[], float numero, int tamUser, int id);

