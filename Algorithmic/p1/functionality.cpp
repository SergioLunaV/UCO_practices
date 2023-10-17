// functionality.cpp
// contains the definitions of the functions for practice 1

#include "functionality.hpp"
#include "sistemaEcuaciones.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>

// Apartado 1
void ordenacionSeleccion()
{
    /*Pedir nMin, nMax, inc, rep */
    int nMin, nMax, inc, rep;

    std::cout << "Introduce el número mínimo de elementos: ";
    std::cin >> nMin;
    std::cout << "Introduce el número máximo de elementos: ";
    std::cin >> nMax;
    std::cout << "Introduce el número de incrementos: ";
    std::cin >> inc;
    std::cout << "Introduce el número de repeticiones: ";
    std::cin >> rep;
    std::cout << "" << std::endl;

    std::vector <double> tiemposReales;
    std::vector <double> numeroElementos;
    std::vector <double> a(3);  // matriz de coeficientes de nxn, siendo n el número de incógnitas del sistema.

    tiemposOrdenacionSeleccion(nMin, nMax, inc, rep, tiemposReales, numeroElementos);   // Calcula tiempos reales
    ajusteCuadratico(numeroElementos, tiemposReales, a);    // Calcula tiempos estimados
    estimaTiempo(a, 2);         // Calcula el tiempo estimado para un tamaño n concreto
    ejecutaGnuplot("./gnuplotOrdenacionSeleccion.sh");         // Crea la gráfica mediante gnuplot
    muestraGrafica("ordenacionSeleccion.eps");       // Muestra la gráfica   
}


/**
* Apartado 2
* El número de repeticiones es 1
* Se ajusta un polinomio de grado 3
* */
void matrizCuadrado()
{
    /* Pedir nMin, nMax, inc */
    int nMin, nMax, inc;

    std::cout << "Introduce el orden mínimo de la matriz: ";
    std::cin >> nMin;
    std::cout << "Introduce el orden máximo de la matriz: ";
    std::cin >> nMax;
    std::cout << "Introduce el número de incrementos: ";
    std::cin >> inc;
    std::cout << "" << std::endl;

    std::vector <double> tiemposReales;
    std::vector <double> numeroElementos;
    std::vector <double> a(4);

    tiemposMatrizCuadrado(nMin, nMax, inc, tiemposReales, numeroElementos); // Calcula los tiempos reales
    ajusteCubico(numeroElementos, tiemposReales, a);    // Calcula los tiempos estimados
    estimaTiempo(a, 3);        // Calcula el tiempo estimado para un tamaño n concreto
    ejecutaGnuplot("./gnuplotMatrizCuadrado.sh");          // Crea la gráfica mediante gnuplot
    muestraGrafica("matrizCuadrado.eps");       // Muestra la gráfica   
}


/**
* Apartado 3
* Curva ajuste: t(n) = a0 + a1*2^n
* Sustitución: z = 2^n
* Obtenemos: t(n) = a0 +a1*z (Ajuste polinómico de grado 1)
* */
void fibonacciRecursivo()
{
    /* Pedir nMin, nMax, inc */
    int nMin, nMax, inc;

    std::cout << "Introduce el número mínimo de elementos: ";
    std::cin >> nMin;
    std::cout << "Introduce el número máximo de elementos: ";
    std::cin >> nMax;
    std::cout << "Introduce el número de incrementos: ";
    std::cin >> inc;
    std::cout << "" << std::endl;

    std::vector <double> tiemposReales;
    std::vector <double> numeroElementos;
    std::vector <double> a(2);  // matriz de coeficientes de nxn, siendo n el número de incógnitas del sistema.

    tiemposFibonacci(nMin, nMax, inc, tiemposReales, numeroElementos);   // Calcula tiempos reales
    ajusteExponencial(numeroElementos, tiemposReales, a);    // Calcula tiempos estimados
    estimaTiempoExponencial(a);         // Calcula el tiempo estimado para un tamaño n concreto
    ejecutaGnuplot("./gnuplotFibonacci.sh");          // Crea la gráfica mediante gnuplot
    muestraGrafica("fibonacci.eps");       // Muestra la gráfica   

}



