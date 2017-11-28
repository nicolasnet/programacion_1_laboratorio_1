#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

#define CANTCLIENTES 5
#define CANTALQUILERES 10
#define CANTCARACTERES 30

#define AMOLADORA 100
#define MEZCLADORA 101
#define TALADRO 102

#define ALQUILADO 1
#define FINALIZADO 2



int main()
{
    eCliente cliente[CANTCLIENTES];
    eAlquiler alquiler[CANTALQUILERES];
    eMixClienteAlquiler codificacion [CANTALQUILERES*CANTCLIENTES];

    int flag=0, opciones=0;
    char seguir='s';

    iniciaAlquileres(alquiler, CANTALQUILERES);
    iniciaClientes(cliente, CANTCLIENTES);
    iniciaCodificacion(codificacion, CANTALQUILERES*CANTCLIENTES);


     while(seguir=='s')
    {
        opciones = menu("\t\t\tMenu Principal\n\n1- Alta de cliente\n2- Modificar datos cliente\n3- Baja del cliente\n4- Nuevo alquiler\n5- Fin de alquiler\n6- Informar\n7- Salir", 1, 7);

        system("cls");


        switch(opciones)
        {
            case 1: //ALTA
                alta(cliente, CANTCLIENTES);
                flag=1;
                system("cls");
                break;

            case 2: //MODIFICAR
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un cliente.\n");
                }
                else{
                    modificar(cliente, CANTCLIENTES);
                    system("cls");

                }
                break;

            case 3: //BAJA
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un cliente.\n");
                }
                else{
                    baja(cliente, CANTCLIENTES);
                }
                break;

            case 4:
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un cliente.\n");
                }
                else{
                    nuevaLLamada(cliente, alquiler, codificacion, CANTALQUILERES, CANTCLIENTES);
                    system("cls");
                }
                break;

            case 5:
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un cliente.\n");
                }
                else{
                    finLLamada(alquiler, cliente, codificacion, CANTCLIENTES, CANTALQUILERES);
                }
                break;

            case 6:
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un cliente.\n");
                }
                else{
                    //imprimeCliente(cliente, CANTCLIENTES);
                    informar(alquiler, cliente, codificacion, CANTCLIENTES, CANTALQUILERES);
                }
                break;

            case 7:
                seguir='n';
                break;
        }
    }

    return 0;
}






