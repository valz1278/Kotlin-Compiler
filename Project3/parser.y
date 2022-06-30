%{
#include <iostream>
#include <fstream>
#include <stack>
#include "SymbolTable.hpp"
#include "lex.yy.cpp"

void yyerror(string s);
extern int linenum;

int top_index = -1;
vector<SymbolTable> tableList;
void push();
bool pop();
void dump();
void addArgument(string id, int data_type);
void create(string id, identifierData data, int id_type);
void createWithTypes(string id, int data_type, int id_type); 
void createFunction(string id, int id_type); 
void createArray(string id, int type, int size);

vector<vector<identifierData>> params;
void beginParam();
void endParam();
void addParam(identifierData data);

void checkDataType(identifierData data, int type);
void checkIdentifierType(identifierData data, int type);
void checkParameters(identifierData* data);
identifierData* fetch(string id);

string className;
ofstream out;
int checkScope(string id);

int labelCount = 0;
vector<int> ifLabelCounter;
vector<int> whileLabelCounter;
vector<int> forLabelCounter;
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

class_declaration : CLASS ID 
                  { 
                    push();
                    className = *$2;
                    out << "class " << className << endl << "{" << endl; 
                  } 
                    class_block 
                  {
                    identifierData* temp = fetch("main");
                    if(temp->id_type != 3) yyerror("main is not a function");
                    // dump();
                    pop();
                    out << "}" << endl;
                  }
                  ;

class_block : '{' class_contents'}' ;

class_contents : declarations class_contents | function class_contents | function;

declarations: declaration declarations | ;

declaration : variable | constant | array ;

formal_arguments: '(' arguments ')' ;

arguments : argument ',' arguments | argument |  ;

argument: ID ':' variable_type { createWithTypes(*$1, $3, 1); addArgument(*$1, $3); };

return_type : ':' variable_type { tableList[top_index - 1].setReturnType($2); } | { tableList[top_index - 1].setReturnType(6); };

block : '{' declarations statements '}';

statements: statement statements | ;

statement : simple_stmt | block | if_statement | loop_stmt;

function  : FUN ID { createFunction(*$2, 3); push();} formal_arguments return_type 
          { 
            if(*$2 == "main") {
              out << "\tmethod public static void main(java.lang.String[])" << endl 
              << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl << "\t{" << endl;
            }
            else {
              out << "\tmethod public static ";
              if(fetch(*$2)->data_type == 6) out << "void ";
              else out << "int ";
              out << *$2 << "(";
              for(int i = 0; i < fetch(*$2)->value.arguments.size(); i++){
                if(i == 0) out << stringDataType(fetch(*$2)->value.arguments[i].data_type);
                else out << ", " << stringDataType(fetch(*$2)->value.arguments[i].data_type);
              }
              out << ")" << endl << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl << "\t{" << endl;
            }
          } 
          block 
          { 
            if(fetch(*$2)->data_type == 6) out << "\t\treturn" << endl << "\t}" << endl;
            else out << "\t}" << endl;
            // dump(); 
            pop();
          }
          ;

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
              if(checkScope(*$1) == -1) out << "\t\tputstatic int " << className << "." << *$1 << endl;
              else if(checkScope(*$1) > -1) out << "\t\tistore " << checkScope(*$1) << endl;
            }
            | ID '[' expression ']' '=' expression { identifierData* temp = fetch(*$1); if ($3->value.int_value >= temp->array_size || $3-> value.int_value < 0) yyerror("Given index is not within range"); if (temp->value.arguments[0].data_type != $6->data_type) yyerror("Data type doesn't match"); }
            | PRINT { out << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl; }
              expression { out << "\t\tinvokevirtual void java.io.PrintStream.print(" << stringDataType($3->data_type) << ")" << endl; }
            | PRINTLN { out << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl; }
              expression { out << "\t\tinvokevirtual void java.io.PrintStream.println(" << stringDataType($3->data_type) << ")" << endl; }
            | RETURN expression { out << "\t\tireturn" << endl; }
            | RETURN { out << "\t\treturn" << endl; }
            ;

body: block | simple_stmt;

if_statement      : IF expression 
                  { 
                    checkDataType(*$2, 3);
                    out << "\t\tifeq L" << labelCount << endl;
                    ifLabelCounter.push_back(labelCount++);
                    ifLabelCounter.push_back(labelCount++);
                  } 
                  body else_statement 
                  ; 

