// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#include <iostream>
#include <string>
#include <stack>

#include "Utility.h"
#include "../Codec.h"

using namespace Atlas;

/*

Sample output for this codec: (whitespace added for clarity)

<atlas>
    <map>
	<int name="foo">13</int>
	<float name="meep">1.5</float>
	<string name="bar">hello</string>
	<list name="args">
	    <int>1</int>
	    <int>2</int>
	    <float>3.0</float>
	</list>
    </map>
</atlas>

The complete specification is located in cvs at:
    forge/protocols/atlas/spec/xml_syntax.html

*/

class XML : public Codec<std::iostream>
{
    public:

    XML(const Codec<std::iostream>::Parameters&);

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
    
    enum Token
    {
	TOKEN_TAG,
	TOKEN_START_TAG,
	TOKEN_END_TAG,
	TOKEN_DATA,
    };
    
    Token token;
    
    enum State
    {
	PARSE_NOTHING,
	PARSE_STREAM,
        PARSE_MAP,
        PARSE_LIST,
	PARSE_INT,
	PARSE_FLOAT,
	PARSE_STRING,
    };
    
    std::stack<State> state;
    std::stack<std::string> data;

    std::string tag;
    std::string name;

    inline void TokenTag(char);
    inline void TokenStartTag(char);
    inline void TokenEndTag(char);
    inline void TokenData(char);

    inline void ParseStartTag();
    inline void ParseEndTag();
};

namespace
{
    Codec<std::iostream>::Factory<XML> factory(
	"XML"					    // name
    );
}
    
XML::XML(const Codec<std::iostream>::Parameters& p)
    : socket(p.stream), bridge(p.bridge)
{
    token = TOKEN_DATA;
    state.push(PARSE_NOTHING);
    data.push("");
}

void XML::TokenTag(char next)
{
    tag.erase();
    
    switch (next)
    {
	case '/':
	    token = TOKEN_END_TAG;
	break;
	
	case '>':
	    // FIXME signal error here
	    // unexpected character
	break;
	
	default:
	    token = TOKEN_START_TAG;
	    tag += next;
	break;
    }
}

void XML::TokenStartTag(char next)
{
    switch (next)
    {
	case '<':
	    // FIXME signal error here
	    // unexpected character
	break;

	case '>':
	    ParseStartTag();
	    token = TOKEN_DATA;
	    data.push("");
	break;

	default:
	    tag += next;
	break;
    }
}

void XML::TokenEndTag(char next)
{
    switch (next)
    {
	case '<':
	    // FIXME signal error here
	    // unexpected character
	break;

	case '>':
	    ParseEndTag();
	    token = TOKEN_DATA;
	    data.pop();
	break;

	default:
	    tag += next;
	break;
    }
}

void XML::TokenData(char next)
{
    switch (next)
    {
	case '<':
	    token = TOKEN_TAG;
	break;

	case '>':
	    // FIXME signal error here
	    // unexpected character
	break;

	default:
	    data.top() += next;
	break;
    }
}

