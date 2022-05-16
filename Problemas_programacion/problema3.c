/*
Autor:         Dulce Calan
Fecha:         Tue Apr 19 12:33:02 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema3.out problema3.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
int main(){
    //1. declaro e inicializo mi variable
    int i = 1;
    int N = 0;
    puts("Raiz cuadrada entera");
    // se pide al usuario ingrese un numero N
    puts("Ingrese un numero: ");
    scanf("%d",&N);
    //mientras i*i sea menor o igual a N se seguira corriendo la instruccion de lo contrario se muestra la raiz de N
    while ((i*i)<=N)
    {
        i++;
    }
    int result=i-1;
    printf("La raiz cuadrada es: %d \n",result);

}



