#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
#include "traductor.h"
#define EOF ""

using namespace std;

Calculator* calc;
Traductor* trad;
int main(int argc, char* argv[]) {
   string line;
   string arg;
    
   trad = new Traductor(); //se instancia el traductor en una variable trad
   
   if(argc > 1){
     arg = argv[1]; // se guardan los parametros ingresados
   }
   
   if (arg == "-c"){  //de ser -c iniciara el main para el modo compilador.
     try{
       trad->setActivo(true); //activa el booleano que por defecto estaba en false.
       cout << "Please enter a calculator expression: ";

       getline(cin, line);
      
       trad->cabecera(); // se imprime la parte superior que siempre estara por defecto.
      
      
       calc = new Calculator();

       int result = calc->eval(line); //aqui estaran todos los llamados a los metodos de ewe.
       trad->final();  // se imprime la parte final que siempre estara por defecto.
       cout << "The result is " << result << endl;

       
     } catch(Exception e){
       cout << "Program aborted due to exception!" << endl;
     }
   }else if (arg == "-i"){ //si se ingreso -i iniciara desde aca para hacerlo iterativo
     cout << "> "; //pone el prompt
     while(getline(cin, line)){ //mientras le sigan ingresando expresiones, continuara pidiendo
       try{
	 if(line == EOF)return 0; // si es un EOF la ejecucion termina
	 calc = new Calculator();
	 int result = calc->eval(line, true); //se le pasa el booleano para que sepa que debe 
	 cout << "= " << result << endl;     //imprimir * cuando saque alguna excepcion
	 cout << "> "; // se vuelve a poner el prompt
	
       }catch(Exception e){
	 cout << "> ";//despues de poner la excepcion vuelve a poner el prompt
	
       }
       
     }

   }else{ // y finalmente, si no se puso ni -c ni -i se ejecutara desde aca normalmente.
   try {
     
      cout << "Please enter a calculator expression: ";

      getline(cin, line);
      
      calc = new Calculator();

      int result = calc->eval(line);
     
      cout << "The result is " << result << endl;

     
      

   }
   catch(Exception ex) {
      cout << "Program Aborted due to exception!" << endl;
   }
   }
   
   delete calc;
   delete trad;
}
   