/*****************/
/** Algoritmos **/
/***************/

// Algoritmo de Ordenación por Selección
void ordenacionSeleccion(std::vector<int> &v)
{
    int posicionMenor;
    int aux;

    for(int i=0; i<v.size()-2; i++)
    {
        posicionMenor = i;

        for(int j=i+1; j<v.size()-1; j++)
        {
            if(v[j]<v[posicionMenor])
            {
                posicionMenor=j;
            }
        }

        aux=v[i];
        v[i]=v[posicionMenor];
        v[posicionMenor]=aux;
    }
}

int algoritmoFibonacciRecursivo(int n)
{
    if(n <= 1)
        return 1;
    else
        return algoritmoFibonacciRecursivo(n-1) + algoritmoFibonacciRecursivo(n-2);
}

/********************************/
/* Funciones para los cálculos */
/******************************/

// Calcula los tiempos reales para el algoritmo de ordenación por selección
void tiemposOrdenacionSeleccion(int nMin, int nMax, int inc, int repeticiones, 
    std::vector <double> &tiemposReales, std::vector <double> &numeroElementos)
{
    Clock reloj;

    for(int i=nMin; i<nMax; i+=inc)
    {
        std::vector<int> v(i);

        double tiempo = 0.0;

        for(int j=0; j<repeticiones; j++)
        {
            rellenaVector(v);
            reloj.start();
            ordenacionSeleccion(v);
            reloj.stop();
            tiempo+=reloj.elapsed();
        }
        
        tiemposReales.push_back(tiempo/repeticiones);
        numeroElementos.push_back(i);
        
        std::cout << "Número de elementos: " << i << "\tTiempo medio: " << tiempo/repeticiones << " microsegundos."<< std::endl;
    }

    std::cout << "" << std::endl;
    almacenaTiempos1(numeroElementos, tiemposReales);
}


void ajusteCuadratico(const std::vector <double> &numeroElementos, 
    const std::vector <double> &tiemposReales, std::vector <double> &a)
{
    std::vector< std::vector <double>> A, B, X;
    A = std::vector< std::vector <double>> (3, std::vector <double> (3));   // matriz de coeficientes de nxn, siendo n el número de incógnitas del sistema
    B = std::vector< std::vector <double>> (3, std::vector <double> (1));   // matriz de terminos independientes de nx1
    X = std::vector< std::vector <double>> (3, std::vector <double> (1));   // valor de las variables que se obtienen resolviendo el sistema de orden nx1

    for(int i=0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            A[i][j]=sumatorio(numeroElementos, tiemposReales, i+j, 0);
        }

        B[i][0]=sumatorio(numeroElementos, tiemposReales, i, 1);
    }

    resolverSistemaEcuaciones(A, B, 3, X);
    for(int i=0; i<3; i++)
    {
        a[i]=X[i][0];
    }

    std::vector <double> tiemposEstimados;
    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados, 2);
    muestraEcuacionSeleccion(a);    // Muestra la ecuacion de mínimos cuadrados
    // Muestra el coeficiente de determinación
    double coeficienteDeterminacion = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    std::cout << "Coeficiente de determinación: " << coeficienteDeterminacion << "\n" << std::endl;
    almacenaTiempos2(numeroElementos, tiemposReales, tiemposEstimados);
}

double sumatorio(const std::vector <double> &n, const std::vector <double> &t, int expN, int expT)
{
    double suma = 0;

    for(int i=0; i<n.size(); i++)
    {
        suma+=pow(n[i],expN)*pow(t[i],expT);
    }

    return suma;
}


