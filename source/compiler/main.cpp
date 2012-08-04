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
    std::cout << APUS_NAME << " " << APUS_VERSION_STRING << " ©" << APUS_COPYRIGHT_YEARS << "\n";
    if (argc < 2) {
        std::cerr << "Run with filename\n";
        return -1;
    } else {
        for (int i = 1; i < argc; ++i) {
            try {
                Driver* driver = Driver::createFromFile(argv[i]);
                driver->parse();
                delete driver;
                std::cout << "Parse '" << argv[i] << " is complete\n";
            } catch (const Exception& ex) {
                std::cerr << ex;
            }
        }
        return 0;
    }
}
