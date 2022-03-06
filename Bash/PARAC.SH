#!/bin/bash
echo Escribe el nombre del archivo
read nombre
if [ -z "$nombre" ];then 
    echo el archivo esta vacio
elif [ -n "$nombre" ]; then
    touch $nombre.c
    echo se creo el archivo "$nombre.c"
    echo "/* " >> "$nombre".c
    echo "Autor: $USER" >> "$nombre".c
    #echo "Compilador: ${}" >> "$nombre".c
    #echo "Compilado: ${}" >> "$nombre".c
    echo "Fecha: $(date)" >> "$nombre".c
    read -p "Ingrese la libreria que desea agregar " library
    echo "Librerías: $library" >> "$nombre".c
    read -p "Ingrese el resumen del documento: " summary
    echo "Resumen: $summary" >> "$nombre".c
    read -p "¿Cuáles son las entradas? " input
    echo "Entradas: $input" >> "$nombre".c
    read -p "¿Cuáles son las salidas? " output
    echo "Salidas: $output" >> "$nombre".c
    echo "*/" >> "$nombre".c
    echo "// Librerías" >> "$nombre".c
    echo "#include <$library.h>" >> "$nombre".c
    echo "// Numerar los pasos del pseudocódigo" >> "$nombre".c
fi