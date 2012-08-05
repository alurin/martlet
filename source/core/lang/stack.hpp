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
#include "apus/ast/function.hpp"
#include "apus/ast/class.hpp"
#include <stack>

namespace apus {
namespace lang {

    ///
    class ApusStack {
    public:
        ast::ScopeStatementAst* peakScope() const;

        void pushScope(ast::ScopeStatementAst* scope);

        ast::ScopeStatementAst* popScope();

        ast::FunctionAst* peakFunction() const;

        void pushFunction(ast::FunctionAst* func);

        ast::FunctionAst* popFunction();

        ast::ClassAst* peakClass() const;

        void pushClass(ast::ClassAst* cls);

        ast::ClassAst* popClass();

    protected:
        std::stack<ast::ScopeStatementAst*> mScopesStack;
        std::stack<ast::FunctionAst*>       mFunctionsStack;
        std::stack<ast::ClassAst*>          mClassesStack;
    };
}}

#endif
