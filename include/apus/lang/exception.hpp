/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_EXCEPTION
#define _APUS_LANG_EXCEPTION

#include "apus/exception.hpp"
#include "apus/location.hpp"

namespace apus {
namespace lang {
    /// Base exception class for all language excception, e.g. not found variables
    class LangException : public virtual Exception {
    public:
        /// Constructor
        LangException();

        /// Constructor
        LangException(const String& message);

        /// Constructor
        LangException(const String& message, const Location& location);

        /// Destructor
        virtual ~LangException() throw();

        /// Return location of error
        Location getLocation() const;

        /// Set location of error
        void setLocation(const Location& location);

        /// Dump error to stream
        virtual void dump(std::ostream& stream) const;
    protected:
        /// Location of error
        Location mLocation;
    };

    /// output core information about position in stream
    std::ostream& operator<<(std::ostream& stream, const Position& position);

    /// output core information about location in stream
    std::ostream& operator<<(std::ostream& stream, const Location& location);
}}

#endif
