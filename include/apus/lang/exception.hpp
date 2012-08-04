/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_EXCEPTION
#define _APUS_LANG_EXCEPTION

#include "apus/exception.hpp"
#include "apus/lang/node.hpp"

namespace apus {
namespace lang {

    /// Information about exception: current nam of file
    typedef boost::error_info<struct tag_filename, std::string> exception_filename;


    /// Base exception class for all language excception, e.g. not found variables
    class LangException : public virtual Exception {
    public:
        const char* what() const throw() {
            return boost::diagnostic_information_what(*this);
        }
    };

    /// Information about exception: current line of file
    typedef boost::error_info<struct tag_fileline, Location> exception_location;

    /// output core information about position in stream
    std::ostream& operator<<(std::ostream& stream, const Position& position);

    /// output core information about location in stream
    std::ostream& operator<<(std::ostream& stream, const Location& location);
}}

#endif
