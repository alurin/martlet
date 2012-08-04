/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "stack.hpp"

using namespace apus;
using namespace apus::ast;
using namespace apus::lang;

ScopeStatementAst* ApusStack::peakScope() const
{
    return mScopesStack.top();
}

void ApusStack::pushScope(ScopeStatementAst* scope)
{
    mScopesStack.push(scope);
}

ScopeStatementAst* ApusStack::popScope()
{
    ScopeStatementAst* scope = mScopesStack.top();
    mScopesStack.pop();
    return scope;
}
