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
            scanf("%ld", &persona[i].dni);

            persona[i].estado = 1;

            break;
        }

    }


}


void listar(EPersona persona[], int CANT){
    int i;

    for(i=0; i<CANT; i++){

        if(persona[i].estado == 1)
        {
        printf("%s", persona[i].nombre);
        printf("%d", persona[i].edad);
        printf("%ld", persona[i].dni);
        }
    }

}



void ordenar(EPersona persona[], int CANT){
    int i, j;
    EPersona auxiliar;

    for(i=0; i<CANT; i++){
        for(j=i+1; j<CANT; j++){
            if(strcmp(persona[i].nombre, persona[j].nombre)>0){
                //- hacer codigo q reemplaza y ordena.
                //- cuando reemplazamos para ordenar, usamos el = ya q reemplazamos toda la estructura NO HACERLO CAMPO X CAMPO
                    persona[i] = auxiliar;
                    persona[j] = persona[i];
                    auxiliar = persona[j];
            }

        }
    }
    listar(EPersona persona[], int CANT);
    }


//hacer funcion q imprime





#endif
