/**
 * @file main.cpp
 * @author Sergio Luna
 * @brief Programa principal para el problema del cambio y de la mochila 
 *      (versión voraz)
 * @version 0.1
 * @date 2023-10-31
 * 
 * Compilación: "cmake ." y después "make"
 * 
 * Objetivos: 
 *  1. Implementa el algoritmo de obtención de la solución al problema del cambio
 * 
 *  2. Implementa el algoritmo de obtención de la solución al problema de la mochila
 */


#include <iostream>

void problemaCambio();
void problemaMochila();

int main(int argc, char **argv){

    int opcion = 0;

    std::cout << "" << std::endl;

    do{
        std::cout << "Introduzca una opcion:" << std::endl;
        std::cout << "[1] Problema del cambio" << std::endl;
        std::cout << "[2] Problema de la mochila" << std::endl;
        std::cout << "[0] Salir" << std::endl;
        std::cout << "" << std::endl;
        std::cin >> opcion;
        std::cout << "" << std::endl;

        switch(opcion) {
            case 1:
                problemaCambio();
            break;
            case 2:
                problemaMochila();
            break;
            case 0:
                return 0;
            break;
            default:
                std::cout << "Error. La opción introducida no coincide con una de las indicadas.\n" << std::endl;
        }

    } while(opcion != 0);
   
}