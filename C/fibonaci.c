/*
Autor:         Dulce Calan
Fecha:         Mon Apr 18 19:01:47 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o fibonaci.out fibonaci.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
long fibonacci(int n);

int main(){
    // declaracion de las variables
// n valor de numero al que querems ejecutr la secuencia de fibonacci
//k varian\ble de conteo
    int n,k;
//limitar al usuario a mis condiciones n> 0    
    do
    {
        puts("ingrese el valor de n: ");
        scanf("%d",&n)
    } while (n <=1 || (isdigit(n)));

// ejecucion de la serie de fibonacci 
// el conteo de  la variable k debe de llegar hasta n
for ( k = 0; k <= n+1; i++)
{
    
}
    
    
    return 0;
}
// recursividad directa
//funcion que valua fibonacci, se llama a si misma del numero de n
long fibonacci(int n){

}


