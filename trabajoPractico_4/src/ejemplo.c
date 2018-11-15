#include <stdio.h>


struct Conteo{
    int cantidad;
}typedef Conteo;

int main(){

    Conteo conteo = Conteo new();

    conteo->cantidad=2;

    printf(conteo->cantidad);

    delete conteo;

    return 0;


}
