/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_SCOPE
#define _APUS_LANG_SCOPE

#include "apus/ast/statement.hpp"
#include <unordered_map>

namespace apus {
namespace ast {
    class MutableAst;
    class VariableAst;
    class FunctionAst;

    class ScopeStatementAst : public SequenceStatementAst {
    public:
        /// Type for map of scope variables
        typedef std::unordered_map<std::string, VariableAst*> variable_map;

        /// Type for iterator by scope variables
        typedef variable_map::const_iterator variable_const_iterator;

        /// Constructor
        ScopeStatementAst(FunctionAst* parent, const Location& location);

        /// Constructor
        ScopeStatementAst(ScopeStatementAst* parent, const Location& location);

        /// Destructor
        virtual ~ScopeStatementAst();

        /// Returns parent function
        FunctionAst* getParentFunction() const;

        /// Returns parent scope
        ScopeStatementAst* getParentScope() const;

        /// Return named variable from scope or its parents
        VariableAst* getVariable(const std::string& name) const;

        /// Return named variable or argument from scope or its parents
        MutableAst* getMutable(const std::string& name) const;
    protected:
        /// Parent function
        FunctionAst* mParentFunction;

        /// Parent scope
        ScopeStatementAst* mParentScope;

        /// Map of variables
        variable_map mVariables;
    };
}}

#endif
