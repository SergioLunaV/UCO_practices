<a name="br1"></a> 

**ALGORÍTMICA: INFORME PARA LA PRÁCTICA 2**

En este documento se analizan los tiempos medios (en microsegundos) del algoritmo Quicksort

(QS1) y de la variante propuesta (QS2) mediante una serie de pruebas.

La variante se diferencia de la original en que a partir de un valor *nElementosMinimo* (a

comparar con el tamaño del vector), el pivote utilizado en el algoritmo no es el elemento central

del vector original, sino la mediana de un vector de tamaño *nMediana.* Dicho vector es

rellenado con elementos aleatorios del vector original, y ordenado mediante el algoritmo de

ordenación por selección.

Puesto que estamos evaluando la mejora del Quicksort, debemos interpretar el cociente

(QS2/QS1) de forma que será mejor cuanto menor sea, puesto que esto nos indica que el

algoritmo mejorado ha tardado menos tiempo que el algoritmo normal.

Las pruebas son realizadas para lo siguientes valores:

\- Fijos:

nMin = 1000000

nMax = 5000000

inc = 100000

rep = 3 repeticiones

\- Variables:

nMediana = 3, 5, 9, 15, 25

nElementosMinimo = 500, 1000, 5000, 10000, 50000

de forma que hay 25 pruebas (5x5).

**Sergio Luna Puerto**

1



<a name="br2"></a> 

**1. Pruebas**

**Nota:** x = nElementosMinimo, y = nMediana

**Tabla de cocientes (QS2/QS1)**

y\x |

500

1000

5000

10000

50000

\---------------------------------------------------------------------------------------------

3

5

9

| 0.999384 1.00111

1\.00006

0\.999693

1\.00103

0\.999786

0\.99871

1\.00024

1\.00135

| 1.00012

| 1.00049

0\.999923 0.998245 1.00004

0\.999928 0.99928

0\.999167

1\.00019

0\.999897

15 | 1.00015

25 | 1.00231

1\.00099

1\.00092

1\.00054

1\.00211

**Tabla de tiempos medios totales para QS1 (microsegundos)**

y\x | 500

1000

5000

10000

50000

\------------------------------------------------------------------------------------

3

5

9

| 468796

| 469225

| 469097

468964

468833

467384

467079

467426

469772

470408

467276

470418

467293

470212

470501

466864

467528

467765

469222

468514

467330

466904

466985

15 | 467974

25 | 469834

**Tabla de tiempos medios totales para QS2 (microsegundos)**

y\x |

500

1000

5000

10000

50000

\-----------------------------------------------------------------------------------

3

5

9

| 468507

| 469281

| 469329

469485

468797

467350

467542

467857

469798

469582

466940

470673

468278

470067

470520

466475

467617

467717

469704

468518

466728

467017

467616

15 | 468045

25 | 468850

2



<a name="br3"></a> 

**2. Interpretación**

**2.1. Mejor combinación de parámetros**

El **mejor caso** de los 25 realizados es para el cual nMediana = 5 y nElementosMinimo = 5000,

con un cociente de 0.998245 (ver gráfica *mediana5nEleMin5000.eps*).

Podemos coger el **peor caso** (nMediana = 25 y nElementosMinimo = 500), con un cociente de

1\.00231, y tan solo se diferencia de la mejor en 0.004065.

Tras las pruebas realizadas hemos obtenido que 15/25 cocientes son mayores a 1, y por tanto

10/25 son menores a 1. Esto indica que en **15 de** las **25** pruebas realizadas, el **QS1** (Quicksort

sin mejorar) tuvo mejor rendimiento, mientras que el **QS2** (variante mejorada) fue el mejor en

las **10** restantes.

Respecto a cuánta diferencia hay entre los cocientes, todos ellos varían entre sí, como mucho,

en milésimas. Es por esto que si realizamos las mismas pruebas varias veces, nos irá saliendo

que la mejor combinación no es siempre la misma.

**2.1. Evolución de los métodos según nMediana y nElementosMinimo**

Fijándonos en la tabla de cocientes, vemos que el aumento de **nMediana** no cambia nada, ya

que no hay ningún patrón de mejora, sino que el cociente aumenta o disminuye

indiscriminadamente. Respecto a la variable **nElementosMinimo** podemos ver que ocurre lo

mismo, es decir, que su aumento tampoco implica una mejora del cociente.

**3. Conclusión**

Tras las pruebas realizadas y el análisis obtenido, podemos concluir que la variante mejorada

del Quicksort (QS2) no nos da indicios de que provoque una mejora real respecto al algoritmo

original de Quicksort (QS1).

3
