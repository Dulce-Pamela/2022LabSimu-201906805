/*
Autor:         Dulce Calan
Fecha:         Sat May 14 22:43:27 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema2.out problema2.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
// Se definen las variables/ un vector de 5 espacios
int vec[5];
// Se definen las fucniones a utilizar
void FillVector();
void OrdV();
void PrintVector();

// Inicializa la funcion
int main(int argc, char const *argv[]) {
// Primero el  usuario llena el vector
  FillVector(); 
// Utilizando la funcion OrdV(Ordenar vector)
  OrdV();
// Se imprime
  PrintVector(); 
  return 0;
}

//funcion para llenar el vector
void FillVector(){
// Inicializamos la variable n
  int n = 0;
  for (int i = 0; i < 5; i++) {
    printf("Ingrese un número entero.\n");
    scanf("%d", &n);
// Se ingresa n al vector
    vec[i] = n;
    }
  }

// funcion para ordenar el vector
void OrdV(){
// Para i=o y mientras se amenor a 4 i avanzara de uno en uno   
  for (int i = 0; i < 4; i++) {
     // valua si para j=0 y mientras j se amenor a 4-i tambien  j avanzara de uno a uno  
    for (int j = 0; j < 4-i; j++) {
      if (vec[j] > vec[j+1]) {
        // Se define la variable local p
        int p = vec[j];
        vec[j] = vec[j+1];
        vec[j+1] = p;
      }
    }
  }
}

// Imprimir el vector
void PrintVector(){
  puts("El vector es (ordenado):");
  for (int i = 0; i < 5; i++) {
    printf("%d ", vec[i]);
  }
}