/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/variable.hpp"

using namespace apus;
using namespace apus::ast;

// ctor
VariableAst::VariableAst(ScopeAst* scope, const std::string& name, const Location& location)
: Node(location), mParent(scope), mName(name) { }

// ctor
LVariableAst::LVariableAst(VariableAst* var, const Location& location)
: LeftValueAst(location), mVariable(var) { }

// ctor
RVariableAst::RVariableAst(VariableAst* var, const Location& location)
: RightValueAst(location), mVariable(var) { }

ScopeAst* VariableAst::getScope() const
{
    return mParent;
}

// get name
std::string VariableAst::getName() const
{
    return mName;
}

// Returns variable
VariableAst* LVariableAst::getVariable() const
{
    return mVariable;
}

// Returns variable
VariableAst* RVariableAst::getVariable() const
{
    return mVariable;
}
