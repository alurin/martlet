/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_NODE
#define _APUS_LANG_NODE

#include "apus/types.hpp"

namespace apus {
namespace lang {

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

    class Location {
    public:
        /// Default constructor
        Location();

        /// Constructor
        Location(const Path& filename);

        /// Constructor
        Location(const Path& filename, const Position& begin, const Position& end);

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

    /// Abstract syntax tree node
    class Node
    {
    public:
        /// Destructor
        virtual ~Node();

        /// Returns location of node in file
        Location getLocation() const;

        /// Set location of node
        void setLocation(const Location& location);
    protected:
        /// Node constructor
        Node(Location& location);
    private:
        /// Location of node
        Location mLocation;
    };

}}

#endif
