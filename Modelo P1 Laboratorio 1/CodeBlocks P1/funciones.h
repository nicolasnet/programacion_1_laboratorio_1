typedef struct {
    int codigo;
    char descripcionProd[51];
    float importe;
    int cantidad;
    int codigoProveedor;
    int estado;

}eProducto;

typedef struct {
    int codigo;
    char descripcionProv[51];

}eProveedor;

/* no lo pide en el examen. pero se usaria en caso de q un proveedor tenga varios productos y un producto varios proveedores.
typedef struct {
    int codigoProducto;
    int CodigoProveedor;


}ProductoProveedor
*/

int menu(char opciones[], int limiteInferior, int limiteSuperior);










