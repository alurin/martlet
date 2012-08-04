/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_DRIVER
#define _APUS_LANG_DRIVER

#include "apus/lang/node.hpp"
#include <string>

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
        /// Create driver for parsing a stream.
        static Driver* createFromStream(std::istream& in, const std::string& sname = "stream input");

        /// Create driver for parsing a string.
        static Driver* createFromString(const std::string& in, const std::string& sname = "string stream");

        /// Create driver for parsing a file.
        static Driver* createFromFile(const std::string& filename);

        /// Destructor
        virtual ~Driver();

        /// Parse file
        Node* parse();

        /// Send lexical or syntax error message to user
        void error(const Location& loc, const String& message);
    protected:
        /// Constructor
        Driver(std::istream* stream, const std::string& streamName, bool hasOwnership);
    private:
        /// Pointer to input stream
        std::istream* mStream;

        /// Driver has ownership for input stream
        bool mHasOwnership;

        /// Name of stream
        std::string mStreamName;

        /// Current lexer
        ApusScanner* mLexer;
    };

}}

#endif
