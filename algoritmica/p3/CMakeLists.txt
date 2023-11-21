cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(practica3)

# Definición de los archivos fuente
set(SOURCES
	moneda.hpp
	problemaCambio.hpp
    problemaCambio.cpp
	material.hpp
	materialUsado.hpp
	problemaMochila.hpp
	problemaMochila.cpp
	main.cpp
)

# Ruta al directorio de los archivos fuente
set(SOURCES_DIR ".")

# Agrega el ejecutable y sus fuentes
add_executable(p3.exe ${SOURCES})

# Establece la ruta a los archivos fuente
target_include_directories(p3.exe PRIVATE ${SOURCES_DIR})
