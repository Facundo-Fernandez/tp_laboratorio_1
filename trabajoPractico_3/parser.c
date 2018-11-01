#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/**\brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path FILE* Puntero al archivo que será leido
 * \param pArrayListEmployee LinkedList* Puntero a la LL
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHoras[1024];
    char bufferSueldo[1024];
    int flagOnce = 0;
    Employee* empleados;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        ret=0;
        do
        {
            if(flagOnce == 0)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferHoras, bufferSueldo);
                flagOnce = 1;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferHoras, bufferSueldo);
            empleados = Employee_newConParametros(bufferId, bufferNombre, bufferHoras, bufferSueldo);
            if(empleados != NULL)
            {
                ll_add(pArrayListEmployee, empleados);
            }
            else
            {
                printf("%s,%s,%s,%s\n", bufferId, bufferNombre, bufferHoras, bufferSueldo);
                getchar();
            }
        }while(!feof(pFile));
    }
    return ret;
}

/**\brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path FILE* Puntero al archivo que será leido
 * \param pArrayListEmployee LinkedList* Puntero a la LL
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* pEmpleado;
    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        do
        {
            pEmpleado=Employee_new();
            fread(pEmpleado, sizeof(Employee), 1, pFile);
            if(Employee_validarEmpleado(pEmpleado) == 0)
            {
                ll_add(pArrayListEmployee, pEmpleado);
            }
            else
            {
                Employee_delete(pEmpleado);
            }
        }
        while(!feof(pFile));
        ret=0;
    }
    return ret;
}
