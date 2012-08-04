/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_POSITION
#define _APUS_POSITION

#include "apus/types.hpp"

namespace apus {

    class Position {
    public:
        /// Default constructor
        Position();

        /// Constructor
        Position(int32_t line, int32_t column);

        /// Returns line number of position
        int32_t getLine() const;

        /// Set line number of position
        void setLine(int32_t line);

        /// Returns column number of position
        int32_t getColumn() const;

        /// Set column number of position
        void setColumn(int32_t column);
    protected:
        /// Line number of position
        int32_t mLine;

        /// Column number of position
        int32_t mColumn;
    };
}

#endif
