#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANTPROD 5  //cambiar a mil para el ejercicio.


int main()
{
    eProducto producto[CANTPROD];
    eProveedor proveedor[] = { {1,"Proveedor A"}, {2,"Proveedor B"}, {3,"Proveedor C"},{4,"Proveedor D"},{5,"Proveedor E"}, {6,"Proveedor F"},{7,"Proveedor G"},{8,"Proveedor H"},{9,"Proveedor I"},{10,"Proveedor J"}};;
    MixProductoProveedor codificacion [100];

    int flag=0, opciones=0;
    char seguir='s';

    iniciaProducto(producto, CANTPROD);
    iniciaMix(codificacion);

    while(seguir=='s')
    {
        opciones = menu("1- Alta producto.\n2- Modificar producto.\n3- Baja Producto.\n4- Informar.\n5- Listar.\n\n6- Salir.\n", 1, 6);
        //system("pause");
        system("cls");


        switch(opciones)
        {
            case 1: //ALTA
                alta(producto, proveedor, codificacion, CANTPROD);
                flag=1;
                system("cls");
                break;

            case 2: //MODIFICAR
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un producto.\n");
                }
                else{
                    modificar(producto, proveedor, codificacion, CANTPROD);


                }
                system("cls");
                break;
            case 3: //BAJA
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un producto.\n");
                }
                else{

                    borrarProducto(producto, proveedor, codificacion, CANTPROD);


                }
                break;

            case 4: //INFORMAR MIN Y MAX
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un producto.\n");
                }
                else{

                    informaMinMax(producto, CANTPROD);

                }
                break;


            case 5:
                if(flag==0)
                {
                    printf("Se debe dar de alta al menos un producto.\n");
                }
                else{
                        imprimeProductos(producto, CANTPROD);

                    /**/
                }
                break;


            case 6:
                seguir='n';
                break;
        }


    }


    return 0;
}



/*
        Inicializacion proveedores (de manera fija sin hacerle alta para usuario).


eProveedor proveedores[]= { {1,"Proveedor A"}, {2,"Proveedor B"}, {3,"Proveedor C"},{4,"Proveedor D"},{5,"Proveedor E"}, {6,"Proveedor F"},{7,"Proveedor G"},{8,"Proveedor H"},{9,"Proveedor I"},{10,"Proveedor J"}};



//Otra manera de hacerlo

void cargarProveedores(eProveedor proveedores[]); //Prototipo

cargarProveedores(proveedores); //Llamada

void cargarProveedores(eProveedor proveedores[])
{
    int i;

    int idProveedor[]={1,2,3,4,5,6,7,8,9,10};
    char descripcion[][51]={"Proveedor A","Proveedor B","Proveedor C","Proveedor A","Proveedor A","Proveedor A","Proveedor A","Proveedor A","Proveedor A","Proveedor A"};
    int estado[]={1,1,1,1,1,1,1,1,1,1};

     for(i=0; i<10;i++){
        proveedores[i].codigo = idProveedor[i];
        strcpy(proveedores[i].descripcion, descripcion[i]);
        proveedores[i].estado = estado[i];
    }

    return;
}

*/



/*
                Pasar de char a int. USANDO atoi
#include <stdio.h>
#include <stdlib.h>

int main(){
    char dato[15];
    int datoInt;

    printf("Ingrese el dato: ");
    scanf("%s", dato);

    datoInt = atoi(dato); //----> atol(): para pasarlo a long int; atof)(): para pasarlo a float.

    printf("\ndatoInt mas 3: %d", datoInt+3);

    sprintf(dato,"%d",datoInt+5);

    printf("\ndato mas 5: %s", dato);

    return 0;
}

*/



/*
                            VALIDACION de NOMBRES (CHAR) USANDO ISDIGIT (osea busca q no sea numero).

#include <stdio.h>
#include <stdlib.h>

int main(){
    char dato[15];
    int i, flag=0, cant;
    //isalpha
    printf("Ingrese el dato: ");
    scanf("%s", dato);

    cant = strlen(dato);

    for(i=0; i<cant; i++){
        if(!isdigit(dato[i])){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        printf("\nNo es un numero");

    }
    else{
        printf("\nEs un numero");
    }

    return 0;
}

*/
