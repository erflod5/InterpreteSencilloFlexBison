#include "declaracion.h"

Declaracion::Declaracion(string *id, Tipo t){
    this->id = id;
    this->t = t;
}

Retorno* Declaracion::ejecutar(TablaDeSimbolos *ts){
    ts->add(new Simbolo(this->id, this->t));
    return NULL;
}