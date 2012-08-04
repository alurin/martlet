/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_DRIVER
#define _APUS_LANG_DRIVER

#include "apus/lang/node.hpp"

namespace apus {
namespace lang {

    class ApusScanner;
    class ApusParser;

    /// Driver for combining lexical and syntactic analysis
    class Driver
    {
        friend class ApusScanner; /// for internal
        friend class ApusParser;  /// for internal
    public:
        /// Parse file
        void parseFile(const Path& filename);

        /// Send lexical or sintax error message to user
        void error(const Location& loc, const String& message);

    private:
        std::string mStreamName;

        ApusScanner* mLexer;
    };

}}

#endif
