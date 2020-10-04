#include "operacion.h"

Operacion::Operacion(Operacion *operandoIzq, Operacion *operandoDer, TipoOperacion tipo){
    this->operandoIzq = operandoIzq;
    this->operandoDer = operandoDer;
    this->tipo = tipo;
}

Operacion::Operacion(Operacion *operandoIzq, TipoOperacion tipo){
    this->operandoIzq = operandoIzq;
    this->tipo = tipo;
}

Operacion::Operacion(float valor, TipoOperacion tipo){
    this->valueFloat = valor;
    this->tipo = tipo;
}

Operacion::Operacion(std::string* valor, TipoOperacion tipo){
    this->stringValue = valor;
    this->tipo = tipo;
}

Retorno* Operacion::ejecutar(TablaDeSimbolos *ts){
    Retorno *ret = new Retorno;
    if(this->tipo == SUMA){
        float result = this->operandoIzq->ejecutar(ts)->valorFloat + this->operandoDer->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;
    }
    else if(this->tipo == RESTA){
        float result = this->operandoIzq->ejecutar(ts)->valorFloat - this->operandoDer->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;
    }
    else if(this->tipo == MULTIPLICACION){
        float result = this->operandoIzq->ejecutar(ts)->valorFloat * this->operandoDer->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;
    }
    else if(this->tipo == DIVISION){
        float result = this->operandoIzq->ejecutar(ts)->valorFloat / this->operandoDer->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;
    }
    else if(this->tipo == NEGATIVO){
        float result = 0 - this->operandoIzq->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;
    }
    else if(this->tipo == ENTERO){
        ret->valorFloat = this->valueFloat;
        ret->t = TNUMERO; 
    }
    else if(this->tipo == DECIMAL){
        ret->valorFloat = this->valueFloat;
        ret->t = TNUMERO; 
    }
    else if(this->tipo == IDENTIFICADOR){
        ret = ts->getValor(this->stringValue);
    }
    else if(this->tipo == CADENA){
        ret->valorString = *this->stringValue;
        ret->t = TCADENA;
    }
    else if(this->tipo == MAYOR_QUE){   
        float result = this->operandoIzq->ejecutar(ts)->valorFloat > this->operandoDer->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;
    }
    else if(this->tipo == MENOR_QUE){
        float result = this->operandoIzq->ejecutar(ts)->valorFloat < this->operandoDer->ejecutar(ts)->valorFloat;
        ret->valorFloat = result;
        ret->t = TNUMERO;

    }
    else if(this->tipo == IGUAL_QUE){
        Retorno *retIzq = this->operandoIzq->ejecutar(ts);
        Retorno *retDer = this->operandoDer->ejecutar(ts);
        ret->t = TNUMERO;
        if(retIzq->t == TNUMERO){
            if(retDer->t == TNUMERO){
                int result = retIzq->valorFloat == retDer->valorFloat;
                ret->valorFloat = result;
            }
            else{
                int result = to_string(retIzq->valorFloat) == retDer->valorString;
                ret->valorFloat = result;
            }
        }
        else{
            if(retDer->t == TNUMERO){
                int result = retIzq->valorString == to_string(retDer->valorFloat);
                ret->valorFloat = result;
            }
            else{
                int result = retIzq->valorString.compare(retDer->valorString) == 1;
                ret->valorFloat = result;
            }
        }
    }
    else if(this->tipo == NO_IGUAL_QUE){
        Retorno *retIzq = this->operandoIzq->ejecutar(ts);
        Retorno *retDer = this->operandoDer->ejecutar(ts);
        ret->t = TNUMERO;
        if(retIzq->t == TNUMERO){
            if(retDer->t == TNUMERO){
                int result = retIzq->valorFloat != retDer->valorFloat;
                ret->valorFloat = result;
            }
            else{
                int result = to_string(retIzq->valorFloat) != retDer->valorString;
                ret->valorFloat = result;
            }
        }
        else{
            if(retDer->t == TNUMERO){
                int result = retIzq->valorString != to_string(retDer->valorFloat);
                ret->valorFloat = result;
            }
            else{
                int result = retIzq->valorString.compare(retDer->valorString) != 1;
                ret->valorFloat = result;
            }
        }
    }
    else if(this->tipo == CONCATENACION){
        Retorno *retIzq = this->operandoIzq->ejecutar(ts);
        Retorno *retDer = this->operandoDer->ejecutar(ts);
        ret->t = TCADENA;
        if(retIzq->t == TNUMERO){
            if(retDer->t == TNUMERO){
                string result = (to_string(retIzq->valorFloat) + to_string(retDer->valorFloat));
                ret->valorString = result;
            }
            else{
                string result = (to_string(retIzq->valorFloat) + retDer->valorString);
                ret->valorString = result;
            }
        }
        else{
            if(retDer->t == TNUMERO){
                string result = (retIzq->valorString + to_string(retDer->valorFloat));
                ret->valorString = result;
            }
            else{
                string result = (retIzq->valorString + retDer->valorString);
                ret->valorString = result;
            }
        }
    }
    else {
        return NULL;
    }
    return ret;
}