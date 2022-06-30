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

To test:
./parser < example.kt

==================================================================
Changes to scanner.l

- Disabled printf
- Added return for each token
- Added new tokens IN and RANGE for FOR loop
- Changed some two character tokens to make them return terms (LE GE EQ NE ADD SUB MUL DIV)
- Moved SymbolTable to a seperate header file