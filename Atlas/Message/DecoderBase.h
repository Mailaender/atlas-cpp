// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Stefanus Du Toit

#ifndef ATLAS_MESSAGE_DECODERBASE_H
#define ATLAS_MESSAGE_DECODERBASE_H

#include <stack>
#include <Atlas/Bridge.h>
#include <Atlas/Message/Object.h>

namespace Atlas { namespace Message {

/** Base class for decoders that take Atlas::Message::Object.
 *
 * This class is passed to a codec as receiver bridge. It decodes a stream
 * into Message::Object objects, and after completion calls the abstract
 * ObjectArrived() method. This is to be overridden by base classes, which
 * might, for instance, provide an object queue or a callback method for
 * arrived messages.
 *
 * @see Atlas::Bridge
 * @see Atlas::Codec
 * @see Object
 * @author Stefanus Du Toit <sdt@gmx.net>
 * 
 */

class DecoderBase : public Bridge
{
public:
    DecoderBase();

    virtual ~DecoderBase() {}

    // Callback functions from Bridge
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

    /// Our current decoding state.
    enum State {
        STATE_STREAM,
        STATE_MAP,
        STATE_LIST
    };

    /// The state stack.
    std::stack<State> state;
    /// The map stack.
    std::stack<Object::MapType> maps;
    /// The list stack.
    std::stack<Object::ListType> lists;
    /// Names for maps and lists.
    std::stack<std::string> names;

    /// Override this - called when an object was received.
    virtual void ObjectArrived(const Object& obj) = 0;
};

} } // namespace Atlas::Message

#endif