else_statement    : ELSE 
                  {
                    out << "\t\tgoto L" << ifLabelCounter.back() << endl;
                    out << "\tL" << ifLabelCounter[ifLabelCounter.size() - 2] << ":" << endl;
                  } 
                   body
                  {
                    out << "\tL" << ifLabelCounter.back() << ":" << endl;
                    ifLabelCounter.pop_back();
                    ifLabelCounter.pop_back();
                  }
                  | 
                  {
                    out << "\tL" << ifLabelCounter[ifLabelCounter.size() - 2] << ":" << endl;
                    ifLabelCounter.pop_back();
                    ifLabelCounter.pop_back();
                  } 
                  ;

loop_stmt : while_loop | for_loop;

while_loop  : WHILE 
            { 
              out << "\tL" << labelCount << ":" << endl;
              whileLabelCounter.push_back(labelCount++);
            } 
              expression 
            {
              checkDataType(*$3, 3);
              out << "\t\tifeq L" << labelCount << "\n";
              whileLabelCounter.push_back(labelCount++);
            } 
              body 
            { 
              out << "\t\tgoto L" << whileLabelCounter[whileLabelCounter.size() - 2] << endl;
              out << "\tL" << whileLabelCounter[whileLabelCounter.size() - 1] << ":" << endl;
              whileLabelCounter.pop_back();
              whileLabelCounter.pop_back();
            } 
            ;

for_loop: FOR '(' ID IN INT_LITERAL RANGE INT_LITERAL ')' body { checkIdentifierType(*fetch(*$3), 1); } 
        ;

assign_expr: '=' expression { $$ = $2;}; 

assign_var_type: ':' variable_type { $$ = $2;}; 

variable: VAR ID 
        { 
          createWithTypes(*$2, 1, 1);
          if(top_index == 0) out << "\tfield static int " << *$2 << endl;
        } 
        | VAR ID assign_expr 
        { 
          create(*$2, *$3, 1);
          if(top_index == 0) {
            out << "\tfield static " << stringDataType($3->data_type) << " " << *$2 << " = ";
            if($3->data_type == 3) out << ($3->value.bool_value? "true" : "false");
            else out << ($3->value.int_value);
            out << endl;
          }
          if(checkScope(*$2) > -1) out << "\t\tistore " << checkScope(*$2) << endl;
        } 
        | VAR ID assign_var_type 
        { 
          createWithTypes(*$2, $3, 1);
          if($3 == 1 || $3 == 3){
            if(top_index == 0) out << "\tfield static " << stringDataType($3) << " " << *$2 << endl;
          }
        } 
        | VAR ID assign_var_type assign_expr 
        { 
          checkDataType(*$4, $3); 
          create(*$2, *$4, 1);
          
          if(top_index == 0) {
            out << "\tfield static " << stringDataType($3) << " " << *$2 << " = ";
            if($4->data_type == 3) out << ($4->value.bool_value? "true" : "false");
            else out << ($4->value.int_value);
            out << endl;
          }
          if (checkScope(*$2) > -1) out << "\t\tistore " << checkScope(*$2) << endl;
        } 
        ;

constant: VAL ID assign_expr { create(*$2, *$3, 2); } 
        | VAL ID assign_var_type assign_expr { checkDataType(*$4, $3); create(*$2, *$4, 2);} 
        ;

array : VAR ID assign_var_type '[' INT_LITERAL ']' { createArray(*$2, $3, $5);}; 

invocation: ID '(' { checkIdentifierType(*fetch(*$1), 3); beginParam(); } comma_separated_expressions ')' 
          { 
            checkParameters(fetch(*$1)); 
            out << "\t\tinvokestatic " << stringDataType(fetch(*$1)->data_type) << " " << className << "." << *$1 << "(";
            for(int i = 0; i < fetch(*$1)->value.arguments.size(); i++){
              if(i == 0) out << stringDataType(fetch(*$1)->value.arguments[i].data_type);
              else out << ", " << stringDataType(fetch(*$1)->value.arguments[i].data_type);
            }
            out << ")" << endl;
            $$ = fetch(*$1); 
            endParam(); 
          }
          ;

comma_separated_expressions : expression { addParam(*$1); } ',' comma_separated_expressions 
                            | expression { addParam(*$1); } 
                            | 
                            ;

