/*
Autor:         Dulce Calan
Fecha:         Fri Mar 25 12:28:41 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o ejemploredondeodedatos.out ejemploredondeodedatos.c
Librerias      stdio, math
Resumen       Ejemplo simple del redondeo de datos
*/

//librerias
#include <stdio.h>
#include <math.h>

int main(){
    int exp;
    double d;
/* voy a imprimir un valor */
    printf("aprosximacion hacia arriba 3.7:  %f \naproximacion hacia abajo de 3.7: %f \n", ceil(3.7),floor(3.7));
    d = cos(3.7);
    printf("coseno de 3.7 %f",d);
    return 0;
}
