// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000-2001 Stefanus Du Toit and Alistair Riddoch

#ifndef ATLAS_OBJECTS_ROOT_H
#define ATLAS_OBJECTS_ROOT_H

#include <Atlas/Message/Encoder.h>
#include <Atlas/Message/Object.h>

namespace Atlas { namespace Objects {

/** An exception indicating the requested attribute does not exist.
 *
 * This is thrown by Root::GetAttr() [and derivatives thereof!]
 */
class NoSuchAttrException
{
public:
    NoSuchAttrException(const std::string& name) : name(name) {}
    std::string name;
};

/** All objects inherit from this


  
*/
class Root {
public:
    /// Construct a Root class definition.
    Root();
    /// Construct a Root instance.
    Root(const std::string& id);
protected:
    /// Constructor for classes which inherit from this one
    Root(const std::string& id, const std::string& parent);
public:
    /// Default destructor.
    virtual ~Root();

    /// Create a new instance of Root.
    static Root Instantiate();

    /// Check whether the attribute "name" exists.
    virtual bool HasAttr(const std::string& name) const;
    /// Retrieve the attribute "name". Throws NoSuchAttrException if it does
    /// not exist.
    virtual Atlas::Message::Object GetAttr(const std::string& name)
        const throw (NoSuchAttrException);
    /// Set the attribute "name" to the value given by "attr".
    virtual void SetAttr(const std::string& name,
                         const Atlas::Message::Object& attr);
    /// Remove the attribute "name". This will not work for static attributes.
    virtual void RemoveAttr(const std::string& name);

    /// Set the "parents" attribute.
    inline void SetParents(const Atlas::Message::Object::ListType& val);
    /// Set the "id" attribute.
    inline void SetId(const std::string& val);
    /// Set the "objtype" attribute.
    inline void SetObjtype(const std::string& val);
    /// Set the "name" attribute.
    inline void SetName(const std::string& val);

    /// Retrieve the "parents" attribute.
    inline const Atlas::Message::Object::ListType& GetParents() const;
    inline Atlas::Message::Object::ListType& GetParents();
    /// Retrieve the "id" attribute.
    inline const std::string& GetId() const;
    inline std::string& GetId();
    /// Retrieve the "objtype" attribute.
    inline const std::string& GetObjtype() const;
    inline std::string& GetObjtype();
    /// Retrieve the "name" attribute.
    inline const std::string& GetName() const;
    inline std::string& GetName();
    
    /// Convert this object to a Message::Object.
    virtual Atlas::Message::Object AsObject() const;
    /// Convert this object to an std::map.
    virtual Atlas::Message::Object::MapType AsMap() const;

    /// Send the contents of this object to a Bridge.
    virtual void SendContents(Atlas::Bridge* b) const;

protected:
    std::map<std::string, Atlas::Message::Object> attributes;
    Atlas::Message::Object::ListType attr_parents;
    std::string attr_id;
    std::string attr_objtype;
    std::string attr_name;

    inline void SendParents(Atlas::Bridge*) const;
    inline void SendId(Atlas::Bridge*) const;
    inline void SendObjtype(Atlas::Bridge*) const;
    inline void SendName(Atlas::Bridge*) const;
};

// 
// Inlined member functions follow.
//

void Root::SetParents(const Atlas::Message::Object::ListType& val)
{
    attr_parents = val;
}

void Root::SetId(const std::string& val)
{
    attr_id = val;
}

void Root::SetObjtype(const std::string& val)
{
    attr_objtype = val;
}

void Root::SetName(const std::string& val)
{
    attr_name = val;
}

const Atlas::Message::Object::ListType& Root::GetParents() const
{
    return attr_parents;
}

Atlas::Message::Object::ListType& Root::GetParents()
{
    return attr_parents;
}

const std::string& Root::GetId() const
{
    return attr_id;
}

std::string& Root::GetId()
{
    return attr_id;
}

const std::string& Root::GetObjtype() const
{
    return attr_objtype;
}

std::string& Root::GetObjtype()
{
    return attr_objtype;
}

const std::string& Root::GetName() const
{
    return attr_name;
}

std::string& Root::GetName()
{
    return attr_name;
}

} }

#endif
