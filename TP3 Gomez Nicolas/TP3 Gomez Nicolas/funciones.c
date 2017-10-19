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


    printf("Ingresar codigo de pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    pelicula.codigo = validaOpcionesInt(auxdato, 1, 9999);


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


void imprimePeliculas(EMovie pelicula, FILE *bin){
    int cant;
    rewind(bin);

    while(!feof(bin)){
        cant = fread(&pelicula,sizeof(pelicula), 1, bin);

        if(cant!=1){
            if(feof(bin)){
                break;
            }
            else{
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(pelicula.codigo != 0)
            printf("\nCodigo: %d\t%s\t%d m.\t%s\t%s\t%.2f\n%s\n\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.descripcion, pelicula.puntaje, pelicula.linkImagen);
    }

}



int borrarPelicula(EMovie pelicula, FILE *bin){
    char auxdato[10], seguir;
    int auxCodigo, cant, flag=0;

    imprimePeliculas(pelicula, bin);

    printf("Ingresar codigo de pelicula a eliminar: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    auxCodigo = validaOpcionesInt(auxdato, 1, 9999);
    system("cls");

    rewind(bin);

    while(!feof(bin)){
        cant = fread(&pelicula,sizeof(pelicula), 1, bin);

        if(cant!=1){
            if(feof(bin)){
                break;
            }
        }

        if(pelicula.codigo == auxCodigo){
            printf("Pelicula encontrada: \n");
            flag=1,
            printf("\nCodigo: %d\t%s\t%d m.\t%s\t%s\t%.2f\n%s\n\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.descripcion, pelicula.puntaje, pelicula.linkImagen);
            printf("Seguro de eliminar esta pelicula? (presionar 's' para confirmar) ");
            seguir = tolower(getche());
            if(seguir == 's'){
                pelicula.codigo = 0;

                fflush(stdin);
                fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                fwrite(&pelicula.codigo, sizeof(pelicula), 1, bin);
            }

        }

    }
    if(flag == 0){
        printf("no se encontro la pelicula.\n\n");
    }


}


void modificaPelicula(EMovie pelicula, int cantCaracteres, FILE *bin){
    char auxdato[10], seguir='s';
    int auxCodigo, cant, flag=0, opcion;

    imprimePeliculas(pelicula, bin);

    printf("Ingresar codigo de pelicula a modificar: \n");
    fflush(stdin);
    scanf("%[^\n]", auxdato);
    auxCodigo = validaOpcionesInt(auxdato, 1, 9999);
    system("cls");

    rewind(bin);

    while(!feof(bin)){
        cant = fread(&pelicula,sizeof(pelicula), 1, bin);
/*
        if(cant!=1){
            if(feof(bin)){
                break;
            }
            else{
                printf("No leyo el ultimo registro");
                break;
            }
        }
*/
        if(pelicula.codigo == auxCodigo){
            printf("Pelicula encontrada: \n");
            flag=1,
            printf("\nCodigo: %d\t%s\t%d m.\t%s\t%s\t%.2f\n%s\n\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.descripcion, pelicula.puntaje, pelicula.linkImagen);

            while(seguir=='s')
            {
                opcion = menu("\t\t\tModificacion de pelicula elegida\n\n1- Titulo\n2- Genero\n3- Duracion\n4- Descripcion\n5- Puntaje\n6- Link de imagen\n7- Salir\n", 1, 7);
                system("cls");

                switch(opcion)
                {
                    case 1:
                        printf("Ingesar titulo de la pelicula: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxdato);
                        validaCadenaDeLetras(auxdato, cantCaracteres);
                        strcpy(pelicula.titulo, auxdato);
                        fflush(stdin);
                        fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                        fwrite(&pelicula.titulo, sizeof(pelicula), 1, bin);
                        break;

                    case 2:
                        printf("Ingresar genero: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxdato);
                        validaCadenaDeLetras(auxdato, cantCaracteres);
                        strcpy(pelicula.genero, auxdato);
                        fflush(stdin);
                        fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                        fwrite(&pelicula.genero, sizeof(pelicula), 1, bin);
                        break;

                    case 3:
                        printf("Ingresar duracion en minutos: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxdato);
                        pelicula.duracion = validaOpcionesInt(auxdato, 1, 200);
                        fflush(stdin);
                        fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                        fwrite(&pelicula.duracion, sizeof(pelicula), 1, bin);
                        break;

                    case 4:
                        printf("Ingesar breve descripcion de la pelicula: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxdato);
                        validaCadenaDeLetras(auxdato, cantCaracteres*2);
                        strcpy(pelicula.descripcion, auxdato);
                        fflush(stdin);
                        fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                        fwrite(&pelicula.descripcion, sizeof(pelicula), 1, bin);
                        break;

                    case 5:
                        printf("Ingresar puntaje: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxdato);
                        pelicula.puntaje = validaPuntaje(auxdato, 1, 10);
                        fflush(stdin);
                        fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                        fwrite(&pelicula.puntaje, sizeof(pelicula), 1, bin);
                        break;

                    case 6:
                        printf("Ingesar link de imagen: \n");
                        fflush(stdin);
                        scanf("%[^\n]", auxdato);
                        validaAlfaNumerico(auxdato, cantCaracteres*6);
                        strcpy(pelicula.linkImagen, auxdato);
                        fflush(stdin);
                        fseek(bin, (long) (-1)*sizeof(pelicula) , SEEK_CUR);
                        fwrite(&pelicula.linkImagen, sizeof(pelicula), 1, bin);
                        break;

                    case 7:
                        seguir = 'n';
                        break;

                }

            }
            break;
        }
    }

    if(flag == 0){
        printf("no se encontro la pelicula.\n\n");
    }
}





#endif
