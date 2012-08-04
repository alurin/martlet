/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LOCATION
#define _APUS_LOCATION

#include "apus/position.hpp"

namespace apus {
    namespace lang {
        struct location;
    }

    /// Structure for store location in file
    class Location {
    public:
        /// Default constructor
        Location();

        /// Constructor
        Location(const Path& filename);

        /// Constructor
        Location(const Path& filename, const Position& begin, const Position& end);

        /// Hack constructor for
        Location(const lang::location& location);

        /// Returns stream name of location
        Path getFilename() const;

        /// Set stream name of location
        void setFilename(const Path& filename);

        /// Returns begin position of location
        Position getBegin() const;

        /// Set begin position of location
        void setBegin(Position begin);

        /// Returns end position of location
        Position getEnd() const;

        /// Set end position of location
        void setEnd(Position end);
    private:
        /// Filename
        Path mFilename;

        /// Begin position of location
        Position mBegin;

        /// End position of location
        Position mEnd;
    };
}

#endif
