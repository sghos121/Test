%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <map>
    #include <cmath>
    #include <cstdlib>
    #include <sstream>
    #include "matrix.h"
    #include "utils.h"

    using namespace std;

    // External declarations
    void yyerror(const char* s);
    int yylex();
    extern FILE *yyin;

    // Symbol table
    struct Value {
        enum { NUMBER, BOOLEAN, STRING, MATRIX } type;
        union {
            double numVal;
            bool boolVal;
            string* strVal;
            Matrix* matrixVal;
        };
        Value() : type(NUMBER), numVal(0.0) {}
        Value(double n) : type(NUMBER), numVal(n) {}
        Value(bool b) : type(BOOLEAN), boolVal(b) {}
        Value(string* s) : type(STRING), strVal(s) {}
        Value(Matrix* m) : type(MATRIX), matrixVal(m) {}
        ~Value() {
            if (type == STRING) delete strVal;
            if (type == MATRIX) delete matrixVal;
        }
    };

    map<string, Value> symbolTable;

    bool isVariableDefined(const string& name) {
        return symbolTable.count(name);
    }

    string getVariableType(const string& name) {
        if (!isVariableDefined(name)) return "Undefined";
        switch (symbolTable[name].type) {
            case Value::NUMBER: return "Number";
            case Value::BOOLEAN: return "Boolean";
            case Value::STRING: return "String";
            case Value::MATRIX: return "Matrix";
            default: return "Unknown";
        }
    }

    string valueToString(const Value& val) {
        ostringstream ss;
        switch (val.type) {
            case Value::NUMBER: ss << val.numVal; break;
            case Value::BOOLEAN: ss << (val.boolVal ? "true" : "false"); break;
            case Value::STRING: ss << *val.strVal; break;
            case Value::MATRIX: ss << *val.matrixVal; break;
            default: ss << "Undefined"; break;
        }
        return ss.str();
    }
%}

%code requires {
    #include <string>
    #include <vector>
    #include "matrix.h"
}

%union {
    double numVal;
    bool boolVal;
    std::string* strVal;
    Matrix* matrixVal;
    struct Value* val;
    std::vector<struct Value*>* valList;
}

%token <numVal> NUMBER
%token <boolVal> TRUE FALSE
%token <strVal> IDENTIFIER STRING
%token IF THEN ELSE FOR WHILE PRINT MATRIX_KEYWORD
%token OR AND NOT
%token PLUS MINUS TIMES DIVIDE ELEMENT_TIMES
%token ASSIGN EQ NEQ LT GT LTE GTE
%token TERNARY_IF TERNARY_ELSE
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA
%token YYEOF

%type <val> expression ternaryExpr logicalOrExpr logicalAndExpr equalityExpr relationalExpr additiveExpr multiplicativeExpr unaryExpr primaryExpr
%type <valList> expressionList

%precedence LOWEST
%precedence TERNARY_PREC
%left OR
%left AND
%left EQ NEQ
%left LT GT LTE GTE
%left PLUS MINUS
%left TIMES DIVIDE ELEMENT_TIMES
%right UMINUS UNOT
%right ASSIGN

%%

program: statementList { cout << "Parsing complete." << endl; }
       ;

statementList: statementList statement
             | statement
             ;

statement: assignmentStmt SEMICOLON
         | ifStmt
         | forStmt
         | whileStmt
         | printStmt SEMICOLON
         | block
         ;

block: LBRACE statementList RBRACE
     ;

assignmentStmt: IDENTIFIER ASSIGN expression {
                string varName = *$1;
                symbolTable[varName] = *$3;
                delete $1;
                delete $3;
              }
              ;

ifStmt: IF LPAREN expression RPAREN THEN block {
        if ($3->type == Value::BOOLEAN && $3->boolVal) {
            // Execute block
        }
        delete $3;
      }
      | IF LPAREN expression RPAREN THEN block ELSE block {
        if ($3->type == Value::BOOLEAN && $3->boolVal) {
            // Execute then-block
        } else {
            // Execute else-block
        }
        delete $3;
      }
      ;

forStmt: FOR LPAREN assignmentStmt SEMICOLON expression SEMICOLON assignmentStmt RPAREN block {
        if ($5->type == Value::BOOLEAN) {
            cout << "For loop condition evaluated to " << ($5->boolVal ? "true" : "false") << endl;
        } else {
            yyerror("For loop condition must be boolean");
        }
        delete $5;
      }
      ;

whileStmt: WHILE LPAREN expression RPAREN block {
          if ($3->type == Value::BOOLEAN) {
              cout << "While loop condition evaluated to " << ($3->boolVal ? "true" : "false") << endl;
          } else {
              yyerror("While loop condition must be boolean");
          }
          delete $3;
        }
        ;

printStmt: PRINT expressionList {
          for (const auto& val : *$2) {
              cout << valueToString(*val) << " ";
              delete val;
          }
          cout << endl;
          delete $2;
        }
        ;

