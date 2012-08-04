/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_STATEMENT
#define _APUS_LANG_STATEMENT

#include "apus/ast/node.hpp"
#include <list>

namespace apus {
namespace ast {
    class RightValueAst;

    class StatementAst : public Node
    {
    protected:
        StatementAst(const Location& location);
    };

    class SequenceStatementAst : public StatementAst
    {
    public:
        SequenceStatementAst(const Location& location);

        virtual ~SequenceStatementAst();

        void prepend(StatementAst* stmt);

        void append(StatementAst* stmt);

    protected:
        std::list<StatementAst*> mStatements;
    };

    class ExpressionStatementAst : public StatementAst
    {
    public:
        ExpressionStatementAst(RightValueAst* rvalue);

        virtual ~ExpressionStatementAst();
    protected:
        RightValueAst* mRvalue;
    };
}}

#endif
