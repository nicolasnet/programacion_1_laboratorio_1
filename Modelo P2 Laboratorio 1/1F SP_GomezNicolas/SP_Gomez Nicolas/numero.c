#ifndef NUMERO_H_INCLUDED
#define NUMERO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "ArrayList.h"
#include "numero.h"


eNumero* numero_new(void)
{
    eNumero* returnAux;

    returnAux = (eNumero*)malloc(sizeof(eNumero));
    if(returnAux !=NULL){
       returnAux->numero= 0;
       strcpy(returnAux->nombre, "sin nombre");
       returnAux->par= 0;
       returnAux->impar= 0;
       returnAux->primo= 0;
    }

    return returnAux;
}


int numero_SetNombre(eNumero* nuevoNumero, char* nombre){
    int returnAux = -1;
    int cant = strlen(nombre);

    if(nuevoNumero != NULL){
        if(cant < CANTCARACTERES){
            strcpy(nuevoNumero->nombre, nombre);
            returnAux = 0;
        }
    }
    return returnAux;
}


int numero_SetNumero(eNumero* nuevoNumero, char* numero){
    int returnAux = -1;
    int nuevoInt;

    if(nuevoNumero != NULL){
        nuevoInt= atoi(numero);
        if(nuevoInt >= 0){
            nuevoNumero->numero = nuevoInt;
            returnAux = 0;
        }
    }
    return returnAux;
}


int numero_SetPar(eNumero* nuevoNumero, char* par){
    int returnAux = -1;
    int nuevoInt;

    if(nuevoNumero != NULL){
        nuevoInt= atoi(par);
        if(nuevoInt == 0 || nuevoInt == 1){
            nuevoNumero->par = nuevoInt;
            returnAux = 0;
        }
    }
    return returnAux;
}


int numero_SetImpar(eNumero* nuevoNumero, char* impar){
    int returnAux = -1;
    int nuevoInt;

    if(nuevoNumero != NULL){
        nuevoInt= atoi(impar);
        if(nuevoInt == 0 || nuevoInt == 1){
            nuevoNumero->impar = nuevoInt;
            returnAux = 0;
        }
    }
    return returnAux;
}


int numero_SetPrimo(eNumero* nuevoNumero, char* primo){
    int returnAux = -1;
    int nuevoInt;

    if(nuevoNumero != NULL){
        nuevoInt= atoi(primo);
        if(nuevoInt == 0 || nuevoInt == 1){
            nuevoNumero->primo = nuevoInt;
            returnAux = 0;
        }
    }
    return returnAux;
}


void numero_CalculaParImpar(eNumero* numero){

    if(numero != NULL){
        if(numero->numero%2 == 0){
            numero->par = 1;
        }
        else{
            numero->impar = 1;
        }
    }

}

void numero_CalculaPrimo(eNumero* numero){
    int i, cant=0;

    if(numero != NULL){
        for(i=1; i < numero->numero+1; i++){
            if(numero->numero%i == 0){
                cant++;
            }
        }

        if(cant == 2){
            numero->primo = 1;
        }
    }
}



#endif

