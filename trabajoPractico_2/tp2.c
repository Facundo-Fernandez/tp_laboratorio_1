#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utn.h"
#include "tp2.h"

//2.1 initEmployees
void initEmployees(Employee* employeeList, int length)
{
    int i;

    for (i=0;i<length;i++)
    {
        strncpy(employeeList[i].name, "no data", 51);
        strncpy(employeeList[i].lastName, "no data", 51);
        employeeList[i].salary = -1;
        employeeList[i].sector = -1;
        employeeList[i].id = -1;
        employeeList[i].isEmpty = true;
    }
}

//2.2 addEmployees
int nextEmptySlot(Employee* employeeList)
{
    int i;
    int ret = -1;

    for(i=0;i<MAX_EMPLOYEES;i++)
    {
        if(employeeList[i].isEmpty == true)
        {
            ret = i;
            break;
        }

    }
    return (ret);
}

int generateID (void)
{
    static int iD = 0;
    iD++;
    return (iD);
}

int addEmployees (Employee* employeesList, int eLength)
{
    int position = nextEmptySlot(employeesList);
    int i;
    int ret = -1;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    utn_getString(name, 2, "\nIngrese el nombre del empleado: ", "El nombre no es valido.\n", 51);
    utn_getString(lastName, 2, "Ingrese el apellido del empleado: ", "El nombre no es valido.\n", 51);
    utn_getFloat(&salary, 2, "Ingrese el salario bruto del empleado: ", "El salario ingresado no es valido\n", 0, 1000000);
    utn_getInt(&sector, 2, "Ingrese el sector del empleado (100 Sectores en total): ", "El sector ingresado es inexistente\n", 0, 101);

    if(employeesList != NULL && nextEmptySlot(employeesList) != -1)
    {
        for(i=0; i<eLength; i++)
        {
            if(i == position)
            {
                strncpy(employeesList[i].name, name, 51);
                strncpy(employeesList[i].lastName, lastName, 51);
                employeesList[i].salary = salary;
                employeesList[i].sector = sector;
                employeesList[i].id = generateID();
                employeesList[i].isEmpty = false;
                ret = 0;
                break;
            }
        }
    }
    return (ret);
}

//2.3 findEmployeeById
int findEmployeeById(Employee* employeesList, int eLength, int id)
{
    int i;
    int ret = -1;

    if(employeesList != NULL && eLength <= MAX_EMPLOYEES)
    {
        for(i=0;i<eLength; i++)
        {
            if(i == id)
            {
                ret = i;
                break;
            }
        }
    }
    return(ret);
}

//2.4 removeEmployee
int removeEmployee (Employee* employeesList, int eLength)
{
    int i;
    int ret = -1;
    int id;

    utn_getInt(&id,2,"Ingrese el numero de ID del empleado a dar de baja", "El ID ingresado no es valido", 0, MAX_EMPLOYEES+1);
    if(employeesList != NULL && eLength <= MAX_EMPLOYEES)
    {
        for(i=0;i<eLength;i++)
        {
            if(employeesList[i].id == id)
            {
                strncpy(employeesList[i].name, "no data", 51);
                strncpy(employeesList[i].lastName, "no data", 51);
                employeesList[i].sector = -1;
                employeesList[i].salary = -1;
                employeesList[i].isEmpty = true;
                ret = 0;
                break;
            }
        }
    }
    return(ret);
}

