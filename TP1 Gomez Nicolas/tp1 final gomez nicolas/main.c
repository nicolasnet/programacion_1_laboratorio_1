#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{

    float numero1=0, numero2=0, resultado;
    char seguir='s';
    int opcion=0, flag=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (num1=%.2f)\n", numero1);
        printf("2- Ingresar 2do operando (num2=%.2f)\n", numero2);
        printf("3- Calcular la suma (%.2f+%.2f)\n", numero1,numero2);
        printf("4- Calcular la resta (%.2f-%.2f)\n", numero1,numero2);
        printf("5- Calcular la division (%.2f/%.2f)\n", numero1,numero2);
        printf("6- Calcular la multiplicacion (%.2f*%.2f)\n", numero1,numero2);
        printf("7- Calcular el factorial (%.0f!)\n", numero1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);


        system("cls");

        switch(opcion)
        {
            case 1: //se ingresa el primer numero.
                printf("ingrese 1er operando: ");
                scanf("%f", &numero1);
                flag=1;     //la bandera toma valor 1 para que se pueda elegir una operacion luego de dar valor a un operando
                system("cls");
                break;

            case 2: //se ingresa el segundo numero.
                printf("ingrese 2do operando: ");
                scanf("%f", &numero2);
                flag=1;     //la bandera toma valor 1 para que se pueda elegir una operacion luego de dar valor a un operando
                system("cls");
                break;

            case 9: //Sale del while.
                    seguir = 'n';
                    break;
        }

        if(flag==1) //al agregar esta bandera, no esta la opcion de realizar operacion sin ingresar algun operando
        {
            switch(opcion)
            {
                case 3: //SUMA de los numeros.
                    resultado=suma(numero1, numero2);
                    printf("la suma de los numeros es: %.2f\n\n", resultado);
                    break;

                case 4: //RESTA de los numeros.
                    resultado=resta(numero1, numero2);
                    printf("la resta de los numeros es: %.2f\n\n", resultado);
                    break;

                case 5: //DIVISION de los numeros.
                    if(numero2==0)
                    {
                        printf("ERROR, el divisor (numero2) no puede ser 0 (cero)\n\n");
                        break;
                    }
                    else
                    {
                    resultado= division(numero1, numero2);
                    printf("la division de los numeros es: %.4f\n\n", resultado);
                    break;
                    }

                case 6: //MULTIPLICAION de los numeros.
                    resultado=multiplicacion(numero1, numero2);
                    if(resultado== -0)
                    {
                        resultado=0;
                    }
                    printf("la multiplicacion de los numeros es: %.2f\n\n", resultado);
                    break;

                case 7: //FACTORIAL del numero1.
                    if(numero1<=0)
                    {
                        printf("ERROR, factorizar nros naturales distintos de 0 (cero)\n\n");
                        break;
                    }
                    else
                    {
                    resultado=factorial(numero1);
                    printf("El factorial de %.0f es %.0f\n\n",numero1,resultado);
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
                        printf("ERROR, el divisor (numero2) no puede ser 0 (cero)\n");
                    }
                    else
                    {
                    resultado= division(numero1, numero2);
                    printf("la division de los numeros es: %.4f\n", resultado);
                    }

                    //MULTIPLICACION de los numeros.
                    resultado=multiplicacion(numero1, numero2);
                    if(resultado== -0)
                    {
                        resultado=0;
                    }
                    printf("la multiplicacion de los numeros es: %.2f\n", resultado);

                    //FACTORIAL del numero1.
                    if(numero1<=0)
                    {
                        printf("ERROR, factorizar nros naturales distintos de 0 (cero)\n\n");
                    }
                    else
                    {
                    resultado=factorial(numero1);
                    printf("El factorial de %.0f es %.0f\n\n",numero1,resultado);
                    }

                    break;
            }
        }
    }

    return 0;
}

