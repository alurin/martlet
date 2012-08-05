/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
%code requires { /*** C/C++ Declarations ***/

#include "apus/config.hpp"
#include "apus/lang/exception.hpp"
#include "apus/ast/statement.hpp"
#include "apus/ast/expression.hpp"
#include "apus/ast/function.hpp"
#include "apus/ast/type.hpp"

}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="apus::lang"

/* set the parser's class identifier */
%define "parser_class_name" "ApusParser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    using namespace apus::ast;
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.mStreamName;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }
%parse-param { class ApusStack& scopeStack }

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
    std::string*                stringVal;
    int32_t                     integerVal;
    apus::ast::StatementAst*    statement;
    apus::ast::LeftValueAst*    lvalue;
    apus::ast::RightValueAst*   rvalue;
    apus::ast::FunctionAst*     func;
    apus::ast::TypeAst*         type;
}

%token                  END             0   "end of file"
%token                  EOL                 "end of line"
%token <stringVal>      IDENTIFIER          "identifier"
%token <stringVal>      VARIABLE            "variable"
%token <integerVal>     INTEGER             "integer constant"
%token                  FOR                 "for"
%token                  WHILE               "while"
%token                  IF                  "if"
%token                  ELSEIF              "elseif"
%token                  ELSE                "else"
%token                  TRY                 "try"
%token                  CATCH               "catch"
%token                  FINALLY             "finally"
%token                  THROW               "throw"

%token                  CLASS               "class"
%token                  NAMESPACE           "namespace"

%token                  INTEGER_TY          "integer"
%token                  BOOLEAN_TY          "boolean"
%token                  STRING_TY           "string"
%token                  CHAR_TY             "char"
%token                  DOUBLE_TY           "double"
%token                  FLOAT_TY            "float"

%token                  DELIMITER            "::"
%token                  OP_LSH              "<<"
%token                  OP_RSH              ">>"
%token                  OP_OR               "||"
%token                  OP_AND              "&&"
%token                  OP_EQ               "=="
%token                  OP_NE               "!="
%token                  OP_GE               ">="
%token                  OP_LE               "<="
%token                  OP_INC              "++"
%token                  OP_DEC              "--"
%token                  OP_AADD             "+="
%token                  OP_ASUB             "-="
%token                  OP_ADIV             "/="
%token                  OP_AMUL             "*="
%token                  OP_ASHL             "<<="
%token                  OP_ASHR             ">>="
%token                  OP_AAND             "&="
%token                  OP_AOR              "|="

%left       '=' "+=" "-=" "/=" "*=" "<<=" ">>=" "&=" "|="
%left       "||"
%left       "&&"
%left       '|'
//%left       '^'
%left       '&'
%nonassoc   "==" "!="
%nonassoc   '<' '>' "<=" ">="
%left       ">>" "<<"
%left       '-' '+'
%left       '*' '/' '%'
%right      UNARY '!'
%right      PRE '.' '[' '('
%nonassoc   MINIM

%destructor { delete $$; } IDENTIFIER VARIABLE

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "apus/lang/driver.hpp"
#include "apus/ast/loop.hpp"
#include "apus/ast/variable.hpp"
#include "apus/ast/constant.hpp"
#include "apus/ast/scope.hpp"
#include "stack.hpp"
#include "scanner.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace apus;
using namespace apus::ast;

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.mLexer->lex

#define yyfree(__px1) delete __px1; __px1 = 0;

%}

%% /*** Grammar Rules ***/

qual_identifier
    : IDENTIFIER DELIMITER qual_identifier
    | IDENTIFIER
    ;

/** COMPOSE: CLASSES AND E.T.C **/

namespace_declare
    : NAMESPACE qual_identifier ';'
    ;

class_declare
    : CLASS IDENTIFIER      {
                                scopeStack.pushClass(new ClassAst(*$2, @2));
                                yyfree($2);
                            }
        '{' class_body '}'
                            { delete scopeStack.popClass(); }
    ;

class_body
    : /* empty */
    | class_element class_body
    ;

class_element
    : function_declare      { scopeStack.peakClass()->addFunction($1);
                                yyfree($1)  /// TODO: REMOVE THIS LINE
                            }
    ;

/** FUNCTIONS **/
%type <func> function_declare;
function_declare
    : IDENTIFIER            {
                                FunctionAst* func = new FunctionAst(*$1, @1);
                                scopeStack.pushFunction(func);
                                yyfree($1);
                            }
        '(' function_args_empty ')'
        ':' type            {
                                scopeStack.peakFunction()->setResultType($7);
                            }
        function_body       {
                                $$ = scopeStack.popFunction();
                            }
    ;

function_args_empty
    : /* empty */
    | function_args
    ;

function_args
    : function_arg ',' function_args
    | function_arg
    ;

function_arg
    : VARIABLE ':' type     {
                                scopeStack.peakFunction()->addArgument(*$1, $3, @1);
                                yyfree($1);
                            }
    ;

