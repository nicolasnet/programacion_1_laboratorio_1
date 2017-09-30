#define CANTCARACTERES 40


typedef struct {
    int codigo;
    char descripcionProd[CANTCARACTERES];
    float importe;
    int cantidad;
    int estado;

}eProducto;

typedef struct {
    int codigo;
    char descripcionProv[CANTCARACTERES];
}eProveedor;

typedef struct {
    int CodProducto;
    int CodProveedor;
    int estado;
}MixProductoProveedor;


int validaOpcionesInt(char dato[], int limiteInferior, int limiteSuperior);



float validaFloat(char dato[]);



void validaCadenaDeLetras(char auxDato [], int cantCaracteres);



int menu(char opciones[], int limiteInferior, int limiteSuperior);



void iniciaProducto(eProducto producto[], int CANTPROD);



void iniciaMix(MixProductoProveedor codificacion[]);



void imprimeProductos(eProducto producto[], int CANTPROD);



void alta(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



void modificar(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



void borrarProducto(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



void informaMinMax(eProducto producto[], int CANTPROD);






