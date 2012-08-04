/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/lang/exception.hpp"
#include "location.hh"

using namespace apus;
using namespace apus::lang;

/// output core information about exception in stream
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

    stream << loc;
}

/// output core information about exception in stream
std::ostream& apus::lang::operator<<(std::ostream& stream, const Position& posR)
{
    position pos;

    pos.filename = 0;
    pos.line   = posR.getLine();
    pos.column = posR.getColumn();

    stream << pos;
}
