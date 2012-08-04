/*
 *******************************************************************************
 *   Copyright (C) 2012 Vasiliy Sheredeko
 *   MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "test.h" // Brings in the UnitTest++ framework
#include "apus/lang/driver.hpp"

using namespace apus;
using namespace apus::lang;

TEST(DriverTest_0001)
{
    Driver* driver = Driver::createFromString("", "string");
    driver->parse();
    CHECK_EQUAL("string", driver->getStreamName());
    delete driver;
}
