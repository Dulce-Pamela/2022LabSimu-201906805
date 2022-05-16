/*
Autor:         Dulce Calan
Fecha:         Mon Apr 18 22:46:25 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o recursividadIndirecta.out recursividadIndirecta.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
#include <string.h>

//Declaracion de los prototipos de las funciones
int par(int n);
int impar(int n);

int main(){
    //declaro mis varables globales para el numero y el resultado
    int n;
    char resultado[12];
    //valuar si el valor ingresado es mayor a 0
    do
    {
        puts("Ingrese un numero");
        scanf("%d", &n);
    } while (n<0);
    //valuar si el valor ingresado es par o impar, para la respuesta se iguala texto a una variable 
    //vectorial del tipo caracter
    if (par(n))
        strcpy(resultado, "Es par");
    else
        strcpy(resultado, "Es Impar");
    //Se presentan los resultados obtenidos
    printf("\t %d, %s \n",n,resultado);

    return 0;
}

//la recursividad los que hace es tomar el numero e ir restando 1 hasta que llega a 0

//funcion par valuar si el numero es par, si es verdadero regresa un 1 de lo contrario ingresa a
//la funcion impar
int par(int n){
    printf(" en par n : %d\n",n);
    if (n==0)
        return 1;
    else
        return impar(n-1);
}

//regresa 0 en el caso  que se el numero impar, de lo contrario ingresa a la funcion par
int impar(int n){
    printf(" en impar n : %d\n",n);
    if (n==0)
        return 0;
    else
        return par(n-1);
}
