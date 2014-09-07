all: calc

calc: calc.o scanner.o token.o ast.o parser.o calculator.o traductor.o 
	$(CXX) -g -o calc calc.o scanner.o token.o ast.o parser.o calculator.o traductor.o
calc.o: calc.C scanner.h token.h
	$(CXX) -g -c calc.C
calculator.o: calculator.C calculator.h parser.h ast.h
	$(CXX) -g -c calculator.C
scanner.o: scanner.C scanner.h token.h
	$(CXX) -g -c scanner.C
token.o: token.C token.h
	$(CXX) -g -c token.C
ast.o: ast.C ast.h
	$(CXX) -g -c ast.C
parser.o: parser.C parser.h
	$(CXX) -g -c parser.C
traductor.o: traductor.C traductor.h calc.h
	$(CXX) -g -c traductor.C
clean:
	rm -f *.o
	rm -f calc
