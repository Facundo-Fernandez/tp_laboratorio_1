#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    float primerOperando;
    float segundoOperando;
    int eleccion;
    printf("tp1_utnCalculator v0.1\nCreator: Facundo Fernandez\n\n");
ingresoDeOperandos:
    utn_getFloat(&primerOperando,"\nIngrese el primer operando: ", "ERROR. La calculadora solo realiza operaciones entre numeros.\n");
    utn_getFloat(&segundoOperando,"Ingrese el segundo operando: ", "ERROR. La calculadora solo realiza operaciones entre numeros.\n");
menuPrincipal:
    printf("\n-------------------------- Menu principal --------------------------");
    printf("\nEl primer operando es: %.2f\nEl segundo operando es: %.2f",primerOperando,segundoOperando);
    printf("\n\nSeleccione la operacion que desea realizar:\n1-Suma\n2-Resta\n3-Multiplicación\n4-División\n5-Factoriales\n\nOperación elegida: ");
    scanf("%d", &eleccion);
    switch (eleccion)
    {
        case 1:
            utn_suma(primerOperando,segundoOperando);
            break;
        case 2:
            utn_resta(primerOperando,segundoOperando);
            break;
        case 3:
            utn_multiplicacion(primerOperando,segundoOperando);
            break;
        case 4:
            utn_division(primerOperando,segundoOperando);
            break;
        case 5:
            utn_calcularFactorial(primerOperando, segundoOperando);
            break;
        default:
            printf("\nERROR. La opcion ingresada no corresponde a una operación valida.\n");
            goto menuPrincipal;
    }
finDeOperacion:
    printf("\n\n¿Desea realizar otra operación?\n1-Si\n2-No\n\nElección: ");
    scanf("%d", &eleccion);
    switch (eleccion)
    {
        case 1:
            goto ingresoDeOperandos;
            break;
        case 2:
            return(0);
            break;
        default:
            printf("\nERROR. La opcion ingresada no corresponde a una operación valida.\n");
            goto finDeOperacion;
    }
}
