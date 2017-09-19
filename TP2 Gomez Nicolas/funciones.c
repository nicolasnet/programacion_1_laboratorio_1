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
    printf("elegir: ");
    scanf("%d", &opciones);
    while(opciones<limiteInferior || opciones>limiteSuperior){
        printf("reintente elegir: ");
        scanf("%d", &opciones);
    }
    return opciones;

}


void inicia(EPersona persona[]){
    int i;
    for(i=0; i<20; i++){
        persona[i].estado = 0;
    }

}


void alta(EPersona persona[]){
    int i;

    for(i=0; i<20; i++){
        if (persona[i].estado==0 ){

            printf("ingresar nombre: \n");
            fflush(stdin);
            scanf("%[^\n]", persona[i].nombre);

            printf("ingresar edad: \n");
            scanf("%d", &persona[i].edad);

            printf("ingresar DNI: \n");
            scanf("%d", &persona[i].dni);

            persona[i].estado = 1;

            break;
        }

    }


}












#endif
