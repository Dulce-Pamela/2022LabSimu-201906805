/*
Autor:         Dulce Calan
Fecha:         Tue Apr 19 12:33:16 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema5.out problema5.c
Librerias      stdio
Resumen       
*/

#include <stdio.h>
// Primero definimos el loop para los números primos
int primo(int N){
  // Inicializamos variables 
  int i = 2;
  int k = 1;
  // Inicializamos el while con la condici[on, mientras i sea menor o igual a n-1 y el valor 
  // de k sea igual a 1 entonces se comprobara otra condicion
  while (i < N - 1 && k == 1) {
    // 0.2.1. Comprobar si N es divisible entre i.
    if (N % i == 0) {
      // 0.2.1.1 Si es divisible, no es primo, cambiamos el valor de la variable.
      k = 0;
    }
    // i va avanzar en uno a uno
    i++;
  }
  return k;
}
//definimos el proceso
int main() {
  // Se inicializan las variables 
  int N1;
  int N2;
  // solicita al usuario ingresar los limites 
  puts("Ingrese el numero menor del rango: ");
  scanf("%d", &N1);
  puts("Ingrese el numero mayor del rango: ");
  scanf("%d", &N2);
  // Da la  respuesta 
  printf("Los números primos dentro del rango [ %d , %d ) son: \n", N1, N2);
  // Inica el loop
  for (int i = N1; i < N2; i++) {
    // Evalua si el numero es primo y si lo es, lo escribe.
    if (primo(i) == 1) {
      printf("%d\n", i);
    }
  }
  return 0;
}