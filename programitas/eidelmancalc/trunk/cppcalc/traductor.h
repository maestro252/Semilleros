#ifndef traductor_h
#define traductor_h
#include "token.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>



class Traductor {
 private:
  int x;
  bool activo;
  char str;
  

 public:
  Traductor();
  ~Traductor();
  void cabecera();
  void final();
  void operar(TokenType type, char c = '*');
  void empezarNodo(TokenType type);
  void tomarNumNode(string val);
  bool getActivo();
  void setActivo(bool traducir);
  void setStr();
  char getStr();
  ofstream archivo;
  void imprimirAst();
  
};

extern Traductor * trad;

#endif
