#!/bin/bash

# Practica 2: Quicksort
cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficaQuicksort.eps"
set key right bottom
set xlabel "Numero elementos N"
set ylabel "Tiempos reales"
plot 'tiemposReales.txt' using 1:2 t "QuickSort1" w l, 'tiemposReales.txt' using 1:3 t "QuickSort2" w l
_end_