// Calcula los tiempos estimados para todos los valores de un vector
void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, 
    const std::vector <double> &a, std::vector <double> &tiemposEstimados, int grado)
{
    for(int i=0; i<numeroElementos.size(); i++)
    {
        tiemposEstimados.push_back(calcularTiempoEstimadoPolinomico(numeroElementos[i], a, grado));
    }
}

// Calcula el tiempo estimado para un valor de n concreto
double calcularTiempoEstimadoPolinomico(const double &n, const std::vector <double> &a, int grado)
{
    if(grado == 2)
        return a[0]+a[1]*n+a[2]*pow(n,2);
    else if(grado == 3)
        return a[0]+a[1]*n+a[2]*pow(n,2)+a[3]*pow(n,3);
    else
        return -1;
}

// Calcula el coeficiente de determinacion
double calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, 
    const std::vector <double> &tiemposEstimados)
{   
    double varianzaTiemposReales = varianza(tiemposReales);
    double varianzaTiemposEstimados = varianza(tiemposEstimados);

    double coeficienteDeterminacion = varianzaTiemposEstimados / varianzaTiemposReales;

    return coeficienteDeterminacion;
}


/**
 * Función que almacena en el fichero "tiempoReales.txt" los valores del vector
 * numeroElementos y tiemposReales
 * */

