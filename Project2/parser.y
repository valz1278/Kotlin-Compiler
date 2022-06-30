%{
#include <iostream>
#include "SymbolTable.hpp"
#include "lex.yy.cpp"

extern int linenum;
int top_index = -1;
vector<SymbolTable> tableList;
vector<vector<identifierData>> params;
void yyerror(string s);
void push();
bool pop();
void dump();
void beginParam();
void endParam();
void addParam(identifierData data);
void addArgument(string id, int data_type);
void create(string id, identifierData data, int id_type);
void createWithTypes(string id, int data_type, int id_type); 
void createFunction(string id, int id_type); 
void createArray(string id, int type, int size);
void checkDataType(identifierData data, int type);
void checkIdentifierType(identifierData data, int type);
void checkParameters(identifierData* data);
identifierData* fetch(string id);
%}

/* Start rule */
%start program

/* Type definition */
%union {
    int integer_value;
    string *string_value;
    bool boolean_value;
    double double_value;
    identifierData* data;
    int data_type;
}

/* Identifier */
%token <string_value> ID

/* Multicharacter operators */
%token LE 
%token GE 
%token EQ 
%token NE 
%token ADD
%token SUB
%token MUL
%token DIV

/* Keywords */
%token BOOL 
%token BREAK
%token CHAR
%token CASE
%token CLASS
%token CONTINUE
%token DECLARE
%token DO 
%token ELSE
%token EXIT
%token FALSE
%token FLOAT 
%token FOR 
%token FUN 
%token IF 
%token IN 
%token INT 
%token LOOP
%token PRINT 
%token PRINTLN 
%token RANGE 
%token RETURN 
%token STRING 
%token VAL 
%token VAR 
%token WHILE

/* Literals */
%token <boolean_value> BOOL_LITERAL
%token <double_value> REAL_LITERAL
%token <string_value> STRING_LITERAL
%token <integer_value> INT_LITERAL

/* Type declarations */
%type <data> literal_constant 
%type <data> expression 
%type <data> bool_expr 
%type <data> arithmetic_expr
%type <data> invocation
%type <data> assign_expr
%type <data_type> assign_var_type
%type <data_type> variable_type

/* Operator precedence */
%left '|'
%left '&'
%left '!'
%left '<' LE EQ GE '>' NE
%left '+' '-'
%left '*' '/'
%nonassoc UNARY_MINUS

%%

program: class_declaration program | ;

class_declaration : CLASS ID { push(); } 
                    class_block 
                  {
                    identifierData* temp = fetch("main");
                    if(temp->id_type != 3) yyerror("main is not a function");
                    dump();
                    pop();
                  }
                  ;

class_block : '{' class_contents'}' ;

class_contents : declarations class_contents | function class_contents | function;

declarations: declaration declarations | ;

declaration : variable | constant | array ;

formal_arguments: '(' arguments ')' ;

arguments : argument ',' arguments | argument |  ;

argument: ID ':' variable_type { createWithTypes(*$1, $3, 1); addArgument(*$1, $3); };

return_type : ':' variable_type { tableList[top_index - 1].setReturnType($2); }
            | { tableList[top_index - 1].setReturnType(6); }
            ;

block : '{' declarations statements '}';

statements: statement statements | statement ;

statement : simple_stmt | block | conditional_stmt | loop_stmt;

function  : FUN ID { createFunction(*$2, 3); push();} formal_arguments return_type block { dump(); pop();};

simple_stmt : ID '=' expression 
            {
              identifierData* temp = fetch(*$1);
              if(temp->id_type != 1){
                yyerror(*$1 + " isn't a variable");
              }
              if(temp->initialized){
                if($3->data_type == temp->data_type){
                  temp->value = $3->value;
                }
                else{
                  yyerror("Incompatible types");
                }
                temp->value = $3->value;
              }
              else{
                temp->value = $3->value;
                temp->initialized = true;
              } 
            }
            | ID '[' expression ']' '=' expression { identifierData* temp = fetch(*$1); if ($3->value.i_val >= temp->array_size || $3-> value.i_val < 0) yyerror("Given index is not within range"); if (temp->value.arguments[0].data_type != $6->data_type) yyerror("Data type doesn't match"); }
            | PRINT expression 
            | PRINTLN expression 
            | RETURN expression 
            | RETURN 
            ;

conditional_stmt  : if_statement | if_statement else_statement ;

if_statement      : IF expression simple_stmt { checkDataType(*$2, 3); }
                  | IF expression block { checkDataType(*$2, 3); }
                  ;

else_statement    : ELSE simple_stmt 
                  | ELSE block 
                  ;

loop_stmt : while_loop | for_loop;

