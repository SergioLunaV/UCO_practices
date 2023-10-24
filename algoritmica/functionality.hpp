/*
 * file: functionality.hpp
 */

#ifndef FUNCTIONALITY_HPP
#define FUNCTIONALITY_HPP

    #include "algoritmos.hpp"
    #include <iostream>
    #include <vector>
    
    void comparacionVariantesQuicksort(int nMin, int nMax, int inc, 
        int rep, int nMediana, int nElementosMinimo);
    
    void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, 
        int repeticiones,int nMediana, int nElementosMinimo, 
        std::vector<double>&tiemposRealesQS1, std::vector <double> &tiemposRealesQS2, 
        std::vector <double>&numeroElementos);

    void almacenaTiempos1(std::vector <double> numeroElementos, 
        std::vector <double> tiemposRealesQS1, std::vector <double> tiemposRealesQS2);

#endif