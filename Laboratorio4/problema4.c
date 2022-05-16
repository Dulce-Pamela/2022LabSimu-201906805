/*
Autor:         Dulce Calan
Fecha:         Sat May 14 22:43:50 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema4.out problema4.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
#include <math.h>
// Inicializamos las variables de las matrices
int matA[3][3];
int matB[3][3];
int Cte;
// Inicializamos las variables de control para las funciones
int i;
int j;
int k;
// Funciones a utilizar
void PrintMatrix(int A[3][3]);//Imprimir
void FillMatrix();// Llenar 
void ConstA();
void Sum();
void Res();
void Mul();
int detA();
void transB();
void InvA();
void GaJo(int A[3][3]);


int main(){
  puts("\n    *** Operaciones con Matrices de 3X3 ***");
  FillMatrix(); // Llena las matrices.
  ConstA(); // Multplicacion de constante
  Sum(); // Suma matrices
  Res(); // Resta matrices
  Mul(); // Multiplicación matrices
  printf("\nEl determinante de A es: \n%d\n", detA()); // Determinante A
  transB();// Traspuesta  B
  if (detA() != 0){ // Inversa de A
    puts("\nLa inversa de A es:");
    InvA(); 
  }else{
// De lo contrario se notifica que A no tiene inversa
    puts("\nLa matriz A no es invertible");
  }
 
  return 0;
}

//Funcion imprimir matriz (entera)
void PrintMatrix(int A[3][3]){
// LLenar los espacios en filas y columnas    
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", A[i][j]);
      if (j == 2){puts("\n");}
    }
  }
}
// Funcion imprimir matriz (float)
void PrintMatrixf(float A[3][3]){
// Llenar los espacios en filas y columnnas
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%.2f ", A[i][j]);
      if (j == 2){puts("\n");} // Salto de línea.
    }
  }
} // Llenar matrices float
void FillMatrix(){
  // El usuario ingresa los valores de las posiciones de la matriz A en orden
  puts("\nIngrese los elementos para la matriz A (fila x colum)), enter para avanzar: ");
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      printf("Ingerse a_%d,%d : ",i+1,j+1);
      scanf("%d",&matA[i][j]);
    }
//Cuando termina este ciclo avanza a la otra matriz
  }
  // El usuario ingresa los valores de las posiciones de la matriz B en orden
  puts("\nIngrese los elementos para la matriz B (fila x colum), enter para avanzar: ");
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      printf("Ingerse b_%d,%d : ",i+1,j+1);
      scanf("%d",&matB[i][j]);
    }
  }
//Se imprimen las matrices que ingreso el usuario
  puts("\nMatriz A: ");
  PrintMatrix(matA);
  puts("\nMatriz B: ");
  PrintMatrix(matB);
  // El usuario ingresa el valor de la constante del ejercicio
  puts("\nIngrese el valor de la constante: ");
  scanf("%d",&Cte);
}
void ConstA(){
//Se inicializa la matriz CteA
  int CteA[3][3];
// Se realiza la multipilicacion de cada elemento  por la constante
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      CteA[i][j]=Cte*matA[i][j];
    }
  }
  
  printf("\n c = %d, la matriz %dA es: \n",Cte,Cte);
  PrintMatrix(CteA);
}
//Se define la funcion suma
void Sum(){
// matriz de suma
  int Su[3][3];
  puts("\nLa suma de A y B es: ");
// for para sumar componente con componente
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      Su[i][j] = matA[i][j] + matB[i][j];
    }
  }
  PrintMatrix(Su);
}
//Funcion resta de matrices
void Res(){
 // Se define la matriz de resta   
  int Re[3][3];
  puts("\nLa resta de A y B es: ");
  //Se restan conponentes con componentes
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      Re[i][j] = matA[i][j] - matB[i][j];
    }
  }
  PrintMatrix(Re);
}
//Funcion de multiplicacion
void Mul(){
// Matriz de multiplicacion
  int MaMult[3][3];
  for (i = 0; i < 3; i++) {
//Le asigna a cada componente la respectiva suma obtenida
    for (j = 0; j < 3; j++) {
      int sumR = 0;
//Suma la multiplicacion de fila por columna 
      for (k = 0; k < 3; k++) {
        sumR += matA[i][k]*matB[k][j];
      }
      MaMult[i][j] = sumR;
    }
  }
  printf("La multiplicacion de matrices es:\n");
  PrintMatrix(MaMult);
}
//funcion determinante de la matriz A 
int detA(){
  int det = (matA[0][0]*matA[1][1]*matA[2][2]+matA[0][1]*matA[1][2]*matA[2][0]+matA[1][0]*matA[2][1]*matA[0][2])-matA[0][2]*matA[1][1]*matA[2][0]-matA[0][1]*matA[1][0]*matA[2][2]-matA[1][2]*matA[2][1]*matA[0][0];
  return det;
}
//Funcion transpuesta de la matriz B
void transB(){
// Se define la matriz transpuesta a llenar
  int TransB[3][3];
  puts("\nLa matriz transpuesta de B es: ");
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      TransB[i][j] = matB[j][i];
    }
  }
  PrintMatrix(TransB);
}
void InvA(){
// DEfinimos la matriz adjunta a utilizar 
  int AdjA[3][3];
// y la matriz inversa a llenar
  float Inve[i][j];
// Por  ser practicos se define por componentes los elementos de la adjunta (por definicion)
  AdjA[0][0] = +matA[1][1]*matA[2][2] - matA[2][1]*matA[1][2];
  AdjA[1][0] = -matA[1][0]*matA[2][2] + matA[2][0]*matA[1][2];
  AdjA[2][0] = +matA[1][0]*matA[2][1] - matA[2][0]*matA[1][1];
  AdjA[0][1] = -matA[0][1]*matA[2][2] + matA[2][1]*matA[0][2];
  AdjA[1][1] = +matA[0][0]*matA[2][2] - matA[2][0]*matA[0][2];
  AdjA[2][1] = -matA[0][0]*matA[2][1] + matA[2][0]*matA[0][1];
  AdjA[0][2] = +matA[0][1]*matA[1][2] - matA[1][1]*matA[0][2];
  AdjA[1][2] = -matA[0][0]*matA[1][2] + matA[1][0]*matA[0][2];
  AdjA[2][2] = +matA[0][0]*matA[1][1] - matA[1][0]*matA[0][1];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      Inve[i][j]=AdjA[i][j]*pow(detA(),-1);
    }
  }
  PrintMatrixf(Inve);
}
// funcion metodo de Gauss Jordan

