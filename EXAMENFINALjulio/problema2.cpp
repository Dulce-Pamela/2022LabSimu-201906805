/*
Autor:         Dulce Calan
Fecha:         Tue Jul 19 14:43:18 CST 2022
Compilador     g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       g++ -o problema2.out problema2.cpp
Librerias      iostream
Resumen       Este programa muetsra la informacion y los onjetos de cada cohete.
*/

//librerias
#include <iostream>
// nombre de la clase
class cohete{
public:
  // Se nombran los atributos = definir variables
  string nombre; // nombre texto
  double Eo, tsfc, m0, mfo; // caracteristicas 
  float cd, A;
public:
     //metodos = funciones
    //definimos constructor
  cohete(string Nombre, double Empuje, double ConsuEEmp, float CoefForm, float Area, double Masa, double CombInic){
    nombre = Nombre;
    Eo = Empuje;
    tsfc = ConsuEEmp;
    cd = CoefForm;
    a = Area;
    m0 = Masa;
    mfo = CombInic;
  }
    // se define el destructor
  ~cohete(){}; 
    //Se ejecutan las especificaciones
  void Esp();

};

//Se muestran las especificaciones dadas
//Esp>>Especificaciones
void cohete::Esp(){ 
    cout << "Propiedades del Cohete " << nombre << '\n';
    cout << "Empuje del cohete: " << Eo << '\n';
    cout << "Consumo especifico del empuje TSFC: " << tsfc << '\n';
    cout << "Coeficiente de Forma CD: " << cd << '\n';
    cout << "Sección transversal del cohete: " << A <<'\n';
    cout << "Masa del propulsor m0: " << m0 <<'\n';
    cout << "Masa Inicial de Combustible mfo: " << mfo << '\n';
} 

int main(){
  // Especificaciones
  //----------------cohete1 AH MUN----------------------
  Cohete cohete1("Ah Mun", 3E7, 3.248E-4, 61.27, 201.06, 1.1E5, 1.5E6);
  cohete1.Esp();

  //----------------cohete2 AHAU KIN---------------------
  Cohete cohete2("Ah Mun", 2.7E7, 2.248E-4, 61.27, 201.06, 1.1E5, 1.5E6);
  cohete2.Esp();

  //----------------cohete2 CHAC-------------------------
  Cohete cohete3("Ah Mun", 2.5E7, 2.248E-4, 70.25, 215.00, 1.8E5, 2.1E6);
  cohete3.Esp();
  return 0;
} 