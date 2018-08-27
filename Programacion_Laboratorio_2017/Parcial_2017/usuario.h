
typedef struct{
    char nombre[50];
    //------------
    int idGenerica;
    int estado;
}eUsuario;


int eUsua_init(eUsuario[],int limite);
int eUsua_buscarPorId(eUsuario[] ,int limite, int id);
int eUsua_siguienteId(eUsuario[] ,int limite);
int eUsua_buscarLugarLibre(eUsuario listado[],int limite);

int eUsua_mostrarUno(eUsuario parametro);
int eUsua_mostrarListado(eUsuario[] ,int limite);
int eUsua_mostrarListadoConBorrados(eUsuario[] ,int limite);

int eUsua_alta(eUsuario[] ,int limite);
int eUsua_baja(eUsuario[] ,int limite, int id);
int eUsua_modificacion(eUsuario[] ,int limite, int id);

int eUsua_ordenar(eUsuario[] ,int limite, int orden);
