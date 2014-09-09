#ifndef parser_h
#define parser_h

#include "ast.h"
#include "scanner.h"

class Parser {
 public:
  Parser(istream* in, bool flag = false);
   ~Parser();

   AST* parse();

 private:
   AST* Prog();
   AST* Expr();
   AST* RestExpr(AST* e);
   AST* Term();
   AST* RestTerm(AST* t);
   AST* Storable();
   AST* Factor();

   Scanner* scan;
   bool flag;
};


#endif   
