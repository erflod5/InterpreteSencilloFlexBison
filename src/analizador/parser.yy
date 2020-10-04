%skeleton "lalr1.cc" /* -*- C++ -*- */

%defines
%define api.parser.class {Parser}
%define api.token.constructor
%define api.value.type variant

%define parse.trace
%define parse.error verbose
%param { Driver& driver }


%code requires
{
   class Driver;
   #include "../arbol/asignacion.h"
   #include "../arbol/declaracion.h"
   #include "../arbol/if.h"
   #include "../arbol/imprimir.h"
   #include "../arbol/instruccion.h"
   #include "../arbol/mientras.h"
   #include "../arbol/operacion.h"
   #include "../arbol/simbolo.h"

}

%{
   #include <string>
   #include <stdio.h>
   #include <iterator>
   #include <list>
   #include "driver.h"
   #include <iostream>
   using namespace std;
   extern list<Instruccion*> lista;
%}


/******* TERMINALES ********/
%token PTCOMA";" LLAVEIZQ"{" LLAVEDER"}" PARIZQ"(" PARDER")" 
%token MAS"+" MENOS"-" POR"*" DIV"/" CONCAT"&" MENQUE"<" MAYQUE">" IGUAL"=" IGUALQUE"==" NIGUALQUE"!="
%token RIMPRIMIR"IMPRIMIR" RNUMERO"NUMERO" RMIENTRAS"MIENTRAS" RIF"IF" RELSE"ELSE"

%token <float> DECIMAL"DECIMAL"
%token <int> ENTERO"ENTERO"
%token <std::string*> IDENTIFICADOR"IDENTIFICADOR" CADENA"CADENA"

%token FIN 0 "eof"

%left CONCAT
%left MAS MENOS
%left POR DIV
%precedence NEG 

/******* NO TERMINALES ********/
%type <list<Instruccion*>> Instrucciones;
%type <Instruccion*> Instruccion;
%type <Operacion*> Expresion_numerica Expresion_logica Expresion_cadena;
%start Inicio;

%%

   Inicio 
      : Instrucciones
      {
         lista = $1;
      }
   ;

   Instrucciones
      : Instrucciones Instruccion {
         $1.push_back($2);
         $$ = $1;
      }
      | Instruccion {
         list<Instruccion*> listaInstr;
         listaInstr.push_back($1);
         $$ = listaInstr;
      }
   ;

   Instruccion
      : RIMPRIMIR "(" Expresion_cadena ")" ";" 
      {
         $$ = new Imprimir($3);
      }
      | RMIENTRAS "(" Expresion_logica ")" "{" Instrucciones "}" 
      {
         $$ = new Mientras($3, $6);
      }
      | RNUMERO IDENTIFICADOR ";"
      {
         $$ = new Declaracion($2, (Tipo)TNUMERO);
      }
      | IDENTIFICADOR "=" Expresion_numerica ";" 
      {
         $$ = new Asignacion($1, $3);
      }
      | RIF "(" Expresion_logica ")" "{" Instrucciones "}"
      {
         $$ = new If($3, $6);
      }
      | RIF "(" Expresion_logica ")" "{" Instrucciones "}" RELSE "{" Instrucciones "}"
      {
         $$ = new If($3, $6, $10);
      }
      | error
      {
         $$ = NULL;
      }
   ;

   Expresion_numerica 
      : Expresion_numerica "+" Expresion_numerica 
      {
         $$ = new Operacion($1, $3, (TipoOperacion)SUMA);
      }
      | Expresion_numerica "-" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)RESTA);
      }
      | Expresion_numerica "*" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)MULTIPLICACION);
      }
      | Expresion_numerica "/" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)DIVISION);
      }
      | "-" Expresion_numerica %prec NEG{
         $$ = new Operacion($2, (TipoOperacion)NEGATIVO);
      }
      | DECIMAL
      {
         $$ = new Operacion($1, (TipoOperacion)DECIMAL);
      }
      | ENTERO
      {
         $$ = new Operacion($1, (TipoOperacion)ENTERO);
      }
      | IDENTIFICADOR
      {
         $$ = new Operacion($1, (TipoOperacion)IDENTIFICADOR);
      }
      | "(" Expresion_numerica ")"
      {
         $$ = $2;
      }
   ;
   
   Expresion_logica
      : Expresion_numerica ">" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)MAYOR_QUE);
      }
      | Expresion_numerica "<" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)MENOR_QUE);
      }
      | Expresion_numerica "==" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)IGUAL_QUE);
      }
      | Expresion_numerica "!=" Expresion_numerica
      {
         $$ = new Operacion($1, $3, (TipoOperacion)NO_IGUAL_QUE);
      }
   ;

   Expresion_cadena
      : Expresion_cadena "&" Expresion_cadena
      {
         $$ = new Operacion($1, $3, (TipoOperacion)CONCATENACION);
      }
      | CADENA 
      {
         $$ = new Operacion($1, (TipoOperacion)CADENA);
      }
      | Expresion_numerica
      {
         $$ = $1;
      }
   ;
%%

void yy::Parser::error( const std::string& error){
  std::cout << error << std::endl;
}