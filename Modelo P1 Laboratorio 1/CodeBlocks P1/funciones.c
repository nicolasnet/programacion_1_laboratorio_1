#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"



int validaOpcionesInt(char dato[], int limiteInferior, int limiteSuperior){

    int opciones, cant, i, flag=0;

    cant = strlen(dato);
    for(i=0; i<cant; i++){
        if(isalpha(dato[i])){
            flag = 1;
            break;
        }
    }
    while(flag==1 || atoi(dato)>limiteSuperior || atoi(dato)<limiteInferior){
        printf("\nreintente elegir: ");
        scanf("%s", dato);
        cant = strlen(dato);

        for(i=0; i<cant; i++){
            if(isalpha(dato[i])){
                flag = 1;
                break;
            }
            else{
                flag = 0;
            }
        }
    }

    opciones = atoi(dato);
    return opciones;
}



int menu(char items[], int limiteInferior, int limiteSuperior){

    char dato[10];
    int opciones;
    printf("%s", items);
    printf("\nElegir: ");
    scanf("%s", dato);

    opciones = validaOpcionesInt(dato, limiteInferior, limiteSuperior);

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



void imprimeProductos(eProducto producto[], int CANTPROD){
    int i;

    for(i=0; i<CANTPROD; i++){
        if(producto[i].estado == 1){
            printf("Codigo: %03d\t", producto[i].codigo);
            printf("Descripcion: %s\t", producto[i].descripcionProd);
            printf("Cant: %04d\t", producto[i].cantidad);
            printf("Precio: %.4f\n\n", producto[i].importe);
        }
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
                        codificacion[j].estado = 1;
                        break;

                    }


                }

                producto[i].estado = 1;

                break;
        }

    }
}



void modificar(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD){

    int i, opciones, codigoInt;
    char auxCodigo[10];

    imprimeProductos(producto, CANTPROD);

    printf("Ingresar codigo del producto a modificar: ");
    scanf("%s", auxCodigo);
    codigoInt = validaOpcionesInt(auxCodigo, 1, CANTPROD);

    system("cls");

    for(i=0; i<CANTPROD; i++){
            if(codigoInt == producto[i].codigo){
                opciones= menu("1- Modificar descripcion producto.\n2- Modificar codigo proveedor.\n3- Modificar Importe.\n4- Modificar cantidades.\n5- Salir.\n", 1, 5);

                system("cls");

                switch(opciones){
                    case 1:
                        printf("Ingrese Descripcion: \n");
                        fflush(stdin);
                        scanf("%[^\n]", producto[i].descripcionProd);


                        break;

                    case 2:

                        printf(" ");

                        break;

                    case 3:
                        printf("Ingrese Precio del producto: \n");
                        scanf("%f", &producto[i].importe);

                        break;

                    case 4:
                        printf("Ingrese Cantidad ingresada del producto: \n");
                        scanf("%d", &producto[i].cantidad);

                        break;

                    case 5:
                        break;
                }

            }
    }


}



void borrarProducto(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD){

    char auxCodigo[10];
    int i, codigoInt;

    imprimeProductos(producto, CANTPROD);

    printf("Elegir Codigo de producto para eliminar: ");
    scanf("%s", auxCodigo);
    codigoInt = validaOpcionesInt(auxCodigo, 1, CANTPROD);

    for(i=0; i<CANTPROD; i++){
        if(producto[i].codigo == codigoInt){
            producto[i].estado = 0;
            break;
        }
    }
    for(i=0; i<100; i++){
            if(codificacion[i].CodProducto == codigoInt){
                codificacion[i].estado = 0;
            }


    }
}



void informaMinMax(eProducto producto[], int CANTPROD){
    int minimo, maximo, i, flag=0;


    for(i=0; i<CANTPROD; i++){

        if(producto[i].estado==1){
            if(flag==0){
                minimo = producto[i].cantidad;
                maximo = producto[i].cantidad;
                flag=1;
            }
            else{

                if(producto[i].cantidad<minimo){
                    minimo = producto[i].cantidad;
                }

                if(producto[i].cantidad>maximo){
                    maximo = producto[i].cantidad;
                }
            }
        }
    }

    printf("Productos con menor stock: \n");
    for(i=0; i<CANTPROD; i++){
        if(producto[i].cantidad==minimo){
            printf("Codigo: %03d\t", producto[i].codigo);
            printf("Descripcion: %s\t", producto[i].descripcionProd);
            printf("Cant: %04d\t", producto[i].cantidad);
            printf("Precio: %.4f\n\n", producto[i].importe);
        }
    }

    printf("Productos con mayor stock: \n");
    for(i=0; i<CANTPROD; i++){
        if(producto[i].cantidad==maximo){
            printf("Codigo: %03d\t", producto[i].codigo);
            printf("Descripcion: %s\t", producto[i].descripcionProd);
            printf("Cant: %04d\t", producto[i].cantidad);
            printf("Precio: %.4f\n\n", producto[i].importe);
        }
    }
}



#endif
