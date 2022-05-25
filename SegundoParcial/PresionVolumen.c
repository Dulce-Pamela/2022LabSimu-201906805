/*
Autor:         Dulce Calan
Fecha:         Wed May 25 10:35:03 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o PresionVolumen.out PresionVolumen.c -lm
Librerias      stdio
Resumen       Se realza un equivalente lineal a la funcion de termodinamica PV^a = b
*/

//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// vamos a hacer una regresion lineal que mejoro se ajuste al comportamiento de los 
// logaritmos naturales del volumen y l apresion, para generar la recta que mejor se ajuste al comportamiento
//  PV^a = b
//  P = V^(-a)b
//  ln(P) = (-a)ln(V) + ln(b)
//Entonces mi recta queda de esta manera
//   y = Ax +B
//  datos proporcionaos
float y[] = {4.11,3.89,3.63,3.35,2.95,2.32};
// incertezas de y
// float dy[] = {log(0.2),log(0.2),log(0.2),log(0.2),log(0.2),log(0.2)};
//  la longitud del arreglo
int n = sizeof(y)/sizeof(y[0]);
// x = valores de P y su incerteza
float x[] = {3.99,4.12,4.28,4.48,4.78,5.27};
// float dx[] = {log(0.1),log(0.1),log(0.1),log(0.1),log(0.1),log(0.1)};
// Antes de continuar, prototipamos nuestras funciones
int gnuplot(float A, float B);// Función para sacar el archivo de gnuplot
//se definen las funciones para las variables 1 y 2 (v1 y v2)
float suma(float v1[]);
// funcion de suma de 2 variables
float sumas(float v1[], float v2[]);

// Se define la funcion principal
int main(int argc, char const *argv[]) {
// Se obtienen los valores de A y B:
  float A;
  //Se define la funcion para A (pendiente)
  A = ( n*sumas(x,y) - suma(x)*suma(y) )/( n*sumas(x,x) - (suma(x)*suma(x)) );
// 	Se define la funcion para encontrar B
  float B;
  B = ( suma(y)*sumas(x,x) - suma(x)*sumas(x,y) )/( n*sumas(x,x) - (suma(x)*suma(x)) );
// 	Se inprimen los valores de A y B.
  printf("y = %fx + %f\n", A, B);
//despejando P calculamos el valor de P cuando V=100
// 	Imprimir el valor de (y-B)/A  recordando que ln(100) = 4.605
float R = exp(B + A*4.605);
  printf("La presion cuando V = 100in^3 es de : %.1f lbin^(-3)\n", R);
// 	3.3. Correr el gnuplot e imprimir un mensaje de éxito.
  gnuplot(A, B);
  puts("Proceso finalizado.\n");
  return 0;
}

// Definicion de la funcion suma
float suma(float v1[]){
  // se inicializa la variable de referencia para ir sumando los terminos
  float v0 = 0;  // variable valor 0
  //  para cada elemento se iran sumando uno a uno
  for (int i = 0; i < n; i++) {
  //    se suma cada elemento a v0
    v0 += v1[i];
  }
  //  3. Retornar a v0
  return v0;
}


// Definicion de la funcion de suma de dos variables
float sumas(float v1[], float v2[]){
// 	definimos la variable valor 0 v0
  float v0 = 0;
// 	para cada pareja de elementos se iran sumando el prducto entre estas variables
  for (int i = 0; i < n; i++) {
    v0 += v1[i]*v2[i];
  }
// 	retornar a v0
  return v0;
}

// descripcion del archivo Gnuplot
int gnuplot(float A, float B) {
    //se crea el archivo .gp 
  FILE *pfile = fopen("gnuplotD.gp", "wt");
    // Se define el archivo gnuplotD.gp
  fprintf(pfile, "unset label\nclear\nset terminal pdf\nset output 'Grafica_PV.pdf'\nset title 'Comportamiento Presion vs Volumen'\n");
    // Se definen los nombres de los ejes
  fprintf(pfile, "set xlabel 'ln(Volumen)'\nset ylabel 'Ln(Presion)'\n");
  fprintf(pfile, "set grid\nset key right\n");
    // Ploteo de datos
  fprintf(pfile, "plot '[ln(V),ln(P)]' w p, ");
    // Se  grafica la recta que mejor se aproxime 
    // po rultimo se escriben los valores de la pendiente y el punto de corte aproximado
    // A y B respectivamente
  fprintf(pfile, "%.3f*x + %.3f w l\n", A, B);
    // Se obtiene la grafica 
  fclose(pfile);
  system("gnuplot gnuplot.gp");
  return 0;
}
