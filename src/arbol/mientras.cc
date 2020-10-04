#include "mientras.h"

Mientras::Mientras(Operacion *a, list<Instruccion*> b){
    this->condicion = a;
    this->instrucciones = b;
}

Retorno* Mientras::ejecutar(TablaDeSimbolos *ts){
    while ((this->condicion->ejecutar(ts)->valorFloat) == 1){
        TablaDeSimbolos *tablaLocal = new TablaDeSimbolos();		    
        tablaLocal->pushTsAnterior(ts);
        for(list <Instruccion*> :: iterator it = this->instrucciones.begin(); it != this->instrucciones.end(); ++it) {
            (*it)->ejecutar(tablaLocal);
	    }
        delete tablaLocal;
    }
    return NULL;
}
