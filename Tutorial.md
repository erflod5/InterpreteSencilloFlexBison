# Intérprete sencillo utilizando Flex y Bison (Linux)
En este tutorial se desarrolla un intérprete sencillo que permite ejecutar un archivo de entrada que contiene sentencias tales como declaración de variables, sentencias de control, impresiones en consola, etc. El lenguaje de programación fue diseñado especialmente para este ejemplo. El proyecto cuenta con comentarios que explican su funcionamiento.


Las tecnologías a utilizar son:
* Flex: Generador de analizadores léxicos
* Bison: Generador de analizadores sintácticos
* Ubuntu 20.04: Sistema operativo
* Visual Studio Code: Editor de código fuente
* C++: Lenguaje de programación

El proyecto completo del ejemplo puede descargarse en el siguiente enlace:
https://github.com/ericknavarro/InterpreteSencilloFlexBison

Si desea una explicación a como utilizar las herramientas paso a paso, en el siguiente link encontrará mas información.
https://github.com/ericknavarro/ProyectoFlexBison

## Lenguaje de entrada
Dentro de la carpeta del proyecto, hay un archivo de entrada llamado “entrada.txt”, en él se muestran ejemplos de todas las funciones del lenguaje diseñado para esta aplicación, al leerlo se puede tener una idea clara de las funciones con las que el lenguaje cuenta, este archivo contiene lo siguiente:

```
/******************************************
 * Ejemplo desarrollado por Erick Navarro *
 * Blog: e-navarro.blogspot.com           *
 * Septiembre - 2015                      *
 ******************************************/

//Se imprime el encabezado
imprimir("Tablas de" & " multiplicar");

//Se declara la variable a, de tipo numero
numero a;
//Se asigna a la variable a el valor 0
a=0;
//Se declara la variable c, de tipo numero
numero c;
//Se asigna a la variable c el valor 0
c=1;
//Se imprime un separador
imprimir("----------------");
/**
 * Se imprimen las tablas del 1 al 5 y 
 * para cada tabla, se imprimen los resultados
 * desde el uno hasta el 5, esto se hace con 
 * dos ciclos while anidados. 
 **/
mientras(a<4+c){	
	a=a+1;
	numero b;
	b=0;
	mientras(b<4+c){
		b=b+1;
		imprimir(a & " * " & b & " = " & a * b);
	}
	imprimir("----------------");
}

//Se asigna a la variable a el valor de 11
a=11;
/**
 * La variable b ya había sido declarada pero 
 * dentro del ámbito del primer ciclo while, 
 * entonces no existe en este ámbito por lo que 
 * debe declararse.
 **/
numero b;
//Se asigna valor de 12 a b y valor de 13 a c
b=12;
c=13;
/**
 * Se evalua si el valor de la variable a es 
 * mayor que 10, si el b es mayor que 11 y si
 * el de c es mayor que 12. 
 **/
if(a>10){
	imprimir("a es mayor que 10.");
	if(b>11){
		imprimir("a es mayor que 10 y b es mayor que 11.");
		if(c>12){
			imprimir("a es mayor que 10, b es mayor que 11 y c es mayor que 12.");
		}
	}
}else{
	imprimir("a es menor o igual que 10.");
}

imprimir(3.3333);
```

