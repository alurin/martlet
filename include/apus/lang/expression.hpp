/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_EXPRESSION
#define _APUS_LANG_EXPRESSION

#include "apus/lang/node.hpp"

namespace apus {
namespace lang {
    class LeftValueAst { };
    class RightValueAst { };

    class AssignAst : public RightValueAst {
    public:
        AssignAst(LeftValueAst* lvalue, RightValueAst* rvalue, const Location& location);
    };
}}

#endif
