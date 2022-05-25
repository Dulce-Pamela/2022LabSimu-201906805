unset label
clear
set terminal pdf
set output 'Grafica_PV.pdf'
set title 'Comportamiento Presion vs Volumen'
set xlabel 'ln(Volumen)'
set ylabel 'Ln(Presion)'
set grid
set key right
plot '[ln(V),ln(P)]' w p, -1.386*x + 9.595 w l
