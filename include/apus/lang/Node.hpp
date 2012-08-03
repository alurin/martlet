/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_NODE
#define _APUS_LANG_NODE

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
        int32_t mLine

        /// Column number of position
        int32_t mColumn;
    }

    class Location {
    public:
        /// Default constructor
        Location();

        /// Constructor
        Location(String filename);

        /// Constructor
        Location(String filename, const Position& begin, const Position& end);

        /// Return begin position of location
        Position getBegin() const;

        /// Set begin position of location
        void setBegin(Position begin);

        /// Return end position of location
        Position getEnd() const;

        /// Set end position of location
        void setEnd(Position end);
    private:
        /// Filename
        String mFilename

        /// Begin position of location
        Position mBegin;

        /// End position of location
        Position mEnd;
    }

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
