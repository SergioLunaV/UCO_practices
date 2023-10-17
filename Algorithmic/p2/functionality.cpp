// functionality.cpp

#include "ClaseTiempo.hpp"
#include "functionality.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <time.h>


// Algoritmo de quicksort del tema 5: el pivote es el elemento central
void quicksort1(int iz, int de, std::vector<int>& v)
{
    int i = iz;
    int j = de;
    int x = v[(iz + de)/2];     // x es el pivote

    do{
        while(v[i] < x)
            i++;
        while(v[j] > x)
            j--;
        
        if(i <= j){
            // Intercambiar v[i] y v[j]
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    // Llamadas recursivas para los subvectoress
    if(iz < j)
        quicksort1(iz, j, v);
    if(i < de)
        quicksort1(i, de, v);
}


// Algoritmo de quicksort con variante: el pivote es la mediana de un subvector ordenado por seleccion
void quicksort2(int iz, int de, std::vector<int>& v, int nElementosMinimo, int nMediana)
{
    int i = iz;
    int j = de;
    int x;      // x es el pivote
    
    // Se toma el central como pivote
    if(v.size() < nElementosMinimo)
        x = v[(iz + de)/2];     
    else // Se toma como pivote la mediana de un subvector con valores aleatorios de v
    {
        std::vector<int> vectorMediana(nMediana);

        // Rellenamos el subvector con valores de v
        for(int i=0; i<nMediana; ++i)
        {
            int pos = rand()%v.size();
            vectorMediana[i] = v[pos];
        }
        // Ordenamos el subvector
        ordenacionSeleccion(vectorMediana);
        // Utilizamos como pivote la mediana del subvector ordenado
        x = vectorMediana[nMediana/2];
    }

    do{
        while(v[i] < x)
            i++;
        while(v[j] > x)
            j--;
        
        if(i <= j){
            // Intercambiar v[i] y v[j]
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    // Llamadas recursivas para los subvectoress
    if(iz < j)
        quicksort1(iz, j, v);
    if(i < de)
        quicksort1(i, de, v);

}



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

    for(int i = nMin; i < nMax; i+=incremento)
    {
        std::vector<int> v(i);

        double tiempo1 = 0.0;
        double tiempo2 = 0.0;

        for(int j = 0; j < repeticiones; j++)
        {
            rellenaVector(v);
            reloj1.start();
            quicksort1(0, v.size()-1, v);
            reloj1.stop();
            tiempo1+=reloj1.elapsed();

            rellenaVector(v);
            reloj2.start();
            quicksort2(0, v.size()-1, v, nElementosMinimo, nMediana);
            reloj2.stop();
            tiempo2+=reloj2.elapsed();
        }

        tiemposRealesQS1.push_back(tiempo1/repeticiones);
        tiemposRealesQS2.push_back(tiempo2/repeticiones);
        numeroElementos.push_back(i);

        std::cout << "n = " << i 
        << "\ttQS1: " << tiempo1/repeticiones << " microsegundos"
        << "\ttQS2: " << tiempo2/repeticiones << " microsegundos" << std::endl;
    }
    std::cout << std::endl;
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

// Algoritmo de Ordenación por Selección
void ordenacionSeleccion(std::vector<int> &v)
{
    int posicionMenor;
    int aux;

    for(int i=0; i<v.size()-2; i++)
    {
        posicionMenor = i;

        for(int j=i+1; j<v.size()-1; j++)
        {
            if(v[j]<v[posicionMenor])
            {
                posicionMenor=j;
            }
        }

        aux=v[i];
        v[i]=v[posicionMenor];
        v[posicionMenor]=aux;
    }
}



/**************************/
/* Funciones de vectores */
/************************/

// Rellena un vector de enteros con números aleatorios [0, 10000000)
void rellenaVector(std::vector<int> &v)
{
    for(auto it=v.begin(); it<v.end(); it++)
    {
        *it=std::rand()%1000000;
    }
}


// Comprueba si un vector está ordenado
bool estaOrdenado(const std::vector<int> &v)
{
    // Recorremos el vector
    for(auto it=v.begin(); it<v.end(); it++)
    {
        // Si el elemento actual es mayor al siguiente no está ordenado (de menor a mayor)
        if(it>it+1)
        {
            return false;
        }
    }
    return true;
}




/* GNUPLOT */

/**
* Generación de la gráfica mediante la ejecución del archivo gnuplot.sh
* Recuerde añadir los permisos de ejecución para el fichero gnuplot.sh
* */
void ejecutaGnuplot(std::string fichero)
{
    int result = system(fichero.c_str());

    // Verificación del resultado de la ejecución
    if(result != 0)
        std::cerr << "Error al ejecutar el script " << fichero << ". Código de salida: " << result << std::endl;
}

// Ejecuta un fichero
void muestraGrafica(std::string fichero)
{
    std::string comando = "xdg-open " + fichero;
    int result = system(comando.c_str());   // c_str() devuelve un puntero a la cadena

    if(result != 0)
        std::cerr << "Error al abrir el archivo. Código de salida: " << result << std::endl;
    else
        std::cout << "Se ha abierto la gráfica correspondiente a los datos iniciales introducidos.\n" << std::endl;
}

