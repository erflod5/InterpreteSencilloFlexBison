#ifndef ASIGNACION_H
#define ASIGNACION_H

#include <string>
#include "operacion.h"
using namespace std;
/**
 * Clase que ejecuta las acciones de una instrucción de asignacion 
 * y que extiende de la clase abstracta Instrucción
*/
class Asignacion : public Instruccion{
    private:
        /**
         * Identificador de la variable a la que se le asigna el valor.
        */
        string *id;
        /**
         * Valor que se le asigna a la variable.
        */
        Operacion *valor;

    public:
        /**
         * Constructor de la clase Asignación
         * @param id identificador de la variable
         * @param valor valor que se le va a asignar
        */
        Asignacion(string *id, Operacion *valor);
        /**
         * Método que ejecuta la acción de asignar un valor,
         * es la sobrecarga del método ejecutar de la clase Instrucción
         * @param ts tabla de simbolos del ámbito padre de la sentencia asignación
         * @return retorna nulo porque esta sentencia no genera valor
        */
        Retorno* ejecutar(TablaDeSimbolos *ts);
};
#endif
