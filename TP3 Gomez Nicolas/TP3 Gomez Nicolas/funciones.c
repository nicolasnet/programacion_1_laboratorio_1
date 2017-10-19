#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"



int validaOpcionesInt(char *dato, int limiteInferior, int limiteSuperior){

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


float validaFloat(char *dato){

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


float validaPuntaje(char *dato, float limiteInferior, float limiteSuperior){

    float auxFloat;
    int cant, i, flag=0;

    cant = strlen(dato);
    for(i=0; i<cant; i++){
        if(isalpha(dato[i])){
            flag = 1;
            break;
        }
    }
    while(flag==1 || atof(dato)>limiteSuperior || atof(dato)<limiteInferior){
        printf("caracteres numericos unicamente(entre %.2f y %.2f): ", limiteInferior, limiteSuperior);
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


void validaCadenaDeLetras(char *auxDato, int cantCaracteres){

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


void validaAlfaNumerico(char *auxDato, int cantCaracteres){
    int cant;
    cant = strlen(auxDato);

    while (cant>cantCaracteres){
        printf("Ingrese caracteres alfanumericos (maximo:%d ): ", cantCaracteres);
        fflush(stdin);
        scanf("%[^\n]", auxDato);
        cant = strlen(auxDato);
    }
}


int menu(char *items, int limiteInferior, int limiteSuperior){

    char dato[10];
    int opciones;
    printf("%s", items);
    printf("\nElegir: ");
    scanf("%s", dato);

    opciones = validaOpcionesInt(dato, limiteInferior, limiteSuperior);

    return opciones;
}




int agregarPelicula(EMovie pelicula, int cantCaracteres, FILE *bin){

    char auxdato[cantCaracteres*5];


    printf("Ingesar titulo de la pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaCadenaDeLetras(auxdato, cantCaracteres);
    strcpy(pelicula.titulo, auxdato);


    printf("Ingresar genero: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaCadenaDeLetras(auxdato, cantCaracteres);
    strcpy(pelicula.genero, auxdato);


    printf("Ingresar duracion en minutos: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    pelicula.duracion = validaOpcionesInt(auxdato, 1, 200);


    printf("Ingesar breve descripcion de la pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaCadenaDeLetras(auxdato, cantCaracteres*2);
    strcpy(pelicula.descripcion, auxdato);


    printf("Ingresar puntaje: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    pelicula.puntaje = validaPuntaje(auxdato, 1, 10);


    printf("Ingesar link de imagen: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    validaAlfaNumerico(auxdato, cantCaracteres*6);
    strcpy(pelicula.linkImagen, auxdato);



    fflush(stdin);
    fseek(bin, 0L, SEEK_END);
    fwrite(&pelicula, sizeof(pelicula), 1, bin);



    return 0;

}
















#endif
