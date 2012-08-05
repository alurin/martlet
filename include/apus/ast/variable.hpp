/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_VARIABLE
#define _APUS_LANG_VARIABLE

#include "apus/ast/mutable.hpp"

namespace apus {
namespace ast {
    class ScopeStatementAst;

    /// Variable node for martlet AST
    class VariableAst : public MutableAst {
    public:
        /// Constructor
        VariableAst(ScopeStatementAst* scope, const std::string& name, TypeAst* type, const Location& location);

        /// Returns parent scope
        ScopeStatementAst* getParentScope() const;
    protected:
        /// Variable parent scope
        ScopeStatementAst* mParentScope;
    };
}}

#endif
