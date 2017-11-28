#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"




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



int validaLongInt(char dato[], int limiteInferior, long int limiteSuperior){

    long int opciones;
    int cant, i, flag=0;

    cant = strlen(dato);
    for(i=0; i<cant; i++){
        if(isalpha(dato[i])){
            flag = 1;
            break;
        }
    }
    while(flag==1 || atol(dato)>limiteSuperior || atol(dato)<limiteInferior){
        printf("reintente elegir (entre %d y %ld): ", limiteInferior, limiteSuperior);
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

    opciones = atol(dato);
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

void iniciaClientes(eCliente cliente[], int CANTCLIENTES){
    int i;

    for(i=0; i<CANTCLIENTES; i++){
        cliente[i].estado = 0;
    }
}


void iniciaAlquileres(eAlquiler alquilere[], int CANTALQUILERES){
    int i;

    for(i=0; i<CANTALQUILERES; i++){
        alquilere[i].estado = 0;
        alquilere[i].tiempoReal = 0;
    }
}



void iniciaCodificacion(eMixClienteAlquiler codificacion[], int cantidadmix){
    int i;

    for(i=0; i<cantidadmix; i++){
        codificacion[i].estado = 0;
        codificacion[i].CodAlquiler = 0;
        codificacion[i].IDcliente = 0;
    }
}


void imprimeCliente(eCliente cliente[], int CANTCLIENTES){
    int i;


    for(i=0; i<CANTCLIENTES; i++){
        if(cliente[i].estado == 1){
            printf("ID: %04d\t", cliente[i].ID);
            printf("Apellido y Nombre: %s, %s\t", cliente[i].apellido, cliente[i].nombre);
            printf("DNI: %ld\n\n", cliente[i].DNI);
        }
    }
    printf("\n");
}

void imprimeAlquilados(eAlquiler alquiler[], eCliente cliente[],  eMixClienteAlquiler codificacion[], int CANTCLIENTES, int CANTALQUILERES){
    int i, j;
    for(i=0; i<CANTALQUILERES; i++){
        if(alquiler[i].estado == 1){
            printf("\nCodigo Alquiler: %04d\t", alquiler[i].codigo);
            printf("Equipo alquilado: %d\t", alquiler[i].equipo);
            printf("Operador: %d\t", alquiler[i].operadorID);
            //printf("Estado: %d\t", alquiler[i].estado);

            for(j=0; j<(CANTALQUILERES*CANTCLIENTES); j++){
                if(alquiler[i].codigo == codificacion[j].CodAlquiler){
                    printf("Codigo Cliente: %d\n", codificacion[j].IDcliente);
                }
            }

        }
    }
    printf("\n");


}

void alta(eCliente cliente[], int CANTCLIENTES){
    int i;
    char auxDato[CANTCARACTERES*5];


    for(i=0; i<CANTCLIENTES; i++){
        if(cliente[i].estado == 0){

                cliente[i].ID = i+1;

                printf("Ingrese Nombre: ");
                fflush(stdin);
                scanf("%[^\n]", auxDato);
                validaCadenaDeLetras(auxDato, CANTCARACTERES);
                strcpy(cliente[i].nombre, auxDato);


                printf("Ingrese Apellido: ");
                fflush(stdin);
                scanf("%[^\n]", auxDato);
                validaCadenaDeLetras(auxDato, CANTCARACTERES);
                strcpy(cliente[i].apellido, auxDato);
                strupr(cliente[i].apellido);

                printf("Ingrese DNI: ");
                fflush(stdin);
                scanf("%[^\n]", auxDato);
                cliente[i].DNI = validaLongInt(auxDato, 1, 99999999);

                cliente[i].estado = 1;

                break;
        }
    }
}

void modificar(eCliente cliente[], int CANTCLIENTES){
    int i, opciones, codigoInt;
    char auxCodigo[10], auxDato[CANTCARACTERES*5];

    imprimeCliente(cliente, CANTCLIENTES);

    printf("Ingresar ID del cliente a modificar: ");
    scanf("%s", auxCodigo);
    codigoInt = validaOpcionesInt(auxCodigo, 1, CANTCLIENTES);

    system("cls");

    for(i=0; i<CANTCLIENTES; i++){
            if(codigoInt == cliente[i].ID){
                opciones = menu("\t\t\tModificacion de datos:\n\n1- Modificar nombre cliente.\n2- Modificar apellido cliente.\n3- Salir.\n", 1, 3);

                system("cls");

                switch(opciones){
                    case 1:
                        printf("Ingrese Nombre: ");
                        fflush(stdin);
                        scanf("%[^\n]", auxDato);
                        validaCadenaDeLetras(auxDato, CANTCARACTERES);
                        strcpy(cliente[i].nombre, auxDato);
                        break;


                    case 2:
                        printf("Ingrese Apellido: ");
                        fflush(stdin);
                        scanf("%[^\n]", auxDato);
                        validaCadenaDeLetras(auxDato, CANTCARACTERES);
                        strcpy(cliente[i].apellido, auxDato);
                        strupr(cliente[i].apellido);
                        break;

                    case 3:
                        break;
                }
            }
    }
}


void baja(eCliente cliente [], int CANTCLIENTES){
    char auxCodigo[10];
    int i, codigoInt;

    imprimeCliente(cliente, CANTCLIENTES);

    printf("Elegir ID de cliente para eliminar (con cero sale): ");
    scanf("%s", auxCodigo);
    printf("\n");
    codigoInt = validaOpcionesInt(auxCodigo, 0, CANTCLIENTES);
    if(codigoInt > 0){

        for(i=0; i<CANTCLIENTES; i++){
            if(cliente[i].ID == codigoInt){
                cliente[i].estado = 0;
                break;
            }
        }
    }
}


void nuevaLLamada(eCliente cliente[], eAlquiler alquiler[], eMixClienteAlquiler codificacion[], int CANTALQUILERES, int CANTCLIENTES){
    int i, j;
    char auxCodigo[10];


    for(i=0; i<CANTALQUILERES; i++){
            if(alquiler[i].estado==0){

                alquiler[i].codigo = i+1;

                for(j=0; j<CANTALQUILERES*CANTCLIENTES; j++){


                    if(codificacion[j].estado == 0){
                        imprimeCliente(cliente, CANTCLIENTES);

                        printf("Ingresar ID del cliente: \n");
                        scanf("%s", auxCodigo);
                        codificacion[j].IDcliente = validaOpcionesInt(auxCodigo, 1, CANTCLIENTES);
                        codificacion[j].CodAlquiler = alquiler[i].codigo;
                        codificacion[j].estado = 1;

                        break;
                    }
                }

                printf("100- AMOLADORA\t");
                printf("101- MEZCLADORA\t");
                printf("102- TALADRO\n");
                printf("Ingresar codigo de equipo: \n");
                scanf("%s", auxCodigo);
                alquiler[i].equipo = validaOpcionesInt(auxCodigo, 100, 102);


                printf("Tiempo estimado de alquiler en dias enteros (maximo 360 dias): \n");
                scanf("%s", auxCodigo);
                alquiler[i].tiempoEstimado = validaOpcionesInt(auxCodigo, 1, 360);


                printf("1- Operador 1\t");
                printf("2- Operador 2\t");
                printf("3- Operador 3\n");
                printf("Ingresar codigo del operador: \n");
                scanf("%s", auxCodigo);
                alquiler[i].operadorID = validaOpcionesInt(auxCodigo, 1, 3);

                alquiler[i].estado = 1;

                break;
            }

    }
}



void finLLamada(eAlquiler alquiler[], eCliente cliente[],  eMixClienteAlquiler codificacion[], int CANTCLIENTES, int CANTALQUILERES){
    char auxCodigo[10];
    int i, codigoInt;

    //imprimeCliente(cliente, CANTCLIENTES);
    imprimeAlquilados(alquiler, cliente, codificacion, CANTCLIENTES, CANTALQUILERES);

    printf("Elegir codigo de alquiler para dar por finalizado (con cero sale): ");
    scanf("%s", auxCodigo);
    printf("\n");
    codigoInt = validaOpcionesInt(auxCodigo, 0, CANTALQUILERES);
    if(codigoInt > 0){

        for(i=0; i<CANTALQUILERES; i++){
            if(alquiler[i].codigo == codigoInt){

                alquiler[i].estado = 2;

                printf("Tiempo REAL de alquiler en dias enteros (maximo 360 dias): \n");
                scanf("%s", auxCodigo);
                alquiler[i].tiempoReal = validaOpcionesInt(auxCodigo, 1, 360);

            }
        }
    }
}




void informar(eAlquiler alquiler[], eCliente cliente[],  eMixClienteAlquiler codificacion[], int CANTCLIENTES, int CANTALQUILERES){
    int i, contador100=0, contador101=0, contador102=0, mayor;
    int sumaTiemposReales100=0, sumaTiemposReales101=0, sumaTiemposReales102=0;
    float promedio100, promedio101, promedio102;


    for(i=0; i<CANTALQUILERES; i++){
            if(alquiler[i].estado == 2 && alquiler[i].equipo == 100){
                contador100++;
                sumaTiemposReales100=sumaTiemposReales100 + alquiler[i].tiempoReal;
            }
            if(alquiler[i].estado == 2 && alquiler[i].equipo == 101){
                contador101++;
                sumaTiemposReales101=sumaTiemposReales101 + alquiler[i].tiempoReal;
            }
            if(alquiler[i].estado == 2 && alquiler[i].equipo == 102){
                contador102++;
                sumaTiemposReales102=sumaTiemposReales102 + alquiler[i].tiempoReal;
            }
    }
    promedio100 = (float) sumaTiemposReales100/contador100;
    printf("\nPromedio de tiempos reales Amoladora: %f\n", promedio100);
    promedio101 = (float) sumaTiemposReales101/contador101;
    printf("\nPromedio de tiempos reales Mezcladora: %f\n", promedio101);
    promedio102 = (float) sumaTiemposReales102/contador102;
    printf("\nPromedio de tiempos reales Taladro: %f\n", promedio102);



     if(contador100 >= contador101 && contador100 >= contador102)
        {
            mayor = contador100;
        }
        else
        {
            if(contador101 >= contador100 && contador101 >= contador102)
            {
                mayor = contador101;
            }
            else
            {
                mayor = contador102;
            }
        }

        if(mayor == contador100){
            printf("\nEquipo mas usado: amoladora\n");
        }
        if (mayor == contador101){
            printf("\nEquipo mas usado: mezcladora\n");
        }
        if (mayor == contador102){
            printf("\nEquipo mas usado: taladro\n");
        }

}

#endif