void almacenaTiempos1(std::vector<double> numeroElementos, std::vector<double> tiemposReales)
{
    std::ofstream fichero("tiempoReales.txt");

    if(!fichero)
    {
        std::cout << "Error al abrir tiempoReales.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<numeroElementos.size(); i++)
        fichero << numeroElementos[i] << "\t" << tiemposReales[i] << "\n";
    
    fichero.close();
}


/**
 * Función que almacena en el fichero datosFinales.txt el tamaño, los tiempos reales
 * y los tiempos estimados.
 * */
void almacenaTiempos2(std::vector<double> numeroElementos, std::vector<double> tiemposReales, std::vector<double> tiemposEstimados)
{
    ofstream fichero("datosFinales.txt");

    if(!fichero)
    {
        cout << "Error al abrir datosFinales.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<numeroElementos.size(); i++)
        fichero << numeroElementos[i] << "\t" << tiemposReales[i] << "\t" << tiemposEstimados[i] << "\n";
    
    fichero.close();
   
}

/* Funciones de vectores */

// Función que rellena un vector de enteros con números aleatorios [0, 10000000)
void rellenaVector(std::vector<int> &v)
{
    for(auto it=v.begin(); it<v.end(); it++)
    {
        *it=std::rand()%10000000;
    }
}

// comprueba si un vector está ordenado
bool estaOrdenado(const std::vector <int> &v)
{
    // Recorremos el vector
    for(auto it=v.begin(); it<v.end(); it++)
    {
        // Si el elemento actual es mayor al siguiente no está ordenado (de menor a mayor)
        if(it>it+1)
        {
            return false;
        }
    }
    return true;
}

// Calcula la varianza de un vector
double varianza(std::vector<double> v)
{
    // varianza = ( Σ(elemento²) / nElementos) - media²

    double mediaTiempos = media(v);

    double sumatorioCuadrados = sumatorioElementosCuadrado(v);

    double varianza = (sumatorioCuadrados / v.size()) - pow(mediaTiempos, 2);

    return varianza;
}

// Calcula la media del vector 
double media(std::vector <double> v)
{
    double suma = 0.0, media;

    for(int i=0; i<v.size(); i++)
        suma+=v[i];
    
    media = suma/v.size();

    return media;
}

// Calcula el sumatorio de los cuadrados de los elementos del vector
double sumatorioElementosCuadrado(std::vector<double> v)
{
    double suma = 0.0;
    
    for(int i=0; i<v.size(); i++)
        suma+=pow(v[i], 2);

    return suma;
}


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

// Ejecuta un fichero
void muestraGrafica(std::string fichero)
{
    std::string comando = "xdg-open " + fichero;
    int result = system(comando.c_str());   // c_str() devuelve un puntero a la cadena

    if(result != 0)
        std::cerr << "Error al abrir el archivo. Código de salida: " << result << std::endl;
    else
        std::cout << "Se ha abierto la gráfica correspondiente a los datos iniciales introducidos.\n" << std::endl;
}

void muestraEcuacionSeleccion(std::vector <double> a)
{
    std::cout << "Ecuación de mínimos cuadrados: " ;
    std::cout << "t(n) = " << a[0] << " + " << a[1] << "*n + " << a[2] << "*n²\n" << std::endl;
}

void muestraEcuacionCuadrado(std::vector <double> a)
{
    std::cout << "Ecuación de mínimos cuadrados: " ;
    std::cout << "t(n) = " << a[0] << " + " << a[1] << "*n + " << a[2] << "*n² + " << a[3] << "*n³\n" << std::endl;
}

/**
* Estima el tiempo para un tamaño del problema a elegir por el usuario (algoritmo ordenacionSeleccion).
* grado indica el grado de la función.
* */
void estimaTiempo(std::vector <double> a, int grado)
{
    double n, tiempo;

    do{
        std::cout << "Introduzca: " << std::endl;
        std::cout << "-> Un valor determinado del tamaño del ejemplar para estimar su tiempo." << std::endl;
        std::cout << "-> 0 para salir." << std::endl;
        std::cout << "" << std::endl;
        std::cin >> n;
        std::cout << "" << std::endl;

        if(n > 0)
        {
            tiempo = calcularTiempoEstimadoPolinomico(n, a, grado);    // tiempo devuelto en microsegundos
            tiempoFormateado(tiempo);
        }
        else if(n < 0)
        {
            std::cerr << "Error: Lo que ha introducido no corresponde a una de las opciones\n." << std::endl;
        }
    }
    while(n != 0);
}

/**
* Función que convierte un tiempo de microsegundos al 
* formato: años, días, horas, minutos, segundos y lo muestra por pantalla.
* */
void tiempoFormateado(double tiempo_microsegundos)
{
    int anios, dias, horas, minutos, segundos;
    
    const double microsegundos_por_segundo = 1'000'000.0;
    const double microsegundos_por_minuto = 60.0 * microsegundos_por_segundo;
    const double microsegundos_por_hora = 60.0 * microsegundos_por_minuto;
    const double microsegundos_por_dia = 24.0 * microsegundos_por_hora;
    const double microsegundos_por_anio = 365.25 * microsegundos_por_dia;

    anios = static_cast<int>(tiempo_microsegundos / microsegundos_por_anio);
    tiempo_microsegundos = fmod(tiempo_microsegundos, microsegundos_por_anio);

    dias = static_cast<int>(tiempo_microsegundos / microsegundos_por_dia);
    tiempo_microsegundos = fmod(tiempo_microsegundos, microsegundos_por_dia);

    horas = static_cast<int>(tiempo_microsegundos / microsegundos_por_hora);
    tiempo_microsegundos = fmod(tiempo_microsegundos, microsegundos_por_hora);

    minutos = static_cast<int>(tiempo_microsegundos / microsegundos_por_minuto);
    tiempo_microsegundos = fmod(tiempo_microsegundos, microsegundos_por_minuto);

    segundos = static_cast<int>(tiempo_microsegundos / microsegundos_por_segundo);

    std::cout << "Tiempo estimado: ";
    std::cout << anios << " años, " << dias << " días, " << horas << " h, " << minutos << " min, " << segundos << " s";
    std::cout << "\n" << std::endl;

}

// Rellena la matriz de datos con números elegidos por el usuario o aleatoriamente con valores entre [0.95, 1.05]
void rellenaMatriz(std::vector < std::vector <double>> &matrizDatos, int n, int opcion)
{
    double dato;

    if(opcion == 1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                std::cout << "Introduce el valor [" << i << "][" << j << "] = ";
                std::cin >> dato;
                matrizDatos[i][j] = dato;
            }
        }
    }
    else
    {
        if(opcion != 2)
            std::cout << "Error. El valor introducido corresponde a una de las opciones. Rellenando la matriz aleatoriamente.\n" << std::endl;

        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dato  = double(95 + std::rand() % 11)/100;
                matrizDatos[i][j] = dato;
                //std::cout << "matrizDatos[" << i << "][" << j << "] = " << dato << std::endl;
            }
        }
    }
}   


