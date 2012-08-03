/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/lang/Node.hpp"

using namespace apus;
using namespace apus::lang;

// position constructor
Position::Position()
: mLine(0), mColumn(0) { }

// position constructor
Position::Position(int32_t line, int32_t column)
: mLine(line), mColumn(column) { }

// returns line
int32_t Position::getLine() const
{
    return mLine;
}

// set line
void Position::setLine(int32_t line)
{
    mLine = line;
}

// returns column
int32_t Position::getColumn() const
{
    return mColumn;
}

// set column
void Position::setColumn(int32_t column)
{
    mColumn = column;
}

// location constructor
Location::Location()
{ }

// location constructor
Location::Location(String filename)
: mFilename(filename) { }

// location constructor
Location::Location(String filename, const Position& begin, const Position& end)
: mFilename(filename), mBegin(begin), mEnd(end) { }

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

// node constructor
Node::Node(Location& location)
: mLocation(location) { }

// node destructor
virtual Node::~Node()
{ }

// returns location
Location Node::getLocation() const
{
    return mLocation;
}

// set location
void Node::setLocation(const Location& location)
{
    mLocation = location;
}
