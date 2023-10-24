/*
 * file: gnuplot.cpp
 */

#include "gnuplot.hpp"
#include <fstream>

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

// Ejecuta un fichero con el visor predeterminado del sistema
void muestraGrafica(std::string fichero)
{
    std::string comando = "xdg-open " + fichero;
    int result = system(comando.c_str());   // c_str() devuelve un puntero a la cadena

    if(result != 0)
        std::cerr << "Error al abrir el archivo. Código de salida: " << result << std::endl;
    else
        std::cout << "Se ha abierto la gráfica correspondiente a los datos iniciales introducidos.\n" << std::endl;
}
