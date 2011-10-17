// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2005 Alistair Riddoch.
// Automatically generated using gen_cpp.py.

#ifndef ATLAS_OBJECTS_ROOT_H
#define ATLAS_OBJECTS_ROOT_H

#include <Atlas/Objects/BaseObject.h>

#include <Atlas/Message/Element.h>

namespace Atlas { namespace Objects { 

template <class T> class SmartPtr;

/** All objects inherit from this.

You can browse all definitions starting from here and 
descending into childrens.

*/

class RootData;
typedef SmartPtr<RootData> Root;

static const int ROOT_NO = 1;


/// \brief All objects inherit from this..
///
/** You can browse all definitions starting from here and 
descending into childrens.
 */
class RootData : public BaseObjectData
{
protected:
    template <typename>
    friend class ::Atlas::Objects::Allocator;

    /// Construct a RootData class definition.
    RootData(RootData *defaults = NULL) :
        BaseObjectData(defaults)
    {
        m_class_no = ROOT_NO;
    }
    /// Default destructor.
    virtual ~RootData();

public:

    /// Copy this object.
    virtual RootData * copy() const;

    /// Is this instance of some class?
    virtual bool instanceOf(int classNo) const;

    /// Retrieve the attribute "name". Return non-zero if it does
    /// not exist.
    virtual int copyAttr(const std::string& name, Atlas::Message::Element & attr) const;
    /// Set the attribute "name" to the value given by"attr"
    virtual void setAttr(const std::string& name,
                         const Atlas::Message::Element& attr);
    /// Remove the attribute "name". This will not work for static attributes.
    virtual void removeAttr(const std::string& name);

    /// Send the contents of this object to a Bridge.
    virtual void sendContents(Atlas::Bridge & b) const;

    /// Write this object to an existing Element.
    virtual void addToMessage(Atlas::Message::MapType &) const;

    /// Set the "id" attribute.
    inline void setId(const std::string& val);
    /// Set the "parents" attribute.
    inline void setParents(const std::list<std::string>& val);
    /// Set the "parents" attribute AsList.
    inline void setParentsAsList(const Atlas::Message::ListType& val);
    /// Set the "stamp" attribute.
    inline void setStamp(double val);
    /// Set the "objtype" attribute.
    inline void setObjtype(const std::string& val);
    /// Set the "name" attribute.
    inline void setName(const std::string& val);

    /// Retrieve the "id" attribute.
    inline const std::string& getId() const;
    /// Retrieve the "id" attribute as a non-const reference.
    inline std::string& modifyId();
    /// Retrieve the "parents" attribute.
    inline const std::list<std::string>& getParents() const;
    /// Retrieve the "parents" attribute as a non-const reference.
    inline std::list<std::string>& modifyParents();
    /// Retrieve the "parents" attribute AsList.
    inline const Atlas::Message::ListType getParentsAsList() const;
    /// Retrieve the "stamp" attribute.
    inline double getStamp() const;
    /// Retrieve the "stamp" attribute as a non-const reference.
    inline double& modifyStamp();
    /// Retrieve the "objtype" attribute.
    inline const std::string& getObjtype() const;
    /// Retrieve the "objtype" attribute as a non-const reference.
    inline std::string& modifyObjtype();
    /// Retrieve the "name" attribute.
    inline const std::string& getName() const;
    /// Retrieve the "name" attribute as a non-const reference.
    inline std::string& modifyName();

    /// Is "id" value default?
    inline bool isDefaultId() const;
    /// Is "parents" value default?
    inline bool isDefaultParents() const;
    /// Is "stamp" value default?
    inline bool isDefaultStamp() const;
    /// Is "objtype" value default?
    inline bool isDefaultObjtype() const;
    /// Is "name" value default?
    inline bool isDefaultName() const;

protected:
    /// Find the class which contains the attribute "name".
    virtual int getAttrClass(const std::string& name)const;
    /// Find the flag for the attribute "name".
    virtual int getAttrFlag(const std::string& name)const;
    /// Id of object
    std::string attr_id;
    /// List of objects this inherits attributes from.
    std::list<std::string> attr_parents;
    /// Last time this object was modified.
    double attr_stamp;
    /// What kind of object this is.
    std::string attr_objtype;
    /// Name of object.
    std::string attr_name;

    /// Send the "id" attribute to an Atlas::Bridge.
    void sendId(Atlas::Bridge&) const;
    /// Send the "parents" attribute to an Atlas::Bridge.
    void sendParents(Atlas::Bridge&) const;
    /// Send the "stamp" attribute to an Atlas::Bridge.
    void sendStamp(Atlas::Bridge&) const;
    /// Send the "objtype" attribute to an Atlas::Bridge.
    void sendObjtype(Atlas::Bridge&) const;
    /// Send the "name" attribute to an Atlas::Bridge.
    void sendName(Atlas::Bridge&) const;

    virtual void iterate(int& current_class, std::string& attr) const;

public:
    static Allocator<RootData> allocator;

private:

