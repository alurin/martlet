/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_LOOP
#define _APUS_LANG_LOOP

#include "apus/lang/statement.hpp"

namespace apus {
namespace lang {
    class RightValueAst;

    class WhileLoopAst : public SequenceStatementAst {
    public:
        WhileLoopAst(RightValueAst* conditional, const Location& loc);
    };
    class ForLoopAst : public SequenceStatementAst {
    public:
        ForLoopAst(StatementAst* initial, RightValueAst* conditional, StatementAst* after, const Location& loc);
    };
}}

#endif
