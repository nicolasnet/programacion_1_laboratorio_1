#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"



int menu(char items[], int limiteInferior, int limiteSuperior){

    int opciones;
    printf("%s", items);
    printf("\nElegir: ");
    scanf("%d", &opciones);
    while(opciones<limiteInferior || opciones>limiteSuperior){
        printf("reintente elegir: ");
        scanf("%d", &opciones);
    }
    return opciones;

}

void iniciaProducto(eProducto producto[], int CANTPROD){
    int i;

    for (i=0; i<CANTPROD; i++){
        producto[i].estado = 0;
    }
}


void iniciaMix(MixProductoProveedor codificacion[]){
    int i;

    for (i=0; i<100; i++){
        codificacion[i].estado = 0;
    }
}



void alta (eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD){
    int i;
    int j;

    for (i=0; i<CANTPROD; i++){
        if (producto[i].estado==0){

                producto[i].codigo = i+1;

                printf("Ingrese Descripcion: \n");
                fflush(stdin);
                scanf("%[^\n]", producto[i].descripcionProd);


                printf("Ingrese Precio del producto: \n");
                scanf("%f", &producto[i].importe);


                printf("Ingrese Cantidad ingresada del producto: \n");
                scanf("%d", &producto[i].cantidad);


                for(j=0; j<10; j++){
                        printf("\n%d -- %s\n", proveedor[j].codigo, proveedor[j].descripcionProv);
                }

                for(j=0; j<100; j++){
                    if(codificacion[j].estado == 0){
                        printf("\nIngrese codigo de proveedor: ");
                        scanf("%d", &codificacion[j].CodProveedor);
                        codificacion[j].CodProducto = producto[i].codigo;
                        break;

                    }


                }

                producto[i].estado = 1;

                break;
        }

    }
}











#endif
