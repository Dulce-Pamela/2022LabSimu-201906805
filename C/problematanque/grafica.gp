unset label
clear
## epslatex es para un archivo latex
set terminal jpeg
set output "graficosaltura.jpg"
set title "Prueba grafico"
set xlabel "x"
set ylabel "datos"
set grid
set style data point
plot "altura" 