/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_CONSTANT
#define _APUS_LANG_CONSTANT

#include "apus/lang/expression.hpp"

namespace apus {
namespace lang {

    class IntegerConstantAst : public RightValueAst {
    public:
        IntegerConstantAst(int32_t value, const Location& loc);
    };

}}

#endif
