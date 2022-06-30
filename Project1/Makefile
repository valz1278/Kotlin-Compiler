all: scanner

scanner: lex.yy.cc
	g++ -o scanner -O lex.yy.cc -lfl

lex.yy.cc: source.l
	lex source.l
	mv lex.yy.c lex.yy.cc

clean:
	rm scanner lex.yy.cc