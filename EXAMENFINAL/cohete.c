/*
Autor:         Dulce Calan
Fecha:         Mon May 16 09:07:37 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o cohete.out cohete.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
#include <math.h>

//inicialezaos variables
int E0;
int TSFC;
int CD;
int A;
int m0;
int mf0;
//declarando constantes
const float G = 6.693E-11;
const float Rt = 6.378E6;
const float Mt = 5.9736E24;
const float R = 287.06;
const float L = 6.5E-3;
const float T0 = 288.15;
const float P0 = 101325;

//prototipando funciones a utilizar
float mft(float t, float TSFC, float E0, float m0);
float mcohete( float m0, float mf0, float t);
float gravedad(float y);
float densidad(float y);
float fuerza_a(float y, float CD, float a,float v);
float Empuje(float mft, float E0);
float aceleracion(float y, float t, float m0, float TSFC, float E0, float mf0, float G, float Mt, float Rt,float R, float T0, float P0, float L);


//funcion principal
int main(){
    //lo que muestra el programa 
    puts("Nombre del cohete: Dulce \n Caracteristicas: ");
    puts("Ingrese las caracteristicas del cohete:\n");
    puts("Empuje E0:");
	scanf("%s", &E0);
    puts("Consumo del empuje TSFC:");
	scanf("%s", &TSFC);
    puts("Coeficiente de forma CD:");
	scanf("%s", &CD);
    puts("Masa del propulsor:");
	scanf("%s", &m0);
    puts("Masa inicial del combustible:");
	scanf("%s", &mf0);
    //ciclo for para hacer el ploteo de los valores
    for(t=0, t<5, t+=0.1){
        
    }
}
 //FUNCIONES

 //son recursividades indirectas

 //Consumo de combustible (resolviendo a mano la EDO de primer orden)
 float mft(float t, float mf0,float TSFC, float E0, float m0){
     return -TSFC*E0*t + mf0;
 }
 //Masa del cohete en funcion de la masa del consumo de combustible
 float mcohete( float m0, float mf0, float t){
     return m0 + mft(t);
 }
 // Gravedad
 float gravedad(float y){
     return ( G* Mt)/(Rt + y)^2;
 }
// Friccion de la atmosfera, antes de la densidad por que depende de esta
 // densidad del aire
 float densidad(float y){
// si supera la altura de T0/L regresa el valor 0 a la densidad
     if (y >= (T0/L))
     {
        return 0;
// de lo contrario sigue utilizando la formula dada
     }else{
         return (P0)/(R*T0)*pow((1-(L*y)/T0),(g0/(R*L)));
     }  
 }
 //fuerza friccion con la atmosfera con v=dy/dt
 float fuerza_a(float y, float densidad, float CD, float A,float v){
    return 1/2* densidad(y)*CD*A*v*fabs(v);
 }
 //valuamos si ya no hay combustible E se vuelve cero
 float Empuje(float mft(t), float E0){
     if (mft == 0)
     {
         E0 =0;
     }else{
         return E0;
     }
 }
 //funcion de la ecuacion diferencial
 float aceleracion(float y, float t, float m0, float TSFC, float E0, float mf0, float G, float Mt, float Rt,float R, float T0, float P0, float L){
     return (Empuje(mft(t))-fuarza_a(y)-mcohete(t)*gravedad(y))/(mcohete(t));
    
 }



