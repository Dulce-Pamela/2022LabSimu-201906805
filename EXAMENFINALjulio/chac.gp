# primer grafica
unset label
clear
set terminal png
set output "tvsHChac.png" #tiempo versus altura
set grid
set title "Grafica Tiempo vs Altura Cohete Chac"
set xlabel "Tiempo"
set ylabel "Altura"
plot "datos.dat" u 1:2 w lp t "t-y"

#segunda graica
unset label
clear
set terminal png
set output "tvsVChac.png" #tiempo versus velocidad
set grid
set title "Grafica Tiempo vs Velocidad Cohete Chac"
set xlabel "Tiempo"
set ylabel "Velocidad"
plot "datos.dat" u 1:3 w lp t "t-v"

#tercera grafica
unset label
clear
set terminal png
set output "HvsVChac.png" #altura vs velocidad
set grid
set title "Grafica Altura-Velocidad Cohete Chac"
set xlabel "Altura"
set ylabel "Velocidad"

plot "datos.dat" u 2:3 w lp t "y-v"