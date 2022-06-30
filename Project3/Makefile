all: parser1

parser1: lex.yy.cpp y.tab.cpp SymbolTable.cpp SymbolTable.hpp
	g++ y.tab.cpp SymbolTable.cpp -o parser -lfl -ly

parser2: lex.yy.cpp y.tab.cpp SymbolTable.cpp SymbolTable.hpp
	g++ y.tab.cpp SymbolTable.cpp -o parser -ll -ly

lex.yy.cpp: scanner.l
	lex -o lex.yy.cpp scanner.l

y.tab.cpp: parser.y
	yacc -d parser.y -o y.tab.cpp

clean:
	rm parser lex.yy.cpp y.tab.* 