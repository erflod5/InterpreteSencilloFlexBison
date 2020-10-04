#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include <list>
#include <iterator>
#include <string>
#include "simbolo.h"
using namespace std;

/**
 * Clase tabla de símbolos, que realiza todas las operaciones habituales de una 
 * tabla de símbolos.
 */
class TablaDeSimbolos {
    private:
        /**
         * Lista en donde se van almacenando los símbolos
        */
        list<Simbolo*> lista;
    public:
        TablaDeSimbolos();
        /**
         * Método que busca una variable en la tabla de símbolos y devuelve su valor.
         * @param id Identificador de la variable que quiere buscarse
         * @return Valor de la variable que se buscaba, si no existe se devuelve nulo
         */
        Retorno* getValor(string *id);
         /**
         * Método que asigna un valor a una variable específica, si no la encuentra
         * no realiza la asignación y despliega un mensaje de error.
         * @param id Identificador de la variable que quiere buscarse
         * @param valor Valor que quiere asignársele a la variable buscada
         */
        void setValor(string *id, void* valor);
        /**
         * Método que agrega un nuevo símbolo a la tabla de símbolos
         * Si ya existe un símbolo con el mismo identificador no lo agrega y
         * despliega un mensaje de error.
         * @param e Simbolo a agregar a la tabla de simbolos en el ámbito actual
         * @return True si la asginacion fue correcta y False si la variable ya existía 
        */
        bool add(Simbolo *e);
        /**
         * Método que busca un símbolo en la tabla de símbolos
         * @param id Identificador de la variable que quiere buscarse
         * @return True si la variable se encontró y False de lo contrario.
        */
        bool contains(string *id);
        /**
         * Método que agrega las variables de una tabla de símbolos padre
         * a la tabla de símbolos actual
         * @param anterior TablaDeSimbolos padre
        */
        void pushTsAnterior(TablaDeSimbolos *anterior);
};
#endif
