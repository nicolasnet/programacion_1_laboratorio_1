#ifndef DESTINATARIO_H_INCLUDED
#define DESTINATARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "ArrayList.h"
#include "destinatario.h"


eDestinatario* destinatario_new(void)
{
    eDestinatario* returnAux;

    returnAux = (eDestinatario*)malloc(sizeof(eDestinatario));
    if(returnAux !=NULL){
       returnAux->estado = 0;
       strcpy(returnAux->nombre, "sin nombre");
       strcpy(returnAux->email, "sin email");
    }

    return returnAux;
}


int destinatario_SetNombre(eDestinatario* nuevoDestinatario, char* nombre){
    int returnAux = -1;
    int cant = strlen(nombre);

    if(nuevoDestinatario != NULL){
        if(cant < CANTCARACTERES){
            strcpy(nuevoDestinatario->nombre, nombre);
            returnAux = 0;
        }
    }
    return returnAux;
}


int destinatario_SetEmail(eDestinatario* nuevoDestinatario, char* email){
    int returnAux = -1;
    int cant = strlen(email);

    if(nuevoDestinatario != NULL){
        if(cant < CANTCARACTERES*20){
            strcpy(nuevoDestinatario->email, email);
            returnAux = 0;
        }
    }
    return returnAux;
}


int destinatario_SetEstado(eDestinatario* nuevoDestinatario, int estado){
    int returnAux = -1;

    if(nuevoDestinatario != NULL){
        if(estado == 0 || estado == 1){
            nuevoDestinatario->estado = estado;
            returnAux = 0;
        }
    }
    return returnAux;
}
















#endif
