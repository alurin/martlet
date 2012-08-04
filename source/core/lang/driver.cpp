/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/lang/driver.hpp"
#include "apus/lang/exception.hpp"
#include "parser.hpp"
#include "scanner.h"
#include "stack.hpp"
#include <fstream>
#include <sstream>

using namespace apus;
using namespace apus::ast;
using namespace apus::lang;

// Constructor
Driver::Driver(std::istream* stream, const std::string& streamName, bool hasOwnership)
: mStream(stream), mHasOwnership(hasOwnership), mStreamName(streamName), mLexer(new ApusScanner(stream))
{ }

// Destructor
Driver::~Driver() {
    delete mLexer;
    if (mHasOwnership) {
        delete mStream;
    }
}

// create driver from stream
Driver* Driver::createFromStream(std::istream& in, const std::string& sname)
{
    return new Driver(&in, sname, false);
}

// create driver from string stream
Driver* Driver::createFromString(const std::string& in, const std::string& sname)
{
    std::istringstream* iss = new std::istringstream(in);
    return new Driver(iss, sname, true);
}

// create driver from file stream
Driver* Driver::createFromFile(const std::string& filename)
{
    std::ifstream* in = new std::ifstream(filename.c_str(), std::ios::binary | std::ios::in);
    if (!in->good()) {
        delete in;
        throw LangException("File not found or not readable", Location(filename));
    }
    return new Driver(in, filename, true);
}

// returns stream name
std::string Driver::getStreamName() const
{
    return mStreamName;
}

// parse stream
Node* Driver::parse()
{
    ApusStack stack;
    ApusParser parser(*this, stack);
    int val = parser.parse();
    std::cerr << "Parser response: " << val << "\n";
    return 0;
}
