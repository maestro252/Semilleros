#include "traductor.h"
#include "token.h"
using namespace std;

Traductor::Traductor(): activo(false) {
  
}

Traductor::~Traductor() {}

bool Traductor::getActivo(){
  return activo;
}

void Traductor::setActivo(bool traducir){
  activo = traducir;                        //en caso de que se active el -c prende un booleano
                                            // para poder llamar los metodos de impresion a la
                                             // variable externa trad cuando se necesite
  archivo.open("a.ewe");                  // se abre el archivo en el que se va a escribir
                                          // el codigo de ewe  
}

void Traductor::cabecera(){
  archivo << "Start:" << endl;                      //por defecto siempre al iniciar pone esto
  archivo << "    sp := 6" << endl;
  archivo << "    uno := 1" << endl;
  archivo << "    tres := 3" << endl;
  archivo << "    sp := sp + uno" << endl;
  
}

void Traductor::empezarNodo(TokenType type){
  if(type == add || type == sub || type == times || type == divide){ // si es binario suma 3
    archivo << "    sp := sp + tres" << endl;
  }else{
    archivo << "    sp := sp + uno" << endl;                         // de lo contrario suma 1
  }
}

void Traductor::tomarNumNode(string val){
  archivo << "    tmp := " << val << endl;                          //toma el valor que
                                                                    // hay en el numNode y lo pone
  archivo << "    M[sp+0] := tmp" << endl;
}

void Traductor::final(){
  archivo << "    sp := sp - uno" << endl;             // por defecto simepre al final
                                                       // pone esta serie de instrucciones
  archivo << "    tmp := M[sp+1]" << endl;
  archivo << "    writeInt(tmp)" << endl;
  archivo << "halt" << endl;
  archivo << "equ tmp   M[0]" << endl;
  archivo << "equ tmp2  M[1]"<< endl;
  archivo << "equ uno   M[2]"<< endl;
  archivo << "equ tres  M[3]"<< endl;
  archivo << "equ mem   M[4]"<< endl;
  archivo << "equ sp    M[5]"<< endl;
  archivo << "equ stack M[6]"<< endl;
  archivo.close(); // debido a que esto es lo ultimo que se escribira en el archivo
                   //despues de esta secuencia de instrucciones se cierra.
}

void Traductor::setStr(){
  str = 's';
}

char Traductor::getStr(){
  return str;
}

void Traductor::imprimirAst(){
  archivo << "    sp := sp - tres" << endl; // secuencia que siempre se realiza al llegar a un
                                            // nodo binario
  archivo << "    tmp := M[sp+3]" << endl;
  archivo << "    M[sp+1] := tmp" << endl;
  archivo << "    sp := sp + tres" << endl;
}

void Traductor::operar(TokenType type, char c){
  if(c == '*'){
    archivo << "    sp := sp - tres" << endl; //siempre que no sea un keyword imprimira esto.
    archivo << "    tmp := M[sp+3]"  << endl;   // pues debe poner los temporales para operarlos.
  archivo << "    M[sp+2] := tmp" << endl;
  archivo << "    tmp := M[sp+1]" << endl;
  archivo << "    tmp2 := M[sp+2]" << endl;
  }
  switch (type){
  case add:
    archivo << "    tmp := tmp + tmp2" << endl; // de ser un add, debe sumar los tmps
    archivo << "    M[sp+0] := tmp" << endl;
    break;
  case sub:
    archivo << "    tmp := tmp - tmp2" << endl; // de ser un sub debe restarlos.
    archivo << "    M[sp+0] := tmp" << endl;
    break;
  case times:
    archivo << "    tmp := tmp * tmp2" << endl; // de ser un times debe hacer su producto
   archivo << "    M[sp+0] := tmp" << endl;
    break;
  case divide:
    archivo << "    tmp := tmp / tmp2" << endl; // de ser un divide debe hacer su division
    archivo << "    M[sp+0] := tmp" << endl;
    break;
  case keyword:
    if(c == 'S' || c == 's'){  // en el caso especial del store node debe tomar el tmp
      archivo << "    sp := sp - uno" << endl;   // y luego asignarlo a la variable mem
      archivo << "    tmp := M[sp+1]" << endl;
      archivo << "    M[sp+0] := tmp" << endl;
      archivo << "    mem := tmp" << endl;
    }else if(c == 'R' || c == 'r'){
      archivo << "    M[sp+0] := mem" << endl; // en el caso del racall debe traer lo que haya en mem
    }
  default:
    break;
  }
}

