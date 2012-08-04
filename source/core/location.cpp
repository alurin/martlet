/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/location.hpp"
#include "lang/location.hh"

using namespace apus;

// position constructor
// location constructor
Location::Location()
{ }

// location constructor
Location::Location(const Path& filename)
: mFilename(filename) { }

// location constructor
Location::Location(const Path& filename, const Position& begin, const Position& end)
: mFilename(filename), mBegin(begin), mEnd(end) { }

// hack location constructor
Location::Location(const lang::location& l)
: mFilename(*l.begin.filename), mBegin(l.begin.line, l.begin.column), mEnd(l.end.line, l.end.column)
{ }

// returns stream name
Path Location::getFilename() const
{
    return mFilename;
}

// set stream name
void Location::setFilename(const Path& filename)
{
    mFilename = filename;
}

// return begin
Position Location::getBegin() const
{
    return mBegin;
}

// set begin
void Location::setBegin(Position begin)
{
    mBegin = begin;
}

// return end
Position Location::getEnd() const
{
    return mEnd;
}

// set end
void Location::setEnd(Position end)
{
    mEnd = end;
}
