/* 
* main.cpp
* @Author: Sergio Luna Puerto
* Hacer cmake . y después make.
* El ejecutable creado se llama p1.exe.
* Nota: Si desea abrir la gráficas generadas o cualquier otro fichero que se este modificando 
* durante la ejecución del programa, esperar a que termine (seguir instrucciones de la consola).
**/

#include <iostream>
#include <cstdlib>
#include "functionality.hpp"

int main()
{
    srand(time(0));
    
    int opt;
    while(opt!=4)
    {
        std::cout <<  "-----------------------------------------------------------" << std::endl; 
        std::cout << "Elija un algoritmo:" << std::endl;
        std::cout << "1. Ordenación por selección." << std::endl;
        std::cout << "2. Matriz cuadrado" << std::endl;
        std::cout << "3. Fibonacci Recursivo" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "" << std::endl;
        
        std::cin>>opt;

        std::cout << "" << std::endl;

        switch(opt)
        {
            case 1:
                ordenacionSeleccion();
            break;
            
            case 2:
                matrizCuadrado();
            break;
                
            case 3:
                fibonacciRecursivo();
            break;
            
            case 4:
                std::cout<<"Saliendo...\n"<<std::endl;
                exit(0);
            break;
            
            default:
                std::cout<<"Error: Lo que ha introducido no corresponde a una de las opciones.\n" << std::endl;
        }
    }

}