while_loop  : WHILE expression simple_stmt { checkDataType(*$2, 3); } 
            | WHILE expression block { checkDataType(*$2, 3); } 
            ;

for_loop: FOR '(' ID IN INT_LITERAL RANGE INT_LITERAL ')' simple_stmt { checkIdentifierType(*fetch(*$3), 1); } 
        | FOR '(' ID IN INT_LITERAL RANGE INT_LITERAL ')' block { checkIdentifierType(*fetch(*$3), 1); } 
        ;

assign_expr: '=' expression { $$ = $2;}; 

assign_var_type: ':' variable_type { $$ = $2;}; 

variable: VAR ID { createWithTypes(*$2, 1, 1);} 
        | VAR ID assign_expr { create(*$2, *$3, 1);} 
        | VAR ID assign_var_type { createWithTypes(*$2, $3, 1);} 
        | VAR ID assign_var_type assign_expr { checkDataType(*$4, $3); create(*$2, *$4, 1);} 
        ;

constant: VAL ID assign_expr { create(*$2, *$3, 2); } 
        | VAL ID assign_var_type assign_expr { checkDataType(*$4, $3); create(*$2, *$4, 2);} 
        ;

array : VAR ID assign_var_type '[' INT_LITERAL ']' { createArray(*$2, $3, $5);}; 

invocation: ID '(' { checkIdentifierType(*fetch(*$1), 3); beginParam(); } comma_separated_expressions ')' { checkParameters(fetch(*$1)); $$ = fetch(*$1); endParam(); };

comma_separated_expressions : expression { addParam(*$1); } ',' comma_separated_expressions 
                            | expression { addParam(*$1); } 
                            | 
                            ;

expression  :'(' expression ')' { $$ = $2; } 
            | ID  { $$ = fetch(*$1); } 
            | literal_constant 
            | ID '[' expression ']' { identifierData *temp = fetch(*$1); if(temp->data_type != 5) yyerror(*$1 + " is not an array"); if($3->value.i_val >= temp->array_size || $3->value.i_val < 0) yyerror("Index out of range"); $$ = new identifierData(); $$->data_type = temp->data_type;}
            | invocation 
            | bool_expr 
            | arithmetic_expr 
            ;

bool_expr : expression '<' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.i_val < $3->value.i_val);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.b_val = ((float)$1->value.i_val < $3->value.d_val);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.d_val < (float)$3->value.i_val);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.b_val = ($1->value.d_val < $3->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            $$ = temp;
          }
          | expression LE expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.i_val <= $3->value.i_val);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.b_val = ((float)$1->value.i_val <= $3->value.d_val);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.d_val <= (float)$3->value.i_val);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.b_val = ($1->value.d_val <= $3->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            $$ = temp;
          }
          | expression EQ expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.i_val == $3->value.i_val);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.b_val = ($1->value.d_val == $3->value.d_val);
            }
            else if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.b_val = ($1->value.b_val == $3->value.b_val);
            }
            else if($1->data_type == 4 && $3->data_type == 4) {
              temp->value.b_val = ($1->value.s_val == $3->value.s_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr == expr");
            }
            $$ = temp;
          }
          | expression GE expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.i_val >= $3->value.i_val);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.b_val = ((float)$1->value.i_val >= $3->value.d_val);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.d_val >= (float)$3->value.i_val);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.b_val = ($1->value.d_val >= $3->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr >= expr");
            }
            $$ = temp;
          }
          | expression '>' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.i_val > $3->value.i_val);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.b_val = ((float)$1->value.i_val > $3->value.d_val);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.d_val > (float)$3->value.i_val);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.b_val = ($1->value.d_val > $3->value.d_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr > expr");
            }
            $$ = temp;
          }
          | expression NE expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.b_val = ($1->value.i_val != $3->value.i_val);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.b_val = ($1->value.d_val != $3->value.d_val);
            }
            else if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.b_val = ($1->value.b_val != $3->value.b_val);
            }
            else if($1->data_type == 4 && $3->data_type == 4) {
              temp->value.b_val = ($1->value.s_val != $3->value.s_val);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr != expr");
            }
            $$ = temp;
          }
          | '!' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($2->data_type == 3) {
              temp->value.b_val = !($2->value.b_val);
            }
            else {
              yyerror("Incompatible type for !expr");
            }
            $$ = temp;
          }
          | expression '&' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.b_val = $1->value.b_val && $3->value.b_val;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            $$ = temp;
          }
          | expression '|' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.b_val = $1->value.b_val || $3->value.b_val;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            $$ = temp;
          } 

