# primer grafica
unset label
clear
set terminal png
set output "tvsHMun.png" #tiempo versus altura
set grid
set title "Grafica Tiempo vs Altura Cohete Ah Mun"
set xlabel "Tiempo"
set ylabel "Altura"
plot "datos.dat" u 1:2 w lp t "t-y"

#segunda graica
unset label
clear
set terminal png
set output "tvsVMun.png" #tiempo versus velocidad
set grid
set title "Grafica Tiempo vs Velocidad Cohete Ah Mun"
set xlabel "Tiempo"
set ylabel "Velocidad"
plot "datos.dat" u 1:3 w lp t "t-v"

#tercera grafica
unset label
clear
set terminal png
set output "HvsVMun.png" #altura vs velocidad
set grid
set title "Grafica Altura-Velocidad Cohete Ah Mun"
set xlabel "Altura"
set ylabel "Velocidad"

plot "datos.dat" u 2:3 w lp t "y-v"