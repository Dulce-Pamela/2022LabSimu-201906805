unset label
clear
## epslatex es para un archivo latex
set terminal epslatex
set output "Ej4.tex"
set title "Prueba grafico"
set xlabel "x"
set ylabel "datos"
set grid
set style data boxplot
plot "datos" using 2:3
