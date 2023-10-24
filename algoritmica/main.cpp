/* 
 * file: main.cpp
 * 
 * Programa principal para la práctica 2 de algorítmica sobre análisis del algoritmo
 * QuickSort y una variante.
 *
 * Compilar con: 
 *  cmake. 
 *  make
 * 
* Ejemplo de ejecución:
*   nMin= 100000, nMax = 500000, inc = 10000, rep = 3, 
*   nMediana = 10, nElementosMinimo = 100
* Probar también hasta 4 millones de elementos con inc de 25000 
*/



#include "functionality.hpp"
#include "gnuplot.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>



/*
* @param nMin Tamano minimo
* @param nMax Tamano maximo
* @param inc Incremento
* @param rep Numero de repeticiones
*/
int main(int argc, char* argv[])
{
    std::cout << std::endl;
    srand(time(NULL));
    if(argc != 7)
    {
        std::cerr << "Error: " << std::endl;
        std::cerr << "       Uso: " << argv[0] << " <nMin> <nMax> <inc> <rep> <nMediana> <nElementosMinimo>." << std::endl;
        std::cerr << "       Por ejemplo: 100000 500000 10000 3 10 100" << std::endl;
        return -1;
    }

    int nMin = std::stoi(argv[1]);
    int nMax = std::stoi(argv[2]);
    int inc = std::stoi(argv[3]);
    int rep = std::stoi(argv[4]);
    int nMediana = std::stoi(argv[5]);
    int nElementosMinimo = std::stoi(argv[6]);

    comparacionVariantesQuicksort(nMin, nMax, inc, 
        rep, nMediana, nElementosMinimo);

    ejecutaGnuplot("./gnuplotQuicksort.sh");        // Crea la gráfica mediante gnuplot
    muestraGrafica("graficaQuicksort.eps");         // Muestra la gráfica   

}