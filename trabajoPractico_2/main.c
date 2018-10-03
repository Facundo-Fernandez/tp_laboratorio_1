#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "tp2.h"

int main()
{
    //Var_init
    int selectedOption;
    int isFirstUse = true;
    static Employee listaDeEmpleados[MAX_EMPLOYEES];


    //Code
    printf("manpowerOrganizer v0.1\n\n");
    initEmployees(listaDeEmpleados, MAX_EMPLOYEES);
    menu:
    printf("\n-------------------------------- Menu principal --------------------------------\n\n");
    printf("Seleccione la opción que desea llevar a cabo:\n\n1) Alta de empleado\n2) Modificar datos de empleado\n3) Baja de empleado\n4) Informar\n\nOpción elegida: ");
    scanf("%d", &selectedOption);
    switch(selectedOption)
    {
    case 1:
        if(isFirstUse == true)
        {
            addEmployees(listaDeEmpleados, MAX_EMPLOYEES);
            isFirstUse = false;
        }
        else
        {
            addEmployees(listaDeEmpleados, MAX_EMPLOYEES);

        }
        break;
    case 2:
        if(isFirstUse == false)
        {
            modifyEmployeeInfo(listaDeEmpleados, MAX_EMPLOYEES);
        }
        else
        {
            printf("\nNo hay empleados cargados para modificar.");
        }
        break;
    case 3:
        if(isFirstUse == false)
        {
            removeEmployee(listaDeEmpleados, MAX_EMPLOYEES);
        }
        else
        {
            printf("\nNo hay empleados cargados para dar de baja.");
        }
        break;
    case 4:
        if(isFirstUse == false)
        {
            sortEmployees(listaDeEmpleados, MAX_EMPLOYEES);
            printEmployees(listaDeEmpleados, MAX_EMPLOYEES);
            averageSalary(listaDeEmpleados, MAX_EMPLOYEES);
        }
        else
        {
            printf("\nNo hay empleados cargados para mostrar.");
        }
        break;
    default:
        printf("\n%d no es una opción valida.\n", selectedOption);
    }
    goto menu;
}
