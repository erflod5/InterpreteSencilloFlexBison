#ifndef OPERACION_H
#define OPERACION_H

#include <string>
#include "instruccion.h"
using namespace std;

/**
 * Enumeración del tipo de operación que puede ser ejecutada por esta clase.
 */
enum TipoOperacion{
    SUMA,
    RESTA,
    MULTIPLICACION,
    DIVISION,
    NEGATIVO,
    ENTERO,
    DECIMAL,
    IDENTIFICADOR,
    CADENA,
    MAYOR_QUE,
    MENOR_QUE,
    IGUAL_QUE,
    NO_IGUAL_QUE,
    CONCATENACION
};

/**
 * Clase que ejecuta las acciones de una operación, ya sea aritmética o realacional
 * y que implementa la clase abstracta instrucción, ya que estas operaciones pueden 
 * ejecutarse y al ejecutarse retornan un valor.
 */
class Operacion : public Instruccion{
    private:
        /**
         * Tipo de operación a ejecutar.
         */
        TipoOperacion tipo;
        /**
         * Operando izquierdo de la operación.
         */
        Operacion *operandoIzq;
        /**
         * Operando derecho de la operación.
         */
        Operacion *operandoDer;
         /**
         * Valor específico si se tratara de una literal de tipo numérico.
         */
        float valueFloat;
         /**
         * Valor específico si se tratara de una literal de tipo cadena.
         */
        string *stringValue;

    public:
        /**
         * Constructor de la clase para operaciones binarias (con dos operandos), estas
         * operaciones son:
         * SUMA, RESTA, MULTIPLICACION, DIVISION, CONCATENACION, MAYOR_QUE, MENOR_QUE
         * @param operandoIzq Operando izquierdo de la operación
         * @param operandoDer Operando derecho de la operación
         * @param tipo Tipo de la operación
         */
        Operacion(Operacion *operandoIzq, Operacion *operandoDer, TipoOperacion tipo);
        /**
         * Constructor para operaciones unarias (un operando), estas operaciones son:
         * NEGATIVO
         * @param operandoIzq Único operando de la operación
         * @param tipo Tipo de operación
         */
        Operacion(Operacion *operandoIzq, TipoOperacion tipo);
        /**
         * Constructor para operaciones unarias (un operando), cuyo operando es
         * específicamente una NUMERO, estas operaciones son:
         * NUMERO_ENTERO, NUMERO_DECIMAL
         * @param a Valor de tipo float que representa la operación a realizar.
         */
        Operacion(float valor, TipoOperacion tipo);
        /**
         * Constructor para operaciones unarias (un operando), cuyo operando es
         * específicamente una cadena, estas operaciones son:
         * IDENTIFICADOR, CADENA
         * @param a Cadena que representa la operación a realizar
         * @param tipo Tipo de operación
         */
        Operacion(std::string* valor, TipoOperacion tipo);
        /**
         * Método que ejecuta la instrucción operación, es una sobreescritura del
         * método ejecutar que se debe programar por la implementación de la clase abstracta
         * instrucción
         * @param ts tabla de símbolos del ámbito padre de la sentencia
         * @return Esta instrucción retorna el valor producido por la operación que se ejecutó
         */   
        Retorno* ejecutar(TablaDeSimbolos *ts);
};
#endif
