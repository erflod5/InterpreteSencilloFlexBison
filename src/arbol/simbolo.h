#ifndef SIMBOLO_H
#define SIMBOLO_H

using namespace std;
#include <string>

/**
 * Enumeración que lista todos los tipos de variable reconocidos en el lenguaje.
 */
enum Tipo {
    TNUMERO,
    TCADENA
};

/**
 * Struct retorno, este se utiliza para definir los valores a retornar en las operaciones.
 * Actualmente el intérprete soporta dos tipos de dato: float y string.
*/
struct Retorno
{
    float valorFloat;
    string valorString;
    Tipo t;
};

/**
 * Clase símbolo, que es un nodo de la tabla de símbolos, estos símbolos son 
 * variables con su valor, identificador y tipo, actualmente todas las variables 
 * son de tipo número, pero se colocó la variable tipo por si se quisiera ampliar
 * el lenguaje y agregar más tipos.
 */
class Simbolo {

    private: 
        Tipo tipo;
        string *id;
        void* valor;
    
    public:
        /**
         * Constructor de la clase Símbolo.
         * @param id identificador de la variable que se desea almacenar
         * @param tipo tipo de la variable que se desea almacenar
         */
        Simbolo(string *id, Tipo tipo);
         /**
         * Método que devuelve el identificador de la variable almacenada en el símbolo.
         * @return Identificador de la variable
         */
        string* getId();
        /**
         * Método que devuelve el puntero al valor que almacena la variable.
         * @return Valor de la variable
         */
        void* getValor();      
        /**
         * Método que asigna un nuevo valor a la variable.
         * @param v Nuevo valor para la variable.
         */
        void setValor(void* v);
        /**
         * Método que devuelve el tipo de dato de la variable
        */
        Tipo getTipo();  
};
#endif