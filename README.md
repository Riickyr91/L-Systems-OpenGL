# Práctica Realidad Virtual
# L-System Tree en OpenGl
### Curso 19/20
### Realidad Virtual
### Por Marina Delgado Pérez y Ricardo Manuel Ruiz Díaz

## Introducción
El objetivo principal de este proyecto es elaborar una aplicación capaz de visualizar un árbol. Para ello, nos hemos basado en el proyecto original de [ Erik Paluka](https://github.com/paluka/L-Systems-OpenGL).  [1]

El enunciado del proyecto puede encontrarse en el siguiente [ enlace](https://github.com/jcarpio/rv1920/blob/master/proyecto_rv1920.md) [2]

Para generar los distintos árboles se han utilizado reglas de generación basadas en [ _Lindenmayer System_](https://en.wikipedia.org/wiki/L-system) [3]. Los L-Systems se basan en aplicar reglas simples a una cadena de caracteres para generar distintas formas. Estos sistemas cuentan con una gramática, un conjunto de reglas y un axioma.

Se han incluido en el proyecto 6 árboles predefinidos, cada uno con distintas reglas de generacion propias. La aplicación de esas reglas producen los árboles de la imagen siguiente, pero en 3D.

<p align="center">
  <img src="./Otros/Imagenes/arboles.jpg">
</p>

La aplicación permite al usuario introducir su propia regla de generación o mostrar uno de los 6 árboles incluidos. Además, sobre esos árboles permite modificar sus parámetros.



## Funcionamiento
En este apartado, explicaremos desde como ejecutar la aplicación hasta los diferentes apartados de ella.
Empezaremos por descargar el proyecto desde GitHub en el siguiente enlace https://github.com/Riickyr91/L-Systems-OpenGL.

Una vez nos descarguemos el repositorio completo, el proyecto se encuentra en la carpeta _Código_. Una vez localizado el proyecto, lo abrimos con Microsoft Visual Studio, pero antes de ejecutar el programa, debemos revisar que las dependencias de este proyecto esten bien referenciadas. Para ello debemos en entrar en Proyecto > Propiedades del proyecto y debemos acceder a la siguiente pantalla.

<p align="center">
  <img src="./Otros/Imagenes/Configuracion.jpg">
</p>

En esta pantalla debemos asegurarnos que en los apartados _Directorios de archivos de inclusión_ y _Directorios de archivos de bibliotecas_ esten las referencias a las carpetas **_Include_** y **_Lib_** del proyecto ( teniendo en cuenta que si son rutas absolutas estén bien). Una vez hechas todas las comprobaciones, el proyecto estaría listo para ser ejecutado.

Al ejecutar el proyecot, nos encontramos con el siguiente menú principal. Este ofrece al usuario la posibilidad de crear su propio árbol (creando una regla de generación nueva) o escoger entre 6 árboles predefinidos.

<p align="center">
  <img src="./Otros/Imagenes/Menu.jpg">
</p>

Al elegir la primera opción, obtendremos un formulario para insertar los parámetros requeridos para generar un árbol (regla de generación, ángulo de creación de ramas, profundidad o numero de repeticiones, ancho y largo del tallo). Para facilitar el proceso, se incluye una leyenda con el significado de cada caracter de la regla de generación.

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

Al escoger la segunda opción, se obtendrá el siguiente menú, que permitirá al usuario decidir qué árbol escoger.

<p align="center">
  <img src="./Otros/Imagenes/EscogeArbol.jpg">
</p> 

Tras seleccionar el árbol, nos enseñará un resumen de alguno de sus parámetros como ángulo de creación de las ramas y ancho de las ramas. En esta pantalla nos da opción a modificar los parámetros predefinidos.

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


Las modificaciones realizadas respecto al proyecto original son las siguientes:
-   Creación de un menú, con el que usuario puede interactuar.
-   Adición de 6 árboles distintos.
-   Posibilidad de crear un árbol único.
-   Movimientos extra de cámara.
-   Cambio del color del fondo (negro -> blanco).
-   Animación del viento desactivada, para apreciar mejor el árbol.
-   Para los árboles predefinidos, limitación del tamaño final del árbol para que se pueda visualizar correctamente.

La ejecución del programa es la siguiente:

En primer lugar, se muestra el menú para que el usuario interacciona con él. Una vez escogido (o creado) el árbol, se llama a la función expand() el número de veces que indique el parámetro DEPTH. 
Esta función se encarga de expandir el axioma mediante las reglas de generación. A cada iteración, sustituye cada caracter por su correspondiente cadena de caracteres.

Una vez terminadas todas las expansiones, se ejecuta el bucle principal del programa, glutMainLoop(). En cada iteración de este bucle se llama a la función display(), que es la responsable de dibujar el árbol (llamando a su vez al método draw()). 

En cada tick del programa, se ejecuta la función draw(). Esta función dibuja contínuamente el árbol mediante las llamadas a las funciones drawLine(), push(), pop(), leaf(), rotR() y rotL(). Estas funciones se llaman en el orden que marque la cadena resultante de todas las expansiones hechas previamente.

Es importante que el árbol se dibuje en todo momento pues, gracias al método keyboard(), el usuario puede mover la cámara para apreciar desde distintos ángulos el árbol. Al mover la cámara, el árbol debe ser dibujado de nuevo.

Debido a que en cada tick se dibuja el árbol entero, no ha sido posible incorporar la aleatoriedad en la generación de ángulos de crecimiento de las ramas. Al considerar un ángulo aleatorio, el efecto que se produce en el árbol es parecido a la animación del viento, pero con movimientos más bruscos.




## Ejemplos 


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

[1] [ Proyecto de Erik Paluka](https://github.com/paluka/L-Systems-OpenGL).

[2] [ Enunciado del proyecto](https://github.com/jcarpio/rv1920/blob/master/proyecto_rv1920.md).

[3] [ _Lindenmayer System_](https://en.wikipedia.org/wiki/L-system).
