/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_TYPES
#define _APUS_TYPES

#include "apus/config.hpp"

// Include std string and intefers headers
#include <string.h>
#include <stdint.h>

// Include unicode headers
#include <unicode/unistr.h>

namespace apus {
    /// String contains characters in Unicode 16 encoding
    typedef UnicodeString                               String;

    /// ASCII string contains paths
    typedef std::string                                 Path;

    /// ASCII string for identificators
    typedef std::string                                 Identifier;
}

#endif
