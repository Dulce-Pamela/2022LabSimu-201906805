/*
Autor:         Dulce Calan
Fecha:         Mon Apr 18 23:23:47 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema2.out problema2.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
//declaracion de variables
int x=0;
int n=0;
int max=0;
int min=0;
float med=0;
int main(){
    //1. leer los datos
    puts("ingrese el valor de alturas \n para finalizar ingrese un valor negativo");
    puts("Ingrese una altura: ");
    scanf("%d", &x);
    //2. guarda el valor de altura en min y max
    max=x;
    min=x;
    //3. verificar que la altura sea igual o mayor a 0
    while (x>=0)
    {
        //4. mientras se cumpla la condicion se iran almacenando los valores de las alturas
        n++;
        med+=x;
        //5. valuar si el valor ingresado es el maximo hasta el momento
        if (x>max)
        {
            max=x;
        }
        //6. valuar si el valor ingresado es el minimo hasta el momento
        if (x<min)
        {
            min=x;
        }
        //7. volvemos a pedir que se ingrese el valor de una altura hasta que el ciclo termine
        puts("Ingrese otra altura: ");
        scanf("%d", &x);
    }
    //8. verifica qque el valor de n sea mayor a 0
    if (n==0)
    {
        puts("No ingreso alturas validas");
    }
    else
    {
        //9. imprime la media, maximo y minimo
        med=med/n;
        printf("De los vaores ingresados: \n La media es: %f, \n El valor maximo es: %d, \n El valor minimo es: %d \n",med,max,min);
    }
}