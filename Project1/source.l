%{
  
#include <string>
#include <vector>
#include <map>

using namespace std;

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; printf("<%s: %d>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s: %s>\n",#t,s);}

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];

class SymbolTable {
  private:
    int index;
    vector<string> symbol;
    map<string, int> symbol_map;
  public:
    SymbolTable() { index = 0; };
    int lookup(string s);
    int insert(string s);
    int dump();
};

int SymbolTable::lookup(string s){
  if(symbol_map.find(s) != symbol_map.end()) {
    return symbol_map[s];
  }
  else {
    return -1;
  }
}

int SymbolTable::insert(string s) {
  if(symbol_map.find(s) != symbol_map.end()){
    return -1;
  }
  else{
    symbol.push_back(s);
    symbol_map[s] = index;
    index++;
    return index;
  }
}

int SymbolTable::dump() {
  for(int i = 0; i < index; i++){
    printf("%s\n", symbol[i].c_str());
  }
  return index;
}

SymbolTable *table;

%}

DIGIT           [0-9]
LETTER          [a-zA-Z]  
INTEGER         ({DIGIT}+)
EXPONENT        ([eE][-+]?{INTEGER}) 
IDENTIFIER      ({LETTER}({DIGIT}|{LETTER}|_)*)
REAL            ([-+]?({INTEGER}\.{INTEGER}?{EXPONENT}?))
STRING          (\"([^\"\n]|\"\")*\")

LINE_COMMENT    (\/\/[^\n]*)
COMMENT_START   (\/\*)
COMMENT_END     (\*\/)
%x COMMENT

%option noyywrap

%%

 /* Delimiters */
","                 { token(','); }
":"                 { token(':'); }
";"                 { token(';'); }
"->"                { token('->'); }
"("                 { token('('); }
")"                 { token(')'); }
"["                 { token('['); }      
"]"                 { token(']'); }
"{"                 { token('{'); }
"}"                 { token('}'); }


 /* Arithmetic, Relational and Logical Operators */
"+"                 { token('+'); }
"-"                 { token('-'); }
"*"                 { token('*'); }
"/"                 { token('/'); }

"%"                 { token('%'); }

"<"                 { token('<'); }
"<="                { token('<='); }
">="                { token('>='); }
">"                 { token('>'); }
"=="                { token('=='); }
"!="                { token('!='); }

"&"                 { token('&'); }
"|"                 { token('|'); }
"!"                 { token('!'); }

"="                 { token('='); }

"+="                { token('+='); }
"-="                { token('-='); }
"*="                { token('*='); }
"/="                { token('/='); }


 /* Keywords */
"bool"              { token(BOOL); }
"break"             { token(BREAK); }
"char"              { token(CHAR); }
"case"              { token(CASE); }
"class"             { token(CLASS); }
"continue"          { token(CONTINUE); }
"declare"           { token(DECLARE); }
"do"                { token(DO); }
"else"              { token(ELSE); }
"exit"              { token(EXIT); }
"false"             { token(FALSE); }
"float"             { token(FLOAT); }
"for"               { token(FOR); }
"fun"               { token(FUN); }
"if"                { token(IF); }
"int"               { token(INT); }
"loop"              { token(LOOP); }
"print"             { token(PRINT); }
"println"           { token(PRINTLN); }
"return"            { token(RETURN); }
"string"            { token(STRING); }
"true"              { token(TRUE); }
"val"               { token(VAL); }
"var"               { token(VAR); }
"while"             { token(WHILE); }


{IDENTIFIER}        { tokenString(id, yytext); table -> insert(yytext);}

{INTEGER}           { tokenInteger(integer, atoi(yytext)); }

{REAL}              { tokenString(real, yytext); }

{STRING}            {
                      char temp[MAX_LINE_LENG] = {0};
                      int index = 0;
                      for(int i = 1; i < strlen(yytext) - 1; i++){
                          if(yytext[i] == '"' && yytext[i + 1] == '"') {
                              ++i;
                          }
                          temp[index] = yytext[i];
                          index++;
                      }
                      tokenString(string, temp);
                    } 


 /* Comment */

{LINE_COMMENT}          { LIST; }

{COMMENT_START}         {
                          LIST;
                          BEGIN COMMENT;
                        }

<COMMENT>.              {
                          LIST;
                        }

<COMMENT>\n             {
                          LIST;
                          printf("%d: %s", linenum++, buf);
                          buf[0] = '\0';
                        }

<COMMENT>{COMMENT_END}  {
                          LIST;
                          BEGIN INITIAL;
                        }

\n                  {
                        LIST;
                        printf("%d: %s", linenum++, buf);
                        buf[0] = '\0';
                    }

[ \t\r]*              { LIST; }

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }

%%

int main() {
    table = new SymbolTable;
    yylex();
    printf("\n");
    printf("Symbol Table:\n");
    table->dump();
}