#ifndef DECLARACION_H
#define DECLARACION_H

#include <string>
#include "instruccion.h"
using namespace std;

/**
 * Clase que ejecuta las acciones de una instrucción de declaración y que implementa
 * la clase abstracta instrucción
 */
class Declaracion : public Instruccion{
    private:
        /**
         * Identificador de la variable que será declarada.
        */
        string *id;
        /**
         * Tipo de la variable que será declarada.
        */
        Tipo t;

    public:
        /**
         * Constructor de la clase
         * @param id Identificador de la variable que será declarada
         * @param t Tipo de la clase que será declarada
         */
        Declaracion(string *id, Tipo t);
        /**
         * Método que ejecuta la accion de declarar una variable, es una sobreescritura del 
         * método ejecutar que se debe programar por la implementación de la clase abstracta
         * instrucción
         * @param ts Tabla de símbolos del ámbito padre.
         * @return No retorna nada porque no es una sentencia que genere un valor.
        */
        Retorno* ejecutar(TablaDeSimbolos *ts);
};
#endif