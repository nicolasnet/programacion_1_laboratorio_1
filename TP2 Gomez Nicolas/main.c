#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANT 20


int main()
{
    EPersona persona[CANT];
    char seguir='s';
    int opciones=0;

    int menores18=0;
    int entre18y35=0;
    int mayores35=0;


    //crear contadores para los parametros de edad, y usarlos como bandera para q no puedan usar las opciones 2,3,4 si no hay datos cargado
    /*ejemplo q se me ocurrio   if(hasta18==0 && entre18y35==0 && mayor35==0){
                                        no hacer nada;
                                        }else
                                        {
                                        habilitar la opcion de las demas opciones (ver tp1 q hice algo similar)
                                        {
    */
    inicia(persona);

    while(seguir=='s')
    {

       opciones = menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n\n", 1, 5);
       system("cls");


        switch(opciones)
        {
            case 1:
                alta(persona, menores18, entre18y35, mayores35);
                system("cls");

                break;

            case 2:
                //borrar(persona); //hacer esta funcion donde cambias la bandera ESTADO a cero para q se pueda sobreescribir
                borrar(persona, CANT);
                break;

            case 3://una funcion que ordene otra que liste.
                ordenar(persona, CANT);
                listar(persona, CANT);

                break;

            case 4:/*hacer grafico de barras
                contadores para contar <18, entre 18 y 35 y >35; y sacar cual es el mayor
                 usar \t   para tabular y dar efecto de grafico.

                graficar(int menor18; int entre18y35; int mayor35);


                 */

                 break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
