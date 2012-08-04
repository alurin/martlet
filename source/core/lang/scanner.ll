/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
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
%x multiline_comment
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

 /* Lexems */
"for"                   { return token::FOR;        }
"while"                 { return token::WHILE;      }
"if"                    { return token::IF;         }
"elseif"                { return token::ELSEIF;     }
"else"                  { return token::ELSE;       }
"try"                   { return token::TRY;        }
"catch"                 { return token::CATCH;      }
"finally"               { return token::FINALLY;    }
"throw"                 { return token::THROW;      }

 /* comments and strings */
"/*"                    { BEGIN(multiline_comment); }
"//"                    { BEGIN(line_comment);      }
"#"                     { BEGIN(line_comment);      }

 /* Constants and identifiers */
[A-Za-z][A-Za-z0-9]* {
    yylval->stringVal = new std::string(yytext, yyleng);
    return token::IDENTIFIER;
}

\$[A-Za-z][A-Za-z0-9_]* {
    yylval->stringVal = new std::string(yytext+1, yyleng-1);
    return token::VARIABLE;
}

[+-]?[0-9]+ {
    yylval->integerVal = atoi(yytext);
    return token::INTEGER;
}

 /* gobble up white-spaces and new lines */
[ \t]+ {
    yylloc->step();
}

[\n\r]+ {
    yylloc->lines(yyleng);
    yylloc->step();
}

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}

<multiline_comment>{
    [^*\n]*             { /* eat anything that's not a '*' */    }
    "*"+[^*/\n]*        { /* eat up '*'s not followed by '/'s */ }
    [\n\r]+             { yylloc->lines(yyleng); yylloc->step(); }
    "*"+"/"             { BEGIN(INITIAL);  yylloc->step();       }
}

<line_comment>{
    [\n\r]+             { yylloc->lines(yyleng); BEGIN(INITIAL); yylloc->step(); }
    .                   { /* eat anything that's not a new line */    }
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