expression  :'(' expression ')' { $$ = $2; } 
            | ID  
            { 
              identifierData* data = fetch(*$1);
              $$ = data; 
              if( data->id_type == 2 || data->id_type == 4 ){
                if(top_index != 0){
                  if(data->data_type == 4) out << "\t\tldc \"" << data->value.string_value << "\"" << endl;
                  else if(data->data_type == 3) out << "\t\t" << (data->value.bool_value? "iconst_1" : "iconst_0") << endl;
                  else if(data->data_type == 2) out << "\t\tsipush " << data->value.int_value << endl;
                  else if(data->data_type == 1) out << "\t\tsipush " << data->value.int_value << endl;
                }
              }
              else {
                if (checkScope(*$1) == -1) out << "\t\tgetstatic int " << className << "." << *$1 << endl;
                else if (checkScope(*$1) > -1) out << "\t\tiload " << checkScope(*$1) << endl;
              }           
            } 
            | literal_constant 
            | ID '[' expression ']' { identifierData *temp = fetch(*$1); if(temp->data_type != 5) yyerror(*$1 + " is not an array"); if($3->value.int_value >= temp->array_size || $3->value.int_value < 0) yyerror("Index out of range"); $$ = new identifierData(); $$->data_type = temp->data_type;}
            | invocation 
            | bool_expr 
            | arithmetic_expr 
            ;

bool_expr : expression '<' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.int_value < $3->value.int_value);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.bool_value = ((float)$1->value.int_value < $3->value.double_value);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.double_value < (float)$3->value.int_value);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.bool_value = ($1->value.double_value < $3->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            $$ = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tiflt" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
          | expression LE expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.int_value <= $3->value.int_value);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.bool_value = ((float)$1->value.int_value <= $3->value.double_value);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.double_value <= (float)$3->value.int_value);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.bool_value = ($1->value.double_value <= $3->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr <= expr");
            }
            $$ = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifle" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
          | expression EQ expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.int_value == $3->value.int_value);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.bool_value = ($1->value.double_value == $3->value.double_value);
            }
            else if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.bool_value = ($1->value.bool_value == $3->value.bool_value);
            }
            else if($1->data_type == 4 && $3->data_type == 4) {
              temp->value.bool_value = ($1->value.string_value == $3->value.string_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr == expr");
            }
            $$ = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifeq" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
          | expression GE expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.int_value >= $3->value.int_value);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.bool_value = ((float)$1->value.int_value >= $3->value.double_value);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.double_value >= (float)$3->value.int_value);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.bool_value = ($1->value.double_value >= $3->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr >= expr");
            }
            $$ = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifge" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
          | expression '>' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.int_value > $3->value.int_value);
            }
            else if($1->data_type == 1 && $3->data_type == 2) {
              temp->value.bool_value = ((float)$1->value.int_value > $3->value.double_value);
            }
            else if($1->data_type == 2 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.double_value > (float)$3->value.int_value);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.bool_value = ($1->value.double_value > $3->value.double_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr > expr");
            }
            $$ = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifgt" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
          | expression NE expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 1 && $3->data_type == 1) {
              temp->value.bool_value = ($1->value.int_value != $3->value.int_value);
            }
            else if($1->data_type == 2 && $3->data_type == 2) {
              temp->value.bool_value = ($1->value.double_value != $3->value.double_value);
            }
            else if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.bool_value = ($1->value.bool_value != $3->value.bool_value);
            }
            else if($1->data_type == 4 && $3->data_type == 4) {
              temp->value.bool_value = ($1->value.string_value != $3->value.string_value);
            }
            else {
              yyerror("Incompatible type / type mismatch for expr != expr");
            }
            $$ = temp;

            int lb1 = labelCount++;
            int lb2 = labelCount++;
            out << "\t\tisub" << endl;
            out << "\t\tifne" << " L" << lb1 << endl;
            out << "\t\ticonst_0" << endl;
            out << "\t\tgoto L" << lb2 << endl;
            out << "\tL" << lb1 << ":" << endl;
            out << "\t\ticonst_1" << endl;
            out << "\tL" << lb2 << ":" << endl;
          }
          | '!' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($2->data_type == 3) {
              temp->value.bool_value = !($2->value.bool_value);
            }
            else {
              yyerror("Incompatible type for !expr");
            }
            $$ = temp;

            out << "\t\ticonst_1" << endl << "\t\tixor" << endl;
          }
          | expression '&' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.bool_value = $1->value.bool_value && $3->value.bool_value;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            $$ = temp;

            out << "\t\tiand" << endl;
          }
          | expression '|' expression 
          {
            identifierData* temp = new identifierData();
            temp->data_type = 3;
            if($1->data_type == 3 && $3->data_type == 3) {
              temp->value.bool_value = $1->value.bool_value || $3->value.bool_value;
            }
            else {
              yyerror("Incompatible type for expr | expr");
            }
            $$ = temp;
            out << "\t\tior" << endl;
          } 

