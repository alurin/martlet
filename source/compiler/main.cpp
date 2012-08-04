/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */

/**
 * @file
 * This file contains main point for Martlet
 */

#include "apus/exception.hpp"
#include "apus/lang/driver.hpp"
#include <iostream>

using namespace apus;
using namespace apus::lang;

int main (int argc, const char **argv)
{
    if (argc == 0) {
        std::cerr << "Run with filename\n";
        return -1;
    } else {
        for (int i = 0; i < argc; ++i) {
            try {
                Driver* driver = Driver::createFromFile(argv[i]);
                driver->parse();
                delete driver;
            } catch (const Exception& ex) {
                std::cerr << ex;
            }
        }
        return 0;
    }
}
