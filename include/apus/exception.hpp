/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_EXCEPTION
#define _APUS_EXCEPTION

#include "apus/types.hpp"
#include <ostream>

namespace apus {
    /// Base exception class for all Kiwi core exceptions
    /// @todo Create analog of Boost::Exception :(
    class Exception : public virtual std::exception {
    public:
        /// Constructor
        Exception();

        /// Constructor with message
        Exception(const String& message);

        /// Destructor
        virtual ~Exception() throw();

        /// Return exception message
        String getMessage() const;

        /// Set exception message
        void setMessage(const String& message);

        /// Dump error to stream
        virtual void dump(std::ostream& stream) const;
    protected:
        /// Error message
        String mMessage;
    };

    /// output core information about exception in stream
    std::ostream& operator<<(std::ostream& stream, const Exception& ex);
}

#endif
