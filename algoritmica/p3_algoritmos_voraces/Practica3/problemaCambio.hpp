/**
 * @file problemaCambio.hpp
 * @author Sergio Luna
 * @brief Cabeceras de las funciones utilizadas para el programa del problema del cambio
 * @version 0.1
 * @date 2023-10-31
 */

#ifndef PRPOBLEMACAMBIO_HPP
#define PROBLEMACAMBIO_HPP

#include "moneda.hpp"
#include <vector>


/**
 * @brief Función de medio nivel para el problema del cambio
 * 
 * Pide al usuario el valor monetario, carga el sistema monetario del fichero y llama a la función de bajo nivel
 */
void problemaCambio();

/**
 * @brief Lee el sistema monetario del fichero y lo almacena en un vector de la clase Moneda
 * 
 * @param sistemaMonetario Conjunto de monedas que se van a considerar
 * @param nombreFichero Nombre del fichero que almacena el sistema monetario
 */
void cargarSistemaMonetario(std::vector <Moneda> &sistemaMonetario, const char *nombreFichero);

/**
 * @brief Calcula el número óptimo de monedas de cada tipo necesarias para devolver el cambio
 *  (Algoritmo del cambio)
 * 
 * La solución de guarda en un vector de enteros donde cada elemento i-ésimo almacena
 * cuantas unidades se necesitan para la i-ésima moneda o billete del sistema monetario.
 * 
 * @param cantidad Valor monetario para el que se calcula el cambio
 * @param sistemaMonetario Conjunto de monedas distintas a considerar
 * @param solucion Cantidad de monedas mínimas necesarias para dar el cambio,
 *     correspondiendo la posición i-ésima con la moneda, y su contenido con la cantidad
 */
void cambio(int cantidad, std::vector <Moneda> sistemaMonetario, std::vector <int> &solucion);

/**
 * @brief Muestra la solución del problema
 * 
 * @param solucion Vector que contiene para los i-ésimos valores las i-ésimas cantidades
 * @param sistemaMonetario Conjunto de monedas distintas a considerar
 */
void escribirSolucion(std::vector <int> &solucion, std::vector <Moneda> &sistemaMonetario);

#endif