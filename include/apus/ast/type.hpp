/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_TYPE
#define _APUS_LANG_TYPE

#include "apus/ast/node.hpp"

namespace apus {
namespace ast {
    class TypeAst : public Node
    {
    public:

    protected:
        TypeAst(const Location& location);
    };


    class ArrayTypeAst : public TypeAst
    {
    public:
        ArrayTypeAst(TypeAst* elementType, const Location& location);

        virtual ~ArrayTypeAst();
    protected:
        TypeAst* mElementType;
    };

    class IntegerTyAst : public TypeAst
    {
    public:
        IntegerTyAst(const Location& location);
    };

    class BooleanTyAst : public TypeAst
    {
    public:
        BooleanTyAst(const Location& location);
    };

    class StringTyAst : public TypeAst
    {
    public:
        StringTyAst(const Location& location);
    };

    class CharTyAst : public TypeAst
    {
    public:
        CharTyAst(const Location& location);
    };

    class DoubleTyAst : public TypeAst
    {
    public:
        DoubleTyAst(const Location& location);
    };

    class FloatTyAst : public TypeAst
    {
    public:
        FloatTyAst(const Location& location);
    };


}}

#endif
