/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_SCOPE
#define _APUS_LANG_SCOPE

#include "apus/lang/statement.hpp"

namespace apus {
namespace lang {
    class VariableAst;

    class ScopeStatementAst : public SequenceStatementAst {
    public:
        ScopeStatementAst(ScopeStatementAst* parent, const Location& location);

        /// Return named variable from scope or its parents
        VariableAst* getVariable(const std::string& name) const;
    protected:
        ScopeStatementAst* mParent;
    };
}}

#endif