    virtual void free();

    /// \brief Get the reference object that contains the default values for
    /// attributes of instances of this class.
    ///
    /// @return a pointer to the default object.
    static void fillDefaultObjectInstance(RootData& data, std::map<std::string, int>& attr_data);
};

//
// Attribute name strings follow.
//

extern const std::string ID_ATTR;
extern const std::string PARENTS_ATTR;
extern const std::string STAMP_ATTR;
extern const std::string OBJTYPE_ATTR;
extern const std::string NAME_ATTR;

//
// Inlined member functions follow.
//

const int ID_FLAG = 1 << 1;

void RootData::setId(const std::string& val)
{
    attr_id = val;
    m_attrFlags |= ID_FLAG;
}

const int PARENTS_FLAG = 1 << 2;

void RootData::setParents(const std::list<std::string>& val)
{
    attr_parents = val;
    m_attrFlags |= PARENTS_FLAG;
}

void RootData::setParentsAsList(const Atlas::Message::ListType& val)
{
    m_attrFlags |= PARENTS_FLAG;
    attr_parents.resize(0);
    for(Atlas::Message::ListType::const_iterator I = val.begin();
        I != val.end();
        I++)
    {
        if((*I).isString()) {
            attr_parents.push_back((*I).asString());
        }
    }
}

const int STAMP_FLAG = 1 << 3;

void RootData::setStamp(double val)
{
    attr_stamp = val;
    m_attrFlags |= STAMP_FLAG;
}

const int OBJTYPE_FLAG = 1 << 4;

void RootData::setObjtype(const std::string& val)
{
    attr_objtype = val;
    m_attrFlags |= OBJTYPE_FLAG;
}

const int NAME_FLAG = 1 << 5;

void RootData::setName(const std::string& val)
{
    attr_name = val;
    m_attrFlags |= NAME_FLAG;
}

const std::string& RootData::getId() const
{
    if(m_attrFlags & ID_FLAG)
        return attr_id;
    else
        return ((RootData*)m_defaults)->attr_id;
}

std::string& RootData::modifyId()
{
    if(!(m_attrFlags & ID_FLAG))
        setId(((RootData*)m_defaults)->attr_id);
    return attr_id;
}

const std::list<std::string>& RootData::getParents() const
{
    if(m_attrFlags & PARENTS_FLAG)
        return attr_parents;
    else
        return ((RootData*)m_defaults)->attr_parents;
}

std::list<std::string>& RootData::modifyParents()
{
    if(!(m_attrFlags & PARENTS_FLAG))
        setParents(((RootData*)m_defaults)->attr_parents);
    return attr_parents;
}

const Atlas::Message::ListType RootData::getParentsAsList() const
{
    const std::list<std::string>& lst_in = getParents();
    Atlas::Message::ListType lst_out;
    for(std::list<std::string>::const_iterator I = lst_in.begin();
        I != lst_in.end();
        I++)
    {
        lst_out.push_back(std::string(*I));
    }
    return lst_out;
}

double RootData::getStamp() const
{
    if(m_attrFlags & STAMP_FLAG)
        return attr_stamp;
    else
        return ((RootData*)m_defaults)->attr_stamp;
}

double& RootData::modifyStamp()
{
    if(!(m_attrFlags & STAMP_FLAG))
        setStamp(((RootData*)m_defaults)->attr_stamp);
    return attr_stamp;
}

const std::string& RootData::getObjtype() const
{
    if(m_attrFlags & OBJTYPE_FLAG)
        return attr_objtype;
    else
        return ((RootData*)m_defaults)->attr_objtype;
}

std::string& RootData::modifyObjtype()
{
    if(!(m_attrFlags & OBJTYPE_FLAG))
        setObjtype(((RootData*)m_defaults)->attr_objtype);
    return attr_objtype;
}

const std::string& RootData::getName() const
{
    if(m_attrFlags & NAME_FLAG)
        return attr_name;
    else
        return ((RootData*)m_defaults)->attr_name;
}

std::string& RootData::modifyName()
{
    if(!(m_attrFlags & NAME_FLAG))
        setName(((RootData*)m_defaults)->attr_name);
    return attr_name;
}

bool RootData::isDefaultId() const
{
    return (m_attrFlags & ID_FLAG) == 0;
}

bool RootData::isDefaultParents() const
{
    return (m_attrFlags & PARENTS_FLAG) == 0;
}

bool RootData::isDefaultStamp() const
{
    return (m_attrFlags & STAMP_FLAG) == 0;
}

bool RootData::isDefaultObjtype() const
{
    return (m_attrFlags & OBJTYPE_FLAG) == 0;
}

bool RootData::isDefaultName() const
{
    return (m_attrFlags & NAME_FLAG) == 0;
}

inline void RootData::free()
{
    allocator.free(this);
}

} } // namespace Atlas::Objects

#endif // ATLAS_OBJECTS_ROOT_H
