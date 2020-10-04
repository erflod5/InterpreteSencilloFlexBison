#include "if.h"

If::If(Operacion *a, list<Instruccion*> b){
    this->condicion = a;
    this->instrucciones = b;
}

If::If(Operacion *a, list<Instruccion*> b, list<Instruccion*> c){
    this->condicion = a;
    this->instrucciones = b;
    this->instruccionesElse = c;
}

Retorno* If::ejecutar(TablaDeSimbolos *ts){
    if(this->condicion->ejecutar(ts)->valorFloat == 1){
        TablaDeSimbolos *tablaLocal = new TablaDeSimbolos();
        tablaLocal->pushTsAnterior(ts);		    
        for(list <Instruccion*> :: iterator it = this->instrucciones.begin(); it != this->instrucciones.end(); ++it) {
            (*it)->ejecutar(tablaLocal);
	    }
        delete tablaLocal;
    }
    else{
        if(this->instruccionesElse.size() > 0){
            TablaDeSimbolos *tablaLocal = new TablaDeSimbolos();		    
            tablaLocal->pushTsAnterior(ts);
            for(list <Instruccion*> :: iterator it = this->instruccionesElse.begin(); it != this->instruccionesElse.end(); ++it) {
                (*it)->ejecutar(tablaLocal);
	        }
            delete tablaLocal;
        }
    }
    return NULL;
}
