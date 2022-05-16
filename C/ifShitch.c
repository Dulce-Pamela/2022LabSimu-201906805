/*
Autor:         Dulce Calan
Fecha:         Mon Apr 18 22:45:29 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o ifShitch.out ifShitch.c
Librerias      stdio
Resumen       
*/

//incluir librerias
#include <stdio.h>
#include <ctype.h>

//se declara una variable enumerada que es la representacion boleana
enum Bool {False, True} validacion;

void main(void){
    //declaro mis variables locales
    char letra;
    int x;

    //solicitar al usuario ingresar una letra
    printf("Ingrese una volcal: ");
    //capturar esa letra en una variable
    letra = getchar();
    //se valida si la letra ingresada es a
    if (letra!='a')
    {
        printf("la vocal ingresada es: %c \n",letra);
    }
    
    //solicitar al usuario ingrese un numero del uno al 5
    printf("ingrese un numero del 0 al 5: ");
    //capturar el valor numerico e ingresarlo en una variable
    scanf("%d",&x);
    //utilizar un if else para validar
    if (x > 3)
    {
        printf("el valor ingresado es mayor a 3 \n");
        validacion = True;
    }
    else
    {
        printf("el valor ingresado es menor o igual a 3 \n");
        validacion = False;
    }
    
    //la forma resumida de un if-> (comparacion)?valor verdadero:falor falso
    //utilizo la validacion con el tipo de variable enum
    (validacion==True)?printf("la validacion es verdadera\n"):printf("la validacion es falso\n");
    //if rapido con numero
    (x>2)?printf("el valor ingresado es mayor a 2 \n"):printf("el valor ingresado es menor a 2 \n");
    //if dentro de otro if
    if (x!=0)
    {
        if (x>3)
        {
            printf("si es mayor 3\n");
        }else
        {
            printf("no es mayor 3\n");
        }
    }
    //if anidado
    if (x>=0 && x<=3)
    {
        printf("entre 0 y 3\n");
    }
    else if (x==4)
    {
        printf("igual a 4\n");
    }
    else if (x>4 && x<=10)
    {
        printf("entre 4 y 10\n");
    }
    //valuar caracteristicas especificas
    if ((isdigit(x)))
    {
        printf("NAN\n");
    }
    //el uso de switch
    switch (letra)
    {
    case 'a':
        puts("vocal a");
        break;
    
    default:
        puts("otra cosa");
        break;
    }
    //corvertir vocal a mayusculas
    letra = toupper(letra);
    switch (letra)
    {
    case 'A':
        puts("vocal A");
        break;
    
    default:
        puts("otra cosa");
        break;
    }
}
