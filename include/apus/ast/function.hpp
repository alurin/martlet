/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_FUNCTION
#define _APUS_LANG_FUNCTION

#include "apus/ast/node.hpp"
#include <unordered_map>

namespace apus {
namespace ast {
    class ScopeStatementAst;
    class TypeAst;
    class ArgumentAst;

    class FunctionAst : public Node
    {
    public:
        /// Type for map of scope arguments
        typedef std::unordered_map<std::string, ArgumentAst*> argument_map;

        /// Type for iterator by scope arguments
        typedef argument_map::const_iterator argument_const_iterator;

        /// Constructor
        FunctionAst(const std::string& name, const Location& location);

        /// Desturctor
        ~FunctionAst();

        /// Returns result type of function
        TypeAst* getResultType() const;

        /// Set result type of function
        void setResultType(TypeAst* resultType);

        /// Return root scope statement of function
        ScopeStatementAst* getRootScope() const;

        /// Set root scope statement of function
        void setRootScope(ScopeStatementAst* rootScope);

        /// Declare argument for function
        ArgumentAst* addArgument(const std::string& name, TypeAst* type, const Location& location);

        /// Returns argument from function by name
        ArgumentAst* getArgument(const std::string& name) const;
    protected:
        /// Function name
        std::string mName;

        /// Result type of function
        TypeAst* mResultType;

        /// Root scope of function
        ScopeStatementAst* mRootScope;

        /// Map of function arguments
        argument_map mArguments;
    };
}}

#endif
