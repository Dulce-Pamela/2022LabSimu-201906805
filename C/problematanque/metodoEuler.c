/*
Autor:         Dulce Calan
Fecha:         Tue Jul 19 00:28:08 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o metodoEuler.out metodoEuler.c
Librerias      stdio
Resumen       solucionar el vaciado de un tanque por medio de euler
*/

//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// prototipado de funciones
float df(int A, float k, float h);


//funcion principal del problema
void main(){
// defino las variables inicializo
    int Area =1;
    float k = 0.1, h = 10, t = 0, delta = 0.1;
    //porque necesito trabajar en un archivo, mistras se ejecuta se crea el archivo
    //inicializamos el puntero de archivos y lo abrimos muientras 
    // se ejecuta el programa
    FILE *pf = fopen("altura", "wt");
    //realizar el metodo numerico  mientras hay agua en el tanque
    while (h>=0)
    {
        // validar el valor de la altura del agua cuand han pasado 3 segundos
        // el round redondea mi variable 
        if (round(t)==3.0)
        {
            printf("\n la  altura en %f segundos es de: %f \n",t,h);
    
        }
        //ingreso cada valor obtenido en mi puntero
        fprintf(pf, "%.2f\t%.2f\n",t,h);
        //ejecuto el metodo num[erico
        h+=df(Area,k,h);
        t+=delta;    
    }
    //ingreso el ulStimo valor obtenido en mi puntero
        fprintf(pf, "%.2f\t%.2f\n",t,h);
        //debbo cerrar el archivo
        fclose(pf);
        printf("\n el tiempo cuando la altura es igual a 0 es de: %f \n",t);   
        system("gnuplot grafica.gp");
}
// la funcion derivaada de la altura con respecto del tiempo
float df(int A, float k, float h){
    float rep;
    rep =-(k*sqrt(h))/A;
    return rep;
}