Como se puede observar, el lenguaje acepta:
* Comentarios de muchas líneas (//).
* Comentarios de una línea (//).
* Concatenación de cadenas, mediante el operador “&”.
* Función “imprimir”: que recibe como parámetro una cadena e imprime en consola dicha cadena.
* Declaración de variables: Únicamente se acepta definición de variables de tipo numero incluyendo enteros y decimales.
* Asignación de variables: A cualquier variable se le puede asignar cualquier expresión que tenga como resultado un número.
* Instrucción “mientras”: tiene el comportamiento clásico del ciclo while, ejecuta el ciclo mientras la expresión booleana que recibe sea verdadera. Esta instrucción soporta anidamiento.
* Instrucción “if” e instrucción “if-else”: si la expresión booleana que recibe es verdadera entonces ejecuta las instrucciones contenidas en el “if”, si es falsa y la instrucción tiene un “else” entonces se ejecutan las instrucciones contenidas en el “else”. Esta instrucción soporta anidamiento.
* Expresiones aritméticas: Estas expresiones soportan sumas, restas, divisiones, multiplicaciones, expresiones negativas y paréntesis para agrupar operaciones. Tiene la precedencia habitual de las expresiones aritméticas.
* Expresiones booleanas: comparan dos expresiones que tengan como resultado un número y soportan únicamente los operadores mayor que y menor que (<, >).

## El resultado de la ejecución
Al ejecutar el archivo de entrada mostrado anteriormente se obtiene el siguiente resultado en consola:
```
"Tablas de"" multiplicar"
"----------------"
1.000000" * "1.000000" = "1.000000
1.000000" * "2.000000" = "2.000000
1.000000" * "3.000000" = "3.000000
1.000000" * "4.000000" = "4.000000
1.000000" * "5.000000" = "5.000000
"----------------"
2.000000" * "1.000000" = "2.000000
2.000000" * "2.000000" = "4.000000
2.000000" * "3.000000" = "6.000000
2.000000" * "4.000000" = "8.000000
2.000000" * "5.000000" = "10.000000
"----------------"
3.000000" * "1.000000" = "3.000000
3.000000" * "2.000000" = "6.000000
3.000000" * "3.000000" = "9.000000
3.000000" * "4.000000" = "12.000000
3.000000" * "5.000000" = "15.000000
"----------------"
4.000000" * "1.000000" = "4.000000
4.000000" * "2.000000" = "8.000000
4.000000" * "3.000000" = "12.000000
4.000000" * "4.000000" = "16.000000
4.000000" * "5.000000" = "20.000000
"----------------"
5.000000" * "1.000000" = "5.000000
5.000000" * "2.000000" = "10.000000
5.000000" * "3.000000" = "15.000000
5.000000" * "4.000000" = "20.000000
5.000000" * "5.000000" = "25.000000
"----------------"
"a es mayor que 10."
"a es mayor que 10 y b es mayor que 11."
"a es mayor que 10, b es mayor que 11 y c es mayor que 12."
3.33
```

## Tabla de símbolos
La tabla de símbolos es una parte importante en el proceso de ejecución del código, es en esta estructura de datos en donde guardamos información de las variables como su tipo, identificador y valor. A esta estructura podemos pedirle el valor de una variable, o pedirle que le asigne cierto valor a una variable.

Es importante mencionar que en el proceso de ejecución la tabla de símbolos va cambiando de forma dinámica, esto con el objetivo de manejar los ámbitos, por ejemplo, la instrucción WHILE tiene su propio ámbito, lo que significa que su tabla de símbolos contiene información de las variables declaradas en ámbitos superiores y la información de las variables declaradas en el ámbito local de la instrucción, al terminar de ejecutar la instrucción, todas las variables declaradas en el ámbito local se eliminan de la tabla de símbolos que almacena la información de los ámbitos superiores, de tal manera que los ámbitos superiores no tendrán acceso a las variables declaradas dentro del WHILE.

## AST
Un árbol de sintaxis abstracta (AST) es una representación simplificada de la estructura sintáctica del código fuente. A nivel de programación un AST es una estructura de datos que se genera durante el proceso de análisis sintáctico.

En este ejemplo el AST es la pieza más importante porque al recorrerlo pueden ejecutarse las acciones del código de entrada y ese es el principal objetivo de la aplicación.

El arbol se va armando desde Bison por medio de la listas de instrucciones, donde cada sentencia es una instrucción y en el bloque contenido en esta sentencia tendríamos otra lista de instrucciones, armando así un árbol en donde cada nodo es un objeto que implementa la clase abstracta instrucción y puede contener mútiples hijos que serían otro objetos que implementan la clase abstracta instrucción y así recursivamente. 

## Estructura del proyecto
El proyecto está dividio en 3 partes:
* analizador: contiene los archivos de Flex y Bison y los analizadores que estas herramientas generaron.
* arbol: contiene todas las clases que forman parte del AST, que se utilizan como estructura primaria en la aplicación.
* main: continene el método principal de la aplicación.

## Ejecutando el proyecto
Para ejecutar el proyecto se tienen que ejecutar los siguientes comandos:
1. Para generar el ejecutable se compilan todos los archivos .cc de nuestro proyecto.
```sh
    c++ ./arbol/*.cc main.cc ./analizador/*.cc
```
2. El comando anterior genera un archivo ``a.out``. Lo ejecutamos desde consola con el comando:
```sh
    ./a.out
```

## Fuentes Consultadas
Compiladores, principios, técnicas y herramientas. Aho, Lam, Sethi y Ullman. Segunda Edición.