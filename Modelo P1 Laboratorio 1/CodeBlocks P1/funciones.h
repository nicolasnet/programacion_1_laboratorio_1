typedef struct {
    int codigo;
    char descripcionProd[51];
    float importe;
    int cantidad;
    int estado;

}eProducto;

typedef struct {
    int codigo;
    char descripcionProv[51];
}eProveedor;

typedef struct {
    int CodProducto;
    int CodProveedor;
    int estado;
}MixProductoProveedor;


int validaOpcionesInt(char dato[], int limiteInferior, int limiteSuperior);



int menu(char opciones[], int limiteInferior, int limiteSuperior);



void iniciaProducto(eProducto producto[], int CANTPROD);



void iniciaMix(MixProductoProveedor codificacion[]);



void imprimeProductos(eProducto producto[], int CANTPROD);



void alta(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



void modificar(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



void borrarProducto(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



void informaMinMax(eProducto producto[], int CANTPROD);






