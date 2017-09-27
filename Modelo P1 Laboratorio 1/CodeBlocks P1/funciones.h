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



int menu(char opciones[], int limiteInferior, int limiteSuperior);


void iniciaProducto(eProducto producto[], int CANTPROD);


void iniciaMix(MixProductoProveedor codificacion[]);


void alta(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);










