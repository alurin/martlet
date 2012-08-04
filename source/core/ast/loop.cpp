/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/loop.hpp"
#include "apus/ast/expression.hpp"

using namespace apus;
using namespace apus::ast;

WhileLoopAst::WhileLoopAst(RightValueAst* conditional, const Location& location)
: SequenceStatementAst(location), mConditional(conditional)
{ }

WhileLoopAst::~WhileLoopAst()
{
    delete mConditional;
}

ForLoopAst::ForLoopAst(StatementAst* initial, RightValueAst* conditional, StatementAst* after, const Location& location)
: SequenceStatementAst(location), mInitial(initial), mConditional(conditional), mAfter(after)
{ }

ForLoopAst::~ForLoopAst()
{
    delete mInitial;
    delete mConditional;
    delete mAfter;
}
