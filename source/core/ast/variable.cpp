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

// ctor
VariableAst::VariableAst(ScopeStatementAst* scope, const std::string& name, TypeAst* type, const Location& location)
: MutableAst(scope->getParentFunction(), name, type, location), mParentScope(scope) { }

/// Returns parent scope
ScopeStatementAst* VariableAst::getParentScope() const {
    return mParentScope;
}
