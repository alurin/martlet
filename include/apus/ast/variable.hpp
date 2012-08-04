/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_VARIABLE
#define _APUS_LANG_VARIABLE

#include "apus/ast/expression.hpp"

namespace apus {
namespace ast {
    class ScopeAst;

    /// Variable node for martlet AST
    class VariableAst : public Node {
    public:
        /// Constructor
        VariableAst(ScopeAst* scope, const std::string& name, const Location& location);

        /// Returns parent scope
        ScopeAst* getScope() const;

        /// Return name of variable
        std::string getName() const;
    protected:
        /// Variable parent scope
        ScopeAst* mParent;

        /// Variable name
        std::string mName;
    };

    class LVariableAst : public LeftValueAst {
    public:
        /// Constructor
        LVariableAst(VariableAst* var, const Location& location);

        /// Returns variable
        VariableAst* getVariable() const;
    private:
        /// Variable
        VariableAst* mVariable;
    };

    class RVariableAst : public RightValueAst {
    public:
        /// Constructor
        RVariableAst(VariableAst* var, const Location& location);

        /// Returns variable
        VariableAst* getVariable() const;
    private:
        /// Variable
        VariableAst* mVariable;
    };
}}

#endif
