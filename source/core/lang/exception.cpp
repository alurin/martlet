/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/lang/exception.hpp"
#include "location.hh"
#include <unicode/ustream.h>

using namespace apus;
using namespace apus::lang;

// Constructor
LangException::LangException()
{ }

// Constructor
LangException::LangException(const String& message)
: Exception(message) { }

// Constructor
LangException::LangException(const String& message, const Location& location)
: Exception(message), mLocation(location) { }

// destructor
LangException::~LangException() throw()
{ }

// return location of error
Location LangException::getLocation() const
{
    return mLocation;
}

// set location of error
void LangException::setLocation(const Location& location)
{
    mLocation = location;
}

// dump error to stream
void LangException::dump(std::ostream& stream) const
{
    stream << getLocation() << ":" << getMessage();
}

// output core information about exception in stream
std::ostream& apus::lang::operator<<(std::ostream& stream, const Location& location)
{
    Position beginR = location.getBegin();
    Position endR   = location.getEnd();
    std::string filename = location.getFilename();

    position begin;
    position end;

    begin.filename = end.filename = &filename;
    begin.line   = beginR.getLine();
    begin.column = beginR.getColumn();
    end.line     = endR.getLine();
    end.column   = endR.getColumn();

    lang::location loc;
    loc.begin = begin;
    loc.end   = end;

    return stream << loc;
}

// output core information about exception in stream
std::ostream& apus::lang::operator<<(std::ostream& stream, const Position& posR)
{
    position pos;

    pos.filename = 0;
    pos.line   = posR.getLine();
    pos.column = posR.getColumn();

    return stream << pos;
}
