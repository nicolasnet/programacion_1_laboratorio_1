int suma (int numero1, int numero2)
{
    int resultado;

    resultado=(numero1+numero2);
    return resultado;
}


int resta (int numero1, int numero2)
{
    int resultado;

    resultado=(numero1-numero2);
    return resultado;
}


int multiplicacion (int numero1, int numero2)
{
    int resultado;

    resultado=(numero1*numero2);
    return resultado;
}


int division (int numero1, int numero2)
{
    float resultado;
    resultado= (float) numero1/numero2;
    return resultado;
}


int factorial(int numero)
{
    int resp;

    if(numero==1)
    {
        return 1;
    }

    resp=numero* factorial(numero-1);
    return (resp);
}
