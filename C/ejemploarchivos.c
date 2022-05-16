/*
Autor:         Dulce Calan
Fecha:         Tue Apr 19 13:04:17 CST 2022
Compilador     gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar       gcc -o ejemploarchivos.out ejemploarchivos.c
Librerias      stdio
Resumen       ejemplo basico del uso de archivos
*/

//librerias
#include <stdio.h>

//declaro un caracter, me va servir para poder almacenar la informacion
//si queremos un elemento de retorno es int
int main(){
    //declarando un caracter para el ingreso de datos
    int c;
    //una variable de conteo
    int dato =0;
    //voy a hacer un archivo simple
    //inicializo el puntero de archivo.
    FILE* pf; //como es puntero lleva asterisco
    //la forma mas sencilla de escribir el nombre del archivo es por medio de un puntero
    char *salida= "salida.txt";
    //primero se debe abrir la comunicacion, luego se debe validar
    //la primera condicion es ver si logra abrir el archivo
    // el puntero que ya cree, wt por que no existe el archivo
    if ((pf= fopen(salida,"wt"))==NULL)
    {
        puts("Existe un error de escritura");
        //retur 1 para que se salga del programa
        return 1;//el return 1 para que se salga del programa 
    }
    puts("Escribir algo");
    //vamos a obtener desde la terminal 10 caracteres o EOF para terminar
    //primero debo decirle que voy a obtener este valor
    //mientras el valor del caracter se mantenga y este valor no se 
    // EOF haga los siguiente y mientras no sea mayor que 10
    while ((c=getchar())!=EOF&&dato<10)
    {
        //validar que se ingrese un caracter pero no identifiqueenter (\n) como un 
        //caracter mas
        if ((c)!='\n')
        {
            putc(c,pf);
            dato++;// que siga avanzando por que ya guardo un caracter
            printf("Caracter %d \n", dato);

        }
        
    }
    //voy a cerrar mi archivo
    //MUY IMPORTANTE CERRAR LA COMUNICACION
    fclose(pf);
    return 0;// para decirle que todo salio bien

}