#include "ast.h"
#include <iostream>
#include "calculator.h"
#include <string>
#include <sstream>
//Jonathan Eidelman
// for debug information uncomment
//#define debug

using namespace std;

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {

  return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
 
  if(trad->getActivo()){
    trad->imprimirAst(); //se imprime la secuencia de instrucciones necesaria
  }
  return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
  
  return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate() {
 
  if(trad->getActivo()){
    trad->empezarNodo(add);  //si el boolean esta encendido debe imprimir 
                             //la apertura de un nodo binario.
  }
  int a = getLeftSubTree()->evaluate();
  int b = getRightSubTree()->evaluate();
  if(trad->getActivo()){
    trad->operar(add);   //de estar activo el -c debe hacer la secuencia de operado
                         //de los valores de los subarboles.
 
  }
 
  
  return a + b;
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
 
  if(trad->getActivo()){
  trad->empezarNodo(sub);
  }
  int a = getLeftSubTree()->evaluate(); //en sub, times, y divide hara lo mismo que en add
  int b = getRightSubTree()->evaluate();//solo que con la operacion correcta 
                                        //para eso se le pasa el parametro dependiendo del tipo
                                        //de nodo.
  if(trad->getActivo()){
  trad->operar(sub);
  }
  return a - b;
}

MulNode::MulNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int MulNode::evaluate() {
 
  if(trad->getActivo()){
  trad->empezarNodo(times);
  }
  int a = getLeftSubTree()->evaluate();
  int b = getRightSubTree()->evaluate();
  if(trad->getActivo()){
  trad->operar(times);
  }
  return a * b;
}


DivNode::DivNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int DivNode::evaluate() {
 
  if(trad->getActivo()){
  trad->empezarNodo(divide);
  }
  int a = getLeftSubTree()->evaluate();
  int b = getRightSubTree()->evaluate();
  if(trad->getActivo()){
  trad->operar(divide);
  }
  return a / b;
}


NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
  stringstream s;
  s << val;  //se convierte el valor que hay en el numnode en un string para concatenarlo al tmp := 
  if(trad->getActivo()){
  trad->tomarNumNode(s.str());
  }
  return val;
}

RecallNode::RecallNode() :
AST()
{}
RecallNode::~RecallNode(){ }

int RecallNode::evaluate(){
  char recall = 'r';
  if(trad->getActivo()){
   
    trad->operar(keyword, recall);//de estar activo imprimira la secuencia que trae lo que esta
                                  //en mem. y se le pasa el char para que cambie el que estaba por
                                  // defecto.
  }
  
  return calc->recall();
}

StoreNode::StoreNode(AST* sub) :
UnaryNode(sub) {}

StoreNode::~StoreNode(){ }

int StoreNode::evaluate(){
  char store = 's';
  if(trad->getActivo()){ // de estar activo hara la secuencia para un nodo unario
    trad->empezarNodo(keyword);
   
    trad->setStr();     //se cambiara lo que haya en str para indicar luego que se debe operar con
                        //store.
  }
  calc->store(getSubTree()->evaluate());
  if(trad->getActivo())trad->operar(keyword, store);
  return calc->recall();
}
