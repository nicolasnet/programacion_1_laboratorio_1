#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "ArrayList.h"
#include "numero.h"



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


int validaAlfaNumerico(char *auxDato, int cantCaracteres){
    int cant, returnAux=-1;
    cant = strlen(auxDato);

    if (cant>cantCaracteres){

        returnAux = 0;
    }

    return returnAux;
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












int parserNumeros(FILE* pFile , ArrayList* pArrayListNumeros){
    int returnAux = -1;
    char auxInt[20], auxNombre[CANTCARACTERES], auxPar[20], auxImpar[20], auxPrimo[10];
    eNumero* nuevoNumero;

    if(pFile != NULL && pArrayListNumeros != NULL){
        //printf("\nentro a parsear\n");

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxInt, auxNombre, auxPar, auxImpar, auxPrimo);
        while(!feof(pFile)){
            //printf("\nentro a parsear y while\n");
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxInt, auxNombre, auxPar, auxImpar, auxPrimo);
            //printf("\n%s\n", auxNombre);
            //printf("\n%d\n", atoi(auxInt));
            //break;

            nuevoNumero = numero_new();

            if(nuevoNumero !=NULL){
                //printf("se creo puntero para numero\n");

                numero_SetNumero(nuevoNumero, auxInt);
                numero_SetNombre(nuevoNumero, auxNombre);
                numero_SetPar(nuevoNumero, auxPar);
                numero_SetImpar(nuevoNumero, auxImpar);
                numero_SetPrimo(nuevoNumero, auxPrimo);

                  //printf("%s\n", nuevoNumero->nombre);
                  //printf("%d\n", nuevoNumero->numero);
                  //printf("%d\n", nuevoNumero->par);

                returnAux = pArrayListNumeros->add(pArrayListNumeros, nuevoNumero); //(void*)
                  //printf("\nse agrego a arraylist, %d\n", returnAux);

                //break;
            }
        }
    }

    return returnAux;
}



void informar(ArrayList* this){
    int i, contadorCeros=0, contadorPares=0, contadorImpares=0, contadorPrimos=0;
    eNumero* auxNumero;

    if(this!= NULL){
        for(i=0; i<this->len(this); i++){
            auxNumero = (eNumero*) al_get(this, i);
            if(auxNumero == NULL){
                printf("\nno se obtuvo el puntero\n");
                printf("\n------------------------------\n");
            }
            else{
                if(auxNumero->numero == 0){
                    contadorCeros++;
                }
                if(auxNumero->par == 1){
                    contadorPares++;
                }
                if(auxNumero->impar == 1){
                   contadorImpares++;
                }
                if(auxNumero->primo == 1){
                    contadorPrimos++;
                }
            }
        }
        printf("\nCant Ceros: %d\n", contadorCeros);
        printf("\nCant nros Pares: %d\n", contadorPares);
        printf("\nCant nros Impares: %d\n", contadorImpares);
        printf("\nCant nros Primos: %d\n", contadorPrimos);
    }
}



int comparaNumeros(void* elemento1 , void* elemento2){
    int returnAux;
    eNumero* aux1;
    eNumero* aux2;

    aux1= (eNumero*) elemento1;
    aux2= (eNumero*) elemento2;

    if(aux1->numero > aux2->numero)
    {
        returnAux = 1;
    }
    if(aux1->numero < aux2->numero)
    {
        returnAux = -1;
    }
    if(aux1->numero == aux2->numero){
        returnAux = 0;
    }

    return returnAux;
}



void completarLista(ArrayList* this){
    int i;
    eNumero* auxNumero;


    if(this!= NULL){
        for(i=0; i<this->len(this); i++){
            auxNumero = (eNumero*) al_get(this, i);
            if(auxNumero == NULL){
                printf("\nno se obtuvo el puntero\n");
                printf("\n------------------------------\n");
            }
            else{
                numero_CalculaParImpar(auxNumero);
                numero_CalculaPrimo(auxNumero);
            }
        }
        printf("Lista completada\n\n");
    }
}



void imprimeLista(ArrayList* this){
    int i;
    eNumero* auxNumero;


    printf("\n\n-----------Listado-----------\n\n");


    if(this!= NULL)
        printf("Cantidad de elementos: %d\n", this->size);
        printf("\n------------------------------\n");

    for(i=0; i<this->len(this); i++){
        auxNumero = (eNumero*) al_get(this, i);
        if(auxNumero == NULL){
            printf("\nno llego a auxiliar destinatario\n");
            printf("\n------------------------------\n");
        }
        else{
            printf("\n%d\n", auxNumero->numero);
            printf("\n%s\n", auxNumero->nombre);
            printf("\n%d\n", auxNumero->par);
            printf("\n%d\n", auxNumero->impar);
            printf("\n%d\n", auxNumero->primo);
            printf("\n------------------------------\n");
        }
    }

}




#endif
