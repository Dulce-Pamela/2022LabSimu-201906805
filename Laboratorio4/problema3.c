/*
Autor:         Dulce Calan
Fecha:         Sat May 14 22:43:36 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema3.out problema3.c -lm
Librerias      stdio
Resumen       El -lm servira ara vilcular la libreria math.h
*/

//librerias
#include <stdio.h>
#include <math.h>
// Definir variables globales.
float VecA[3];
float VecB[3];
// Definimos las funciones que vamos a utilizar
float Mag(float VecV[3]); // Magnitud de cada vector
void sum(); // Suma
float dotP(float VecV[3], float VecU[3]); // Producto punto.
void crossP(float VecV[3], float VecU[3]); // Producto cruz.
void FillVects(); 

int main(int argc, char const *argv[]) {

  FillVects(); // primero se llenan los ectores 
  puts("");// Despues se imprimen los resultados
  printf("Las normas son: ||a|| = %.2f,\n||b|| = %.2f,\n", Mag(VecA), Mag(VecB)); // Imprimir sus normas.
  printf("La suma de los vectores es: a + b = "); sum(); puts(",");// Imprimir la suma de los vectores.
  printf("El  producto punto es: a • b = %.2f,\n", dotP(VecA,VecB)); // Imprimir el producto punto de los vectores.
  printf("El producto cruz a × b = "); crossP(VecA,VecB); puts(",");// Imprmir un producto vectorial
  printf("El producto cruz b × a = "); crossP(VecA,VecB); puts(".");// Imprmir el otro producto vectorial
  return 0;
}

// Magnitud de cada vector
float Mag(float VecV[3]){
// Se inicializa la variable magnitud
  float magn = 0;
  magn = sqrt(dotP(VecV,VecV)); 
  return magn;
}

//Suma 
void sum(){
  static float VecV[3];
//Para i=0 y mientras i sea menor que 3, i avanzara de uno en uno
  for (int i = 0; i < 3; i++) {
// Definimos la suma como la suma de las componentes
    VecV[i] = VecA[i] + VecB[i]; 
    printf("%.2f ", VecV[i]);
  }
}

// Se define el producto cruz
float dotP(float VecV[3], float VecU[3]){
// Se define la suma para el producto punto
  float sum = 0;
// Para i=0 y mientras sea menor que 3 se realizara la multiplicacion
// y suma de cada componente (producto cruz)
  for (int i = 0; i < 3; i++) {
    sum += VecV[i]*VecU[i]; 
  }
  return sum;
}

// Se define el Producto Cruz
void crossP(float VecV[3], float VecU[3]){
//Se define la variable estatica en la memoria componentes
  static float Co[3];
  Co[0] = VecV[1]*VecU[2] - VecV[2]*VecU[1];
  Co[1] = VecV[2]*VecU[0] - VecV[0]*VecU[2];
  Co[2] = VecV[0]*VecU[1] - VecV[1]*VecU[0];

  // imprime el vector resultante 
  // para i menor que 3 mostrara el resultado de cada componente
  for (int i = 0; i < 3; i++) {
    printf("%.2f ", Co[i]);
  }
}

//Se le soliicta al usuario ingresar las componentes de cada vector
void FillVects() {
  puts("Vector A");
  for (int i = 0; i < 3; i++) {
    printf("Ingrese la componente %d del vector A.\n", i+1);
    scanf("%f", &VecA[i]);
  }
  puts("vector B");
  for (int i = 0; i < 3; i++) {
    printf("Ingrese la componente %d del vector B.\n", i+1);
    scanf("%f", &VecB[i]);
  }
}
