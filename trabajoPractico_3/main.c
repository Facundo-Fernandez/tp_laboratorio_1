#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int selectedOption;
    LinkedList* listaEmpleados = ll_newLinkedList();
menu:
    printf("manPower organizer v0.1");
    printf("\n-------------------------------- Menu principal --------------------------------\n\n");
    printf("Seleccione la opción que desea llevar a cabo:\n\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3) Alta de empleado\n4) Modificar datos de empleado\n5) Baja del empleado\n6) Listar empleados\n7) Ordenar empleados\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10) Salir\n\nOpción elegida: ");
    scanf("%d", &selectedOption);
    switch(selectedOption)
    {
    case 1:
        system("clear");
        if(controller_loadFromText("data.csv", listaEmpleados) == 0)
           {
               printf("Carga completada con exito.\n\n");
           }
           else
           {
               printf("Ha ocurrido un error al cargar los datos.\n\n");
           }
        break;
    case 2:
        system("clear");
        if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
           {
               printf("Carga completada con exito.\n\n");
           }
           else
           {
               printf("Ha ocurrido un error al cargar los datos.\n\n");
           }
        break;
    case 3:
        system("clear");
        controller_addEmployee(listaEmpleados);
        break;
    case 4:
        system("clear");
        controller_editEmployee(listaEmpleados);
        break;
    case 5:
        system("clear");
        controller_removeEmployee(listaEmpleados);
        break;
    case 6:
        system("clear");
        controller_ListEmployee(listaEmpleados);
        break;
    case 7:
        system("clear");
        if(controller_sortEmployee(listaEmpleados) == 0)
        {
            printf("\nLa lista de empleados se ha ordenado de forma exitosa.");
        }
        break;
    case 8:
        system("clear");
        controller_saveAsText("data.cvs", listaEmpleados);
        break;
    case 9:
        system("clear");
        controller_saveAsBinary("data.bin", listaEmpleados);
        break;
    case 10:
        exit(EXIT_SUCCESS);
        break;
    default:
        printf("\n%d no es una opción valida.\n", selectedOption);
    }
finDeOperacion:
    printf("\n¿Desea realizar otra accion?\n1)Si\n2)No\n\nElección: ");
    scanf("%d", &selectedOption);
    switch (selectedOption)
    {
        case 1:
            system("clear");
            goto menu;;
            break;
        case 2:
            return(0);
            break;
        default:
            printf("\nERROR. La opcion ingresada no corresponde a una operación valida.\n");
            goto finDeOperacion;
    }
}
