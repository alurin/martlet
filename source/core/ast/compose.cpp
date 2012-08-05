/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/compose.hpp"

using namespace apus;
using namespace apus::ast;

// ctor
ComposeAst::ComposeAst(const Location& location)
: Node(location) { }

// Add function in compose ast
void ComposeAst::addFunction(FunctionAst* func)
{
}
