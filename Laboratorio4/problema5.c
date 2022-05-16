/*
Autor:         Dulce Calan
Fecha:         Sat May 14 22:43:55 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema5.out problema5.c -lm
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
// Funcion recursiva en funcion del numero ingresado n
int factorial(int N);

// Se define la funcion principal del programa
int main(int argc, char const *argv[]) {
  int n = 1; 
// el usuario ingresa el numero N para aplicar el factorial
  puts("Ingrese un número entero positivo:");
  scanf("%d", &n);
// Se imprime el factorial del numero ingresado
  printf("%d! = %d\n", n, factorial(n)); 
  return 0;
}

// Funcion recursiva factorial
int factorial(int N){
// Para N mayor o igual se multiplica el nuemro por el anterior hasta llegar a 1
  if (N >= 1) {
    return N*factorial(N-1); 
// De lo contrario si N es igual a cero regresa a el valor por defecto 1
  } else if (N == 0) {
    return 1; 
// De lo contrario se termina el programa y envia 0
  } else {
    return 0;
  }
}