arithmetic_expr :'-' expression %prec UNARY_MINUS 
                {
                  identifierData* temp = new identifierData();
                  if($2->data_type == 1) {
                    *temp = *$2;
                    temp->value.int_value = -1 * temp->value.int_value;
                  }
                  else if($2->data_type == 2) {
                    *temp = *$2;
                    temp->value.double_value = -1 * temp->value.double_value;
                  }
                  else {
                    yyerror("Incompatible type for -expr");
                  }
                  $$ = temp;

                  if($2->data_type == 1) out << "\t\tineg" << endl;
                }
                | expression '*' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ($1->value.int_value * $3->value.int_value);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)$1->value.int_value * $3->value.double_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value * (double)$3->value.int_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value * $3->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr * expr");
                  }
                  $$ = temp;

                  if(temp->data_type == 1) out << "\t\timul" << endl;
                }
                | expression '/' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ($1->value.int_value / $3->value.int_value);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)$1->value.int_value / $3->value.double_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value / (double)$3->value.int_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value / $3->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr / expr");
                  }
                  $$ = temp;

                  if(temp->data_type == 1) out << "\t\tidiv" << endl;
                }
                | expression '+' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ($1->value.int_value + $3->value.int_value);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)$1->value.int_value + $3->value.double_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value + (double)$3->value.int_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value + $3->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr + expr");
                  }
                  $$ = temp;

                  if(temp->data_type == 1) out << "\t\tiadd" << endl;
                }
                | expression '-' expression 
                {
                  identifierData* temp = new identifierData();
                  if($1->data_type == 1 && $3->data_type == 1) {
                    temp->data_type = 1;
                    temp->value.int_value = ($1->value.int_value - $3->value.int_value);
                  }
                  else if($1->data_type == 1 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ((double)$1->value.int_value - $3->value.double_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 1) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value - (double)$3->value.int_value);
                  }
                  else if($1->data_type == 2 && $3->data_type == 2) {
                    temp->data_type = 2;
                    temp->value.double_value = ($1->value.double_value - $3->value.double_value);
                  }
                  else {
                    yyerror("Incompatible type for expr - expr");
                  }
                  $$ = temp;

                  if(temp->data_type == 1) out << "\t\tisub" << endl;
                }

literal_constant: INT_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 1;
                  data->value.int_value = $1;
                  data->id_type = 4;
                  if(top_index != 0) out << "\t\tsipush " << $1 << endl;
                  $$ = data;
                }
                | REAL_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 2;
                  data->value.double_value = $1;
                  data->id_type = 4;
                  $$ = data;
                }
                | BOOL_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 3;
                  data->value.bool_value = $1;
                  data->id_type = 4;
                  if(top_index != 0) out << "\t\t" << ($1 ? "iconst_1" : "iconst_0") << endl;
                  $$ = data;
                }
                | STRING_LITERAL
                {
                  identifierData* data = new identifierData();
                  data->data_type = 4;
                  data->value.string_value = *$1;
                  data->id_type = 4;
                  if(top_index != 0) out << "\t\tldc \"" << *$1 << "\"" << endl;
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
    if (tableList[i].doesExist(id)) return tableList[i].lookup(id);
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

int checkScope(string id) {
  for(int i = top_index; i >= 0; i--) {
    if(tableList[i].doesExist(id)) {
      if(i == 0) return -1; /* Global variable detected */
      else return tableList[i].id_map[id].index; /* Local variable */
    }
  }
  return -2;
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  string filename;
  filename = string(argv[1]);
  filename = filename.substr(0, filename.find("."));
  filename += ".jasm";
  out.open(filename);
  yyparse();
  return 0;
}