/*
Autor:         Dulce Calan
Fecha:         Tue Apr 19 12:37:21 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o ejemplopunteros.out ejemplopunteros.c
Librerias      stdio
Resumen       Realizar el el=jemp;lo del uso simple de punteros
*/

//librerias
#include <stdio.h>
// declaro mi funci[on]
void main(){
    //declara una variable y un lugar
    int n = 70;
    //voy a declara una variable tipo puntero y la igualo a la direccion donde ya se encuentra la variable n
    int* p=&n; //&(amperson)
    //imprimir difeerentes formas de presentacion del untero
    puts("Diversas formas del puntero");
    //se imprime variables y punteros de diversas formas
    //primero el valor, la direccion de n(amperson), lugo el valor de p
    printf("n=%d, &n=%p, p=%p ,&p=%p \n",n,&n,p,&p); 

    //variable tipo caracter
    char c;
    //declaro un puntero para la variable char pc puntero del caracter
    char *pc;
    c = '0';
    pc=&c; //valor de la variable del caracter
    // voy a imprimir cual es el valor y la direccion
    // cuando es un caracter se puede poner sin el %p par apoderlo parciar (%p) se puede hacer silo *pc
    printf("%c direccion %c \n",c,*pc);
    //hacemos un for para incrementar el valor del caracter
    for (c = 'A'; c <= 'Z'; c++)
    {
        printf("El valor es %c, en la direccion %p \n",*pc,&c);
    }
    
}
