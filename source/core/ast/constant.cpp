/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/constant.hpp"

using namespace apus;
using namespace apus::ast;

// ctor
IntegerConstantAst::IntegerConstantAst(int32_t value, const Location& location)
: RightValueAst(location), mValue(value) { }

// Return value of integer constant
int32_t IntegerConstantAst::getValue() const
{
    return mValue;
}
