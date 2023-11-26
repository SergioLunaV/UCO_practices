/**
 * @file problemaMochila.hpp
 * @author Sergio Luna
 * @brief 
 * @version 0.1
 * @date 2023-10-31
 */

#ifndef PROBLEMAMOCHILA_HPP
#define PROBLEMAMOCHILA_HPP

#include "material.hpp"
#include "materialUsado.hpp"
#include <vector>

/**
 * @brief Función de medio nivel para el problema de la mochila
 * 
 * Pide al usuario el volumen, carga los materiales del fichero y llama a la función de bajo nivel
 * 
 */
void problemaMochila();

/**
 * @brief Lee los materiales del fichero "materialesmochila.txt", con la estructura etiqueta, volumen y precio
 * 
 * @param materiales Vector que almacena los materiales leídos
 * @param nombreFichero Fichero del cual se leen los materiales
 */

void cargarMateriales(std::vector<Material> &materiales, const char *nombreFichero);

/**
 * @brief Algoritmo del problema de la mochila
 * 
 * Introduce los materiales empezando con los de mayor precio, de forma que 
 * el ultimo sera el que quepa parcialmente
 * 
 * @param volumenMochila Volumen de la mochila
 * @param materiales Vector de los materiales a considerar para meter en la mochila
 * @param solucion Vector de los materiales usados donde se guarda el material y el volumen usado de los mismos
 */
void mochila(float volumenMochila, std::vector<Material> &materiales, std::vector<MaterialUsado> &solucion);

/**
 * @brief Muestra por pantalla, ordenando por la etiqueta del material,  
 * el material y el volumen utilizado del mismo, y finalmente el coste final de la mochila
 * 
 * @param solucion Vector de materialesUsados donde se guarda la solucion (materiales y volumen usado)
 */
void escribirSolucion(std::vector<MaterialUsado> &solucion);

#endif