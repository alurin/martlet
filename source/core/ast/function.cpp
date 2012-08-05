/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/function.hpp"
#include "apus/ast/argument.hpp"
#include "apus/ast/scope.hpp"
#include "apus/ast/type.hpp"

using namespace apus;
using namespace apus::ast;

// Constructor
FunctionAst::FunctionAst(const std::string& name, const Location& location)
: Node(location), mName(name), mResultType(0), mRootScope(0) { }

// Desturctor
FunctionAst::~FunctionAst()
{
    delete mRootScope;
    delete mResultType;
    for (argument_const_iterator i = mArguments.begin(); i != mArguments.end(); ++i) {
        ArgumentAst* arg = i->second;
        delete arg;
    }
}

// Returns result type of function
TypeAst* FunctionAst::getResultType() const
{
    return mResultType;
}

// Set result type of function
void FunctionAst::setResultType(TypeAst* resultType)
{
    mResultType = resultType;
}

// Return root scope statement of function
ScopeStatementAst* FunctionAst::getRootScope() const
{
    return mRootScope;
}

// Set root scope statement of function
void FunctionAst::setRootScope(ScopeStatementAst* rootScope)
{
    mRootScope = rootScope;
}

// Declare argument for function
ArgumentAst* FunctionAst::addArgument(const std::string& name, TypeAst* type, const Location& location)
{
    // check if argument with name already exists in function
    ArgumentAst* arg = getArgument(name);
    if (arg) return 0;

    // create new argument
    arg = new ArgumentAst(this, name, type, location);
    mArguments.insert(std::make_pair(name, arg));
    return arg;
}

// Returns argument from function by name
ArgumentAst* FunctionAst::getArgument(const std::string& name) const
{
    argument_const_iterator result = mArguments.find(name);
    if (result != mArguments.end()) return result->second;
    return 0;
}