expressionList: expression {
                $$ = new vector<struct Value*>();
                $$->push_back($1);
              }
              | expressionList COMMA expression {
                $$ = $1;
                $$->push_back($3);
              }
              ;

expression: ternaryExpr { $$ = $1; }
          ;

ternaryExpr: logicalOrExpr { $$ = $1; }
           | logicalOrExpr TERNARY_IF expression TERNARY_ELSE ternaryExpr {
             if ($1->type == Value::BOOLEAN && $1->boolVal) {
                 $$ = $3;
                 delete $1;
                 delete $5;
             } else {
                 $$ = $5;
                 delete $1;
                 delete $3;
             }
           }
           %prec TERNARY_PREC
           ;

logicalOrExpr: logicalAndExpr { $$ = $1; }
             | logicalOrExpr OR logicalAndExpr {
               if ($1->type == Value::BOOLEAN && $3->type == Value::BOOLEAN) {
                   $$ = new Value($1->boolVal || $3->boolVal);
               } else {
                   yyerror("Operands of OR must be boolean");
                   $$ = new Value(false);
               }
               delete $1;
               delete $3;
             }
             ;

logicalAndExpr: equalityExpr { $$ = $1; }
              | logicalAndExpr AND equalityExpr {
                if ($1->type == Value::BOOLEAN && $3->type == Value::BOOLEAN) {
                    $$ = new Value($1->boolVal && $3->boolVal);
                } else {
                    yyerror("Operands of AND must be boolean");
                    $$ = new Value(false);
                }
                delete $1;
                delete $3;
              }
              ;

equalityExpr: relationalExpr { $$ = $1; }
            | equalityExpr EQ relationalExpr {
              if ($1->type == $3->type) {
                  switch ($1->type) {
                      case Value::NUMBER:
                          $$ = new Value($1->numVal == $3->numVal);
                          break;
                      case Value::BOOLEAN:
                          $$ = new Value($1->boolVal == $3->boolVal);
                          break;
                      case Value::STRING:
                          $$ = new Value(*$1->strVal == *$3->strVal);
                          break;
                      default:
                          yyerror("Equality not supported for this type");
                          $$ = new Value(false);
                          break;
                  }
              } else {
                  yyerror("Type mismatch in equality comparison");
                  $$ = new Value(false);
              }
              delete $1;
              delete $3;
            }
            | equalityExpr NEQ relationalExpr {
              if ($1->type == $3->type) {
                  switch ($1->type) {
                      case Value::NUMBER:
                          $$ = new Value($1->numVal != $3->numVal);
                          break;
                      case Value::BOOLEAN:
                          $$ = new Value($1->boolVal != $3->boolVal);
                          break;
                      case Value::STRING:
                          $$ = new Value(*$1->strVal != *$3->strVal);
                          break;
                      default:
                          yyerror("Inequality not supported for this type");
                          $$ = new Value(false);
                          break;
                  }
              } else {
                  yyerror("Type mismatch in inequality comparison");
                  $$ = new Value(false);
              }
              delete $1;
              delete $3;
            }
            ;

relationalExpr: additiveExpr { $$ = $1; }
              | relationalExpr LT additiveExpr {
                if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                    $$ = new Value($1->numVal < $3->numVal);
                } else {
                    yyerror("Operands of < must be numbers");
                    $$ = new Value(false);
                }
                delete $1;
                delete $3;
              }
              | relationalExpr GT additiveExpr {
                if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                    $$ = new Value($1->numVal > $3->numVal);
                } else {
                    yyerror("Operands of > must be numbers");
                    $$ = new Value(false);
                }
                delete $1;
                delete $3;
              }
              | relationalExpr LTE additiveExpr {
                if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                    $$ = new Value($1->numVal <= $3->numVal);
                } else {
                    yyerror("Operands of <= must be numbers");
                    $$ = new Value(false);
                }
                delete $1;
                delete $3;
              }
              | relationalExpr GTE additiveExpr {
                if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                    $$ = new Value($1->numVal >= $3->numVal);
                } else {
                    yyerror("Operands of >= must be numbers");
                    $$ = new Value(false);
                }
                delete $1;
                delete $3;
              }
              ;

additiveExpr: multiplicativeExpr { $$ = $1; }
            | additiveExpr PLUS multiplicativeExpr {
              if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                  $$ = new Value($1->numVal + $3->numVal);
              } else if ($1->type == Value::MATRIX && $3->type == Value::MATRIX) {
                  try {
                      $$ = new Value(new Matrix(*$1->matrixVal + *$3->matrixVal));
                  } catch (const exception& e) {
                      yyerror(("Matrix addition error: " + string(e.what())).c_str());
                      $$ = new Value(0.0);
                  }
              } else {
                  yyerror("Operands of + must be numbers or matrices");
                  $$ = new Value(0.0);
              }
              delete $1;
              delete $3;
            }
            | additiveExpr MINUS multiplicativeExpr {
              if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                  $$ = new Value($1->numVal - $3->numVal);
              } else if ($1->type == Value::MATRIX && $3->type == Value::MATRIX) {
                  try {
                      $$ = new Value(new Matrix(*$1->matrixVal - *$3->matrixVal));
                  } catch (const exception& e) {
                      yyerror(("Matrix subtraction error: " + string(e.what())).c_str());
                      $$ = new Value(0.0);
                  }
              } else {
                  yyerror("Operands of - must be numbers or matrices");
                  $$ = new Value(0.0);
              }
              delete $1;
              delete $3;
            }
            ;

