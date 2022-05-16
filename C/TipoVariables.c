/*
Autor:         Dulce Calan
Fecha:         Sun Apr 17 15:34:52 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o TipoVariables.out TipoVariables.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
//deefinir variables globales
//definir variables
int x;
int y;
char texto;
//definir e inicializar constantes
#define PI 3.1416 // declare e inicialice constante del tipo simbolica aqui no se una ; ni tipo de variabele
const float g = 9.8; //declare e inicialice constante del tipo float

//inicia funcion principall
int main(){
    //las variables locales se definen e inicializan dentro de las funciones 
    float resultado;
    double res = 0.0000253;

    //para inicializar las variables definidas
    x = 2;
    y = 3;

    // para imprimir variables existen diferentes presentaciones de las variables en texto
    //printf("entero: %d, punto flotante: %f, texto: %c, double: %f, doble formato cientifico: %e \n",x,PI,texto,res,res);
    
    //peraciones entre entero y flotante
    //si asigna a una variable del tipo entero 
    resultado = y + PI;
    printf("resultado=y+PI %f \n", resultado);
    
    // operaciones del tipo entero asignando a una variable del tipo float cn resultado entero
    resultado = y + x;
    printf("resultado=y+x %f \n", resultado);

    // operaciones del tipo entero asignando a una variable del tipo float cn resultado float
    //importante hacer la conversion
    resultado = (float) y + x;
    printf("resultado=y+x %f \n", resultado);

    //parciar un resultado, es decir solo quiero ver cuanto me queda que los datos no se me almacennes sino que solo se me muestren
    printf("resultado=y*x %d \n", x*y);
    

    return 0;

}

