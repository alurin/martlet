/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_LOOP
#define _APUS_LANG_LOOP

#include "apus/ast/scope.hpp"

namespace apus {
namespace ast {
    class RightValueAst;

    class LoopAst : public ScopeStatementAst { };

    class WhileLoopAst : public SequenceStatementAst {
    public:
        WhileLoopAst(RightValueAst* conditional, const Location& loc);

        virtual ~WhileLoopAst();
    protected:
        RightValueAst* mConditional;
    };

    class ForLoopAst : public SequenceStatementAst {
    public:
        ForLoopAst(StatementAst* initial, RightValueAst* conditional, StatementAst* after, const Location& loc);

        virtual ~ForLoopAst();
    protected:
        StatementAst* mInitial;
        RightValueAst* mConditional;
        StatementAst* mAfter;
    };
}}

#endif
