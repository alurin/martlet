/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/type.hpp"

using namespace apus;
using namespace apus::ast;

TypeAst::TypeAst(const Location& location)
: Node(location) { }

ArrayTypeAst::ArrayTypeAst(TypeAst* elementType, const Location& location)
: TypeAst(location), mElementType(elementType) { }

ArrayTypeAst::~ArrayTypeAst()
{
    delete mElementType;
}

IntegerTyAst::IntegerTyAst(const Location& location)
: TypeAst(location) { }

BooleanTyAst::BooleanTyAst(const Location& location)
: TypeAst(location) { }

StringTyAst::StringTyAst(const Location& location)
: TypeAst(location) { }

CharTyAst::CharTyAst(const Location& location)
: TypeAst(location) { }

DoubleTyAst::DoubleTyAst(const Location& location)
: TypeAst(location) { }

FloatTyAst::FloatTyAst(const Location& location)
: TypeAst(location) { }
