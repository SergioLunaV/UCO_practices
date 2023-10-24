/* 
 * file: functionality.cpp
 */

#include "ClaseTiempo.hpp"
#include "functionality.hpp"
#include "vector.hpp"
#include <cstdlib>
#include <cmath>
#include <fstream>

void comparacionVariantesQuicksort(int nMin, int nMax, int inc, 
    int rep, int nMediana, int nElementosMinimo)
{
    std::vector<double> tiemposRealesQS1, tiemposRealesQS2, numeroElementos;

    tiemposOrdenacionVariantesQuicksort(nMin, nMax, inc, rep, nMediana, nElementosMinimo, 
        tiemposRealesQS1, tiemposRealesQS2, numeroElementos);
}


void tiemposOrdenacionVariantesQuicksort
    (int nMin, int nMax, int incremento, int repeticiones,int nMediana, 
    int nElementosMinimo, std::vector<double>&tiemposRealesQS1, 
    std::vector <double> &tiemposRealesQS2, std::vector <double>&numeroElementos)
{
    Clock reloj1, reloj2;

    // Medias para las iteraciones con tamaño n fijo
    double mediaTamanioNQS1 = 0.0;
    double mediaTamanioNQS2 = 0.0;

    // Medias totales 
    double mediaTotalQS1 = 0.0;
    double mediaTotalQS2 = 0.0;

    // Numero de repeticiones con distinta n
    int cont = 0;

    // Cociente (tiempo medio QS2) / (tiempo medio QS1)
    float cociente;

    for(int i = nMin; i < nMax; i+=incremento)
    {

        std::vector<int> v1(i);
        std::vector<int> v2(i);

        double tiempo1 = 0.0;
        double tiempo2 = 0.0;

        for(int j = 0; j < repeticiones; j++)
        {
            rellenaVector(v1);
            v2 = v1;
            reloj1.start();
            quicksort1(0, v1.size()-1, v1);
            reloj1.stop();
            tiempo1+=reloj1.elapsed();
            
            reloj2.start();
            quicksort2(0, v2.size()-1, v2, nElementosMinimo, nMediana);
            reloj2.stop();
            tiempo2+=reloj2.elapsed();
        }

        // Comprobación opcional para ver que se han ordenado
        /*
        if(estaOrdenado(v1))
            std::cout << "\nv1 (método QS1) está ordenado\n" << std::endl;
        else
            std::cout << "v1 (método QS1) no se ha ordenado\n" << std::endl;
        
        if(estaOrdenado(v2))
            std::cout << "v2 (método QS2) está ordenado\n" << std::endl;
        else
            std::cout << "v2 (método QS2) no se ha ordenado\n" << std::endl;
        */

        // Media para las repeticiones, con tamanio fijo de n
        mediaTamanioNQS1 = tiempo1/repeticiones;
        mediaTamanioNQS2 = tiempo2/repeticiones;

        tiemposRealesQS1.push_back(mediaTamanioNQS1);
        tiemposRealesQS2.push_back(mediaTamanioNQS2);
        numeroElementos.push_back(i);

        std::cout << "n = " << i 
            << "\ttQS1: " << tiempo1/repeticiones << " microsegundos"
            << "\ttQS2: " << tiempo2/repeticiones << " microsegundos"
        << std::endl;

        // Suma de las medias de cada algoritmo para cada valor de n
        mediaTotalQS1 += mediaTamanioNQS1;
        mediaTotalQS2 += mediaTamanioNQS2;

        cont++;
    }

    // Tiempo total para todas las n posibles entre el numero de veces ejecutado
    mediaTotalQS1 = mediaTotalQS1/cont;
    mediaTotalQS2 = mediaTotalQS2/cont;

    std::cout << "\nMedias totales:    "
        << "QS1: " << mediaTotalQS1 << " microsegundos"
        << "\tQS2: " << mediaTotalQS2 << " microsegundos\n"
    << std::endl;

    cociente = mediaTotalQS2/mediaTotalQS1;

    std::cout << "Cociente (QS2/QS1) = " << cociente << "\n" << std::endl;

    almacenaTiempos1(numeroElementos, tiemposRealesQS1, tiemposRealesQS2);
}



void almacenaTiempos1(std::vector <double> numeroElementos, 
    std::vector <double> tiemposRealesQS1, std::vector <double> tiemposRealesQS2)
{
    std::ofstream fichero("tiemposReales.txt");

    if(!fichero)
    {
        std::cout << "Error al abrir tiemposReales.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<numeroElementos.size(); i++)
        fichero << numeroElementos[i] << "\t" << tiemposRealesQS1[i] << "\t" << tiemposRealesQS2[i] << "\n";
    
    fichero.close();
}

