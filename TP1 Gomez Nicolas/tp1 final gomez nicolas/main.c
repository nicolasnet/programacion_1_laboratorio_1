#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"


//revisar el .h q aparece en el esqueleto, el bloque de codigo q aparece sirve para q no salte error en caso de incluir
//bibliotecas en los otros archivos .c del proyecto,

//cambiar todos los int por float para poder hacer operaciones con los numeros reales

int main()
{

    float numero1=0, numero2=0, resultado;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (num1=%.2f)\n", numero1);
        printf("2- Ingresar 2do operando (num2=%.2f)\n", numero2);
        printf("3- Calcular la suma (%.2f+%.2f)\n", numero1,numero2);
        printf("4- Calcular la resta (%.2f-%.2f)\n", numero1,numero2);
        printf("5- Calcular la division (%.2f/%.2f)\n", numero1,numero2);
        printf("6- Calcular la multiplicacion (%.2f*%.2f)\n", numero1,numero2);
        printf("7- Calcular el factorial (%d!)\n", numero1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1: //se ingresa el primer numero.
                printf("ingrese numero1: ");
                scanf("%.2f", &numero1);
                break;

            case 2: //se ingresa el segundo numero.
                printf("ingrese numero2: ");
                scanf("%.2f", &numero2);
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
                resultado= division(numero1, numero2);
                printf("la division de los numeros es: %.4f\n", resultado);
                break;
                }

            case 6: //MULTIPLICAION de los numeros.
                resultado=multiplicacion(numero1, numero2);
                printf("la multiplicacion de los numeros es: %.2f\n", resultado);
                break;

            case 7: //saca factorial del numero1.
                if(numero1==0)
                {
                    printf("ERROR, ingresar nros naturales distintos de 0 (cero)");
                    break;
                }
                else
                {
                resultado=factorial(numero1);
                printf("El factorial de %d es %.0f\n",numero1,resultado);
                break;
                }
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
                resultado= division(numero1, numero2);
                printf("la division de los numeros es: %.2f\n", resultado);
                }

                //MULTIPLICACION de los numeros.
                resultado=multiplicacion(numero1, numero2);
                printf("la multiplicacion de los numeros es: %.2f\n", resultado);

                //saca factorial del numero1.
                if(numero1==0)
                {
                    printf("ERROR, ingresar nros naturales distintos de 0 (cero)");
                }
                else
                {
                resultado=factorial(numero1);
                printf("El factorial de %d es %.0f\n",numero1,resultado);
                }


                break;

            case 9: //Sale del while.
                seguir = 'n';
                break;
        }
    }

    //system("cls");

    return 0;

}

