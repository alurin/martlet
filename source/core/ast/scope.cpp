/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/function.hpp"
#include "apus/ast/scope.hpp"
#include "apus/ast/variable.hpp"
#include "apus/ast/argument.hpp"

using namespace apus;
using namespace apus::ast;

ScopeStatementAst::ScopeStatementAst(ScopeStatementAst* parent, const Location& location)
: SequenceStatementAst(location), mParentFunction(parent->getParentFunction()), mParentScope(parent)
{ }

// Constructor
ScopeStatementAst::ScopeStatementAst(FunctionAst* parent, const Location& location)
: SequenceStatementAst(location), mParentFunction(parent), mParentScope(0) {

}

ScopeStatementAst::~ScopeStatementAst() {
    for (variable_const_iterator i = mVariables.begin(); i != mVariables.end(); ++i) {
        VariableAst* var = i->second;
        delete var;
    }
}

// Returns parent function
FunctionAst* ScopeStatementAst::getParentFunction() const
{
    return mParentFunction;
}

// Returns parent scope
ScopeStatementAst* ScopeStatementAst::getParentScope() const
{
    return mParentScope;
}

// Return named variable from scope or its parents
VariableAst* ScopeStatementAst::getVariable(const std::string& name) const
{
    const ScopeStatementAst* current = this;
    while (current) {
        variable_const_iterator result = current->mVariables.find(name);
        if (result != current->mVariables.end()) return result->second;
        current = current->mParentScope;
    }
    return 0;
}

// Return named variable from scope or its parents
MutableAst* ScopeStatementAst::getMutable(const std::string& name) const
{
    const ScopeStatementAst* current = this;
    while (current) {
        variable_const_iterator result = current->mVariables.find(name);
        if (result != current->mVariables.end()) return result->second;
        current = current->mParentScope;
    }
    return mParentFunction->getArgument(name);
}
