%{
  
#include "y.tab.hpp"

using namespace std;

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; if(debugPrint) printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; if(debugPrint) printf("<%s: %d>\n",#t,i);}
#define tokenString(t,s) {LIST; if(debugPrint) printf("<%s: %s>\n",#t,s);}

#define MAX_LINE_LENG 256

int debugPrint = 0;
int linenum = 1;
char buf[MAX_LINE_LENG];

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

%%

 /* Delimiters */
","                 { token(','); return ',';}
":"                 { token(':'); return ':';}
";"                 { token(';'); return ';';}
"("                 { token('('); return '(';}
")"                 { token(')'); return ')';}
"["                 { token('['); return '[';}      
"]"                 { token(']'); return ']';}
"{"                 { token('{'); return '{';}
"}"                 { token('}'); return '}';}

 /* Arithmetic, Relational and Logical Operators */
"+"                 { token('+'); return '+';}
"-"                 { token('-'); return '-';}
"*"                 { token('*'); return '*';}
"/"                 { token('/'); return '/';}

"%"                 { token('%'); return '%';}

"<"                 { token('<'); return '<';}
"<="                { token('<='); return LE;}
">="                { token('>='); return GE;}
">"                 { token('>'); return '>';}
"=="                { token('=='); return EQ;}
"!="                { token('!='); return NE;}

"&"                 { token('&'); return '&';}
"|"                 { token('|'); return '|';}
"!"                 { token('!'); return '!';}

"="                 { token('='); return '=';}

"+="                { token('+='); return ADD;}
"-="                { token('-='); return SUB;}
"*="                { token('*='); return MUL;}
"/="                { token('/='); return DIV;}



".."                { token(RANGE); return RANGE;}

 /* Keywords */
"bool"              { token(BOOL); return BOOL;}
"break"             { token(BREAK); return BREAK;}
"char"              { token(CHAR); return CHAR;}
"case"              { token(CASE); return CASE;}
"class"             { token(CLASS); return CLASS;}
"continue"          { token(CONTINUE); return CONTINUE;}
"declare"           { token(DECLARE); return DECLARE;}
"do"                { token(DO); return DO;}
"else"              { token(ELSE); return ELSE;}
"exit"              { token(EXIT); return EXIT;}
"false"             { token(FALSE); yylval.boolean_value = false; return BOOL_LITERAL;}
"float"             { token(FLOAT); return FLOAT;}
"for"               { token(FOR); return FOR;}
"fun"               { token(FUN); return FUN;}
"if"                { token(IF); return IF;}
"in"                { token(IN); return IN;}
"int"               { token(INT); return INT;}
"loop"              { token(LOOP); return LOOP;}
"print"             { token(PRINT); return PRINT;}
"println"           { token(PRINTLN); return PRINTLN;}
"return"            { token(RETURN); return RETURN;}
"string"            { token(STRING); return STRING;}
"true"              { token(TRUE); yylval.boolean_value = true; return BOOL_LITERAL;}
"val"               { token(VAL); return VAL;}
"var"               { token(VAR); return VAR;}
"while"             { token(WHILE); return WHILE;}


{IDENTIFIER}        { 
                      tokenString(id, yytext);
                      yylval.string_value = new string(yytext);
                      return ID;
                    }

{INTEGER}           { 
                      tokenInteger(integer, atoi(yytext)); 
                      yylval.integer_value = atoi(yytext);
                      return INT_LITERAL;
                    }

{REAL}              { 
                      tokenString(real, yytext); 
                      yylval.double_value = atof(yytext);
                      return REAL_LITERAL;
                    }

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
                      yylval.string_value = new string(temp);
                      return STRING_LITERAL;
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
                          if(debugPrint) printf("%d: %s", linenum++, buf);
                          buf[0] = '\0';
                        }

<COMMENT>{COMMENT_END}  {
                          LIST;
                          BEGIN INITIAL;
                        }

\n                  {
                        LIST;
                        if(debugPrint) printf("%d: %s", linenum++, buf);
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