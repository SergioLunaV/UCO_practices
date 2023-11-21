/**
 * @file problemaCambio.cpp
 * @author Sergio Luna
 * @brief Cuerpo de las funciones utilizadas para el programa del problema del cambio
 * @version 0.1
 * @date 2023-10-31
 */

#include "problemaCambio.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void problemaCambio(){
    int cantidad;
    
    do {
        std::cout << "Introduzca un valor de cambio en centimos o 0 para volver atras: ";
        std::cin >> cantidad;
        std::cout << "" << std::endl;

        if(cantidad < 0)
            std::cerr << "Error. Debe introducir una cantidad de cambio mayor a cero, o 0 para volver atras.\n" << std::endl;

        else if(cantidad == 0)
            return;

        else
        {
            std::vector <Moneda> sistemaMonetario;
            std::vector<int> solucion; // el elemento i-ésimo almacenará la cantidad de la moneda i-ésima 
            
            const char *nombreFichero = "sistemamonetario.txt";

            cargarSistemaMonetario(sistemaMonetario, nombreFichero);
            cambio(cantidad, sistemaMonetario, solucion);

            // Si no ha encontrado solución, volver al menú
            if(solucion.empty())
            {
                std::cerr << "No se ha podido encontrar cambio para una cantidad de " << cantidad << " centimos\n" << std::endl;
                return;
            }
            
            escribirSolucion(solucion, sistemaMonetario);
        }
    } while (cantidad != 0);
}

void cargarSistemaMonetario(std::vector <Moneda> &sistemaMonetario, const char *nombreFichero){
    
    std::ifstream fichero(nombreFichero);

    if(!fichero)
    {
        std::cout << "Error al abrir " << nombreFichero << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string valorString;

    while(fichero >> valorString)
    {
        int valorInt = std::stoi(valorString);

        Moneda moneda(valorInt);
        
        sistemaMonetario.push_back(moneda);
    }

    fichero.close();
}

void cambio(int cantidad, std::vector <Moneda> sistemaMonetario, std::vector <int> &solucion){

    for(int i = 0; i < sistemaMonetario.size() && cantidad > 0; i++) 
    {
        solucion.push_back(cantidad/sistemaMonetario[i].getValor());
        cantidad-=solucion[i]*sistemaMonetario[i].getValor();
    }
    
}

void escribirSolucion(std::vector <int> &solucion, std::vector <Moneda> &sistemaMonetario){

    std::cout << "La solucion es:" << std::endl;

    for(int i = 0; i < solucion.size(); i++){
        if(solucion[i]!=0)
            std::cout << "  " << solucion[i] << " moneda(s) de " << sistemaMonetario[i].getValor() << " centimos" << std::endl;
    }
    std::cout << "" << std::endl;
}