/*
* Función de ajuste para un polinomio de grado 3 
* donde a es un vector de coeficientes del polinomio de ajuste
* */
void ajusteCubico(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a)
{
    std::vector< std::vector <double>> A, B, X;
    A = std::vector< std::vector <double>> (4, std::vector <double> (4));   // matriz de coeficientes de nxn, siendo n el número de incógnitas del sistema
    B = std::vector< std::vector <double>> (4, std::vector <double> (1));   // matriz de terminos independientes de nx1
    X = std::vector< std::vector <double>> (4, std::vector <double> (1));   // valor de las variables que se obtienen resolviendo el sistema de orden nx1

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            A[i][j]=sumatorio(n, tiemposReales, i+j, 0);
        }

        B[i][0]=sumatorio(n, tiemposReales, i, 1);
    }

    resolverSistemaEcuaciones(A, B, 4, X);
    for(int i=0; i<4; i++)
    {
        a[i]=X[i][0];
    }

    std::vector <double> tiemposEstimados;
    // El dos indica que se usa la opcion grado 3
    calcularTiemposEstimadosPolinomico(n, a, tiemposEstimados, 3);
    muestraEcuacionCuadrado(a);    // Muestra la ecuacion de mínimos cuadrados

    // Muestra el coeficiente de determinación
    double coeficienteDeterminacion = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    std::cout << "Coeficiente de determinación: " << coeficienteDeterminacion << "\n" << std::endl;
    almacenaTiempos2(n, tiemposReales, tiemposEstimados);
}

// Calcula los tiempos reales para el algoritmo de ajuste cuadrático
void tiemposMatrizCuadrado(int nMin, int nMax, int inc, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos)
{
    Clock reloj;

    int opcion;
    std::cout << "Introduzca: " << std::endl; 
    std::cout << "1. para rellenar las matrices a mano." << std::endl;
    std::cout << "2. para rellenar las matrices aleatoriamente con valores en el rango [0.95, 1.05].\n" << std::endl;
    std::cin >> opcion;
    std::cout << "" << std::endl;

    for(int i=nMin; i<nMax; i+=inc)
    {
        std::vector < std::vector <double>> matrizDatos;
        matrizDatos = std::vector< std::vector< double > >(i, std::vector< double >(i));

        std::vector < std::vector <double>> matrizProducto;
        matrizProducto = std::vector< std::vector< double > >(i, std::vector< double >(i));

        double tiempo = 0.0;

        rellenaMatriz(matrizDatos, i, opcion);
        reloj.start();
        multiplicarMatrices(matrizDatos, matrizDatos, matrizProducto);
        reloj.stop();
        tiempo=reloj.elapsed();
        
        tiemposReales.push_back(tiempo);
        numeroElementos.push_back(i);
        
        std::cout << "Número de elementos: " << i << "\tTiempo: " << tiempo << " microsegundos\n"<< std::endl;
    }

    std::cout << "" << std::endl;
    almacenaTiempos1(numeroElementos, tiemposReales);
}

