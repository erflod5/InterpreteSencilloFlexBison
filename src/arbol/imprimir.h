#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include "operacion.h"

/**
 * Clase que ejecuta las acciones de una instrucción imprimir y que implementa
 * la clase abstracta instrucción
 */
class Imprimir : public Instruccion{
    private:
        /**
         * Contenido que será impreso al ejecutar la instrucción imprimir, este debe
         * ser una instrucción que genere un valor al ser ejecutada.
         */
        Operacion *contenido;
        
    public:
        /**
         * Constructor de la clase imprimir
         * @param contenido contenido que será impreso al ejecutar la instrucción
         */
        Imprimir(Operacion *contenido);
         /**
         * Método que ejecuta la accion de imprimir un valor, es una sobreescritura del 
         * método ejecutar que se debe programar por la implementación de la interfaz
         * instrucción
         * @param ts Tabla de símbolos del ámbito padre de la sentencia.
         * @return Esta instrucción retorna nulo porque no produce ningun valor al ser
         * ejecutada.
         */
        Retorno* ejecutar(TablaDeSimbolos *ts);
};
#endif
