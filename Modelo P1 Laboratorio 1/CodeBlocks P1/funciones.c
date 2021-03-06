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
        printf("reintente elegir (entre %d y %d): ", limiteInferior, limiteSuperior);
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



float validaFloat(char dato[]){

    float auxFloat;
    int cant, i, flag=0;

    cant = strlen(dato);
    for(i=0; i<cant; i++){
        if(isalpha(dato[i])){
            flag = 1;
            break;
        }
    }
    while(flag==1){
        printf("caracteres numericos unicamente: ");
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

    auxFloat = atof(dato);
    return auxFloat;
}



void validaCadenaDeLetras(char auxDato [], int cantCaracteres){

    int i, cant, flag=0;

    while (flag==0){

        cant = strlen(auxDato);

        for(i=0; i<cant; i++){

            if(!isdigit(auxDato[i])){
                flag=1;
            }
            else{
                flag=0;
                break;
            }
        }

        if(flag==0 || cant>cantCaracteres){

            flag=0;
            printf("Ingrese caracteres alfabetico (maximo:%d ): ", cantCaracteres);
            fflush(stdin);
            scanf("%[^\n]", auxDato);
        }
    }

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
        codificacion[i].CodProveedor = 0;
    }
}



void imprimeProductos(eProducto producto[], int CANTPROD){
    int i;

    for(i=0; i<CANTPROD; i++){
        if(producto[i].estado == 1){
            printf("Codigo: %03d\t", producto[i].codigo);
            printf("Descripcion: % 40s\t", producto[i].descripcionProd); //agregado la cant de espacios para q todas las descripciones queden alineadas
            printf("Cant: %04d\t", producto[i].cantidad);
            printf("Precio: $%.4f\n\n", producto[i].importe);
        }
    }

}



void alta (eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD){
    int i;
    int j;
    char auxDato[CANTCARACTERES*5];

    for (i=0; i<CANTPROD; i++){
        if (producto[i].estado==0){

                producto[i].codigo = i+1;

                printf("Ingrese Descripcion: \n");
                fflush(stdin);
                scanf("%[^\n]", auxDato);
                validaCadenaDeLetras(auxDato, CANTCARACTERES);
                strcpy(producto[i].descripcionProd, auxDato);
                strupr(producto[i].descripcionProd);


                /* para tener todo en minuscula y las primeras d c/nombre en mayuscula
            strlwr(persona[i].nombre);
            persona[i].nombre[0] = toupper(persona[i].nombre[0]);

            for(j=0; j<50; j++)
            {
                if(persona[i].nombre[j] == ' ' && persona[i].nombre[j+1] != ' ')
                {
                     persona[i].nombre[j+1] = toupper(persona[i].nombre[j+1]);
                }
            }


                */


                printf("Ingrese Precio del producto: \n");
                fflush(stdin);
                scanf("%[^\n]", auxDato);
                producto[i].importe = validaFloat(auxDato);



                printf("Ingrese Cantidad ingresada del producto: \n");
                fflush(stdin);
                scanf("%[^\n]", auxDato);
                producto[i].cantidad = validaOpcionesInt(auxDato, 0, 30000);


                for(j=0; j<10; j++){
                        printf("\n%d -- %s\n", proveedor[j].codigo, proveedor[j].descripcionProv);
                }

                for(j=0; j<100; j++){
                    if(codificacion[j].estado == 0){
                        printf("\nIngrese codigo de proveedor: ");
                        fflush(stdin);
                        scanf("%[^\n]", auxDato);
                        codificacion[j].CodProveedor = validaOpcionesInt(auxDato, 1, 10);
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

    int i, j, opciones, codigoInt;
    char auxCodigo[10], auxDato[CANTCARACTERES*5];

    imprimeProductos(producto, CANTPROD);

    printf("Ingresar codigo del producto a modificar: ");
    scanf("%s", auxCodigo);
    codigoInt = validaOpcionesInt(auxCodigo, 1, CANTPROD);

    system("cls");

    for(i=0; i<CANTPROD; i++){
            if(codigoInt == producto[i].codigo){
                opciones = menu("\t\t\tModificacion de datos:\n\n1- Modificar descripcion producto.\n2- Modificar codigo proveedor.\n3- Modificar Importe.\n4- Modificar cantidades.\n5- Salir.\n", 1, 5);

                system("cls");

                switch(opciones){
                    case 1:
                        printf("Ingrese Descripcion: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxDato);
                        validaCadenaDeLetras(auxDato, CANTCARACTERES);
                        strcpy(producto[i].descripcionProd, auxDato);
                        strupr(producto[i].descripcionProd);
                        break;

                    case 2:
                        for(j=0; j<10; j++){
                            printf("\n%d -- %s\n", proveedor[j].codigo, proveedor[j].descripcionProv);
                        }

                        for(j=0; j<100; j++){
                            if(codificacion[j].CodProducto == codigoInt){
                                printf("\nIngrese nuevo codigo de proveedor: ");
                                fflush(stdin);
                                scanf("%[^\n]", auxDato);
                                codificacion[j].CodProveedor = validaOpcionesInt(auxDato, 1, 10);
                                break;

                            }
                        }
                        break;

                    case 3:
                        printf("Ingrese Precio del producto: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxDato);
                        producto[i].importe = validaFloat(auxDato);
                        break;

                    case 4:
                        printf("Ingrese Cantidad ingresada del producto: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxDato);
                        producto[i].cantidad = validaOpcionesInt(auxDato, 0, 30000);
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

    printf("Elegir Codigo de producto para eliminar (con cero sale): ");
    scanf("%s", auxCodigo);
    printf("\n");
    codigoInt = validaOpcionesInt(auxCodigo, 0, CANTPROD);
    if(auxCodigo > 0){

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



void listaOrdenado(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD){
    int i, j, k, flag;



    for(i=9; i>-1; i--){ //proveedores
            flag=0;
        for(j=0; j<100; j++){ //codificacion

            if(proveedor[i].codigo == codificacion[j].CodProveedor){
                if(flag==0){
                        printf("\n-%s: " , proveedor[i].descripcionProv);
                        flag=1;
                }
                for(k=0; k<CANTPROD; k++){ //productos

                    if(codificacion[j].CodProducto == producto[k].codigo && producto[k].estado==1){

                        printf("\n\tCodigo: %03d\t", producto[k].codigo);
                        printf("Cant: %04d\t", producto[k].cantidad);
                        printf("Precio: $%.4f\t", producto[k].importe);
                        printf("Descripcion: %s", producto[k].descripcionProd);
                    }
                }
            }
        }
    }

    printf("\n\n\n");

}


#endif
