/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_STACK_INTERNAL
#define _APUS_LANG_STACK_INTERNAL

#include "apus/ast/node.hpp"
#include "apus/ast/scope.hpp"
#include <stack>

namespace apus {
namespace lang {

    ///
    class ApusStack {
    public:
        ast::ScopeStatementAst* peakScope() const;

        void pushScope(ast::ScopeStatementAst* scope);

        ast::ScopeStatementAst* popScope();

    protected:
        std::stack<ast::ScopeStatementAst*> mScopesStack;
    };
}}

#endif
