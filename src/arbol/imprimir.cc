#include "imprimir.h"
#include <iostream>
#include <string>
using namespace std;

Imprimir::Imprimir(Operacion *contenido){
    this->contenido = contenido;
}

Retorno* Imprimir::ejecutar(TablaDeSimbolos *ts){
    Retorno *result = this->contenido->ejecutar(ts);
    if(result->t == TNUMERO){
        printf("%0.2f\n", result->valorFloat);     
    }
    else{
        cout<<result->valorString<<"\n";
    }
    return NULL;    
}
