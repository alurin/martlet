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
    class VariableAst;

    class ScopeStatementAst : public SequenceStatementAst {
    public:
        /// Type for map of scope variables
        typedef std::unordered_map<std::string, VariableAst*> variable_map;

        /// Type for iterator by scope variables
        typedef variable_map::const_iterator variable_const_iterator;

        /// Constructor
        ScopeStatementAst(ScopeStatementAst* parent, const Location& location);

        /// Destructor
        virtual ~ScopeStatementAst();

        /// Return named variable from scope or its parents
        VariableAst* getVariable(const std::string& name) const;
    protected:
        /// Parent scope
        ScopeStatementAst* mParent;

        /// Map of variables
        variable_map mVariables;
    };
}}

#endif
