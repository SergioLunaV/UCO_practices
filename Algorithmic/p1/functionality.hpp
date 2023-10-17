// functionality.hpp
// contains the headers of the functions for practice 1

#include <iostream>
#include <vector>
#include "ClaseTiempo.hpp"

#ifndef FUNCTIONALITY_HPP
#define FUNCTIONALITY_HPP


    /* Apartado 1 */

    void ordenacionSeleccion();

    void ordenacionSeleccion(std::vector<int> &v);

    void tiemposOrdenacionSeleccion(int nMin, int nMax, int inc, int repeticiones, 
        std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);

    void ajusteCuadratico(const std::vector <double> &numeroElementos, 
        const std::vector <double> &tiemposReales, std::vector <double> &a);

    bool estaOrdenado(const std::vector <int> &v);

    void rellenaVector(std::vector<int> &v);

    void muestraEcuacionSeleccion(std::vector <double> a);


    /* Apartado 2 */
    void matrizCuadrado();

    void rellenaMatriz(std::vector < std::vector <double>> &matrizDatos, int n);

    void ajusteCubico(const std::vector <double> &n, 
        const std::vector <double> &tiemposReales, std::vector <double> &a);

    void tiemposMatrizCuadrado(int nMin, int nMax, int inc, 
        std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);

    void muestraEcuacionCuadrado(std::vector <double> a);


    /* Apartado 3 */

    void fibonacciRecursivo();
    
    void ajusteExponencial(const std::vector <double> &n, 
        const std::vector <double> &tiemposReales, std::vector <double> &a);

    void calcularTiemposEstimadosExponencial(const std::vector <double> &n,
        const std::vector <double> &a, std::vector <double> &tiemposEstimados);

    double calcularTiempoEstimadoExponencial(const double &n, const std::vector <double> &a);

    void tiemposFibonacci(int nMin, int nMax, int inc,
        std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);

    int algoritmoFibonacciRecursivo(int n);

    void estimaTiempoExponencial(std::vector <double> a);

    void muestraEcuacionExponencial(std::vector <double> a);


    /* Funciones comunes */
    
    double sumatorio(const std::vector <double> &n, const std::vector <double> &t, int expN, 
        int expT);
    
    void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, 
        const std::vector <double> &a, std::vector <double> &tiemposEstimados, int grado);
    
    double calcularTiempoEstimadoPolinomico(const double &n, 
        const std::vector <double> &a, int grado);

    double calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, 
        const std::vector <double> &tiemposEstimados);

    double media(std::vector <double> v);
    
    double sumatorioElementosCuadrado(std::vector<double> v);

    double varianza(std::vector<double> v);

    void almacenaTiempos1(std::vector<double> numeroElementos, 
        std::vector<double> tiemposReales);

    void almacenaTiempos2(std::vector<double> numeroElementos, 
        std::vector<double> tiemposReales, std::vector<double> tiemposEstimados);

    void ejecutaGnuplot(std::string fichero);

    void muestraGrafica(std::string fichero);

    void estimaTiempo(std::vector <double> a, int grado);

    void tiempoFormateado(double tiempo_microsegundos);

    
#endif