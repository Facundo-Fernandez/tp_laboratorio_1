#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

/**
*@brief Solicita al usuario un numero y lo valida mediante un mensaje definido por parametros, en caso de ser incorrecto muestra un mensaje de error tambien definido por parametros.
*@param *pFloat Contiene la direccion de memoria del valor ingresado.
*@param msg Es el mensaje que solicita que el usuario ingrese un valor.
*@param errorMsg Es el mensaje que indica que se cometió un error al ingresar el valor.
*@return Si el numero es validado retorna 0.
*/
int utn_getFloat (float *pFloat, char msg[], char errorMsg[])
{
    float auxNumber;
    int ret = -1;
ingresoDeOperando:
    printf("%s",msg);
    if(scanf("%f", &auxNumber) == 1)
    {
        *pFloat = auxNumber;
        ret = 0;
    }
    else
    {
        printf("%s", errorMsg);
        __fpurge(stdin);
        goto ingresoDeOperando;
    }
    return(ret);
}

/**
*@brief Suma dos operandos y los muestra mediante un printf.
*@param primerOperando Es el primer operando que se ingresó.
*@param segundoOperando Es el segundo operando que se ingresó.
*/
void utn_suma(float primerOperando, float segundoOperando)
{
    float resultado;
    resultado = primerOperando + segundoOperando;
    printf("\nEl resultado de %.3f + %.3f es %.3f",primerOperando, segundoOperando, resultado);
}

/**
*@brief Resta dos operandos y los muestra mediante un printf.
*@param primerOperando Es el primer operando que se ingresó.
*@param segundoOperando Es el segundo operando que se ingresó.
*/
void utn_resta(float primerOperando, float segundoOperando)
{
    float resultado;
    resultado = primerOperando - segundoOperando;
    printf("\nEl resultado de %.3f - %.3f es %.3f",primerOperando, segundoOperando, resultado);
}

/**
*@brief Multiplica dos operandos y los muestra mediante un printf.
*@param primerOperando Es el primer operando que se ingresó.
*@param segundoOperando Es el segundo operando que se ingresó.
*/
void utn_multiplicacion(float primerOperando, float segundoOperando)
{
    float resultado;
    resultado = primerOperando * segundoOperando;
    printf("\nEl resultado de %.3f x %.3f es %.3f",primerOperando, segundoOperando, resultado);
}

/**
*@brief Divide dos operandos y los muestra mediante un printf, muestra un mensaje de error si se intenta dividir por 0.
*@param primerOperando Es el primer operando que se ingresó.
*@param segundoOperando Es el segundo operando que se ingresó.
*/
void utn_division(float primerOperando, float segundoOperando)
{
    float resultado;
    if(segundoOperando == 0)
        {
            printf("\nError matemático. No se pueden dividir por 0");
        }
        else
        {
            resultado = primerOperando / segundoOperando;
            printf("\nEl resultado de %.3f / %.3f es %.3f",primerOperando, segundoOperando, resultado);
        }
}

/**
*@brief Recibe un numero y calcula el factorial del mismo, para numeros negativos denota un mensaje de error y el resultado toma el valor -1.
*@param number Es el operando al en el cual se llevará a cabo la operación.
*@return Retorna el factorial del numero ingresado.
*/
float utn_factorial(float number)
{
    float i;
    float result = 1;
    if(number >= 0)
    {
        for(i=1;i <= number;i++)
        {
            result = result * i;
        }
    }
    else
    {
        printf ("ERROR. No existe el factorial de un numero negativo.\n");
        result = -1;
    }
    return(result);
}

/**
*@brief Calcula los factoriales de dos operandos.
*@param primerOperando Es el primer operando que se ingresó.
*@param segundoOperando Es el segundo operando que se ingresó.
*/
void utn_calcularFactorial(float primerOperando, float segundoOperando)
{
    float resultPrimerOperando;
    float resultSegundoOperando;
    resultPrimerOperando = utn_factorial(primerOperando);
    resultSegundoOperando = utn_factorial(segundoOperando);
    printf("El factorial del primer operando es: %.0f\nEl factorial del segundo operando es: %.0f\n", resultPrimerOperando, resultSegundoOperando);
}
