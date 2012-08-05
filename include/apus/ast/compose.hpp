/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_COMPOSE
#define _APUS_LANG_COMPOSE

#include "apus/ast/node.hpp"

namespace apus {
namespace ast {

    class FunctionAst;

    class ComposeAst : public Node
    {
    public:
        /// Add function in compose ast
        void addFunction(FunctionAst* func);
    protected:
        ComposeAst(const Location& location);
    };

}}

#endif
