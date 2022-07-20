/*
Autor:         Dulce Calan
Fecha:         Tue Jul 19 10:25:47 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o comparacionMN.out comparacionMN.c
Librerias      stdio
Resumen       una comparacion de los metodos numericos de ruguekuta, euer modificado y heun
*/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototipar funcicones
float f(float t, float y);
float puntomedio(float h, float n);
float eulerMod(float h, int n);
float heun(float h, int n);

void main(){
    int a=0, b=2;
    int n=10;
    float h=(b-a)/n;
    printf("el punto medio: %f \t euler modificado: %f \t heun: %f", puntomedio(h,n),eulerMod(h,n),heun(h,n));


}

//funciones
//la funcion dada
float f(float t, float y){
    float rep=0;
    rep = y -pow(t,2) +1;
    return rep;
}
//metodo numerico de punto medio
float puntomedio(float h, float n){
    float w, t, K1, K2;
    t=0;
    w=0.5;
    for (int i = 0; i < n; i++)
    {
        //primero encontramoslos coeficientes
        K1 = h*f(t,w);
        K2 = h*f(t+h/2,w+K1/2);
        //incrementa el valor de w futuro valuado con w pasado
        w+=K2;
        //incrementa el tiempo
        t+=h;
        
    }
    return w;
}

float eulerMod(float h, int n){
    float w, t, tf;
    t=0;
    w=0.5;
    for (int i = 0; i < n; i++)
    {
        //primero encontramoslos coeficientes
        tf = t + h;
        //incrementa el valor de w futuro valuado con w pasado
        w+=(h/2)*(f(t,w)+f(tf,w+h*f(t,w)));
        //incrementa el tiempo
        t+=tf;
        
    }
    return w;
}

//metodo numerico de huen
float heun(float h, int n){
    float w, t;
    t=0;
    w=0.5;
    for (int i = 0; i < n; i++)
    {

        //incrementa el valor de w futuro valuado con w pasado
         w+=(h/4)*(f(t,w)+3*f(t+2*h/3,w+(2*h/3)*f(t,w)));
        //incrementa el tiempo
        t+=h;
        
    }
    return w;

}

