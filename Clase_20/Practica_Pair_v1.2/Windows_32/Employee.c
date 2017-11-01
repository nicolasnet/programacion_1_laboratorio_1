#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{

}


Employee* employee_new(void)
{
    Employee* returnAux = NULL;
    Employee* returnAux = (Employee*) malloc(sizeof(Employee));

    //if(returnAux == NULL){ como retorna algo, habria q controlar el NULL cuando termina esta funcion.
        //
        //printf("no se pudo dar memoria para la estructura");

    //}

    return returnAux;
}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


