/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/statement.hpp"
#include "apus/ast/expression.hpp"

using namespace apus;
using namespace apus::ast;

StatementAst::StatementAst(const Location& location)
: Node(location) { }

SequenceStatementAst::SequenceStatementAst(const Location& location)
: StatementAst(location) { }

SequenceStatementAst::~SequenceStatementAst()
{
    for (std::list<StatementAst*>::iterator i = mStatements.begin(); i != mStatements.end(); ++i)
    {
        StatementAst* stmt = *i;
        delete stmt;
    }
}

ExpressionStatementAst::ExpressionStatementAst(RightValueAst* rvalue)
: StatementAst(rvalue->getLocation()), mRvalue(rvalue) { }

ExpressionStatementAst::~ExpressionStatementAst()
{
    delete mRvalue;
}

void SequenceStatementAst::prepend(StatementAst* stmt)
{
    if (stmt) mStatements.push_front(stmt);
}

void SequenceStatementAst::append(StatementAst* stmt)
{
    if (stmt) mStatements.push_back(stmt);
}
