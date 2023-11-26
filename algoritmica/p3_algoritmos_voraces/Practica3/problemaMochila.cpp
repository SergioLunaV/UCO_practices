/**
 * @file problemaMochila.cpp
 * @author Sergio Luna
 * @brief 
 * @version 0.1
 * @date 2023-10-31
 */

#include <iostream>
#include "problemaMochila.hpp"
#include <fstream>


void problemaMochila(){
    // Volumen de la mochila
    float volumen;
    
    do {
        std::cout << "Introduzca el volumen de la mochila o 0 para salir: ";
        std::cin >> volumen;
        std::cout << "" << std::endl;

        if(volumen < 0)
            std::cerr << "Error. Debe introducir una cantidad de volumen mayor a cero, o 0 para volver atras\n" << std::endl;

        else if(volumen == 0)
            return;
        else
        {
            std::vector<Material> materiales;
            std::vector<MaterialUsado> solucion;

            const char *nombreFichero = "materialesmochila.txt";
            
            cargarMateriales(materiales, nombreFichero);

            mochila(volumen, materiales, solucion);

            escribirSolucion(solucion);
        }
    }while(volumen != 0);
}

void cargarMateriales(std::vector<Material> &materiales, const char *nombreFichero) {
    std::ifstream fichero(nombreFichero);

    if(!fichero)
    {
        std::cout << "Error al abrir " << nombreFichero << std::endl;
        exit(EXIT_FAILURE);
    }

    int etiqueta;
    float volumen;
    float precio;

    while(fichero >> etiqueta >> volumen >> precio){
        Material material(etiqueta, volumen, precio);
        materiales.push_back(material);
    }

    fichero.close();
}

void mochila(float volumenMochila, std::vector<Material> &materiales, std::vector<MaterialUsado> &solucion) {
    float resto = volumenMochila;
    
    solucion.resize(materiales.size());
    
    // Se copia el vector materiales en la solucion y se marcan los materiales como no usados
    for(int i = 0; i < solucion.size(); i++)
    {
        solucion[i].setMaterial(materiales[i]);
        solucion[i].setVolumenUsado(0);
    }
        
    float precioMaximo;
    int materialMaximo;
    bool materialDisponible;

    do {
        precioMaximo = 0;
        materialMaximo = 0;
        materialDisponible = false;

        // Se selecciona el material de mayor coste
        for(int i = 0; i < solucion.size(); i++)
        {
            if(solucion[i].getVolumenUsado() == 0)
            {
                materialDisponible = true;

                if(solucion[i].getMaterial().getPrecio() > precioMaximo)
                {
                    precioMaximo = solucion[i].getMaterial().getPrecio();
                    materialMaximo = i;
                }
            }
        }

        // Comprobamos si el material de mayor coste cabe en la mochila
        if(materialDisponible == true)
        {
            float volumenMaterialMaximo = solucion[materialMaximo].getMaterial().getVolumen();

            if(resto >= volumenMaterialMaximo)
            {
                solucion[materialMaximo].setVolumenUsado(volumenMaterialMaximo);
                resto -= volumenMaterialMaximo;
            }
            else
            {
                solucion[materialMaximo].setVolumenUsado(resto);
                resto = 0;
            }
        }
    } while(resto != 0 && materialDisponible == true);
}

// Nota: El orden en que se muestran es el orden que siga el fichero del que se obtienen los materiales, no el de seleccion
void escribirSolucion(std::vector<MaterialUsado> &solucion) {
    
    float costeFinal = 0;

    std::cout << "La solucion es:" << std::endl;

    for(int i = 0; i < solucion.size(); i++) 
    {
        if(solucion[i].getVolumenUsado() > 0)
        {
            std::cout << "  Material " << solucion[i].getMaterial().getEtiqueta() << ", volumen usado " << solucion[i].getVolumenUsado() << std::endl;
            costeFinal += solucion[i].getVolumenUsado()*solucion[i].getMaterial().getPrecio();
        }
    }
    
    std::cout << "" << std::endl;
    std::cout << "  Coste final = " << costeFinal << "\n" << std::endl;
}