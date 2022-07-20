/*
Autor:         Dulce Calan
Fecha:         Tue Jul 19 01:13:36 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o metodoTaylor.out metodoTaylor.c -lm
Librerias      stdio math
Resumen       Evaluar la funcion con el metodo de taylor
*/

//librerias
#include <stdio.h>
#include <math.h>

//protipado de funciones
float f(float t, float y);
float df(float t, float y);
float politaylor(float t, float y, float h);
float mtaylor(int a, int b, int n);

void main(){
    int a=0, b=2;
    int n;
    puts("ingrese el numero de iteracioens");
    scanf("%d", &n);
    printf("El valor es de: %f",mtaylor(a,b,n));

}

//funcion
float f(float t, float y){
    float rep=0;
    //pow es potenica de 2
    rep = y -pow(t,2) + 1;
    return rep;
}
//derivada de la funcion
float df(float t, float y){
    float rep=0;
    //pow es potenica de 2
    rep = f(t,y) - 2*t;
    return rep;
}
//el polinomio de taylor
float politaylor(float t, float y, float h){
    float rep=0;
    //pow es potenica de 2
    rep = f(t,y)+h/2*df(t,y);
    return rep;
}

// aplicacion del  metodo de taylor 
float mtaylor(int a, int b, int n){
    // defin las variables iternas o iniciales 
    float h, t, w=0, y;
    // encuentro los altos temporales 
    h=(b-a)/n;
    // inicializo mis variables iniciales
    t=0;
    y=0.5;
    //utilizo el y valuaado por que w es una variable pivote
    w=y;
    //las iteraciones para el metodo de taylor
    for (int i = 0; i < n; i++)
    {
        //actualiza el valor de y valuado
        w+=h*politaylor(t,y,h);
        //incrementa el tiempo
        t+=h;
        //actualiza el valor de  y
        y=w;
        
    }
    return y;
}