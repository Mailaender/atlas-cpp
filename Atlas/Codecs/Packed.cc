// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Stefanus Du Toit, Michael Day

#include <iostream>
#include <string>
#include <stack>

#include "Utility.h"
#include "../Codec.h"

using namespace std;
using namespace Atlas;

/*

The form for each element of this codec is as follows:

[type][name=][data][|endtype]
  
( ) for lists
[ ] for maps
$ for string
@ for int
# for float

Sample output for this codec: (whitespace added for clarity)

[@id=17$name=Fred +28the +2b great+29#weight=1.5(args=@1@2@3)]

The complete specification is located in cvs at:
    forge/protocols/atlas/spec/packed_syntax.html
    
*/

class Packed : public Codec<std::iostream>
{
public:
    
    Packed(const Codec<std::iostream>::Parameters&);

    virtual void Poll(bool can_read = true);

    virtual void StreamBegin();
    virtual void StreamMessage(const Map&);
    virtual void StreamEnd();

    virtual void MapItem(const std::string& name, const Map&);
    virtual void MapItem(const std::string& name, const List&);
    virtual void MapItem(const std::string& name, long);
    virtual void MapItem(const std::string& name, double);
    virtual void MapItem(const std::string& name, const std::string&);
    virtual void MapEnd();
    
    virtual void ListItem(const Map&);
    virtual void ListItem(const List&);
    virtual void ListItem(long);
    virtual void ListItem(double);
    virtual void ListItem(const std::string&);
    virtual void ListEnd();

protected:
    
    std::iostream& socket;
    Bridge* bridge;

    enum State
    {
	PARSE_STREAM,
        PARSE_MAP,
        PARSE_LIST,
	PARSE_MAP_BEGIN,
	PARSE_LIST_BEGIN,
        PARSE_INT,
        PARSE_FLOAT,
        PARSE_STRING,
        PARSE_NAME,
    };
    
    std::stack<State> state;

    std::string name;
    std::string data;

    inline void ParseStream(char);
    inline void ParseMap(char);
    inline void ParseList(char);
    inline void ParseMapBegin(char);
    inline void ParseListBegin(char);
    inline void ParseInt(char);
    inline void ParseFloat(char);
    inline void ParseString(char);
    inline void ParseName(char);

    inline const string HexEncode(const std::string& data)
    {
	return hexEncode("+", "+[]()@#$=", data);
    }

    inline const string HexDecode(const std::string& data)
    {
	return hexDecode("+", data);
    }
};

namespace
{
    Codec<std::iostream>::Factory<Packed> factory(
	"Packed"				    // name
    );
}

Packed::Packed(const Codec<std::iostream>::Parameters& p) :
    socket(p.stream), bridge(p.bridge)
{
    state.push(PARSE_STREAM);
}

void Packed::ParseStream(char next)
{
    switch (next)
    {
	case '[':
	    bridge->StreamMessage(MapBegin);
	    state.push(PARSE_MAP);
	break;
    
	default:
	    // FIXME signal error here
	    // unexpected character
	break;
    }
}

void Packed::ParseMap(char next)
{
    switch (next)
    {
	case ']':
	    bridge->MapEnd();
	    state.pop();
	break;

	case '[':
	    state.push(PARSE_MAP);
	    state.push(PARSE_MAP_BEGIN);
	    state.push(PARSE_NAME);
	break;

	case '(':
	    state.push(PARSE_LIST);
	    state.push(PARSE_LIST_BEGIN);
	    state.push(PARSE_NAME);
	break;

	case '$':
	    state.push(PARSE_STRING);
	    state.push(PARSE_NAME);
	break;

	case '@':
	    state.push(PARSE_INT);
	    state.push(PARSE_NAME);
	break;

	case '#':
	    state.push(PARSE_FLOAT);
	    state.push(PARSE_NAME);
	break;

	default:
	    // FIXME signal error here
	    // unexpected character
	break;
    }
}

void Packed::ParseList(char next)
{
    switch (next)
    {
	case ')':
	    bridge->ListEnd();
	    state.pop();
	break;

	case '[':
	    bridge->ListItem(MapBegin);
	    state.push(PARSE_MAP);
	break;

	case '(':
	    bridge->ListItem(ListBegin);
	    state.push(PARSE_LIST);
	break;

	case '$':
	    state.push(PARSE_STRING);
	break;

	case '@':
	    state.push(PARSE_INT);
	break;

	case '#':
	    state.push(PARSE_FLOAT);
	break;

	default:
	    // FIXME signal error here
	    // unexpected character
	break;
    }
}

void Packed::ParseMapBegin(char next)
{
    bridge->MapItem(HexDecode(name), MapBegin);
    socket.putback(next);
    state.pop();
    name.erase();
}

