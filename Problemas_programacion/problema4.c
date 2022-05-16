/*
Autor:         Dulce Calan
Fecha:         Tue Apr 19 12:33:10 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema4.out problema4.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
int main(){
    //inicializo mis valores
    int i = 2;
    int N = 0;
    int primo = 1;
    // el usuario debe ingresar el numero N
    puts("Numero primo o no primo?");
    // se pide al usuario ingrese un numero N
    puts("Ingrese un numero: ");
    scanf("%d",&N);
    //inicio el ciclo while
    while ((i<=N-1)&&(primo==1))
    {
        if (N%i==0)
        {
            primo=0;
        }
        i++;
        
    }
    if (primo==0)
    {
        puts("No es primo");
    }else{
        puts("Es primo");
    }
    
}