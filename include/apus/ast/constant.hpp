/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_CONSTANT
#define _APUS_LANG_CONSTANT

#include "apus/ast/expression.hpp"

namespace apus {
namespace ast {

    class IntegerConstantAst : public RightValueAst {
    public:
        /// Constructor
        IntegerConstantAst(int32_t value, const Location& loc);

        /// Return value of integer constant
        int32_t getValue() const;
    protected:
        /// Value of integer constant
        int32_t mValue;
    };

}}

#endif
