#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

//PROBLEMA CON FLOAT EN LA DIVISION
//DUDA CON LOS ARCHIVOS .c Y .h


int main()
{

    int numero1=0, numero2=0;
    float resultado;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (num1=%d)\n", numero1);
        printf("2- Ingresar 2do operando (num2=%d)\n", numero2);
        printf("3- Calcular la suma (%d+%d)\n", numero1,numero2);
        printf("4- Calcular la resta (%d-%d)\n", numero1,numero2);
        printf("5- Calcular la division (%d/%d)\n", numero1,numero2);
        printf("6- Calcular la multiplicacion (%d*%d)\n", numero1,numero2);
        printf("7- Calcular el factorial (%d!)\n", numero1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: //se ingresa el primer numero.
                printf("ingrese numero1: ");
                scanf("%d", &numero1);
                break;

            case 2: //se ingresa el segundo numero.
                printf("ingrese numero2: ");
                scanf("%d", &numero2);
                break;

            case 3: //SUMA de los numeros.
                resultado=suma(numero1, numero2);
                printf("la suma de los numeros es: %.2f\n", resultado);
                break;

            case 4: //RESTA de los numeros.
                resultado=resta(numero1, numero2);
                printf("la resta de los numeros es: %.2f\n", resultado);
                break;

            case 5: //DIVISION de los numeros.
                if(numero2==0)
                {
                    printf("ERROR, numero2 no puede ser 0 (cero)\n");
                    break;
                }
                else
                {
                resultado= (float) division(numero1, numero2);
                printf("la division de los numeros es: %.2f\n", resultado);
                break;
                }

            case 6: //MULTIPLICAION de los numeros.
                resultado=multiplicacion(numero1, numero2);
                printf("la multiplicacion de los numeros es: %.2f\n", resultado);
                break;

            case 7: //saca factorial del numero1.
                resultado=factorial(numero1);
                printf("El factorial de %d es %.2f\n",numero1,resultado);
                break;

            case 8: //realizar todas las operaciones.

                 //SUMA de los numeros.
                resultado=suma(numero1, numero2);
                printf("la suma de los numeros es: %.2f\n", resultado);

                //RESTA de los numeros.
                resultado=resta(numero1, numero2);
                printf("la resta de los numeros es: %.2f\n", resultado);

                //DIVISION de los numeros.
                if(numero2==0)
                {
                    printf("ERROR, numero2 no puede ser 0 (cero)\n");
                }
                else
                {
                resultado= (float) division(numero1, numero2);
                printf("la division de los numeros es: %.2f\n", resultado);
                }

                //MULTIPLICACION de los numeros.
                resultado=multiplicacion(numero1, numero2);
                printf("la multiplicacion de los numeros es: %.2f\n", resultado);

                break;

            case 9: //Sale del while.
                seguir = 'n';
                break;
        }
    }

    //system("cls");

    return 0;

}