//2.5 sortEmployees
int sortEmployees(Employee* employeesList, int eLength)
{
    int i, j;
    float salarioAux;
    char nameAux[51];
    char lastNameAux[51];
    int sectorAux, idAux;
    int isEmptyAux;
    int ret = -1;

    if(employeesList != NULL && eLength <= MAX_EMPLOYEES)
    {
        for(i=0; i<MAX_EMPLOYEES; i++)
        {
            for(j=i+1; j<MAX_EMPLOYEES; j++)
            {
                if(employeesList[i].lastName < employeesList[j].lastName)
                {
                    strcpy(lastNameAux,employeesList[i].lastName);
                    strcpy(employeesList[i].lastName, employeesList[j].lastName);
                    strcpy(employeesList[j].lastName, lastNameAux);

                    strcpy(nameAux,employeesList[i].name);
                    strcpy(employeesList[i].name, employeesList[j].name);
                    strcpy(employeesList[j].name, nameAux);

                    sectorAux = employeesList[i].sector;
                    employeesList[i].sector = employeesList[j].sector;
                    employeesList[j].sector = sectorAux;

                    idAux = employeesList[i].id;
                    employeesList[i].id = employeesList[j].id;
                    employeesList[j].id = idAux;

                    isEmptyAux = employeesList[i].isEmpty;
                    employeesList[i].isEmpty = employeesList[j].isEmpty;
                    employeesList[j].isEmpty = isEmptyAux;

                    salarioAux = employeesList[i].salary;
                    employeesList[i].salary = employeesList[j].salary;
                    employeesList[j].salary = salarioAux;

                    ret = 0;
                }

                if(employeesList[i].lastName == employeesList[j].lastName)
                {
                    if(employeesList[i].sector < employeesList[j].sector)
                    {
                        strcpy(lastNameAux,employeesList[i].lastName);
                        strcpy(employeesList[i].lastName, employeesList[j].lastName);
                        strcpy(employeesList[j].lastName, lastNameAux);

                        strcpy(nameAux,employeesList[i].name);
                        strcpy(employeesList[i].name, employeesList[j].name);
                        strcpy(employeesList[j].name, nameAux);

                        sectorAux = employeesList[i].sector;
                        employeesList[i].sector = employeesList[j].sector;
                        employeesList[j].sector = sectorAux;

                        idAux = employeesList[i].id;
                        employeesList[i].id = employeesList[j].id;
                        employeesList[j].id = idAux;

                        isEmptyAux = employeesList[i].isEmpty;
                        employeesList[i].isEmpty = employeesList[j].isEmpty;
                        employeesList[j].isEmpty = isEmptyAux;

                        salarioAux = employeesList[i].salary;
                        employeesList[i].salary = employeesList[j].salary;
                        employeesList[j].salary = salarioAux;

                        ret = 0;
                    }
                }
            }
        }
    }
    return (ret);
}

//2.6
void printEmployees (Employee* employeesList, int eLength)
{
    int i;

    printf("\nApellido\tNombre\t\tSector\t\tID\t\tSalario\n");
        for(i=0; i < eLength; i++)
        {
            if(employeesList[i].isEmpty == false)
            {
                printf("\n%s\t%s\t\t%d\t\t%d\t\t%.2f", employeesList[i].lastName, employeesList[i].name, employeesList[i].sector, employeesList[i].id, employeesList[i].salary);
            }
        }
}

void modifyEmployeeInfo(Employee* employeesList, int eLength)
{
    int i;
    int idEmpleado;

    utn_getInt(&idEmpleado, 2, "\nIngrese el ID del empleado cuyos datos desea modificar: ", "ID Fuera de rango.", 0, eLength+1);
    for(i=0;i<eLength;i++)
    {
        if(employeesList[i].isEmpty == false && employeesList[i].id == idEmpleado)
           {
                    utn_getString(employeesList[i].name, 2, "Ingrese el nuevo nombre del empleado: ", "El nombre ingresado es invalido\n.", 51);
                    utn_getString(employeesList[i].lastName, 2, "Ingrese el nuevo apellido del empleado: ", "El apellido ingresado es invalido\n.", 51);
                    utn_getInt(&employeesList[i].sector, 2, "Ingrese el nuevo sector del empleado (100 Sectores en total): ", "El sector ingresado es inexistente\n", 0, 101);
                    utn_getFloat(&employeesList[i].salary, 2, "Ingrese el nuevo salario bruto del empleado: ", "El salario ingresado no es valido\n", 0, 1000000);
           }
    }
}

void averageSalary (Employee* employeesList, int eLength)
{
    int i;
    float aux = 0;
    float avgSalary;
    int qty = 0;

    for(i=0;i<eLength;i++)
    {
        if(employeesList[i].isEmpty == false)
        {
            aux = aux + employeesList[i].salary;
            qty++;
        }
    }
    avgSalary = aux / qty;
    printf("\n\nEl salario promedio de los empleados es: %.2f", avgSalary);
}
