#include <stdio.h>
#include "./analizador/driver.h"
#include <list>
#include "./arbol/instruccion.h"

//Variable externa que contiene la lista de instruciones globales a ejecutar
//Fue declarada en el analizador léxico para poder utilizarse
//en el analizador sintáctico y aquí.
extern list<Instruccion*> lista;

int main() {
	//Driver encargado de la conexión entre el analizador léxico y sintáctico
	Driver driver;
	driver.parse("entrada.txt");
	
	//Se crea una tabla de símbolos global para ejecutar las instrucciones.
	TablaDeSimbolos *ts = new TablaDeSimbolos;
	//Se ejecuta cada instruccion en el ast, es decir, cada instruccion de 
    //la lista principal de instrucciones.
	for(list <Instruccion*> :: iterator it = lista.begin(); it != lista.end(); ++it) {
		//Si existe un error léxico o sintáctico en cierta instrucción esta
		//será inválida y se cargará como null, por lo tanto no deberá ejecutarse
		//es por esto que se hace esta validación.
		if((*it) != NULL)
			(*it)->ejecutar(ts);
	}
	return 0;
}