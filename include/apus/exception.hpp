/*
 *******************************************************************************
 *   Copyright (C) 2012 Vasiliy Sheredeko
 *   MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_EXCEPTION
#define _APUS_EXCEPTION

#include "apus/types.hpp"
#include <boost/exception/all.hpp>
#include <boost/format.hpp>
#include <ostream>

namespace apus {
    /// Information about exception: current nam of file
    typedef boost::error_info<struct tag_message, std::string>  exception_message;

    /// Base exception class for all Kiwi core exceptions
    class Exception : virtual public boost::exception, public virtual std::exception {
    };

    /// output core information about exception in stream
    std::ostream& operator<<(std::ostream& stream, const Exception& ex);

    #define exception_format(_format, _args) exception_message(boost::str(boost::format(_format) % _args ))
}

#endif