arithmetic_expr :'-' expression %prec UNARY_MINUS 
                {
                  identifierData* temp = new identifierData();
                    if($2->data_type == 1) {
                    *temp = *$2;
                    temp->value.i_val = -1 * temp->value.i_val;
                  }
                  else if($2->data_type == 2) {
                    *temp = *$2;
                    temp->value.d_val = -1 * temp->value.d_val;
                  }
                  else {
                    yyerror("Incompatible type for -expr");
                  }
                  $$ = temp;
                }
                | expression '*' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ($1->value.i_val * $3->value.i_val);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)$1->value.i_val * $3->value.d_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val * (double)$3->value.i_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val * $3->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr * expr");
                  }
                  $$ = temp;
                }
                | expression '/' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ($1->value.i_val / $3->value.i_val);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)$1->value.i_val / $3->value.d_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val / (double)$3->value.i_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val / $3->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr / expr");
                  }
                  $$ = temp;
                }
                | expression '+' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ($1->value.i_val + $3->value.i_val);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)$1->value.i_val + $3->value.d_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val + (double)$3->value.i_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val + $3->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr + expr");
                  }
                  $$ = temp;
                }
                | expression '-' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.i_val = ($1->value.i_val - $3->value.i_val);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ((double)$1->value.i_val - $3->value.d_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val - (double)$3->value.i_val);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.d_val = ($1->value.d_val - $3->value.d_val);
                  }
                  else {
                    yyerror("Incompatible type for expr - expr");
                  }
                  $$ = temp;
                }

literal_constant: INT_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 1;
                  data->value.i_val = $1;
                  data->id_type = 4;
                  $$ = data;
                }
                | REAL_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 2;
                  data->value.d_val = $1;
                  data->id_type = 4;
                  $$ = data;
                }
                | BOOL_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 3;
                  data->value.b_val = $1;
                  data->id_type = 4;
                  $$ = data;
                }
                | STRING_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 4;
                  data->value.s_val = *$1;
                  data->id_type = 4;
                  $$ = data;
                }
                ;

variable_type : INT { $$ = 1; }
              | FLOAT { $$ = 2; }
              | BOOL { $$ = 3; }
              | STRING { $$ = 4; }
              ;


%%

void yyerror(string s) {
  cout << "Error line: " << linenum  << " (" << s  << ')' << endl;
  exit(1);
}

void checkDataType(identifierData data, int type){
  if (type != data.data_type) yyerror("Incompatible data type");
}

void checkIdentifierType(identifierData data, int type){
  if (type != data.id_type) yyerror("Incompatible identifier type");
}

void checkParameters(identifierData* data){
  if (params[params.size() - 1].size() != data->value.arguments.size()) { 
    yyerror("Parameter amount doesn't match");
  }
  for (int i = 0; i < data->value.arguments.size(); i++) {
    if (params[params.size() - 1].at(i).data_type != data->value.arguments[i].data_type) yyerror("Parameter type does not match"); 
  }
}

void create(string id, identifierData data, int id_type){
  int result = tableList[top_index].insert(id, data.data_type, id_type, data.value, true);
  if (result == -1) yyerror(id + " already exists");
}

void createWithTypes(string id, int data_type, int id_type){
  values* temp = new values();
  int result = tableList[top_index].insert(id, data_type, id_type, *temp, false);
  if (result == -1) yyerror(id + " already exists");
}

void createFunction(string id, int id_type){
  identifierData* temp = new identifierData();
  int result = tableList[top_index].insert(id, temp->data_type, id_type, temp->value, temp->initialized);
  if (result == -1) yyerror(id + " already exists");
}

void createArray(string id, int type, int size){
  int result = tableList[top_index].insert(id, type, size);
  if (result == -1) yyerror(id + " already exists");
}

identifierData* fetch(string id) {
  identifierData *result = NULL;
  for (int i = top_index; i >= 0; i--) {
    if (tableList[i].doesExist(id)) result = tableList[i].lookup(id);
  }
  if (result == NULL) yyerror(id + " does not exist");
  return result;
}

void push()
{
  tableList.push_back(SymbolTable());
  top_index++;
}

bool pop()
{
  if (tableList.size() <= 0) return false;
  tableList.pop_back();
  top_index--;
  return true;
}

void dump()
{
  cout << endl << "**************************************************" << endl << endl;
  for (int i = top_index; i >= 0; i--) {
    cout << "Index: " << i << endl;
    tableList[i].dump();
  }
  cout << "**************************************************" << endl << endl;
}

void addArgument(string id, int data_type)
{
  identifierData* temp = new identifierData();
  temp->data_type = data_type;
  tableList[top_index - 1].addArgument(id, *temp);
}

void beginParam(){
  params.push_back(vector<identifierData>());
}

void endParam(){
  params.pop_back();
}

void addParam(identifierData data){
  params[params.size() - 1].push_back(data);
}

int main(void) {
    yyparse();
    return 0;
}