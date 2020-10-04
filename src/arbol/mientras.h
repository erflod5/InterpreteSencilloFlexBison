#ifndef MIENTRAS_H
#define MIENTRAS_H

#include <iterator>
#include <list>
#include "operacion.h"
using namespace std;

/**
 * Clase que ejecuta las acciones de una instrucción mientras y que implementa
 * la clase abstracta instrucción
 */
class Mientras : public Instruccion{
    private:
        /**
         * Condición de la sentencia mientras.
         */
        Operacion *condicion;
        /**
         * Lista de las instrucciones que deben ejecutarse si la condición se cumple.
         */
        list<Instruccion*> instrucciones;
        
    public:
        /**
         * Constructor de la clase Mientras
         * @param a condición que debe evaluarse para ejecutar el ciclo
         * @param b instrucciones que deben ejecutarse si la condición se cumpliera
         */
        Mientras(Operacion *a, list<Instruccion*> b);
        /**
         * Método que ejecuta la instrucción mientras, es una sobreescritura del 
         * método ejecutar que se debe programar por la implementación de la clase abstracta
         * instrucción
         * @param ts tabla de símbolos del ámbito padre de la sentencia
         * @return Esta instrucción retorna nulo porque no produce ningun valor
         */
        Retorno* ejecutar(TablaDeSimbolos *ts);
};
#endif
