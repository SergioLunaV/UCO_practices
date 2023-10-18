cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(practica2)

# Definición de los archivos fuente
set(SOURCES
    ClaseTiempo.hpp
    functionality.cpp
    functionality.hpp
    main.cpp
#    sistemaEcuaciones.cpp
#    sistemaEcuaciones.hpp
)

# Ruta al directorio de los archivos fuente
set(SOURCES_DIR ".")

# Agrega el ejecutable y sus fuentes
add_executable(p2.exe ${SOURCES})

# Establece la ruta a los archivos fuente
target_include_directories(p2.exe PRIVATE ${SOURCES_DIR})
