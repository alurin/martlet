/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/position.hpp"

using namespace apus;

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
