// functionality.hpp

#include <iostream>
#include <vector>


#ifndef FUNCTIONALITY_HPP
#define FUNCTIONALITY_HPP

    /* Funciones de quicksort */

    void quicksort1(int iz, int de, std::vector<int>& v);
    void quicksort2(int iz, int de, std::vector<int>& v, int nElementosMinimo, int nMediana);

    
    void comparacionVariantesQuicksort(int nMin, int nMax, int inc, 
        int rep, int nMediana, int nElementosMinimo);
    
    void tiemposOrdenacionVariantesQuicksort
        (int nMin, int nMax, int incremento, int repeticiones,int nMediana, 
        int nElementosMinimo, std::vector<double>&tiemposRealesQS1, 
        std::vector <double> &tiemposRealesQS2, std::vector <double>&numeroElementos);

    void almacenaTiempos1(std::vector <double> numeroElementos, 
        std::vector <double> tiemposRealesQS1, std::vector <double> tiemposRealesQS2);    
    
    
    /* Funciones de vectores */

    void rellenaVector(std::vector<int> &v);
    bool estaOrdenado(const std::vector<int> &v);
    
    void ordenacionSeleccion(std::vector<int> &v);


    /* Funciones de gnuplot*/

    void ejecutaGnuplot(std::string fichero);

    void muestraGrafica(std::string fichero);

#endif