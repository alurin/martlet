/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_ARGUMENT
#define _APUS_LANG_ARGUMENT

#include "apus/ast/mutable.hpp"

namespace apus {
namespace ast {
    class FunctionAst;
    class TypeAst;

    class ArgumentAst : public MutableAst
    {
        friend class FunctionAst;
    private:
        /// Constructor
        ArgumentAst(FunctionAst* parent, const std::string& name, TypeAst* type, const Location& location);
    };

}}

#endif
