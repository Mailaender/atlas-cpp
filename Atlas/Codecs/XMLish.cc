// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#include <iostream>
#include <string>

#include "Utility.h"
#include "../Codec.h"

using namespace Atlas;

/*

    FIXME documentation forthcoming

*/

class XMLish : public Codec<std::iostream>
{
    public:

    XMLish(const Codec<std::iostream>::Parameters&);

    virtual void Poll(bool can_read = true);

    virtual void StreamBegin();
    virtual void StreamMessage(const Map&);
    virtual void StreamEnd();

    virtual void MapItem(const std::string& name, const Map&);
    virtual void MapItem(const std::string& name, const List&);
    virtual void MapItem(const std::string& name, int);
    virtual void MapItem(const std::string& name, double);
    virtual void MapItem(const std::string& name, const std::string&);
    virtual void MapEnd();
    
    virtual void ListItem(const Map&);
    virtual void ListItem(const List&);
    virtual void ListItem(int);
    virtual void ListItem(double);
    virtual void ListItem(const std::string&);
    virtual void ListEnd();

    protected:

    std::iostream& socket;
    Bridge* bridge;
};

namespace
{
    /*
        We're not going to enable this sucker until it actually works.
    
    Codec<iostream>::Factory<XMLish> factory(
	"XMLish"				    // name
    );

    */
}
    
XMLish::XMLish(const Codec<std::iostream>::Parameters& p)
    : socket(p.stream), bridge(p.bridge)
{
}

void XMLish::Poll(bool can_read = true)
{
    if (!can_read) return;
    do
    {
	char next = socket.get();

	// FIXME handle incoming characters
    }
    while (socket.rdbuf()->in_avail());
}

void XMLish::StreamBegin()
{
    socket << "<atlas>";
}

void XMLish::StreamMessage(const Map&)
{
    socket << "<map>";
}

void XMLish::StreamEnd()
{
    socket << "</atlas>";
}

void XMLish::MapItem(const std::string& name, const Map&)
{
    socket << "<map name=\"" << name << "\">";
}

void XMLish::MapItem(const std::string& name, const List&)
{
    socket << "<list name=\"" << name << "\">";
}

void XMLish::MapItem(const std::string& name, int data)
{
    socket << "<int name=\"" << name << "\">" << data << "</int>";
}

void XMLish::MapItem(const std::string& name, double data)
{
    socket << "<float name=\"" << name << "\">" << data << "</float>";
}

void XMLish::MapItem(const std::string& name, const std::string& data)
{
    socket << "<string name=\"" << name << "\">" << data << "</string>";
}

void XMLish::MapEnd()
{
    socket << "</map>";
}

void XMLish::ListItem(const Map&)
{
    socket << "<map>";
}

void XMLish::ListItem(const List&)
{
    socket << "<list>";
}

void XMLish::ListItem(int data)
{
    socket << "<int>" << data << "</int>";
}

void XMLish::ListItem(double data)
{
    socket << "<float>" << data << "</float>";
}

void XMLish::ListItem(const std::string& data)
{
    socket << "<string>" << data << "</string>";
}

void XMLish::ListEnd()
{
    socket << "</list>";
}

