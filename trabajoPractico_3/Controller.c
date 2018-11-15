#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            ret = parser_EmployeeFromText(pArchivo, pArrayListEmployee);
            fclose(pArchivo);
        }
    }
    return (ret);
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "r");
        if(pArchivo != NULL)
        {
            ret = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
            fclose(pArchivo);
        }
    }
    return (ret);
}


/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee* empleado;
    char auxNombre[50];
    int auxHoras;
    int auxSueldos;
    if(pArrayListEmployee != NULL && utn_getString(auxNombre, 3, "Ingrese el nombre del empleado: \n", "El nombre ingresado no es valido.\n", 50) == 0 &&
                                     utn_getInt(&auxHoras, 3, "Ingrese las horas que trabaja el empleado: \n", "Las horas ingresadas no son validas.\n", 0, 500) == 0 &&
                                     utn_getInt(&auxSueldos, 3, "Ingrese el sueldo del empleado: \n", "El sueldo ingresado no es valido.\n", 0, 100000) == 0)
    {
        empleado=Employee_new();
        if(empleado!=NULL && !Employee_setNombre(empleado,auxNombre) &&
                             !Employee_setId(empleado,-1)&& !Employee_setSueldo(empleado,auxSueldos)&&
                             !Employee_setHorasTrabajadas(empleado,auxHoras))
        {
            ret=0;
            ll_add(pArrayListEmployee,empleado);
        }
        else
        {
            Employee_delete(empleado);
            empleado=NULL;
        }
    }
    return ret;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int length;
    int i;
    Employee* empleado;
    char bufferNombre[50];
    int bufferHoras;
    int bufferSueldo;
    int bufferId;
    int auxId;
    if(pArrayListEmployee != NULL && !utn_getInt(&auxId, 3, "Ingrese el ID del empleado a modificar: \n","El ID ingresado no es valido.\n",0,1001))
    {
        length=ll_len(pArrayListEmployee);
        for(i=0;i<length;i++)
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            Employee_getId(empleado,&bufferId);
            if(bufferId==auxId && utn_getString(bufferNombre, 3, "Ingrese el nombre del empleado.\n", "El nombre ingresado no es valido.\n", 50) == 0 &&
                                  utn_getInt(&bufferHoras, 3, "Ingrese las horas que trabaja el empleado.\n", "Las horas ingresadas no son validas.\n", 0, 500) == 0 &&
                                  utn_getInt(&bufferSueldo, 3, "Ingrese el sueldo del empleado.\n", "El sueldo ingresado no es valido.\n", 0, 100000) == 0 &&
                                  !Employee_setNombre(empleado,bufferNombre) &&
                                  !Employee_setSueldo(empleado,bufferSueldo) &&
                                  !Employee_setHorasTrabajadas(empleado,bufferHoras))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int length;
    int i;
    Employee* empleado;
    int bufferId;
    int auxId;
    if(pArrayListEmployee!= NULL && !utn_getInt (&auxId, 3, "Ingrese el ID del empleado a modificar: \n","El ID ingresado no es valido.\n",0,9999))
    {
        length=ll_len(pArrayListEmployee);
        for(i=0; i<length; i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee, i);
            Employee_getId(empleado, &bufferId);
            if(bufferId == auxId)
            {
                ll_remove (pArrayListEmployee, i);
                ret=0;
                break;
            }
        }
    }
    return ret;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int length;
    int i;
    int bufferId;
    int bufferSueldo;
    char bufferNombre[50];
    int bufferHoras;
    Employee* bufferEmployee;
    if(pArrayListEmployee != NULL)
    {
        ret = 0;
        length=ll_len(pArrayListEmployee);
        for(i=0;i<length;i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            Employee_getNombre(bufferEmployee, bufferNombre);
            Employee_getId(bufferEmployee, &bufferId);
            Employee_getSueldo(bufferEmployee, &bufferSueldo);
            Employee_getHorasTrabajadas(bufferEmployee, &bufferHoras);
            printf("Id: %d\nNombre: %s\nHoras trabajadas: %d, Sueldo: %d\n\n", bufferId, bufferNombre, bufferHoras, bufferSueldo);
        }
        getchar();
    }
    return ret;
}

