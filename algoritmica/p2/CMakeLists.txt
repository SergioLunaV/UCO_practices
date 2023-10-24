cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(practica2)

# Definición de los archivos fuente
set(SOURCES
    ClaseTiempo.hpp
	algoritmos.cpp
	algoritmos.hpp
	vector.cpp
	vector.hpp
	gnuplot.cpp
	gnuplot.hpp
    functionality.cpp
    functionality.hpp
    main.cpp
	
)

# Ruta al directorio de los archivos fuente
set(SOURCES_DIR ".")

# Agrega el ejecutable y sus fuentes
add_executable(p2.exe ${SOURCES})

# Establece la ruta a los archivos fuente
target_include_directories(p2.exe PRIVATE ${SOURCES_DIR})
