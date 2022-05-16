/*
Autor:         Dulce Calan
Fecha:         Sat May 14 22:53:11 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema6.out problema6.c -lm
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//se definen los prototipos de funciones para los incisos
float a(int s);
float b(int s);
float c(int s);
float d(int s);

int main(int argc, char const *argv[]) {
// Se iniccializa la variable que guarda el limite de la sumatoria
  int N; 
// El usuario deber[a[ ingresar el limite]]
  puts("Ingrese el limite superior de la sumatoria");
  scanf("%d", &N); // Guardamos el número en la variable
  printf("∑ k^2(k-3) = %f\n", a(N));
  printf("∑ 3/(k-1) = %f\n", b(N)); 
  printf("∑ ((1+√(5))/2)^k/√(5) - ((1-√(5))/2)^k/√(5) = %f\n", c(N)); 
  printf("∑ 0.1(3[2^(k-2)]+4) = %f\n", d(N)); 
  return 0;
}
//a
float a(int s){
  float suma = 0; 
  for (float k = 1; k <= s; k++) {
// Suma    
    suma += pow(k,2)*(k-3); 
  }
  return suma;
}
//b
float b(int s){
  float suma = 0; 
  for (float k = 2; k <= s; k++) {
// Suma    
    suma += 3/(k-1); 
  }
  return suma;
}
//c
float c(int s){
  float suma = 0; 
  for (float k = 1; k <= s; k++) {
// Suma
    suma += pow((1+sqrt(5))/2,k)/sqrt(5) - pow((1-sqrt(5))/2,k)/sqrt(5); 
  }
  return suma;
}
//d
float d(int s){
  float suma = 0; 
  for (float k = 1; k <= s; k++) {
// Suma
    suma += 0.1*(3*pow(2,(k-2)) + 4); 
  }
  return suma;
}
