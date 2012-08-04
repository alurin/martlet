/*
 *******************************************************************************
 *      Copyright (C) 2012 Vasiliy Sheredeko
 *      MIT license. All Rights Reserved.
 *******************************************************************************
 */
#include "apus/ast/node.hpp"

using namespace apus;
using namespace apus::ast;

// node constructor
Node::Node(const Location& location)
: mLocation(location) { }

// node destructor
Node::~Node()
{ }

// returns location
Location Node::getLocation() const
{
    return mLocation;
}

// set location
void Node::setLocation(const Location& location)
{
    mLocation = location;
}