function_body
    : '{'               {
                            FunctionAst* parent       = scopeStack.peakFunction();
                            ScopeStatementAst* scope  = new ScopeStatementAst(parent, @1);
                            scopeStack.pushScope(scope);
                        }
        statements '}'  {
                            scopeStack.peakFunction()->setRootScope(scopeStack.popScope());
                        }
    | ';'
    ;

/** TYPES **/
%type <type> type;
type
    : simple_type '*'       { $$ = new ArrayTypeAst($1, @$); }
    | simple_type '[' ']'   { $$ = new ArrayTypeAst($1, @$); }
    | simple_type           { $$ = $1; }
    ;

%type <type> simple_type;
simple_type
    : INTEGER_TY            { $$ = new IntegerTyAst(@1); }
    | BOOLEAN_TY            { $$ = new BooleanTyAst(@1); }
    | STRING_TY             { $$ = new StringTyAst(@1);  }
    | CHAR_TY               { $$ = new CharTyAst(@1);    }
    | DOUBLE_TY             { $$ = new DoubleTyAst(@1);  }
    | FLOAT_TY              { $$ = new FloatTyAst(@1);   }
    ;

/** STATEMENTS **/
%type <statement> statements;
statements
    : /* empty */
    | statement             {  }
        statements
    ;

%type <statement> scope;
scope
    : '{'               {
                            ScopeStatementAst* parent = scopeStack.peakScope();
                            ScopeStatementAst* scope  = new ScopeStatementAst(parent, @1);
                            scopeStack.pushScope(scope);
                        }
        statements '}'  {
                            $$ = scopeStack.popScope();
                        }
    ;


%type <statement> statement;
statement
    : scope
    | for_loop
    | while_loop
    | if_statement
    | try_statement
    | line_statement
    ;

%type <statement> line_statement;
line_statement
    : expression ';'            { $$ = new ExpressionStatementAst($1); }
    | exception_statement ';'   { $$ = $1; }
    ;


%type <statement> empty_statement;
empty_statement
    : /* empty */               { $$ = 0; }
    | statement
    ;

%type <rvalue> conditional;
conditional
    : expression
    ;

%type <rvalue> empty_conditional;
empty_conditional
    : /* empty */               { $$ = 0; }
    | conditional
    ;

%type <rvalue> empty_expression;
empty_expression
    : /* empty */               { $$ = 0; }
    | expression
    ;

%type <statement> for_loop;
for_loop
    : FOR '(' empty_statement ';' empty_conditional ';' empty_statement ')' statements
        {
            ForLoopAst* stmt = new ForLoopAst($3, $5, $7, @1);
            stmt->append($9);
            $$ = stmt;
        }
    ;

%type <statement> while_loop;
while_loop
    : WHILE                             {
                                            WhileLoopAst* stmt = new WhileLoopAst($3, @1);
                                            $$ = stmt;

                                        }
        '(' conditional ')' statements  {
                                            scopeStack.pushSequence();
                                        }
    ;

%type <statement> if_statement;
if_statement
    : IF '(' conditional ')' statements
    | IF '(' conditional ')' statements elseif_parts
    | IF '(' conditional ')' statements elseif_parts ELSE statements
    ;

elseif_parts
    : /* empty */
    | elseif_part elseif_parts
    ;

elseif_part
    : ELSEIF '(' conditional ')' statements
    ;

%type <statement> try_statement;
try_statement
    : TRY CATCH ELSE FINALLY
    ;

%type <statement> exception_statement;
exception_statement
    : THROW
    ;

/** EXPRESSIONS **/
%type <rvalue> expression;
expression
    : lvalue '=' expression             { $$ = new AssignAst($1, $3, @$); }
    | rvalue                            { $$ = $1; }
    ;

%type <lvalue> lvalue;
lvalue
    : VARIABLE                          {
                                            MutableAst* var = scopeStack.peakScope()->getMutable(*$1);
                                            yyfree($1);
                                            if (var)
                                                $$ = new LMutableAst(var, @$);
                                            else {
                                                error(@1, "Variable or argument not found in current scope");
                                                YYERROR;
                                            }
                                        }
    ;

%type <rvalue> rvalue;
rvalue
    : VARIABLE                          {
                                            MutableAst* var = scopeStack.peakScope()->getMutable(*$1);
                                            yyfree($1);
                                            if (var)
                                                $$ = new RMutableAst(var, @$);
                                            else {
                                                error(@1, "Variable or argument not found in current scope");
                                                YYERROR;
                                            }
                                        }
    | INTEGER                           { $$ = new IntegerConstantAst($1, @1); }
    ;

/** START POINT **/
start
    : END /* empty */
    | namespace_declare class_declare END
    ;

/*** END GRAMAR - Change the example grammar rules above ***/

%% /*** Additional Code ***/

using namespace apus;
using namespace apus::lang;

void ApusParser::error(const ApusParser::location_type& l,
			    const std::string& m)
{
    std::cout << l << ": " << m << "\n";
    new LangException(String::fromUTF8(m), l);
}
