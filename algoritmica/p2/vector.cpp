/*
 * file: vector.cpp
 */ 

#include "vector.hpp"
#include <stdlib.h>

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
