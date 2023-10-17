// main.cpp

#include "functionality.hpp"
#include <iostream>
#include <string>

/**
 * Compilar con: 
 *  cmake. 
 *  make
 * 
* Ejemplo de ejecución:
*   nMin= 100.000, nMax = 500.000, inc = 10.000, rep = 3, 
*   nMediana = 10, nElementosMinimo = 100
* Probar también hasta 4 millones de elementos con inc de 25.000 
*/


/*
* 
* @param nMin Tamano minimo
* @param nMax Tamano maximo
* @param inc Incremento
* @param rep Numero de repeticiones
*/
int main(int argc, char* argv[])
{
    srand(time(NULL));
    if(argc != 7)
    {
        std::cerr << "Error. Uso: " << argv[0] << " <nMin> <nMax> <inc> <rep> <nMediana> <nElementosMinimo>." << std::endl;
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