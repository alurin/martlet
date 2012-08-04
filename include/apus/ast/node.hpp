/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#ifndef _APUS_LANG_NODE
#define _APUS_LANG_NODE

#include "apus/location.hpp"

namespace apus {
namespace ast {

    /// Abstract syntax tree node
    class Node
    {
    public:
        /// Enumeration for node indentificators
        enum class NodeID : int32_t { };

        /// Destructor
        virtual ~Node();

        /// Returns location of node in file
        Location getLocation() const;

        /// Set location of node
        void setLocation(const Location& location);
    protected:
        /// Node constructor
        Node(const Location& location);
    private:
        /// Node class identificator
        NodeID mNodeID;

        /// Location of node
        Location mLocation;
    };
}}

#endif
