#ifndef IF_H
#define IF_H

#include <iterator>
#include <list>
#include "operacion.h"

using namespace std;

/**
 * Clase que ejecuta las acciones de una instrucción si...entonces y que implementa
 * la clase abstracta instrucción
 *
*/
class If : public Instruccion{
    private:
        /**
         * Condición de la instrucción si..entonces.         
        */
        Operacion *condicion;
        /**
         * Lista de instrucciones que serán ejecutadas si la condición se cumple.
        */
        list<Instruccion*> instrucciones;
        /**
         * Lista de instrucciones que se ejecutarán si la condición no se cumple,
         * esta lista existirá solo si la instrucción posee la clausula ELSE, de lo
         * contrario la lista será null.
        */
        list<Instruccion*> instruccionesElse;
        
    public:
        /**
         * Primer constructor de la clase, este se utiliza cuando la instrucción no 
         * tiene clausula ELSE.
         * @param a Condición del si..entonces
         * @param b Lista de instrucciones que deberían ejecutarse si la condición se cumple
         */
        If(Operacion *a, list<Instruccion*> b);
        /**
         * Segundo constructor de la clase, este se utiliza cuando la instrucción tiene
         * clausula ELSE.
         * @param a Condición del si..entonces
         * @param b Lista de instrucciones que deberían ejecutarse si la condición se cumple
         * @param c Lista de instrucciones que deberían ejecutarse si la condición no se cumple
         */
        If(Operacion *a, list<Instruccion*> b, list<Instruccion*> c);
        /**
         * Método que ejecuta la instrucción si..entonces, es una sobreescritura del 
         * método ejecutar que se debe programar por la implementación de la clase abstracta
         * instrucción
         * @param ts tabla de símbolos del ámbito padre de la sentencia.
         * @return Estra instrucción retorna nulo porque no produce ningún valor en 
         * su ejecución
         */
        Retorno* ejecutar(TablaDeSimbolos *ts);
};
#endif
