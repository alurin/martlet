/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/class.hpp"

using namespace apus;
using namespace apus::ast;

// ctor
ClassAst::ClassAst(const std::string& name, const Location& location)
: ComposeAst(location), mName(name) { }
