/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_MUTABLE
#define _APUS_LANG_MUTABLE

#include "apus/ast/expression.hpp"

namespace apus {
namespace ast {
    class FunctionAst;
    class TypeAst;

    /// Mutable variable node for martlet AST
    class MutableAst : public Node {
    public:
        /// Destructor
        virtual ~MutableAst();

        /// Returns parent function of mutable variable
        FunctionAst* getParentFunction() const;

        /// Returns mutable variable name
        std::string getName() const;

        /// Returns mutable variable type
        TypeAst* getType() const;
    protected:
        /// parent function of mutable variable
        FunctionAst* mParentFunction;

        /// mutable variable name
        std::string mName;

        /// mutable variable type
        TypeAst* mType;

        /// Constructor
        MutableAst(FunctionAst* parentFunction, const std::string& name, TypeAst* type, const Location& location);
    };

    class LMutableAst : public LeftValueAst {
    public:
        /// Constructor
        LMutableAst(MutableAst* mut, const Location& location);

        /// Returns mutable variable
        MutableAst* getMutable() const;
    private:
        /// Mutable variable
        MutableAst* mMutable;
    };

    class RMutableAst : public RightValueAst {
    public:
        /// Constructor
        RMutableAst(MutableAst* mut, const Location& location);

        /// Returns mutable variable
        MutableAst* getMutable() const;
    private:
        /// Mutable variable
        MutableAst* mMutable;
    };
}}

#endif
