/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   apus::langlex

/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 41 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 136 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"


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



/* Line 299 of lalr1.cc  */
#line 77 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace apus { namespace lang {

/* Line 382 of lalr1.cc  */
#line 163 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ApusParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  ApusParser::ApusParser (class Driver& driver_yyarg, class ApusStack& scopeStack_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      scopeStack (scopeStack_yyarg)
  {
  }

  ApusParser::~ApusParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  ApusParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  ApusParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  ApusParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 4: /* "\"identifier\"" */

/* Line 480 of lalr1.cc  */
#line 132 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
	{ delete (yyvaluep->stringVal); };

/* Line 480 of lalr1.cc  */
#line 269 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"
	break;
      case 5: /* "\"variable\"" */

/* Line 480 of lalr1.cc  */
#line 132 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
	{ delete (yyvaluep->stringVal); };

/* Line 480 of lalr1.cc  */
#line 278 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"
	break;

	default:
	  break;
      }
  }

  void
  ApusParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  ApusParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ApusParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ApusParser::debug_level_type
  ApusParser::debug_level () const
  {
    return yydebug_;
  }

  void
  ApusParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  ApusParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  ApusParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ApusParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 45 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
{
    using namespace apus::ast;
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.mStreamName;
}

/* Line 565 of lalr1.cc  */
#line 377 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 5:

/* Line 690 of lalr1.cc  */
#line 176 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                scopeStack.pushClass(new ClassAst(*(yysemantic_stack_[(2) - (2)].stringVal), (yylocation_stack_[(2) - (2)])));
                                yyfree((yysemantic_stack_[(2) - (2)].stringVal));
                            }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 181 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { delete scopeStack.popClass(); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 190 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { scopeStack.peakClass()->addFunction((yysemantic_stack_[(1) - (1)].func));
                                yyfree((yysemantic_stack_[(1) - (1)].func))  /// TODO: REMOVE THIS LINE
                            }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 198 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                FunctionAst* func = new FunctionAst(*(yysemantic_stack_[(1) - (1)].stringVal), (yylocation_stack_[(1) - (1)]));
                                scopeStack.pushFunction(func);
                                yyfree((yysemantic_stack_[(1) - (1)].stringVal));
                            }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 204 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                scopeStack.peakFunction()->setResultType((yysemantic_stack_[(7) - (7)].type));
                            }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 207 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                (yyval.func) = scopeStack.popFunction();
                            }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 223 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                scopeStack.peakFunction()->addArgument(*(yysemantic_stack_[(3) - (1)].stringVal), (yysemantic_stack_[(3) - (3)].type), (yylocation_stack_[(3) - (1)]));
                                yyfree((yysemantic_stack_[(3) - (1)].stringVal));
                            }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 230 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                            FunctionAst* parent       = scopeStack.peakFunction();
                            ScopeStatementAst* scope  = new ScopeStatementAst(parent, (yylocation_stack_[(1) - (1)]));
                            scopeStack.pushScope(scope);
                        }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 235 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                            scopeStack.peakFunction()->setRootScope(scopeStack.popScope());
                        }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 244 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new ArrayTypeAst((yysemantic_stack_[(2) - (1)].type), (yyloc)); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 245 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new ArrayTypeAst((yysemantic_stack_[(3) - (1)].type), (yyloc)); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 246 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = (yysemantic_stack_[(1) - (1)].type); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 251 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new IntegerTyAst((yylocation_stack_[(1) - (1)])); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 252 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new BooleanTyAst((yylocation_stack_[(1) - (1)])); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 253 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new StringTyAst((yylocation_stack_[(1) - (1)]));  }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 254 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new CharTyAst((yylocation_stack_[(1) - (1)]));    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 255 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new DoubleTyAst((yylocation_stack_[(1) - (1)]));  }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 256 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.type) = new FloatTyAst((yylocation_stack_[(1) - (1)]));   }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 262 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.statement) = 0;  }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 263 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 265 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.statement) = (yysemantic_stack_[(2) - (1)].statement); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 270 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                            ScopeStatementAst* parent = scopeStack.peakScope();
                            ScopeStatementAst* scope  = new ScopeStatementAst(parent, (yylocation_stack_[(1) - (1)]));
                            scopeStack.pushScope(scope);
                        }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 275 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                            (yyval.statement) = scopeStack.popScope();
                        }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 293 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.statement) = new ExpressionStatementAst((yysemantic_stack_[(2) - (1)].rvalue)); }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 294 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.statement) = (yysemantic_stack_[(2) - (1)].statement); }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 300 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.statement) = 0; }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 311 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.rvalue) = 0; }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 324 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
            ForLoopAst* stmt = new ForLoopAst((yysemantic_stack_[(9) - (3)].statement), (yysemantic_stack_[(9) - (5)].rvalue), (yysemantic_stack_[(9) - (7)].statement), (yylocation_stack_[(9) - (1)]));
            stmt->append((yysemantic_stack_[(9) - (9)].statement));
            (yyval.statement) = stmt;
        }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 334 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
            WhileLoopAst* stmt = new WhileLoopAst((yysemantic_stack_[(5) - (3)].rvalue), (yylocation_stack_[(5) - (1)]));
            stmt->append((yysemantic_stack_[(5) - (5)].statement));
            (yyval.statement) = stmt;
        }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 370 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.rvalue) = new AssignAst((yysemantic_stack_[(3) - (1)].lvalue), (yysemantic_stack_[(3) - (3)].rvalue), (yyloc)); }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 371 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.rvalue) = (yysemantic_stack_[(1) - (1)].rvalue); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 376 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                            MutableAst* var = scopeStack.peakScope()->getMutable(*(yysemantic_stack_[(1) - (1)].stringVal));
                                            yyfree((yysemantic_stack_[(1) - (1)].stringVal));
                                            if (var)
                                                (yyval.lvalue) = new LMutableAst(var, (yyloc));
                                            else {
                                                error((yylocation_stack_[(1) - (1)]), "Variable or argument not found in current scope");
                                                YYERROR;
                                            }
                                        }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 390 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    {
                                            MutableAst* var = scopeStack.peakScope()->getMutable(*(yysemantic_stack_[(1) - (1)].stringVal));
                                            yyfree((yysemantic_stack_[(1) - (1)].stringVal));
                                            if (var)
                                                (yyval.rvalue) = new RMutableAst(var, (yyloc));
                                            else {
                                                error((yylocation_stack_[(1) - (1)]), "Variable or argument not found in current scope");
                                                YYERROR;
                                            }
                                        }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 400 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
    { (yyval.rvalue) = new IntegerConstantAst((yysemantic_stack_[(1) - (1)].integerVal), (yylocation_stack_[(1) - (1)])); }
    break;



