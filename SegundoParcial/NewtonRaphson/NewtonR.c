/*
Autor:         Dulce Calan
Fecha:         Wed May 25 12:08:17 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilar       gcc -o NewtonR.out NewtonR.c -lm
Librerias      stdio
Resumen       Metodo de Newton Raphson para la fincion de seno
*/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Prototipamos las funciones a utilizar
// funcion principal
float f(float x);
// derivada de la funcion
float df(float x);
// Se define el metodo de Newton Raphson
// esta funcion utilizara las variables 
// x i nicial, tolerancia, iteracion maxima, iteracion actual, y valor anterior v0
void NewtonR(float x_0, float T, int Imax, int *Iactual, float *v0);
// Definimos la fucnion principal
void main(void){
  // Se definen las variables
  float x_i;
  float T;
  float xS;
  int I;
  int AI;
//se le solicita a usuario ingresar los valores y se guardan en sus respectivas variables
  puts("Ingrese el primer valor aproximado de x");
  scanf("%f", &x_i);
// Definicion de la tolerancia minima para definir la solucion 
  puts("Ingrese el valor de tolerancia del problema");
  scanf("%f", &T);
// se solicita el numero de iteraciones maxima a realizar
  puts("Ingrese el numero de interaciones maximas");
  scanf("%d", &I);

//Se aplico el metodo de Newton Raphson definido
  NewtonR(x_i, T,I, &AI, &xS);
// si las iteraciones maximas son iguales a la actual mostrar:
  if (AI == I) {
  printf("No se llegó a una solución aceptable luego de %d iteraciones\n", I);
  } else{
//mostrar que solo se usaron ciertas iteraciones y el valor obtenido
  printf("Luego de %d iteraciones, se encontró la solución x = %f\n", AI, xS);
  }
}
// Funcion del problema
float f(float x){
	// sin(x)/(x)
  return sin(x)/x;
}

// funcion derivada 
float df(float x){
	// cos(x)/x - sin(x)/x^2
  return cos(x)/x - sin(x)/(x*x) ;
}

// Definicion metodo de Newton Ramphson
void NewtonR(float x_0, float T, int Imax, int *Iactual, float *v0) {
// Se definen las variables a utilizar
  float xp; // x pasado
  float x; // x actual
  float Dife; // diferencia entre los valores de x
  xp = x_0;  // se define al x anterior como el x actual para ir avanzando en el proceso
// Se define i para la primera iteraci[on]
  int i = 1;
  x = xp - f(xp)/df(xp);
  Dife = x - xp;
// con el valor absoluto de la diferencia para el metodo
  (Dife < 0)?Dife = -Dife:Dife; 

//S edefine la funcion mientras la diferencia entre los valores consecutivos de x sea menor a la tolerancia permitida
// y mientras el número de iteraciones no haya pasado el máximo definido por el usuario
  while (Dife > T && i < Imax){
// se define el valor siguiente de x
    xp = x;
// Se continua con la siguiente iteracion
    x = xp - f(xp)/df(xp);
    Dife = x - xp;
    (Dife < 0)?Dife = -Dife:Dife; 
 // se sigue avanzando en las iteracioens   
    i++;
  }
// Estas variables sn tipo puntero para almacerar en memoria 
  *v0 = x;
  *Iactual = i;
}
