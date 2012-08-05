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

//==----------------------------- Scopes -----------------------------------==//
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

//==----------------------------- Functions --------------------------------==//
FunctionAst* ApusStack::peakFunction() const
{
    return mFunctionsStack.top();
}

void ApusStack::pushFunction(FunctionAst* func)
{
    mFunctionsStack.push(func);
}

FunctionAst* ApusStack::popFunction()
{
    FunctionAst* func = mFunctionsStack.top();
    mFunctionsStack.pop();
    return func;
}

//==----------------------------- Classes ----------------------------------==//

ClassAst* ApusStack::peakClass() const
{
    return mClassesStack.top();
}

void ApusStack::pushClass(ClassAst* cls)
{
    mClassesStack.push(cls);
}

ClassAst* ApusStack::popClass()
{
    ClassAst* cls = mClassesStack.top();
    mClassesStack.pop();
    return cls;
}
