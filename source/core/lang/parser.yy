/*
 *******************************************************************************
 *   Copyright (C) 2012 Vasiliy Sheredeko
 *   MIT license. All Rights Reserved.
 *******************************************************************************
 */
%{ /*** C/C++ Declarations ***/

#include "apus/config.hpp"
#include <stdio.h>
#include <string>
#include <vector>

%}

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
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.mStreamName;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union { }

%token                  END             0   "end of file"
%token                  EOL                 "end of line"
%token                  UNIX_SCRIPT         "unix script"

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "apus/lang/driver.hpp"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.mLexer->lex

#define yyfree(__px1) delete __px1; __px1 = 0;

%}

%% /*** Grammar Rules ***/


/** START POINT **/
start
    : /* empty */
    | END
    ;

/*** END GRAMAR - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void apus::lang::ApusParser::error(const ApusParser::location_type& l,
			    const std::string& m)
{
    // driver.error(l, m);
}
