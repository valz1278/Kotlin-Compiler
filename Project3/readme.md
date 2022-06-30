To generate program, run Makefile:
make

If error, run:
make parser2

Error might be due to different flex versions

Manual compilation:
lex -o lex.yy.cpp scanner.l
yacc -d parser.y -o y.tab.cpp
g++ y.tab.cpp SymbolTable.cpp -o parser -lfl -ly (Used this to test on my PC)
or
g++ y.tab.cpp SymbolTable.cpp -o parser -ll -ly (Used this to test on ubuntu server)

For directory cleanup:
make clean

==============================================================

Test phases:
On cygwin : ./parser example.kt
            ./javaa example.jasm
On JVM : java example.class

==============================================================