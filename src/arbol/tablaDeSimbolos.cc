#include "tablaDeSimbolos.h"
#include <iostream>
#include <string>
using namespace std;

TablaDeSimbolos::TablaDeSimbolos(){

}

Retorno* TablaDeSimbolos::getValor(string *id){
    if(contains(id)){
        for(list <Simbolo*> :: iterator it = this->lista.begin(); it != this->lista.end(); ++it) {
            if((*(*it)->getId()) == (*id)){
                Retorno *ret = new Retorno;
                ret->t = (*it)->getTipo();
                if(ret->t == TNUMERO){
                    ret->valorFloat = *(float*)(*it)->getValor();
                }
                return ret;
            }
	    }
    }
    cout<<"La variable "<<*id<<" no existe en este ambito\n";
    return NULL;
}

void TablaDeSimbolos::setValor(string *id, void* valor){
    for(list <Simbolo*> :: iterator it = this->lista.begin(); it != this->lista.end(); ++it) {
        if((*(*it)->getId()) == (*id)){
            (*it)->setValor(valor);
            return;
        }
	}
    cout<<"La variable "<<*id<<" no existe en este ambito\n";
}

bool TablaDeSimbolos::add(Simbolo *e){
    if(!contains(e->getId())){
        this->lista.push_back(e);
        return true;
    }
    cout<<"La variable "<<*(e->getId())<<" no puede declararse porque ya existe en este ámbito\n";
    return false;
}

bool TablaDeSimbolos::contains(string *id){
	for(list <Simbolo*> :: iterator it = this->lista.begin(); it != this->lista.end(); ++it) {
        if((*(*it)->getId()) == (*id)){
            return true;
        }
	}
    return false;
}

void TablaDeSimbolos::pushTsAnterior(TablaDeSimbolos *anterior){
    for(list <Simbolo*> :: iterator it = anterior->lista.begin(); it != anterior->lista.end(); ++it) {
        this->lista.push_back((*it));
	}
}