multiplicativeExpr: unaryExpr { $$ = $1; }
                  | multiplicativeExpr TIMES unaryExpr {
                    if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                        $$ = new Value($1->numVal * $3->numVal);
                    } else if ($1->type == Value::MATRIX && $3->type == Value::MATRIX) {
                        try {
                            $$ = new Value(new Matrix(*$1->matrixVal * *$3->matrixVal));
                        } catch (const exception& e) {
                            yyerror(("Matrix multiplication error: " + string(e.what())).c_str());
                            $$ = new Value(0.0);
                        }
                    } else {
                        yyerror("Operands of * must be numbers or matrices");
                        $$ = new Value(0.0);
                    }
                    delete $1;
                    delete $3;
                  }
                  | multiplicativeExpr DIVIDE unaryExpr {
                    if ($1->type == Value::NUMBER && $3->type == Value::NUMBER) {
                        if ($3->numVal != 0) {
                            $$ = new Value($1->numVal / $3->numVal);
                        } else {
                            yyerror("Division by zero");
                            $$ = new Value(0.0);
                        }
                    } else {
                        yyerror("Operands of / must be numbers");
                        $$ = new Value(0.0);
                    }
                    delete $1;
                    delete $3;
                  }
                  | multiplicativeExpr ELEMENT_TIMES unaryExpr {
                    if ($1->type == Value::MATRIX && $3->type == Value::MATRIX) {
                        try {
                            $$ = new Value(new Matrix($1->matrixVal->elementWiseMultiply(*$3->matrixVal)));
                        } catch (const exception& e) {
                            yyerror(("Element-wise multiplication error: " + string(e.what())).c_str());
                            $$ = new Value(0.0);
                        }
                    } else {
                        yyerror("Operands of .* must be matrices");
                        $$ = new Value(0.0);
                    }
                    delete $1;
                    delete $3;
                  }
                  ;

unaryExpr: primaryExpr { $$ = $1; }
         | MINUS unaryExpr %prec UMINUS {
           if ($2->type == Value::NUMBER) {
               $$ = new Value(-$2->numVal);
           } else if ($2->type == Value::MATRIX) {
               $$ = new Value(new Matrix(-*$2->matrixVal));
           } else {
               yyerror("Unary minus not supported for this type");
               $$ = new Value(0.0);
           }
           delete $2;
         }
         | NOT unaryExpr %prec UNOT {
           if ($2->type == Value::BOOLEAN) {
               $$ = new Value(!$2->boolVal);
           } else {
               yyerror("NOT operator requires boolean operand");
               $$ = new Value(false);
           }
           delete $2;
         }
         ;

primaryExpr: NUMBER { $$ = new Value($1); }
           | TRUE { $$ = new Value(true); }
           | FALSE { $$ = new Value(false); }
           | STRING { $$ = new Value(new string(*$1)); delete $1; }
           | IDENTIFIER {
             string varName = *$1;
             if (isVariableDefined(varName)) {
                 const Value& val = symbolTable[varName];
                 switch (val.type) {
                     case Value::NUMBER: $$ = new Value(val.numVal); break;
                     case Value::BOOLEAN: $$ = new Value(val.boolVal); break;
                     case Value::STRING: $$ = new Value(new string(*val.strVal)); break;
                     case Value::MATRIX: $$ = new Value(new Matrix(*val.matrixVal)); break;
                     default: $$ = new Value(0.0); break;
                 }
             } else {
                 yyerror(("Undefined variable: " + varName).c_str());
                 $$ = new Value(0.0);
             }
             delete $1;
           }
           | LPAREN expression RPAREN { $$ = $2; }
           | MATRIX_KEYWORD LBRACKET NUMBER COMMA NUMBER RBRACKET {
             int rows = static_cast<int>($3);
             int cols = static_cast<int>($5);
             if (rows > 0 && cols > 0) {
                 $$ = new Value(new Matrix(rows, cols));
             } else {
                 yyerror("Matrix dimensions must be positive");
                 $$ = new Value(0.0);
             }
           }
           ;

%%

void yyerror(const char* s) {
    cerr << "Error: " << s << endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            cerr << "Cannot open file: " << argv[1] << endl;
            return 1;
        }
    }
    yyparse();
    if (yyin) fclose(yyin);
    return 0;
}