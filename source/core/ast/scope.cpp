/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/scope.hpp"
#include "apus/ast/variable.hpp"

using namespace apus;
using namespace apus::ast;

ScopeStatementAst::ScopeStatementAst(ScopeStatementAst* parent, const Location& location)
: SequenceStatementAst(location), mParent(parent)
{ }

ScopeStatementAst::~ScopeStatementAst() {
    for (variable_const_iterator i = mVariables.begin(); i != mVariables.end(); ++i) {
        VariableAst* var = i->second;
        delete var;
    }
}

/// Return named variable from scope or its parents
VariableAst* ScopeStatementAst::getVariable(const std::string& name) const
{
    variable_const_iterator result = mVariables.find(name);
    if (result != mVariables.end()) return result->second;
    return 0;
}