/** \brief Compara dos nombres
 * \param primerNombre
 * \param segundoNombre
 * \return Retorna -1 si primerNombre es mayor, 1 si segundoNombre es mayor y 0 si son iguales.
 *
 */
int controller_compareNames(void* primerNombre, void* segundoNombre)
{
    char auxPrimerNombre[50];
    char auxSegundoNombre[50];
    int ret;

    Employee_getNombre(primerNombre, auxPrimerNombre);
    Employee_getNombre(segundoNombre, auxSegundoNombre);
    if(strcmp(auxPrimerNombre, auxSegundoNombre) < 0)
    {
        ret=-1;
    }
    else if(strcmp(auxPrimerNombre, auxSegundoNombre) > 0)
    {
        ret=1;
    }
    else
    {
        ret=0;
    }
    return (ret);
}

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int method;
    utn_getInt(&method,3,"Para ordenar a los empleados:\nDe la Z a la A presione 0.\nDe la A a la Z presione 1.\n\nElección: ", "El valor ingresado no es valido\n", -1, 2);
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, controller_compareNames, 0+method);
        ret = 0;
    }
    return ret ;
}

/**\brief Guarda el contenido de la LL como texto
 * \param pFile FILE* Puntero al archivo destino
 * \param pArrayListEmployee LinkedList* Puntero a la LL
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_saveLLAsText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int ret=-1;
    int i=0;
    int length;
    int bufferId;
    int bufferSueldo;
    char bufferNombre[50];
    int bufferHoras;
    if(pFile != NULL && pArrayListEmployee!= NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        length = ll_len(pArrayListEmployee);
        do
        {
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            Employee_getNombre(empleado,bufferNombre);
            Employee_getId(empleado,&bufferId);
            Employee_getSueldo(empleado,&bufferSueldo);
            Employee_getHorasTrabajadas(empleado,&bufferHoras);
            fprintf(pFile,"%d,%s,%d,%d\n",bufferId, bufferNombre, bufferHoras, bufferSueldo);
            i++;
        }
        while(i < length);
        if(i == length)
        {
            ret=0;
        }
    }
return ret;
}

/**\brief Guarda el contenido de la LL como binario
 * \param pFile FILE* Puntero al archivo destino
 * \param pArrayListEmployee LinkedList* Puntero a la LL
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int controller_saveLLAsBinary(FILE* pArchivo, LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int ret=-1;
    int i;
    int length= ll_len(pArrayListEmployee);
    if(pArchivo != NULL && pArrayListEmployee!= NULL)
    {
        ret=0;
        for(i=0;i<length;i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            if(empleado!= NULL)
            {
                fwrite(empleado, sizeof(Employee), 1, pArchivo);
            }
        }
        if(i==length)
        {
            ret=0;
        }
    }
    return (ret);
}

/**\brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int ret= -1;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL && controller_saveLLAsText(pArchivo, pArrayListEmployee) == 0)
        {
            fclose(pArchivo);
            printf("El archivo fue guardado exitosamente.\n");
            getchar();
            ret=0;
        }
        else
        {
            printf("ERROR. No se puede abrir el archivo.\n");
        }
    }
    return ret;
}

/**\brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int ret = -1;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo=fopen(path,"wb");
        if(pArchivo != NULL && controller_saveLLAsBinary(pArchivo,pArrayListEmployee) == 0)
        {
            fclose(pArchivo);
            printf("El archivo fue guardado exitosamente.\n");
            getchar();
            ret=0;
        }
        else
        {
            printf("ERROR. No se puede abrir el archivo.\n");
        }
    }
    return ret;
}

