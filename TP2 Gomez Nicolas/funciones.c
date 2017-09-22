#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"



int menu(char items[]){

    int opciones;
    char aux;

    printf("%s", items);
    printf("Elegir: ");
    fflush(stdin);
    scanf("%c", &aux);

    while(!(isdigit(aux)))
    {
            printf("digite un numero: ");
            fflush(stdin);
            scanf("%c", &aux);

    }
    opciones=(int) (aux-48);

    return opciones;
}



void inicia(EPersona persona[]){
    int i;
    for(i=0; i<20; i++){
        persona[i].estado = 0;
    }
}



void alta(EPersona persona[]){
    int i, j;
    char auxNombre[150];

    for(i=0; i<20; i++){


        if (persona[i].estado==0 )
        {
            //NOMBRE
            printf("ingresar nombre: \n");
            fflush(stdin);
            scanf("%[^\n]", auxNombre);
            while(strlen(auxNombre)>49 || strlen(auxNombre)<2)
            {
                printf("entre 2 y 50 caracteres: ");
                fflush(stdin);
                scanf("%[^\n]", auxNombre);
            }
            strcpy(persona[i].nombre, auxNombre);

            strlwr(persona[i].nombre);
            persona[i].nombre[0] = toupper(persona[i].nombre[0]);

            for(j=0; j<50; j++)
            {
                if(persona[i].nombre[j] == ' ' && persona[i].nombre[j+1] != ' ')
                {
                     persona[i].nombre[j+1] = toupper(persona[i].nombre[j+1]);
                }
            }

            //EDAD
            printf("ingresar edad: \n");
            scanf("%d", &persona[i].edad);
            while(persona[i].edad <1 || persona[i].edad>100)
            {
                scanf("%d", &persona[i].edad);
            }

            //DNI
            printf("ingresar DNI: \n");
            scanf("%ld", &persona[i].dni);
            while(persona[i].dni<0 || persona[i].dni>99999999 )
            {
                scanf("%ld", &persona[i].dni);
            }

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

                auxiliar = persona[i];
                persona[i] = persona[j];
                persona[j] = auxiliar;
            }

        }
    }

    }



void listar(EPersona persona[], int CANT){
    int i, flag=0;

    printf("Listado de personas ingresadas:\n\n");
    for(i=0; i<CANT; i++){

        if(persona[i].estado == 1)
        {
        printf("%s   ", persona[i].nombre);
        printf("Edad: %d   ", persona[i].edad);
        printf("DNI: %ld\n", persona[i].dni);
        flag=1;
        }
    }
    if(flag==0){
        printf("No hay datos de personas cargadas.\n");
    }
    printf("\n\n");

}



void graficar(EPersona persona[],int CANT){

    int menores18=0;
    int entre18y35=0;//incluye 18 y 35 años
    int mayores35=0;
    int i, mayor, flag=0;

    for(i=0; i<CANT; i++){
        if(persona[i].estado==1)
        {
            if(persona[i].edad<18){
                menores18++;
            }
            else
            {
                if(persona[i].edad<36){
                        entre18y35++;

                }
                else
                {
                    mayores35++;
                }
            }
        }
    }

    if(menores18 >= entre18y35 && menores18 >= mayores35)
        {
            mayor = menores18;
        }
        else
        {
            if(entre18y35 >= menores18 && entre18y35 >= mayores35)
            {
                mayor = entre18y35;
            }
            else
            {
                mayor = mayores35;
            }
        }

    printf("Cant.\n");
    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

        if(i<= menores18)
        {
            printf("*");
        }

        if(i<= entre18y35)
        {
            flag=1;
            printf("\t *");
        }

        if(i<= mayores35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }

            if(flag==1)
            {
                printf("\t*");
            }
        }

        printf("\n");
    }

    printf("--+---------------------");
    printf("\n  |<18\t19-35\t>35\tRangos");
    printf("\n   %d\t%d\t%d\n\n", menores18, entre18y35, mayores35);

}



#endif
