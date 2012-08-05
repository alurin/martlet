/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_CLASS
#define _APUS_LANG_CLASS

#include "apus/ast/compose.hpp"

namespace apus {
namespace ast {

    class ClassAst : public ComposeAst
    {
    public:
        ClassAst(const std::string& name, const Location& location);

    protected:
        const std::string& mName;
    };

}}

#endif
