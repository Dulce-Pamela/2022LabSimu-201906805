/*
Autor:         Dulce Calan
Fecha:         Sat May 14 22:03:01 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o problema1.out problema1.c
Librerias      stdio
Resumen       
*/

//librerias
#include <stdio.h>
// Definimos variables.
int vec[10];
char Ord;
// Funciones a utilizar
void FillVector();
void PrintVector(char Ord);

// Función 1
int main(){
	FillVector(); // Funcion para llenar al vector de 10 espacios
	// Pregunta al usuario en que tipo de orden desea ver la lista de nuemros
	puts("¿Elija el orden en que desea ver los elementos?\n'a'=Ascendente\n'd'=Descendente");
	scanf("%s", &Ord);
	// No dejar pasar hasta que se ingrese lo esperado.
	while(Ord != 'a' && Ord != 'd'){
		puts("Por favor ingrese una opcion valida ");
		puts("¿En qué orden desea ver los elementos?\n'a'=Ascendente\n'd'=Descendente");
		scanf("%s", &Ord);
	}
	PrintVector(Ord); // Imprime el vector en el orden que eligio el usuario.
	return 0;
}

// Se define la funcion para llenar los espacios del vector
void FillVector(){
// para i ingal a cero y mientras sea menor a 10, avanza en uno a uno hasta ingresar los valores en vec
	for (int i = 0; i < 10; i++){
		vec[i] = (i + 1)*2;
	}
}

// se define la función para imprimir el vector.
void PrintVector(char o){
	// Definir las variables locales/ auxiliares
	int n = 1;
    int m = 0;
	int a = 1;
	// verifica si el usuario requiere el orden descendente
	if (Ord == 'd'){
		n = -1; // invierte el orden para llenar 
		m = 9; // Define la posicion de inicio del recorrido
	}
    //Si se inicia desde el extremo superior hacia  atras ypara i no igual a 9-m+n, i va
    // avanzando de uno en uno, en este caso para atras
	for (int i = m; i != 9-m+n; i += n){
        // se imprime el valor de vec
		printf("%d\n", vec[i]);
	}
}
