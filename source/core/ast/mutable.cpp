/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/variable.hpp"
#include "apus/ast/type.hpp"

using namespace apus;
using namespace apus::ast;

// ctor
MutableAst::MutableAst(FunctionAst* parentFunction, const std::string& name, TypeAst* type, const Location& location)
: Node(location), mParentFunction(parentFunction), mName(name), mType(type) { }

MutableAst::~MutableAst()
{
    delete mType;
}

// ctor
LMutableAst::LMutableAst(MutableAst*mut, const Location& location)
: LeftValueAst(location), mMutable(mut) { }

// ctor
RMutableAst::RMutableAst(MutableAst* mut, const Location& location)
: RightValueAst(location), mMutable(mut) { }

// Returns parent function of mutable variable
FunctionAst* MutableAst::getParentFunction() const
{
    return mParentFunction;
}

// Returns mutable variable name
std::string MutableAst::getName() const
{
    return mName;
}

// Returns mutable variable type
TypeAst* MutableAst::getType() const
{
    return mType;
}

// Returns variable
MutableAst* LMutableAst::getMutable() const
{
    return mMutable;
}

// Returns variable
MutableAst* RMutableAst::getMutable() const
{
    return mMutable;
}
