#include "asignacion.h"

Asignacion::Asignacion(string *id, Operacion *valor){
    this->id = id;
    this->valor = valor;
}
        
Retorno* Asignacion::ejecutar(TablaDeSimbolos *ts){
    Retorno *ret = this->valor->ejecutar(ts);
    if(ret->t == TNUMERO){
        ts->setValor(this->id, &ret->valorFloat);
    }
    else{
        ts->setValor(this->id, &ret->valorString);
    }
    return NULL;
}