# Práctica Realidad Virtual
# L-System Tree en OpenGl
### Curso 19/20
### Realidad Virtual
### Por Marina Delgado Pérez y Ricardo Manuel Ruiz Díaz

## Introducción
El objetivo principal de este proyecto es visualizar un árbol. Para ello, nos hemos basado en el proyecto original de [1] [ Erik Paluka](https://pages.github.com/).

## Funcionamiento
En este apartado, explicaremos desde como ejecutar la aplicación hasta los diferentes apartados de ella.
Empezaremos por descargar el proyecto desde GitHub en el siguiente enlace https://github.com/Riickyr91/L-Systems-OpenGL.

Una vez nos descarguemos el repositorio completo, el proyecto se encuentra en en la carpeta Código. Una vez localizado el proyecto, lo abrimos con Microsoft Visual Studio, pero antes de ejecutar el programa, debemos revisar que las dependencias de este proyecto esten bien referenciadas. Para ello debemos en entrar en Proyecto > Propiedades del proyecto y debemos acceder a la siguiente pantalla.

<p align="center">
  <img src="./Otros/Imagenes/Configuracion.jpg">
</p>

En esta pantalla debemos asegurarnos que en los apartados Directorios de archivos de inclusión y Directorios de archivos de bibliotecas esten las referencias a las carpetas Include y Lib del proyecto ( teniendo en cuenta que si son rutas absolutas estén bien). Una vez esto, ya estaría preparado para ejecutar el proyecto.

Una vez ejecutemos el proyecto, nos encontramos con el siguiente menu principal en el que podemos elegir entre crear un árbol con nuestra regla que insertemos o escoger entre 6 árboles predefinidos que tenemos en el proyecto.

<p align="center">
  <img src="./Otros/Imagenes/Menu.jpg">
</p>

Empezaremos con la opción 1, si elegimos esta, la siguiente pantalla que nos saldrá será para insertar los parámetros del árbol que creemos, es decir, insertar la regla, ángulo de la creación de ramas, profundidad ( repeticiones para la generación del árbol), ancho y largo del tallo. Además al principio insertamos con una leyenda los valores a insertar en la regla.

<p align="center">
  <img src="./Otros/Imagenes/InsertaRegla.jpg">
</p>    

Una vez relleno, nos encontramos con el resumen del árbol que hemos descrito y con el manual para manejar la cámara en la visualización del árbol.

<p align="center">
  <img src="./Otros/Imagenes/ResumenInserteRegla.jpg">
</p> 

Y por último, podemos visualizar el árbol que hemos creado.

<p align="center">
  <img src="./Otros/Imagenes/EjemploInsertaRegla.jpg">
</p> 

Ahora veremos la aplicación si escogiesemos la opción 2, es decir, la opción de elegir un árbol entre los predefinidos por el programa. Al elegir esta opción nos encontraremos con la siguiente pantalla, en la que debemos elegir el tipo de árbol ( entre 1 y 6).

<p align="center">
  <img src="./Otros/Imagenes/EscogeArbol.jpg">
</p> 

Una vez escogamos un tipo de árbol, nos enseñará un resumen de alguno de sus parámetros como ángulo de creación de las ramas y ancho de las ramas. En esta pantalla nos da opción a modificar estos parámetros.

<p align="center">
  <img src="./Otros/Imagenes/ResumenEscogeArbol1.jpg">
</p> 

Si le dieramos a si, nos saldría la siguiente pantalla en la que debemos insertar los nuevos valores de estos parámetros.

<p align="center">
  <img src="./Otros/Imagenes/ModificaEscogeRegla.jpg">
</p> 

Al pulsar no en la pregunta de modificación de parámetros o al terminar de modificarlos nos lleva a la siguiente pantalla en la que nos muestra un resumen del árbol y una leyenda con los comandos de la cámara a la hora de la visualización de este ( debemos de tener en cuenta que dependiendo de la complejidad del árbol la cámara se va a mover más fluida o mas lenta)

<p align="center">
  <img src="./Otros/Imagenes/ResumenEscogeArbol2.jpg">
</p> 

Y al pulsa continuar podremos ver el ejemplo del árbol que hemos creado.

<p align="center">
  <img src="./Otros/Imagenes/EjemploEscogeRegla.jpg">
</p> 

## Consideraciones de implementación

## Ejemplos 
Aquí veremos todos los árboles predefinidos que tenemos en la aplicación

### Arbol 1

<p align="center">
  <img src="./Otros/Imagenes/Arbol1.jpg">
</p> 

### Arbol 2

<p align="center">
  <img src="./Otros/Imagenes/Arbol2.jpg">
</p> 

### Arbol 3

<p align="center">
  <img src="./Otros/Imagenes/Arbol3.jpg">
</p> 

### Arbol 4

<p align="center">
  <img src="./Otros/Imagenes/Arbol4.jpg">
</p> 

### Arbol 5

<p align="center">
  <img src="./Otros/Imagenes/Arbol5.jpg">
</p> 

### Arbol 6

<p align="center">
  <img src="./Otros/Imagenes/Arbol6.jpg">
</p> 

## Posibles mejoras
Como hemos podido ver en nuestro proyecto, basandonos en un proyecto de Erik Paluka, hemos mejorado la generación de árboles con L-system pero gráficamente es muy similar, por lo que las posibles mejoras están destinadas a la mejora gráfica para que sea más realista:
-   Generación de ramas con un ángulo aleatorio entre unos márgenes.
-   Mejora de texturas para que sean texturas realistas, no sólo sea una línea con color.
-   Mejora de animación del árbol, la animación ahora es igual para todas las ramas y se mueven a la vez, se podría mejorar para que fueran independientes.


## Referencias
