/*
Autor:         Dulce Calan
Fecha:         Tue Jul 19 11:37:02 CST 2022
Compilador     g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       g++ -o primerconDes.out primerconDes.cpp
Librerias      iostream
Resumen       un ejemplo simple de como utilizar y crear clases, objetos, atrubutos y demas constructor y destructor
*/
// podriamos improvisar el diagrma aqui de la sig manera 
/*
-----------
complejos
=---------
+real: double
+ img: double
-------------
+Complejos 
+ ~ Complejos
----------
*/

//librerias
#include <iostream>
//crear la clase con los atruibutos real img cons y des
class Complejos
{
public:
    //atributos = definir variables
    double real, img;
public:
    //metodos = funciones
    //definimos constructor
    Complejos(double a, double b){
        real = a;
        img = b;
    };
    //definimos  destructor
    ~Complejos(){};
};

int main(void)
{
    //crea objeto y se inicializan los valores de los atibutos 
    Complejos valor1(1.,2.);
    //vamos  a mostrar el valor en consola del objeto
    std::cout << "Numero complejo : real = "<<valor1.real<<"+"<<valor1.img<<"i"<<std::endl;
    //se elimina el objeto 
    valor1.~Complejos();
    return 0;
    
}