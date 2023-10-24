/*
 * file: algoritmos.cpp
 */

#include "algoritmos.hpp"
#include <iostream>
#include <stdlib.h>

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


// Algoritmo de Ordenación por Selección de un vector
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

