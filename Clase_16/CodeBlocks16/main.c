/*
            Punteros con respecto a estructura.

sizeof     ----> tamaño en bytes en memoria.




*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
        /*
        char nombre[51]= "ANDRES";
        mostrarCadena(nombre);
        */

        ePersona per, *ptrPer, Pers[2], *ptrPers; //----> al declarar un puntero solo ocupa el espacio para guardar un direc. de mem. que es 1 byte.
        int i;
        ptrPers = Pers;

        ptrPer = &per; //---> le almacenamos al puntero la direccion de inicio de la estructura.
                    //ptrPer->dni  //la flecha reemplaza el punto para llegar al valor de una variable de la estructura.
                    //ptrPer->fechaNac.dia
/*
        (*ptrPer).dni = 35947729; //igual a ptrPer->dni

        strcpy(ptrPer->nombre, "Nicolas");

        ptrPer->fechaNac.dia = 25;
        ptrPer->fechaNac.mes = 11;
        ptrPer->fechaNac.anio = 1991;


        printf("DNI: %ld \n", per.dni);
        printf("Nombre: %s \n", per.nombre);
        printf("Anio: %d/", per.fechaNac.dia);
        printf("%d/", per.fechaNac.mes);
        printf("%d\n", per.fechaNac.anio);
*/
        for(i=0; i<2; i++){
            printf("Nombre: ");
            fflush(stdin);
            scanf("%[^\n]", ptrPers[i].nombre );

            printf("DNI: ");
            scanf("%ld", &ptrPers[i].dni );

            printf("FECHA NACIMIENTO\n");
            printf("\nDIA: ");
            scanf("%d", &ptrPers[i].fechaNac.dia);

            printf("\nMES: ");
            scanf("%d", &ptrPers[i].fechaNac.mes);

            printf("\nANIO: ");
            scanf("%d", &ptrPers[i].fechaNac.anio);
        }

        for(i=0; i<2; i++){
            printf("Nombre: %s -- DNI: %ld -- FNAc: %d/%d/%d \n", Pers[i].nombre, Pers[i].dni, Pers[i].fechaNac.dia, Pers[i].fechaNac.mes, Pers[i].fechaNac.anio);
        }

        return 0;
}

/*      CODIFICACION DEL PROFESOR:

        typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    long int dni;
    char nombre[31];
    EFecha fechaNac;
}EPersona;

int main()
{
    EPersona per, *ptrPer;

    ptrPer = &per;

    printf("DNI: ");
    scanf("%ld", &per.dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", &per.nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &per.fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &per.fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &per.fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", per.nombre, per.dni, per.fechaNac.dia, per.fechaNac.mes, per.fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA OPERADOR FLECHA:");

    printf("DNI: ");
    scanf("%ld", &ptrPer->dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", ptrPer->nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &ptrPer->fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &ptrPer->fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &ptrPer->fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", ptrPer->nombre, ptrPer->dni, ptrPer->fechaNac.dia, ptrPer->fechaNac.mes, ptrPer->fechaNac.anio);

    printf("\n\nPUNTERO A ESTRUCTURA NOTACION PUNTERO:");

    printf("DNI: ");
    scanf("%ld", &(*ptrPer).dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", (*ptrPer).nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &(*ptrPer).fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &(*ptrPer).fechaNac.mes);

    printf("\nAÑO: ");
    scanf("%d", &(*ptrPer).fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", (*ptrPer).nombre, (*ptrPer).dni, (*ptrPer).fechaNac.dia, (*ptrPer).fechaNac.mes, (*ptrPer).fechaNac.anio);


    //
    printf("\n\nARRAY PUNTERO A ESTRUCTURA:");

    for(i=0; i<2; i++){
        printf("DNI: ");
        scanf("%ld", &(*(ptrPers+i)).dni);

        printf("\nNOMBRE: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", (*(ptrPers+i)).nombre);

        printf("FECHA NACIMIENTO\n");

        printf("\nDIA: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.dia);

        printf("\nMES: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.mes);

        printf("\nAÑO: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.anio);
    }

    for(i=0; i<2; i++){
        printf("%s - %ld - %d/%d/%d", (*(ptrPers+i)).nombre, (*(ptrPers+i)).dni, (*(ptrPers+i)).fechaNac.dia, (*(ptrPers+i)).fechaNac.mes, (*(ptrPers+i)).fechaNac.anio);
    }


    return 0;
*/

