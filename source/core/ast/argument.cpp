/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/argument.hpp"

using namespace apus;
using namespace apus::ast;

// Constructor
ArgumentAst::ArgumentAst(FunctionAst* parent, const std::string& name, TypeAst* type, const Location& location)
: MutableAst(parent, name, type, location) { }
