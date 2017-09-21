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


void alta(EPersona persona[], int menores18, int entre18y35, int mayores35){
    int i;

    for(i=0; i<20; i++){
        if (persona[i].estado==0 ){

            printf("ingresar nombre: \n");
            fflush(stdin);
            scanf("%[^\n]", persona[i].nombre);

            printf("ingresar edad: \n");
            scanf("%d", &persona[i].edad);
            if(persona[i].edad<18){
                menores18++;
            }

            printf("ingresar DNI: \n");
            scanf("%ld", &persona[i].dni);

            persona[i].estado = 1;

            break;
        }

    }

}



void borrar(EPersona persona[], int CANT){

    long int dni;
    int i;
    char seguir;

    printf("Ingrese el dni a eliminar de la base de datos: ");
    scanf("%ld", &dni);

    for(i=0; i<CANT; i++){
        if(persona[i].estado == 1){

                if (dni == persona[i].dni){
                    printf("presione 's' para confimar eliminacion de: %s, o 'n' para cancelar\n", persona[i].nombre);
                    seguir = getch();
                    if(seguir == 's'){
                        persona[i].estado = 0;

                    }
                    else{
                        break;
                    }

                }
        }
    }
}






void ordenar(EPersona persona[], int CANT){
    int i, j;
    EPersona auxiliar;

    for(i=0; i<CANT; i++){
        for(j=i+1; j<CANT; j++){
            if(strcmp(persona[i].nombre, persona[j].nombre)>0){

                persona[i] = auxiliar;
                persona[j] = persona[i];
                auxiliar = persona[j];
            }

        }
    }

    }



void listar(EPersona persona[], int CANT){
    int i;

    for(i=0; i<CANT; i++){

        if(persona[i].estado == 1)
        {
        printf("%s   ", persona[i].nombre);
        printf("%d   ", persona[i].edad);
        printf("%ld\n", persona[i].dni);
        }
    }


}





#endif
