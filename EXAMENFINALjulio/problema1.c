/*
Autor:         Dulce Calan
Fecha:         Tue Jul 19 14:41:49 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema1.out problema1.c -lm
Librerias      stdio
Resumen       Este programa es un simulador de despeje de cohetes, se analiza el comportamiento de la
              trayectoria vertical, revisamdo la cantidad de combustible y el momento de impacto con 
              el suelo.

*/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. se definen las constantes
#define G 6.693E-11  // Cte de gravitacion
#define Rt 6.378E6    // Radio de la tierra
#define Mt 5.9736E24 // masa de la tierra
#define R 287.06     // constante del gas ideal
#define L 6.5E-3     // constante termica
#define g 9.81       // gravedad nivel del mar
#define To 288.15    // temperatura  nivel  del mar
#define Po 101325    // presion nivel del mar

// 2. Se prototipan las funciones
float MasaCohete(float t, float m0, float tsfc, float Eo, float mfo); 
float Mf(float t, float tsfc, float Eo, float mfo); //masa del combustible
float Gra(float y);                                 // gravedad
float Fa(float y, float cd, float A, float v);      //fuerza de friccion
float Den(float y);                                 // densidad
float Emp(float mf, float Eo);                      // Empuje 
float ED(float t, float y, float v, float A, float cd, float m0, float tsfc, float Eo, float mfo); // ecuacion diferencial general
void MetEuler(float h, float m0, float tsfc, float Eo, float mfo, float cd, float A, float *tC, float *tF, float *hm);

int main(){
 
  float Eo, tsfc, cd, A, m0, mfo, tC, tF, hm;
  // ----------------------------Cohete 1------ AH MUB
  //caracteristicas
  Eo = 3E7;
  tsfc = 3.248E-4;
  cd = 61.27;
  A = 201.06;
  m0 = 1.1E5;
  mfo = 1.5E6;
  
  MetEuler(0.1, m0, tsfc, Eo, mfo, cd, A, &tC, &tF, &hm);
  // Se imprimen los datos solicitados
  puts("Nombre: Cohete Ah Mun");
  puts("Caracteristicas");
  printf("Empuje: %f\nConsumo del empuje: %.6f\nCD: %f\nSeccion Transversal: %f\nMasa del Propulsor: %f\nMasa inicial del Combulstible: %f\n", Eo, tsfc, cd, A, m0, mfo);
  printf("La altura maxima es: %f m\n", hm);
  printf("Instante en el que se agota el combustible: %f minuto\n", tC/60);
  printf("Instante de impacto: %f minuto\n", tF/60);

  // generamos las graficas
  system("gnuplot ahmun.gp");

  // --------------------------Cohete 2------ AHAU KIN
  //caracteristicas
  Eo = 2.7E7;
  tsfc = 2.248E-4;
  cd = 61.27;
  A = 201.06;
  m0 = 1.1E5;
  mfo = 1.5E6;

  
  MetEuler(0.1, m0, tsfc, Eo, mfo, cd, A, &tC, &tF, &hm);
  // Se imprimen los datos solicitados
  puts("Nombre: Cohete Ahau Kin");
  puts("Caracteristicas");
  printf("Empuje: %f\nConsumo del empuje: %.6f\nCD: %f\nSeccion Transversal: %f\nMasa del Propulsor: %f\nMasa inicial del Combulstible: %f\n", Eo, tsfc, cd, A, m0, mfo);
  printf("La altura maxima es: %f m\n", hm);
  printf("Instante en el que se agota el combustible: %f minuto\n", tC/60);
  printf("Instante de impacto: %f minuto\n", tF/60);

  // grafica
  system("gnuplot ahaukin.gp");

   // ----------------------Cohete 3------ ACHAC
  //caracteristicas
  Eo = 2.5E7;
  tsfc = 2.248E-4;
  cd = 70.25;
  A = 215.00;
  m0 = 1.8E5;
  mfo = 2.1E6;

  MetEuler(0.1, m0, tsfc, Eo, mfo, cd, A, &tC, &tF, &hm);
  // Se imprimen los datos solicitados
  puts("Nombre: Cohete Chac");
  puts("Caracteristicas");
  printf("Empuje: %f\nConsumo del empuje: %.6f\nCD: %f\nSeccion Transversal: %f\nMasa del Propulsor: %f\nMasa inicial del Combulstible: %f\n", Eo, tsfc, cd, A, m0, mfo);
  printf("La altura maxima es: %f m\n", hm);
  printf("Instante en el que se agota el combustible: %f minuto\n", tC/60);
  printf("Instante de impacto: %f minuto\n", tF/60);

  // grafica
  system("gnuplot chac.gp");
  return 0;
}