/**
* Función que realiza el ajuste exponencial
* @Param a Vector de coeficientes del polinomio de ajuste de primer grado (contiene a0 y a1)
* */
void ajusteExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a)
{

    std::vector< std::vector <double>> A, B, X;
    A = std::vector< std::vector <double>> (2, std::vector <double> (2));   // matriz de coeficientes de nxn, siendo n el número de incógnitas del sistema
    B = std::vector< std::vector <double>> (2, std::vector <double> (1));   // matriz de terminos independientes de nx1
    X = std::vector< std::vector <double>> (2, std::vector <double> (1));   // valor de las variables que se obtienen resolviendo el sistema de orden nx1

    // Pasamos la curva t(n) = a0 + a1*2^n a curva t(n) = a0 + a1*Z
    std::vector <double> Z = std::vector <double> (n.size());

    for(int i=0; i < n.size(); i++)
        Z[i] = pow(2, n[i]);


    for(int i=0; i<2; i++)
    {
        for(int j =0; j<2; j++)
        {
            // Usamos Z en lugar de n
            A[i][j]=sumatorio(Z, tiemposReales, i+j, 0);
        }

        B[i][0]=sumatorio(Z, tiemposReales, i, 1);
    }

    resolverSistemaEcuaciones(A, B, 2, X);

    for(int i=0; i<2; i++)
    {
        a[i]=X[i][0];
    }

    std::vector <double> tiemposEstimados;
    calcularTiemposEstimadosExponencial(Z, a, tiemposEstimados);
    muestraEcuacionExponencial(a);    // Muestra la ecuacion de mínimos cuadrados
    // Muestra el coeficiente de determinación
    double coeficienteDeterminacion = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
    std::cout << "Coeficiente de determinación: " << coeficienteDeterminacion << "\n" << std::endl;
    almacenaTiempos2(n, tiemposReales, tiemposEstimados);
}

/**
* Función para calcular los tiempos estimados para la función exponencial
* */
void calcularTiemposEstimadosExponencial(const std::vector <double> &n,
    const std::vector <double> &a, std::vector <double> &tiemposEstimados)
{
    for(int i=0; i<n.size(); i++)
    {
        tiemposEstimados.push_back(calcularTiempoEstimadoExponencial(n[i], a));
    }

}

/**
* Función que estima el tiempo apartir de un valor de numeroElementos
* */
double calcularTiempoEstimadoExponencial(const double &n, const std::vector <double> &a)
{
    // Ojo: Realmente n sería z, que es 2^n
    return a[0]+a[1]*n;
}

void tiemposFibonacci(int nMin, int nMax, int inc,
    std::vector <double> &tiemposReales, std::vector <double> &numeroElementos)
{
    Clock reloj;

    for(int i=nMin; i<nMax; i+=inc)
    {
        double tiempo = 0.0;
        int resultado;
        
        reloj.start();
        resultado = algoritmoFibonacciRecursivo(i);
        reloj.stop();
        tiempo = reloj.elapsed();
        
        tiemposReales.push_back(tiempo);
        numeroElementos.push_back(i);
        
        std::cout << "Número de elementos: " << i << "\tTiempo medio: " << tiempo << " microsegundos."<< std::endl;
    }

    std::cout << "" << std::endl;
    almacenaTiempos1(numeroElementos, tiemposReales);
}

void estimaTiempoExponencial(std::vector <double> a)
{
    double n, tiempo;

    do{
        std::cout << "Introduzca: " << std::endl;
        std::cout << "-> Un valor determinado del tamaño del ejemplar para estimar su tiempo." << std::endl;
        std::cout << "-> 0 para salir." << std::endl;
        std::cout << "" << std::endl;
        std::cin >> n;
        std::cout << "" << std::endl;

        if(n > 0)
        {
            double z = pow(2, n);
            tiempo = calcularTiempoEstimadoExponencial(z, a);    // tiempo devuelto en microsegundos
            tiempoFormateado(tiempo);
        }
        else if(n < 0)
        {
            std::cerr << "Error: Lo que ha introducido no corresponde a una de las opciones\n." << std::endl;
        }
    }
    while(n != 0);
   
}


// Muestra la ecuación de mínimos cuadrados para el algoritmo de Fibonacci
void muestraEcuacionExponencial(std::vector <double> a)
{
    std::cout << "Ecuación de mínimos cuadrados: " ;
    std::cout << "t(n) = " << a[0] << " + " << a[1] << "*2^n\n" << std::endl;
}