void Packed::ParseListBegin(char next)
{
    bridge->MapItem(HexDecode(name), ListBegin);
    socket.putback(next);
    state.pop();
    name.erase();
}

void Packed::ParseInt(char next)
{
    switch (next)
    {
	case '[':
	case ']':
	case '(':
	case ')':
	case '$':
	case '@':
	case '#':
	    socket.putback(next);
	    state.pop();
	    if (state.top() == PARSE_MAP)
	    {
		bridge->MapItem(HexDecode(name), atol(data.c_str()));
		name.erase();
	    }
	    else if (state.top() == PARSE_LIST)
	    {
		bridge->ListItem(atol(data.c_str()));
	    }
	    else
	    {
		// FIXME some kind of sanity checking assertion here
	    }
	    data.erase();
	break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '-':
	case '+':
	    data += next;
	break;

	default:
	    // FIXME signal error here
	    // unexpected character
	break;
    }
}

void Packed::ParseFloat(char next)
{
    switch (next)
    {
	case '[':
	case ']':
	case '(':
	case ')':
	case '$':
	case '@':
	case '#':
	    socket.putback(next);
	    state.pop();
	    if (state.top() == PARSE_MAP)
	    {
		bridge->MapItem(HexDecode(name), atof(data.c_str()));
		name.erase();
	    }
	    else if (state.top() == PARSE_LIST)
	    {
		bridge->ListItem(atof(data.c_str()));
	    }
	    else
	    {
		// FIXME some kind of sanity checking assertion here
	    }
	    data.erase();
	break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
	case '-':
	case '+':
	case 'e':
	case 'E':
	    data += next;
	break;

	default:
	    // FIXME signal error here
	    // unexpected character
	break;
    }
}

void Packed::ParseString(char next)
{
    switch (next)
    {
	case '[':
	case ']':
	case '(':
	case ')':
	case '$':
	case '@':
	case '#':
	    socket.putback(next);
	    state.pop();
	    if (state.top() == PARSE_MAP)
	    {
		bridge->MapItem(HexDecode(name), HexDecode(data));
		name.erase();
	    }
	    else if (state.top() == PARSE_LIST)
	    {
		bridge->ListItem(HexDecode(data));
	    }
	    else
	    {
		// FIXME some kind of sanity checking assertion here
	    }
	    data.erase();
	break;

	case '=':
	    // FIXME signal error here
	    // unexpected character
	break;

	default:
	    data += next;
	break;
    }
}

void Packed::ParseName(char next)
{
    switch (next)
    {
	case '=':
	    state.pop();
	break;

	case '[':
	case ']':
	case '(':
	case ')':
	case '$':
	case '@':
	case '#':
	    // FIXME signal error here
	    // unexpected character
	break;

	default:
	    name += next;
	break;
    }
}

void Packed::Poll(bool can_read = true)
{
    if (!can_read) return;
    do
    {
	char next = socket.get();

	switch (state.top())
	{
	    case PARSE_STREAM:	    ParseStream(next); break;
	    case PARSE_MAP:	    ParseMap(next); break;
	    case PARSE_LIST:	    ParseList(next); break;
	    case PARSE_MAP_BEGIN:   ParseMapBegin(next); break;
	    case PARSE_LIST_BEGIN:  ParseListBegin(next); break;
	    case PARSE_INT:	    ParseInt(next); break;
	    case PARSE_FLOAT:	    ParseFloat(next); break;
	    case PARSE_STRING:	    ParseString(next); break;
	    case PARSE_NAME:	    ParseName(next); break;
	}
    }
    while (socket.rdbuf()->in_avail());
}

void Packed::StreamBegin()
{
}

void Packed::StreamMessage(const Map&)
{
    socket << '[';
}

void Packed::StreamEnd()
{
}

void Packed::MapItem(const std::string& name, const Map&)
{
    socket << '[' << HexEncode(name) << '=';
}

void Packed::MapItem(const std::string& name, const List&)
{
    socket << '(' << HexEncode(name) << '=';
}

void Packed::MapItem(const std::string& name, long data)
{
    socket << '@' << HexEncode(name) << '=' << data;
}

void Packed::MapItem(const std::string& name, double data)
{
    socket << '#' << HexEncode(name) << '=' << data;
}

void Packed::MapItem(const std::string& name, const std::string& data)
{
    socket << '$' << HexEncode(name) << '=' << HexEncode(data);
}

void Packed::MapEnd()
{
    socket << ']';
}

void Packed::ListItem(const Map&)
{
    socket << '[';
}

void Packed::ListItem(const List&)
{
    socket << '(';
}

void Packed::ListItem(long data)
{
    socket << '@' << data;
}

void Packed::ListItem(double data)
{
    socket << '#' << data;
}

void Packed::ListItem(const std::string& data)
{
    socket << '$' << HexEncode(data);
}

void Packed::ListEnd()
{
    socket << ')';
}