void XML::ParseStartTag()
{
    int tag_end = tag.find(' ');
    int name_start = tag.find("name=\"") + 6;
    int name_end = tag.rfind("\"");
    
    if (name_start < name_end)
    {
	name = std::string(tag, name_start, name_end - name_start);
    }
    else
    {
	name.erase();
    }
    
    tag = std::string(tag, 0, tag_end);

    switch (state.top())
    {
	case PARSE_NOTHING:
	    if (tag == "atlas")
	    {
		bridge->StreamBegin();
		state.push(PARSE_STREAM);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
	case PARSE_STREAM:
	    if (tag == "map")
	    {
		bridge->StreamMessage(MapBegin);
		state.push(PARSE_MAP);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_MAP:
	    if (tag == "map")
	    {
		bridge->MapItem(name, MapBegin);
		state.push(PARSE_MAP);
	    }
	    else if (tag == "list")
	    {
		bridge->MapItem(name, ListBegin);
		state.push(PARSE_LIST);
	    }
	    else if (tag == "int")
	    {
		state.push(PARSE_INT);
	    }
	    else if (tag == "float")
	    {
		state.push(PARSE_FLOAT);
	    }
	    else if (tag == "string")
	    {
		state.push(PARSE_STRING);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_LIST:
	    if (tag == "map")
	    {
		bridge->ListItem(MapBegin);
		state.push(PARSE_MAP);
	    }
	    else if (tag == "list")
	    {
		bridge->ListItem(ListBegin);
		state.push(PARSE_LIST);
	    }
	    else if (tag == "int")
	    {
		state.push(PARSE_INT);
	    }
	    else if (tag == "float")
	    {
		state.push(PARSE_FLOAT);
	    }
	    else if (tag == "string")
	    {
		state.push(PARSE_STRING);
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_INT:
	case PARSE_FLOAT:
	case PARSE_STRING:
	    // FIXME signal error here
	    // unexpected tag
	break;
    }
}

void XML::ParseEndTag()
{
    switch (state.top())
    {
	case PARSE_NOTHING:
	    // FIXME signal error here
	    // unexpected tag
	break;
	
	case PARSE_STREAM:
	    if (tag == "atlas")
	    {
		bridge->StreamEnd();
		state.pop();
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_MAP:
	    if (tag == "map")
	    {
		bridge->MapEnd();
		state.pop();
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
	
        case PARSE_LIST:
	    if (tag == "list")
	    {
		bridge->ListEnd();
		state.pop();
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_INT:
	    if (tag == "int")
	    {
		state.pop();
		if (state.top() == PARSE_MAP)
		{
		    bridge->MapItem(name, atoi(data.top().c_str()));
		}
		else
		{
		    bridge->ListItem(atoi(data.top().c_str()));
		}
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_FLOAT:
	    if (tag == "float")
	    {
		state.pop();
		if (state.top() == PARSE_MAP)
		{
		    bridge->MapItem(name, atof(data.top().c_str()));
		}
		else
		{
		    bridge->ListItem(atof(data.top().c_str()));
		}
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;

	case PARSE_STRING:
	    if (tag == "string")
	    {
		state.pop();
		if (state.top() == PARSE_MAP)
		{
		    bridge->MapItem(name, data.top());
		}
		else
		{
		    bridge->ListItem(data.top());
		}
	    }
	    else
	    {
		// FIXME signal error here
		// unexpected tag
	    }
	break;
    }
}

void XML::Poll(bool can_read = true)
{
    if (!can_read) return;
    do
    {
	char next = socket.get();

	switch (token)
	{
	    case TOKEN_TAG:	    TokenTag(next); break;
	    case TOKEN_START_TAG:   TokenStartTag(next); break;
	    case TOKEN_END_TAG:	    TokenEndTag(next); break;
	    case TOKEN_DATA:	    TokenData(next); break;
	}
    }
    while (socket.rdbuf()->in_avail());
}

void XML::StreamBegin()
{
    socket << "<atlas>";
}

void XML::StreamEnd()
{
    socket << "</atlas>";
}

void XML::StreamMessage(const Map&)
{
    socket << "<map>";
}

void XML::MapItem(const std::string& name, const Map&)
{
    socket << "<map name=\"" << name << "\">";
}

void XML::MapItem(const std::string& name, const List&)
{
    socket << "<list name=\"" << name << "\">";
}

void XML::MapItem(const std::string& name, int data)
{
    socket << "<int name=\"" << name << "\">" << data << "</int>";
}

void XML::MapItem(const std::string& name, double data)
{
    socket << "<float name=\"" << name << "\">" << data << "</float>";
}

void XML::MapItem(const std::string& name, const std::string& data)
{
    socket << "<string name=\"" << name << "\">" << data << "</string>";
}

void XML::MapEnd()
{
    socket << "</map>";
}

void XML::ListItem(const Map&)
{
    socket << "<map>";
}

void XML::ListItem(const List&)
{
    socket << "<list>";
}

void XML::ListItem(int data)
{
    socket << "<int>" << data << "</int>";
}

void XML::ListItem(double data)
{
    socket << "<float>" << data << "</float>";
}

void XML::ListItem(const std::string& data)
{
    socket << "<string>" << data << "</string>";
}

void XML::ListEnd()
{
    socket << "</list>";
}

