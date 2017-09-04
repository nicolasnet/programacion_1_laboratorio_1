#include <stdio.h>
#include <stdlib.h>

/*int suma(int, int);  //FIRMA de la funcion, PROTOTIPO
//int suma(int num1, int numb2); //tmb se puede poner asi
int main()
{
    int op1, op2, result;

    printf("ingrese operando1: ");
    scanf("%d", &op1);
    printf("ingrese operando2: ");
    scanf("%d", &op2);

    //result= op1+op2;
    result=suma(op1, op2);
    printf("la suma es: %d", result);

    return 0;
}
    int suma(int num1, int num2){
    int resultado;             //CUERPO o DEFINICION---> esta funcion creada va debajo de todo o se agrega a una biblioteca.
    resultado= num1+num2;
    return resultado;
    }*/


  /*  int num1=5;  //variable GLOBAL (cualquier funcion puede acceder a esta variable. tiene prioridad una variable local sobre una global
    int main(){
    int num1=7; //esta es una variable local (guardada en una direccion diferente de la Var. global)
    printf("%d", num1);

    }*/


    //PAGINA 6 GUIA DE EJERCICIOS. FUNCIONES. 1)

    float superficie(float, float);
    float main(){
    float lado1=0, lado2=0, resultado;
	
    while(lado1!=0 && lado2!=0 )
{
	
    printf("ingrese lado1: ");
    scanf("%f", &lado1);
	if(lado1==0){
	continue;
	}


    printf("ingrese lado2: ");
    scanf("%f", &lado2);
	if(lado2==0){
	continue;
	}
    
	

    resultado= superficie(lado1, lado2);
    printf("la superficie es: %f", resultado);

    return 0;
    }
 }

    float superficie(float lado1, float lado2){
    float resultado;
    resultado= lado1*lado2;
    return resultado;

    }


