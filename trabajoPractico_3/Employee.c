#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=Employee_new();

    if(!Employee_setId(this,atoi(id))&&
       !Employee_setNombre(this,nombre)&&
       !Employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
       !Employee_setSueldo(this,atoi(sueldo)))
    {
        return this;
    }
    Employee_delete(this);
    return NULL;
}

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/**\brief Valida un nombre para guardar en el campo nombre
 * \param nombre Cadena de texto a analizar
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
static int isValidNombre(char* nombre)
{
    int ret = -1;
    if(nombre!= NULL && strlen(nombre)<50 && strlen(nombre)>1)
    {
        ret = 0;
    }
    return ret;
}

/**\brief Valida una hora valida
 * \param horas Numero a analizar
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */

static int isValidHoras(int horas)
{
    int ret = -1;
    if(horas>0)
    {
        ret = 0;
    }
    return ret;
}

/**\brief Valida un id valido
 * \param id Numero a analizar
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
static int isValidId(int id)
{
    int ret = -1;
    if(id > -2)
    {
        ret = 0;
    }
    return ret;
}

/**\brief Valida un sueldo valido
 * \param sueldo numero a analizar
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
static int isValidSueldo(int sueldo)
{
    int ret = -1;
    if(sueldo>0)
    {
        ret = 0;
    }
    return ret;
}

/**\brief Valida que una estructura Employee tenga datos validos
 * \param pEmpleado Employee* puntero a la estructura
 * \return Retorna 0 si la operación concluyó correctamente, caso contrario denota -1
 */
int Employee_validarEmpleado(Employee* pEmpleado)
{
    int ret=-1;
    if(isValidId(pEmpleado->id) == 0 &&
       isValidNombre(pEmpleado->nombre) == 0 &&
       isValidHoras(pEmpleado->horasTrabajadas) == 0 &&
       isValidSueldo(pEmpleado->sueldo) == 0)
    {
        ret = 0;
    }
    return ret;
}
