
typedef struct{
    char nombre[51];
    int cantidad;
    int codigo;
    int estado;
    float importe;
}eProducto;

typedef struct{
    int codigo;
    char nombre[51];
    int estado;
}eProvedoor;

typedef struct{
    int codigoProduc;
    int codigoProvee;
    int estado;
}pIOLA;

int init(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[]);

int menu(void);

int validarMenu(char valorMenu[]);

int agregarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[]);

int modificarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[]);

int borrarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[]);

int imformarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[]);

int listaOrdenada(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[]);

int validarString(char productoDescripcion[]);
int validarEntero(char validarCodigo[]);
int validarFloat(char validarImporte[]);