/* Line 690 of lalr1.cc  */
#line 788 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  ApusParser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char ApusParser::yypact_ninf_ = -68;
  const signed char
  ApusParser::yypact_[] =
  {
        12,   -68,     9,    -1,    21,     2,   -33,    24,    30,   -68,
       9,   -68,   -68,   -68,   -68,   -30,    28,   -68,   -29,    28,
     -68,   -20,   -68,   -68,    41,   -17,   -14,   -68,   -13,    22,
     -11,    41,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -36,
      22,   -68,   -68,   -15,   -68,   -68,   -43,   -68,   -68,   -68,
      -5,    14,   -68,    -2,     1,     3,    46,   -68,   -68,     0,
     -68,    -5,   -68,   -68,   -68,   -68,   -68,     4,     5,    20,
     -68,    -5,    18,    18,    50,    -5,   -68,   -68,   -68,   -68,
      18,   -68,     6,     7,   -68,     8,    53,    10,   -68,    18,
      -5,    -5,   -68,   -68,   -68,    13,   -68,    58,    -5,    17,
      64,    58,    15,    18,    -5,   -68,    -5,    16,   -68,   -68,
      -5,   -68
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  ApusParser::yydefact_[] =
  {
         0,    63,     0,     0,     0,     3,     0,     0,     0,     1,
       0,     4,     5,    64,     2,     0,     7,    10,     0,     7,
       9,     0,     6,     8,    13,     0,     0,    14,    16,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    17,    23,
       0,    15,    21,     0,    11,    22,     0,    20,    18,    12,
      30,    61,    62,     0,     0,     0,     0,    57,    33,     0,
      35,    30,    40,    36,    37,    38,    39,     0,     0,     0,
      59,    43,     0,     0,     0,    30,    19,    32,    42,    41,
       0,    44,     0,     0,    45,     0,     0,     0,    58,    46,
      30,    30,    56,    34,    47,     0,    49,    50,    43,     0,
      51,    53,     0,     0,    30,    54,    30,     0,    52,    48,
      30,    55
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  ApusParser::yypgoto_[] =
  {
       -68,    59,   -68,   -68,   -68,    57,   -68,   -68,   -68,   -68,
     -68,    49,   -68,   -68,   -68,    37,   -68,   -56,   -68,   -68,
     -60,   -68,   -16,   -67,   -68,   -68,   -68,   -68,   -18,   -68,
     -68,   -68,   -64,   -68,   -68,   -68
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  ApusParser::yydefgoto_[] =
  {
        -1,     6,     3,     8,    15,    18,    19,    20,    21,    46,
      26,    27,    28,    49,    50,    38,    39,    59,    60,    75,
      61,    62,    82,    83,    95,    63,    64,    65,   100,   101,
      66,    67,    68,    69,    70,     4
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char ApusParser::yytable_ninf_ = -61;
  const signed char
  ApusParser::yytable_[] =
  {
        51,    52,    53,    54,    55,    77,    85,    56,    84,    84,
      57,    81,     1,     5,    42,     7,    88,    47,    48,    87,
      43,     9,    94,    51,    52,    84,    10,    11,    12,     2,
      13,    16,    17,    22,    96,    97,   107,    24,    81,    84,
      32,    33,    34,    35,    36,    37,    25,    29,   108,    30,
     109,    45,    31,    40,   111,    71,    58,   -60,    72,    74,
      73,    86,    76,    80,    78,    79,    89,    92,    99,    14,
      90,    91,    93,    98,   103,   104,    23,    44,   106,   110,
      41,     0,   102,   105
  };

  /* YYCHECK.  */
  const signed char
  ApusParser::yycheck_[] =
  {
         5,     6,     7,     8,     9,    61,    73,    12,    72,    73,
      15,    71,     0,     4,    50,    16,    80,    60,    61,    75,
      56,     0,    89,     5,     6,    89,    24,    60,     4,    17,
       0,    61,     4,    62,    90,    91,   103,    57,    98,   103,
      18,    19,    20,    21,    22,    23,     5,    64,   104,    63,
     106,    66,    65,    64,   110,    57,    61,    43,    57,    13,
      57,    11,    62,    43,    60,    60,    60,    14,    10,    10,
      63,    63,    62,    60,    57,    11,    19,    40,    63,    63,
      31,    -1,    98,   101
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  ApusParser::yystos_[] =
  {
         0,     0,    17,    69,   102,     4,    68,    16,    70,     0,
      24,    60,     4,     0,    68,    71,    61,     4,    72,    73,
      74,    75,    62,    72,    57,     5,    77,    78,    79,    64,
      63,    65,    18,    19,    20,    21,    22,    23,    82,    83,
      64,    78,    50,    56,    82,    66,    76,    60,    61,    80,
      81,     5,     6,     7,     8,     9,    12,    15,    61,    84,
      85,    87,    88,    92,    93,    94,    97,    98,    99,   100,
     101,    57,    57,    57,    13,    86,    62,    84,    60,    60,
      43,    87,    89,    90,    99,    90,    11,    84,    99,    60,
      63,    63,    14,    62,    90,    91,    84,    84,    60,    10,
      95,    96,    89,    57,    11,    95,    63,    90,    84,    84,
      63,    84
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  ApusParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    61,   124,    38,    60,    62,    45,    43,
      42,    47,    37,    33,   298,    46,    91,    40,   299,   300,
      59,   123,   125,    41,    58,    44,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  ApusParser::yyr1_[] =
  {
         0,    67,    68,    68,    69,    71,    70,    72,    72,    73,
      75,    76,    74,    77,    77,    78,    78,    79,    81,    80,
      80,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    86,    85,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    91,    91,    92,    93,
      94,    94,    94,    95,    95,    96,    97,    98,    99,    99,
     100,   101,   101,   102,   102
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  ApusParser::yyr2_[] =
  {
         0,     2,     3,     1,     3,     0,     6,     0,     2,     1,
       0,     0,     9,     0,     1,     3,     1,     3,     0,     4,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     0,     4,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     1,     1,     0,     1,     9,     5,
       5,     6,     8,     0,     2,     5,     4,     1,     3,     1,
       1,     1,     1,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const ApusParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"identifier\"", "\"variable\"", "\"integer constant\"", "\"for\"",
  "\"while\"", "\"if\"", "\"elseif\"", "\"else\"", "\"try\"", "\"catch\"",
  "\"finally\"", "\"throw\"", "\"class\"", "\"namespace\"", "\"integer\"",
  "\"boolean\"", "\"string\"", "\"char\"", "\"double\"", "\"float\"",
  "\"::\"", "\"<<\"", "\">>\"", "\"||\"", "\"&&\"", "\"==\"", "\"!=\"",
  "\">=\"", "\"<=\"", "\"++\"", "\"--\"", "\"+=\"", "\"-=\"", "\"/=\"",
  "\"*=\"", "\"<<=\"", "\">>=\"", "\"&=\"", "\"|=\"", "'='", "'|'", "'&'",
  "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'", "UNARY", "'.'",
  "'['", "'('", "PRE", "MINIM", "';'", "'{'", "'}'", "')'", "':'", "','",
  "']'", "$accept", "qual_identifier", "namespace_declare",
  "class_declare", "$@1", "class_body", "class_element",
  "function_declare", "$@2", "$@3", "function_args_empty", "function_args",
  "function_arg", "function_body", "$@4", "type", "simple_type",
  "statements", "scope", "$@5", "statement", "line_statement",
  "empty_statement", "conditional", "empty_conditional", "for_loop",
  "while_loop", "if_statement", "elseif_parts", "elseif_part",
  "try_statement", "exception_statement", "expression", "lvalue", "rvalue",
  "start", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const ApusParser::rhs_number_type
  ApusParser::yyrhs_[] =
  {
       102,     0,    -1,     4,    24,    68,    -1,     4,    -1,    17,
      68,    60,    -1,    -1,    16,     4,    71,    61,    72,    62,
      -1,    -1,    73,    72,    -1,    74,    -1,    -1,    -1,     4,
      75,    57,    77,    63,    64,    82,    76,    80,    -1,    -1,
      78,    -1,    79,    65,    78,    -1,    79,    -1,     5,    64,
      82,    -1,    -1,    61,    81,    84,    62,    -1,    60,    -1,
      83,    50,    -1,    83,    56,    66,    -1,    83,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    -1,    87,    -1,    87,    84,    -1,    -1,    61,    86,
      84,    62,    -1,    85,    -1,    92,    -1,    93,    -1,    94,
      -1,    97,    -1,    88,    -1,    99,    60,    -1,    98,    60,
      -1,    -1,    87,    -1,    99,    -1,    -1,    90,    -1,     7,
      57,    89,    60,    91,    60,    89,    63,    84,    -1,     8,
      57,    90,    63,    84,    -1,     9,    57,    90,    63,    84,
      -1,     9,    57,    90,    63,    84,    95,    -1,     9,    57,
      90,    63,    84,    95,    11,    84,    -1,    -1,    96,    95,
      -1,    10,    57,    90,    63,    84,    -1,    12,    13,    11,
      14,    -1,    15,    -1,   100,    43,    99,    -1,   101,    -1,
       5,    -1,     5,    -1,     6,    -1,     0,    -1,    69,    70,
       0,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  ApusParser::yyprhs_[] =
  {
         0,     0,     3,     7,     9,    13,    14,    21,    22,    25,
      27,    28,    29,    39,    40,    42,    46,    48,    52,    53,
      58,    60,    63,    67,    69,    71,    73,    75,    77,    79,
      81,    82,    84,    87,    88,    93,    95,    97,    99,   101,
     103,   105,   108,   111,   112,   114,   116,   117,   119,   129,
     135,   141,   148,   157,   158,   161,   167,   172,   174,   178,
     180,   182,   184,   186,   188
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  ApusParser::yyrline_[] =
  {
         0,   165,   165,   166,   172,   176,   176,   184,   186,   190,
     198,   204,   198,   212,   214,   218,   219,   223,   230,   230,
     238,   244,   245,   246,   251,   252,   253,   254,   255,   256,
     262,   263,   264,   270,   270,   283,   284,   285,   286,   287,
     288,   293,   294,   300,   301,   306,   311,   312,   323,   333,
     343,   344,   345,   348,   350,   354,   359,   364,   370,   371,
     376,   390,   400,   405,   406
  };

  // Print the state stack on the debug stream.
  void
  ApusParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  ApusParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  ApusParser::token_number_type
  ApusParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    52,    45,     2,
      57,    63,    50,    49,    65,    48,    55,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    60,
      46,    43,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    44,    62,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    54,    58,
      59
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int ApusParser::yyeof_ = 0;
  const int ApusParser::yylast_ = 83;
  const int ApusParser::yynnts_ = 36;
  const int ApusParser::yyempty_ = -2;
  const int ApusParser::yyfinal_ = 9;
  const int ApusParser::yyterror_ = 1;
  const int ApusParser::yyerrcode_ = 256;
  const int ApusParser::yyntokens_ = 67;

  const unsigned int ApusParser::yyuser_token_number_max_ = 300;
  const ApusParser::token_number_type ApusParser::yyundef_token_ = 2;


} } // apus::lang

/* Line 1136 of lalr1.cc  */
#line 1387 "/home/alurin/workplace/project/martlet/source/core/lang/parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 411 "/home/alurin/workplace/project/martlet/source/core/lang/parser.yy"
 /*** Additional Code ***/

using namespace apus;
using namespace apus::lang;

void ApusParser::error(const ApusParser::location_type& l,
			    const std::string& m)
{
    std::cout << l << ": " << m << "\n";
    new LangException(String::fromUTF8(m), l);
}

