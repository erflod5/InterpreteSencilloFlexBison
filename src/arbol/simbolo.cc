#include "simbolo.h"

Simbolo::Simbolo(string *id, Tipo tipo){
    this->id = id;
    this->tipo = tipo;
}

string* Simbolo::getId(){
    return this->id;
}

void* Simbolo::getValor(){
    return this->valor;
}

void Simbolo::setValor(void* v){
    this->valor = v;
}

Tipo Simbolo::getTipo(){
    return this->tipo;
}