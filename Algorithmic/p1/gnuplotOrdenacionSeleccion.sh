#!/bin/bash

# Práctica 1 - Apartado 1
cat << _end_ | gnuplot
set terminal postscript eps color
set output "ordenacionSeleccion.eps"
set key right bottom
set xlabel "Numero elementos N"
set ylabel "Tiempos Estimados"
plot 'tiempoReales.txt' using 1:2 t "Tiempos reales respecto numero elementos", 'datosFinales.txt' using 1:3 t "Tiempos estimados respecto numero elementos" w l
_end_