// ----------------------------FUNCIONES------------------------------
//---------masa del cohete---------
float MasaCohete(float m0, float tsfc, float Eo, float mfo, float t){
     float res;
// si la masa del combustible es cero muestre la masa inical del cohete
  if (round(Mf(tsfc, Eo, mfo, t)) == 0){
    return m0;
// de lo contrario agregue la variacion de masa del combustible (como en la ecuacion)    
  } else{
    res = m0 + Mf(tsfc, Eo, mfo, t);  
    return res;
  } 
}

//---------masa del combustible-----
float Mf(float tsfc, float Eo, float mfo, float t){
    float res;
    res = -(tsfc*Eo*t) + mfo; //(ecuacion ya integrada)
    return res;
}

// --------gravedad------------------
float Gra(float y){
    float res;
    res = (G*Mt)/(pow(Rt + y,2)); // (ecuacion dada)
    return res;
}         

//---------fuerza de friccion--------
float Fa(float y, float cd, float A, float v){
    float res;
    res = (1/2)*Den(y)*cd*A*v*abs(v); //(ecuacion dada)
    return res;
}

// ---------densidad-----------------
float Den(float y){
    float res;
    // Tomando en cuenta la restriccion, donde p es valida para alturas inferiores a To/L.
    if (y < To/L){
        res = (Po/(R*To))*pow(1 - (L*y)/To, g/(R*L));
        return res;
    } else{  // si sobre pasa ese limite se muestra una densidad igual a cero
        return 0;
    } 
}                            

// -----------empuje-----------------
// Es constante pero tiene una restriccion, cuando la masa del combustible es cero el 
// empuje se vuelve cero, de lo contrario permanece constante
float Emp(float mf, float Eo){
    if (round(mf) == 0){
        return 0;
    } else{
        return Eo;
    } 
}

// ----------ecuacion diferencial general de >>segundo orden<<------------
float ED(float y, float v, float t, float m0, float tsfc, float Eo, float mfo, float cd, float A){
  float res;
  res = (Emp(Mf(tsfc, Eo, mfo, t), Eo) - Fa(y, cd, A, v) - (MasaCohete(m0, tsfc, Eo, mfo, t)*Gra(y)) )/MasaCohete(m0, tsfc, Eo, mfo, t);
  return res;
}



// Resolucion de la ecuacion diferencial de segundo orden y la de primer orden con el metodo  de euler mkl 
void MetEuler(float h, float m0, float tsfc, float Eo, float mfo, float cd, float A, float *tC, float *tF, float *hm){
  // condiciones iniciales, con el carnet 201906805
  float y = 0.05, v = 0, t = 0; // altura inicial 0.05metros, velocidad inicial y tiempo inicial
  
   //porque necesito trabajar en un archivo, mistras se ejecuta se crea el archivo
   //inicializamos el puntero de archivos y lo abrimos mientras se ejecuta el programa
   // en cada ejecucion se debe reiniciar el proceso para no guardar los datos de una ejecucion anterior 
  FILE* f; // se inicializa el puntero
  if ((f= fopen("datos.dat","wt"))==NULL){
        puts("error");
  } 

   // se define el numero de iteraciones del modelo
   // mientras exista altura se encuentran  los valores de velocidad y posicion (altura)
  while (y > 0.01){
    fprintf(f,"%.2f\t%.2f\t%.2f\n",t,y,v); // con dos decimales se defime el avance del intervalo t
    t += h;
    // recordemos que v=dy/dt, por tanto se calcula la velocidad con euler
    v = ED(y, v, t, m0, tsfc, Eo, mfo, cd, A)*t;
    // usando cinematica se calcula la altura del cohete (y=vt+1/2at^2)
    y = v*t + (1/2)*ED(y, v, t, m0, tsfc, Eo, mfo, cd, A)*pow(t,2);
    // Se debe detectar el momento en el que el combustible el nulo 
    if (round(Mf(tsfc, Eo, mfo, t)) == 0){
      *tC = t;
    } else if(round(v) == 0){
      *hm = y; // se le asigna la direccion de memoria 
    } 
  }

  fclose(f); // se cierra e
  *tF = t; // se le asigma el valor a la direccion de memoria
} 
