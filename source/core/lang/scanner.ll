/*
 *******************************************************************************
 *   Copyright (C) 2012 Vasiliy Sheredeko
 *   MIT license. All Rights Reserved.
 *******************************************************************************
 */
%{ /*** C/C++ Declarations ***/

#include "apus/types.hpp"
#include <string>
#include <sstream>
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef apus::lang::ApusParser::token token;
typedef apus::lang::ApusParser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "ApusFlexLexer" */
%option prefix="Apus"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

/* States */
%x comment
%x line_comment
%x string_state
%x char_state

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN RULES ***/

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}

 /*** END RULES ***/

%% /*** Additional Code ***/

namespace apus {
namespace lang {

ApusScanner::ApusScanner(std::istream* in,
		 std::ostream* out)
    : ApusFlexLexer(in, out) {
}

ApusScanner::~ApusScanner() {
}

int ApusScanner::LexerInput(char* buf, int max_size) {
    int result = ApusFlexLexer::LexerInput(buf, max_size);
    return result;
}

void ApusScanner::LexerError(const char* msg) {
}

void ApusScanner::LexerOutput(const char* buf, int size) {
}

void ApusScanner::set_debug(bool b) {
    yy_flex_debug = b;
}

} // namespace lang
} // namespace apus

/* This implementation of ApusFlexLexer::yylex() is required to fill the
 * vtable of the class ApusFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int ApusFlexLexer::yylex() {
    std::cerr << "in ApusFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int ApusFlexLexer::yywrap() {
    return 1;
}
