Run makefile:
make

Clean scanner.o % lex.yy:
make clean

Manual compilation steps:
lex scanner.l
mv lex.yy.c lex.yy.cc
g++ -o scanner -O lex.yy.cc -ll