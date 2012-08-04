/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_VARIABLE
#define _APUS_LANG_VARIABLE

#include "apus/lang/expression.hpp"

namespace apus {
namespace lang {
    class VariableAst : public Node { };
    class LVariableAst : public LeftValueAst {
    public:
        LVariableAst(VariableAst* var, const Location& location);
    };
    class RVariableAst : public RightValueAst {
    public:
        RVariableAst(VariableAst* var, const Location& location);
    };
}}

#endif
