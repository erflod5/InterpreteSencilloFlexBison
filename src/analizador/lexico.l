
%{
  #include <stdio.h>
  #include <string>
  #include "driver.h"
  #include "parser.tab.hh"
  #include <iterator>
  #include <list>
  #include "../arbol/instruccion.h"
  std::list<Instruccion*> lista;
%}

%option noyywrap 
%option outfile="scanner.cc" 

CADENACOMILLASDOBLES [\"]([^\"\n]|(\\\"))*[\"]
DIGIT   [0-9]

ENTERO      {DIGIT}+
DECIMAL     {DIGIT}+("."{DIGIT}+)

ID [A-Za-z]+["_"0-9A-Za-z]*
COMENTARIOSIMPLE ("//".*\r\n)|("//".*\n)|("//".*\r)
COMENTMULTILINEA "/*""/"*([^*/]|[^*]"/"|"*"[^/])*"*"*"*/"

%%
{COMENTARIOSIMPLE}  {}
{COMENTMULTILINEA}  {}
{CADENACOMILLASDOBLES}  { return yy::Parser::make_CADENA(new std::string(yytext, yyleng)); }


"imprimir"      { return yy::Parser::make_RIMPRIMIR(); } 
"numero"        { return yy::Parser::make_RNUMERO(); } 
"mientras"      { return yy::Parser::make_RMIENTRAS(); } 
"if"            { return yy::Parser::make_RIF(); } 
"else"          { return yy::Parser::make_RELSE(); } 

";"             { return yy::Parser::make_PTCOMA(); } 
"{"             { return yy::Parser::make_LLAVEIZQ(); } 
"}"             { return yy::Parser::make_LLAVEDER(); } 
"("             { return yy::Parser::make_PARIZQ(); } 
")"             { return yy::Parser::make_PARDER(); } 
"+"             { return yy::Parser::make_MAS(); } 
"-"             { return yy::Parser::make_MENOS(); } 
"*"             { return yy::Parser::make_POR(); } 
"/"             { return yy::Parser::make_DIV(); } 
"&"             { return yy::Parser::make_CONCAT(); } 
"<"             { return yy::Parser::make_MENQUE(); } 
">"             { return yy::Parser::make_MAYQUE(); } 
"=="            { return yy::Parser::make_IGUALQUE(); }
"!="            { return yy::Parser::make_NIGUALQUE(); }
"="             { return yy::Parser::make_IGUAL(); }

{ENTERO}        { return yy::Parser::make_ENTERO(atoi(yytext)); }
{DECIMAL}       { return yy::Parser::make_DECIMAL(atof(yytext)); }
{ID}            { return yy::Parser::make_IDENTIFICADOR(new std::string(yytext, yyleng)); }  
[[:blank:]]     {}
.               {printf("Caracter no reconocido: %s\n",yytext);}
<<EOF>>		      {return yy::Parser::make_FIN();}
%%

void Driver::runScanner() {
  yy_flex_debug = false;
  yyin = fopen (file.c_str (), "r");
  if(yyin == NULL){
      printf("No se encontro el archivo de entrada");
      exit(1);
  }
}

void Driver::closeFile(){
  fclose(yyin);
}

