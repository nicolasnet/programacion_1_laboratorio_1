#ifndef FUNCIONES_H_INCLUDED  //vincular y evitar duplicacion de las bibliotecas de todo el proyecto.
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED


float suma (float numero1, float numero2)
{
    float resultado;

    resultado=(numero1+numero2);
    return resultado;
}


float resta (float numero1, float numero2)
{
    float resultado;

    resultado=(numero1-numero2);
    return resultado;
}


float multiplicacion (float numero1, float numero2)
{
    float resultado;

    resultado=(numero1*numero2);
    return resultado;
}


float division (float numero1, float numero2)
{
    float resultado;

    resultado= numero1/numero2;
    return resultado;
}


int factorial(int numero)
{
    int resp;

    if(numero==1)
    {
        return 1;
    }

    resp=numero*factorial(numero-1);
    return (resp);
}

