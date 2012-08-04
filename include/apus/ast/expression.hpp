/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_EXPRESSION
#define _APUS_LANG_EXPRESSION

#include "apus/ast/node.hpp"

namespace apus {
namespace ast {
    class LeftValueAst : public Node {
    public:
        /// Constructor
        LeftValueAst(const Location& location);
    };
    class RightValueAst : public Node {
    public:
        /// Constructor
        RightValueAst(const Location& location);
    };

    class AssignAst : public RightValueAst {
    public:
        /// Constructor
        AssignAst(LeftValueAst* lvalue, RightValueAst* rvalue, const Location& location);

        /// Destructor
        virtual ~AssignAst();

        /// Returns left value of assign node
        LeftValueAst* getLeftValue() const;

        /// Returns right value of assign node
        RightValueAst* getRightValue() const;
    protected:
        /// Left value of assign node
        LeftValueAst* mLvalue;

        /// Rigth value of assign node
        RightValueAst* mRvalue;
    };
}}

#endif
