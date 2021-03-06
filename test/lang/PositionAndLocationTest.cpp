/*
 *******************************************************************************
 *   Copyright (C) 2012 Vasiliy Sheredeko
 *   MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "test.h" // Brings in the UnitTest++ framework
#include "apus/lang/node.hpp"

using namespace apus::lang;

TEST(LangPositionTest_0001)
{
    Position pos;
    CHECK_EQUAL(0, pos.getLine());
    CHECK_EQUAL(0, pos.getColumn());

    pos.setLine(1);
    CHECK_EQUAL(1, pos.getLine());

    pos.setColumn(1);
    CHECK_EQUAL(1, pos.getColumn());
}

TEST(LangPositionTest_0002)
{
    Position pos = Position(10, 12);
    CHECK_EQUAL(10, pos.getLine());
    CHECK_EQUAL(12, pos.getColumn());
}

TEST(LangLocationTest_0001)
{
    Position begin(10, 1);
    Position end(12, 24);
    Location loc("filename", begin, end);

    CHECK_EQUAL("filename", loc.getFilename());
    CHECK_EQUAL(10, loc.getBegin().getLine());
    CHECK_EQUAL(1, loc.getBegin().getColumn());
    CHECK_EQUAL(12, loc.getEnd().getLine());
    CHECK_EQUAL(24, loc.getEnd().getColumn());
}

TEST(LangLocationTest_0002)
{
    Location loc("filename");

    CHECK_EQUAL("filename", loc.getFilename());
    CHECK_EQUAL(0, loc.getBegin().getLine());
    CHECK_EQUAL(0, loc.getBegin().getColumn());
    CHECK_EQUAL(0, loc.getEnd().getLine());
    CHECK_EQUAL(0, loc.getEnd().getColumn());
}

TEST(LangLocationTest_0003)
{
    Location loc;

    CHECK_EQUAL("", loc.getFilename());
    CHECK_EQUAL(0, loc.getBegin().getLine());
    CHECK_EQUAL(0, loc.getBegin().getColumn());
    CHECK_EQUAL(0, loc.getEnd().getLine());
    CHECK_EQUAL(0, loc.getEnd().getColumn());
}
