/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/expression.hpp"

using namespace apus;
using namespace apus::ast;

LeftValueAst::LeftValueAst(const Location& location)
: Node(location) { }

RightValueAst::RightValueAst(const Location& location)
: Node(location) { }

AssignAst::AssignAst(LeftValueAst* lvalue, RightValueAst* rvalue, const Location& location)
: RightValueAst(location), mLvalue(lvalue), mRvalue(rvalue) { }

AssignAst::~AssignAst()
{
    delete mLvalue;
    delete mRvalue;
}

// Returns left value of assign node
LeftValueAst* AssignAst::getLeftValue() const
{
    return mLvalue;
}

// Returns right value of assign node
RightValueAst* AssignAst::getRightValue() const
{
    return mRvalue;
}
