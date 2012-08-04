/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_STATEMENT
#define _APUS_LANG_STATEMENT

#include "apus/lang/node.hpp"

namespace apus {
namespace lang {
    class RightValueAst;

    class StatementAst : public Node { };
    class SequenceStatementAst : public StatementAst
    {
    public:
        void prepend(StatementAst* stmt);

        void append(StatementAst* stmt);
    };

    class ExpressionStatementAst : public StatementAst
    {
    public:
        ExpressionStatementAst(RightValueAst* rvalue);

        ~ExpressionStatementAst();
    };
}}

#endif
